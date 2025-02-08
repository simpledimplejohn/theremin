# Theremin Project
Build a theremin for playing at psyche night.  

## Materials
- Arduino Uno 
- Raspberry pi4
  - Debian 

## Instalation
### Raspberry Pi
1. Pi Debien with imiger
2. Install system wide dependencies:
  - `sudo apt update`
  - `sudo apt install -y puredata fluidsynth fluid-soundfont-gm jackd2 qjackctl python3-venv python3-pip` 
3. Setup virtual environment
  - `python3 -m venv ~/theremin_env`
  - `source ~/theremin_env/bin/activate`
4. Install python dependencies
  - `pip install pyserial pyfluidsynth python-rtmidi`
5. Arduino IDE
  - download .tar.xy file
7. Install Sound File:
wget -O /home/pi/theremin.sf2 https://musical-artifacts.com/artifacts/32/Synths.sf2

## RUNNING:
1. activate virtual environments needed:
  - `source ~/theremin_env/bin/activate`
  - `python3 theremin.py`









