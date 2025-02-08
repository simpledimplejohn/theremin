## PySynth Script

import serial
import fluidsynth
import time

# Set up FluidSynth
fs = fluidsynth.Synth()
fs.start()
sfid = fs.sfload("/home/pi/theremin.sf2")  # Load the SoundFont
fs.program_select(0, sfid, 0, 0)

# Connect to Arduino (Change ttyUSB0 if needed)
ser = serial.Serial('/dev/ttyUSB0', 9600, timeout=1)
time.sleep(2)  # Wait for Arduino to initialize

while True:
    try:
        line = ser.readline().decode().strip()  # Read serial data
        if line:
            pitch, volume = map(int, line.split(","))

            # Map pitch range (200 Hz - 1500 Hz)
            frequency = int(200 + (pitch / 1000) * 1300)

            # Map volume (0 - 127)
            velocity = min(max(int(volume / 50), 0), 127)

            # Play note
            fs.noteon(0, frequency % 128, velocity)

    except ValueError:
        continue
    except KeyboardInterrupt:
        print("Exiting...")
        fs.delete()
        break
