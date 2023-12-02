# Newton keyboard converter (newton_usb)

newton_usb converts the Apple Newton keyboard (X0044) to a USB keyboard.
newton_usb is created with reference to `keyboards/converter/sub_usb` and `keyboards/converter/palm_usb`.  
I also referred to the following sites. Thank you to the pioneers.

* [Information about Newton keyboard](https://sharktastica.co.uk/articles/apple_model_m "Apple Newton Keyboard - The time Apple turned to IBM/Lexmark for a Model M")
* [Newton keyboard converter for TMK](https://github.com/themav/tmk-keyboard-newton "TMK Keyboard for Apple Newton")
* [Newton keyboard converter for Arduino](https://jimandnoreen.com/?p=259 "A USB adapter for the Apple Newton keyboard")

* Keyboard Maintainer: [cheer4u](https://github.com/cheer4u-code)
* Hardware Supported: Pro micro compatible boards
* Hardware Availability: self-built

Make example for this keyboard (after setting up your build environment):

    make converter/newton_usb:default

Flashing example for this keyboard:

    make converter/newton_usb:default:flash

See the [build environment setup](https://docs.qmk.fm/#/getting_started_build_tools) and the [make instructions](https://docs.qmk.fm/#/getting_started_make_guide) for more information. Brand new to QMK? Start with our [Complete Newbs Guide](https://docs.qmk.fm/#/newbs).

## Bootloader

Enter the bootloader by:

* **Keycode in layout**: Press the key mapped to `QK_BOOT` if it is available

## Hardware

Target MCU is ATMega32u4 but other USB capable AVR will also work. The maintainer mostly uses Pro micro compatible boards.

Required parts:

* Apple Newton keyboard (X0044)
* Pro micro 5V/16Mhzboards
* PHR-6 Connector Housing and Wire for connecting PHR-6 and Pro micro
* USB cable for connecting Pro Micro to PC
* Soldering tools, wire strippers/cutters, etc.

|Newton keyboard PCB/PHR-6 | Pro micro board|
|--------------------------|----------------|
|6 GND                     | GND            |
|5 5V                      | VCC            |
|3 DATA                    | RXI            |

Circuit:

    Newton keyboard PCB
    -------.
           |                    Pro micro board
           |
     PHR-6 connector            .---|USB|---.
    .------|                    |           |
    |6 GND +-----------------------------------.
    |5 5V  +-----------------------------------|-.
    |4     |                    |           |  | |
    |3 DATA+--------------------+RXI     GND+-'  |
    |2     |                    |           |    |
    |1     |                    |        VCC+---'
    `------|                    |           |
           |                    |           |
           |                    |           |
    FPC connector               |           |
    .------|                    |           |
    |      |                    `-----------'


## Bootmagic not working

Bootmagic does not work because the keyboard does not send pre-boot key presses.
