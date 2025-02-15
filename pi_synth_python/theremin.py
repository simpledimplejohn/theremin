import time
import fluidsynth

# 1. Initialize FluidSynth and specify the driver.
#    (You can leave the driver default if ALSA is the default on your Pi)
fs = fluidsynth.Synth(driver="alsa")
fs.start()

# 2. Load your SoundFont file (adjust the path if needed)
soundfont_path = "/home/pi/theremin.sf2"
sfid = fs.sfload(soundfont_path)
fs.program_select(0, sfid, 0, 0)

# 3. Play a Middle C (MIDI note 60) at full velocity (127)
fs.noteon(0, 60, 127)
time.sleep(2)

# 4. Turn the note off
fs.noteoff(0, 60)

print("Played a note successfully!")
