# split62

My take on a low profile split keyboard. 

* [x] Low profile choc 1350 switches
* [x] Hot swappable
* [x] Split layout
* [x] Ortholinear
* [x] Column staggered

This was a really rewarding project and I learned a bunch along the way! I hope that this 
repo and documentation help you build your own. That said...

**Disclaimer:** While the keyboard is working while I type out this readme, there may be 
errors and/or poorly designed componetents throughout this repository. Use these files 
at your own risk. Please also read through the [TODO](#TODO) section before deciding to 
use anything in this repository.

![image](https://github.com/mzizzi/mzizzi-split62/blob/main/images/top.jpg)
![image](https://github.com/mzizzi/mzizzi-split62/blob/main/images/top-and-bottom.jpg)

## Firmware

This keyboard's firmware is built using QMK.

[Set up QMK](https://docs.qmk.fm/newbs_getting_started) locally and copy `qmk/keyboards/mzizzi`
 from this repository into your local qmk keyboards directory.

Connect one half of the keyboard and put the elite-pi into bootloader mode. keeb.io has excellent 
documentation on flashing firmware to the elite-pi: https://docs.keeb.io/elite-pi-guide#flashing

Enter bootloader mode (use one of the following methods):
* For a new Elite-Pi out of the packaging, it will already start in bootloader mode when plugged 
  into the computer
* Hold the Boot button (the left button) down, while pluging in the USB-C cable
* Wait for OS to detect the Elite-Pi. It will show up as a USB mass-storage device named RPI-RP2.

After the initial flash of the board you can simply hold down top innermost key (5 or 6 depending 
on the hand) while plugging in the elite-pi to make it connect in bootloader mode.

Each half of the keyboard must be flashed separately with qmk 
[handedness](https://docs.qmk.fm/features/split_keyboard#handedness-by-eeprom) flags specifying 
which side is being flashed. Both halves must be flashed:

```
qmk flash -kb mzizzi/split62 -km via -bl uf2-split-left
or
qmk flash -kb mzizzi/split62 -km via -bl uf2-split-right
```

## Configuration with via

This keyboard's firmware is compiled with support for [VIA](https://www.caniusevia.com/) which 
will allow for the keymap to be modified on the fly. The 
[via documentation](https://www.caniusevia.com/docs/specification) covers everything needed to 
get via working with the split62.

* Flash the keyboard via the instructions in this readme.
* Open https://usevia.app/ in your web browser
* Enable design mode in via settings
* Upload `qmk/keyboards/mzizzi/split62/via.json` in the design tab
* Authorize via access to the device
* Start customizing!                                                                                  |

## PCB

The PCB for this board was designed with [ergogen](https://ergogen.xyz/). I highly recommend
reading the [flatfootfox ergogen introducution](https://flatfootfox.com/ergogen-introduction/)
if you're looking to modify this board or make your own.

The PCB for this keyboard is reversible to cut down on cost of having it manufactured. Most board
manufacturers have a minimum order quantity per design (5 boards for jlcpcb). This makes for an 
interesting footprint for the elite-pi. The board is marked on either side to try and make it 
harder to accidentally install the controller socket on the wrong side.

All of the gerber files that I used to order these boards are included in the `gerbers` directory. 
Please read the [TODO](#TODO) section below before deciding whether or not to use these 
files as-is.

## Case

The case for the split62 is 3d printed. The outter shell of the case also serves as a key-plate to 
lock the choc switches into position. Ergogen is not used to generate the stls for the case.
Instead ergogen is used to generate dxfs for a "keyplate" outline. I imported that outline into
another CAD program and used it as a starting point to model the case. I printed the case on a 
bambulab x1c with 0.2mm layer height using 
[Overture matte black PLA](https://www.amazon.com/gp/product/B089S2QDHD)

## Bill of Materials

I built this keyboard for around $200 but also have a bunch of spare parts left over. 
[keeb.io](https://keeb.io/) links because they're awesome and did same day order+pickup for 
components that weren't even listed on their site!


| Item                      | Count | Cost    | Notes                                                                                                                                                                                      |
| ------------------------- | ----- | ------- | ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------ |
| 5x PCB                    | 5     | $21.00  | Only 2x needed. 5x minimum order from JLCPCB                                                                                                                                               |
| 3D Printed Cases          | 1     | $5.00   | Probably less if you have a printer (or know someone with a printer!)                                                                                                                      |
| Elite-Pi Controllers      | 2     | $26.00  | [https://keeb.io/products/elite-pi-usb-c-pro-micro-replacement-rp2040](https://keeb.io/products/elite-pi-usb-c-pro-micro-replacement-rp2040)                                               |
| Controller sockets        | 2     | $10.00  | Not required but recommended: [https://www.amazon.com/gp/product/B07H3SK179](https://www.amazon.com/gp/product/B07H3SK179)                                                                 |
| Kailh 1350 switches       | 62    | $38.00  | [https://keeb.io/products/kailh-choc-low-profile-switches-v1](https://keeb.io/products/kailh-choc-low-profile-switches-v1)                                                                 |
| Kailh 1350 sockets        | 62    | $16.00  | [https://www.amazon.com/100Pieces-Chocolate-Switches-Accessories-Mechanical-PC/dp/B0CPVJLMDJ](https://www.amazon.com/100Pieces-Chocolate-Switches-Accessories-Mechanical-PC/dp/B0CPVJLMDJ) |
| 1N4148 SMT SOD-123 Diodes | 62    | $10.00  | [https://www.amazon.com/gp/product/B09DR5KFXM](https://www.amazon.com/gp/product/B09DR5KFXM)                                                                                               |
| PJ-320A TRRS jacks        | 2     | $1.00   | [https://keeb.io/products/trrs-jack-3-5mm](https://keeb.io/products/trrs-jack-3-5mm)                                                                                                       |
| Choc 1350 Keycaps         | 62    | $54.00  | [https://keeb.io/products/mbk-glow-r2-choc-keycap-set](https://keeb.io/products/mbk-glow-r2-choc-keycap-set)                                                                               |
| TRRS Cable                | 1     | $4.00   | [https://keeb.io/products/trrs-cable?variant=50550149190](https://keeb.io/products/trrs-cable?variant=50550149190)                                                                         |
| m2 screws                 | 8     | $7.00   | [https://www.amazon.com/Countersunk-DIN7991-Stainless-Threaded-Fasteners/dp/B0CG1PDBWN](https://www.amazon.com/Countersunk-DIN7991-Stainless-Threaded-Fasteners/dp/B0CG1PDBWN)             |
| m2 threaded inserts       | 8     | $8.00   | [https://www.amazon.com/gp/product/B0B8GN63S2](https://www.amazon.com/gp/product/B0B8GN63S2)                                                                                               |
| Rubber feet               | 8     | $3.00   | [https://keeb.io/products/skuf-silicone-rubber-keyboard-feet](https://keeb.io/products/skuf-silicone-rubber-keyboard-feet)                                                                 |
| Total                     |       | $203    |                                                                                                          

## TODO

* Put the trrs jack closer to the side of the board. I had to cut away a few millimeters of the 
  board with a rotary tool so that the trrs connector had clearance to be fully inserted.
* Double check the trace size for 3v3 power and ground over the trrs cable. I used whatever the 
  default was without looking into how much power the rp2040 consumes. Google says that the rp2040 
  draws 20mA peak.
* More mounting holes on the PCB. A few more wouldn't hurt and would help with any warping of the
  3d printed case.
* Pull the sides of the PCB in a few mm. I didn't account for the case adding another 1-2mm.
* A better way to attach the MCU cover. This was an afterthought in v1 and attached with 
  double sided foam tape.
* Optional tenting mounts for the base of the case.
* Aluminum case

## Helpful Resources

Links to pages that helped me along the way:

* An excellent guide on using ergogen: https://flatfootfox.com/ergogen-introduction/
* qmk's documentation on a keyboard matrix and how it works:
  https://docs.qmk.fm/how_a_matrix_works
  * This article is what really made it stick for me: 
    https://www.dribin.org/dave/keyboard/one_html/
* The qmk hand wiring guide is a good introduction what you will later design a 
  pcb for: https://docs.qmk.fm/hand_wire 
* Matrix configuration: https://docs.qmk.fm/porting_your_keyboard_to_qmk#matrix-configuration
* Split keyboard layout marco: https://docs.qmk.fm/features/split_keyboard#layout-macro
* via: https://www.caniusevia.com/docs/specification

## More pictures
![image](https://github.com/mzizzi/mzizzi-split62/blob/main/images/pcb-front-back-switches.jpg)
![image](https://github.com/mzizzi/mzizzi-split62/blob/main/images/pcb-front-back.jpg)
![image](https://github.com/mzizzi/mzizzi-split62/blob/main/images/side.jpg)
![image](https://github.com/mzizzi/mzizzi-split62/blob/main/images/case-bottom.png)
![image](https://github.com/mzizzi/mzizzi-split62/blob/main/images/cad.jpg)
