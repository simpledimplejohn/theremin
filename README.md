# Theremin Project
Build a theremin for playing at psyche night.  

## Materials
- Arduino Uno 
- Raspberry pi4
  - Debian 

## Instalation
### Raspberry Pi
1. Pi Debien with imiger
2. pure data
3. -`sudo apt update`
  - `sudo apt install puredata`
3. fluidsynth
  - `sudo apt install fluidsynth fluid-soundfont-gm`
4. Jack (performance)
  - `sudo apt install jackd2 qjackctl`
5. MIDI support
  - `sudo apt install python3-venv`
  - `python3 -m venv ~/theremin_env`
  - `source ~/theremin_env/bin/activate`
  - `pip install python-rtmidi`
  - it had to be installed with an virtual environment
6. Arduino IDE
  - download .tar.xy file
7. Install Sound File:
wget -O /home/pi/theremin.sf2 https://musical-artifacts.com/artifacts/32/Synths.sf2
8. pyserial fluidsynth:
  - `source ~/synth_env/bin/activate`
  - `pip install pyserial fluidsynth`
  - must run this everytime you start the pi
9. VS Code
  - `sudo apt install code -y`

## RUNNING:
1. activate virtual environments needed:
  - source ~/theremin_env/bin/activate










