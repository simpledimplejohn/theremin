import serial
import fluidsynth
import time

# Initialize FluidSynth
fs = fluidsynth.Synth()
fs.start()
sfid = fs.sfload("/home/pi/theremin.sf2")  # Load the SoundFont
fs.program_select(0, sfid, 0, 0)

# Connect to Arduino (Adjust the port if needed, e.g., /dev/ttyUSB0 or /dev/ttyACM0)
ser = serial.Serial('/dev/ttyUSB0', 9600, timeout=1)
time.sleep(2)  # Wait for Arduino to initialize

previous_note = None  # Store last played note

def map_value(value, in_min, in_max, out_min, out_max):
    """Map a value from one range to another"""
    return int(out_min + (float(value - in_min) / float(in_max - in_min) * (out_max - out_min)))

while True:
    try:
        line = ser.readline().decode().strip()  # Read serial data
        if line:
            pitch, volume = map(int, line.split(","))

            # Convert pitch sensor to a MIDI note (C2 to C7 range: 36-96)
            midi_note = map_value(pitch, 0, 1000, 36, 96)

            # Ensure volume is in the valid MIDI range (0-127)
            velocity = max(0, min(volume, 127))

            # Stop the previous note if different
            if previous_note is not None and previous_note != midi_note:
                fs.noteoff(0, previous_note)

            # Play the new note
            fs.noteon(0, midi_note, velocity)
            previous_note = midi_note  # Store last note played

    except ValueError:
        continue
    except KeyboardInterrupt:
        print("Exiting...")
        fs.delete()
        break
