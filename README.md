# ArcadeStick-10b
This repository contains the source code for using a TeensyLC microcontroller for a USB fightsticks.  It can be easily configured for other Teensy models.  Use with other Arduino boards depends on that vendor providing joystick firmware for their board.

This does not support the Microsoft proprietary XInput and is unlikely to support any game consoles with USB inputs.

This code does not implement SOCD (Simultaneous Opposite Cardinal Directions) cleaning.  It would be easy to add, but I prefer zeroing the output and lighting a warning light for debugging hand built controllers.

Setup instructions:
- Install the arduino software and the Teensy libraries:
https://www.arduino.cc/
https://www.pjrc.com/teensy/td_download.html
- Open this project in the arduino software
- Under "Tools->Board", set your board type.
- Under "Tools->USB Type", pick something that includes "Joystick"

Known bugs:
- Like all USB HID devices, attaching two identical devices will work, but on each startup they will be assigned an order at random.  The host system cannot tell them apart and therefore does not know which one you want to be "Player 1".  One option is to power on the device, then attach the joysticks in the desired order.

Additional code:
- "ArcadeStick-10b-StarTrek" contains a button mapping for "Star Trek Bridge Crew".  The game does not support joysticks, so I mapped the keyboard hotkeys to this joystick.



