# M5 Keyboard and Mouse Emulator

This project implements a USB HID and a BLE HID device using the M5Cardputer, capable of emulating both a keyboard and a mouse. The device can switch between mouse and keyboard modes, sending the appropriate input data to a connected USB/BLE device.

# This fork

- Added an i2c Trackball from Pimoroni.
- Left click by pressing the ball, right click through either fn+click or G0 btn.
- Scroll horizontally/vertically by tracking while holding fn key.
- opt key is mapped to LeftGUI key (i.e Command ⌘ or Windows).
- Handle and correctly send the arrows, and esc keycodes.

To-do:
- Update the display graphics for cues on the key combo
- Update bluetooth le HID


## Key Features

- <b>Mouse and Keyboard Emulation:</b> The device can function as either a mouse or a keyboard, sending the corresponding input data via BLE.
- <b>Mode Switching:</b> You can toggle between mouse and keyboard modes using a designated key (Btn GO).
- <b>Controlling mouse with the arrow keys</b>


## Installation

- <b>M5Burner</b> : Search into M5CARDPUTER section and simply burn it
- <b>Old school</b> : Build or take the firmware.bin from the github release and flash it


## Usage

- <b> Mode :</b> Toggle GO button (on the edge) to change between Keyboard and Mouse
- <b>Keyboard :</b> Default Cardputer Keys. The keyboard layout depends on the configuration of the connected PC.
- <b> Mouse : </b>Arrow LEFT/RIGHT/UP/DOWN and 'OK' and '\\' (just above 'OK' Button)</b>