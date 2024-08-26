# [MEMSduino: Arduino-Based Controller for MEMS Switches](https://github.com/lafefspietz/MEMSduino/)

![](visual-abstract.png)

# Background

Measurement of microwave signals in the quantum regime is of increasing interest due the growth of superconducting quantum information technology, dark matter studies, and fundamental microwave quantum optics studies.  In order to observer microwaves in the quantum regime, the circuits being measured must be cooled to temperatures well below hf/k, where f is the frequency, h is the Planck constant, and k is the Boltzmann constant.  For the frequency range from 1 to 10 GHz typical in superconducting quantum information technology, if we want kT to be more than 10 times below hf, this means we need temperatures in the range from 0.005 to 0.05 kelvin.  This is generally accomplished with a dilution refrigerator, which uses the entropy of mixing of the two isotopes of liquid helium to cool large volumes(up to of order 1 cubic meter) of electronics down to approximately 0.01 kelvin.  


If we are to have a circuit thermalize to these low temperatures, we need to attenuate power going into the dilution refrigerator by several orders of magnitude.  In order to not overwhelm the extremely small quantum signals(<1 fW) with noise, these circuits generally also have cryogenic amplifiers inside the dilution refrigerator, which amplify the signal also by several orders of magnitude in power.  These amplifiers are expensive, bulky, and add to the heat load of the system. 

If researchers want to measure large numbers of samples in a single signal path, calibrate the noise, or calibrate the scattering parameters, they need to have the ability to switch a single signal line between a choice of multiple lines while the apparatus is cold.  At room temperature there are many solutions for this, but at low temperature the three known solutions are solenoid-based cryogenic electro-mechanical switches, piezo-based probe manipulators, and MEMS-based electro-mechanical switches.  The solenoid-based switches require large current pulses which heat up the whole cryostat, requiring on the order of an hour after each switching event. Also, they have been anecdotally and intermittently shown to destroy cryogenic HEMT amplifiers, which are several thousand dollars to replace, with potentially long lead times.  It is unknown at this time exactly what would be involved in preventing this from happening.  The piezo-based probe manipulators have been shown to be good for doing cryogenic on-wafer calibrations, but are slow and difficult to use, and are not compatible with many of the enclosures which are used in quantum information science experiments.  

This work concerns how to control the third of these solutions, the MEMS-based microwave switches from Menlo Microwave.  These switches have been shown to work at dilution refrigerator temperatures, and multiple commercial products exist today which are used for this.  Unlike the cryogenic solenoid-based switches, these switches are very compact, and are sold as a square surface mount package approximately 2.5mm on a side. These can be integrated into large and complex systems of interconnected circuit boards to make a wide range of possible experiments and products.  In order to control the RF lines of these switches, 90 volt DC signals are required.  In room temperature apparatus, this can be provided by built-in serial communication electronics. However, none of that CMOS-based electronics works at cryogenic temperatures.  

As companies create commercial products based on these MEMS switches, they can build custom controllers for any given switch design. However, in the current state of the field, there is considerable need for researchers to build new and ever-changing circuits using these switches, where rapid prototyping requires that they be able to control a variable number of 90 volt control lines.  Furthermore, it is useful in addition to being able to control these lines using software that a human operator be able to push buttons to change the state of the switch and see the current state in a clear and easy to understand display independent of any control computers.  

We present here an Arduino-based controller which allows experimenters to cheaply and easily control MEMS-based switches in a dilution refrigerator.  

# System Elements

## [bill of materials (.xlsx)](BOM.xlsx)

 - MEMS-based cryogenic switches(SP9T, SP8T, SP6T, E-Cal)
 - Control Software
 - Wood rack panel
 - Custom metal box
 - 3d printed parts
 - Arduino UNO
 - Arduino shield circuit board
 - Control panel circuit board
 - DB 25 relay circuit board
 - 5V to 90V boost
 - DB25 to Fischer cable
 - Cryogenic mounting hardware
 - MicroD breakout board


# System Build Steps

1. Cut the wood board and drill out the holes in it
2. Machine out the Bud box if you are not getting that done by a shop
3. Print the 3d printed parts and add thread inserts
4. Assemble shield board
5. Assemble DC DC converter System, set the voltage with the potentiometer and test
6. Assemble DB25 relay board other than the DB25 connector
7. Put the DB25 connector into the lid, add insulating tape to the lid, and finish the assembly
8. Finish the whole assembly of the BUD box, the Front Panel board, the Arduino mount, Arduino, Arduino shield, and cables
9. Connect Arduino UNO, program it, and test it
10. Assemble the DC cold control board
11. Machine the brass parts for the cryogenic assembly
11. Assemble the assembly


# Build Files

 - [builds/build-whole-system.pdf](builds/build-whole-system.pdf)
 - [builds/build-3dprinted-parts.pdf](builds/build-3dprinted-parts.pdf)
 - [builds/build-90V.pdf](builds/build-90V.pdf)
 - [builds/Arduino.pdf](builds/Arduino.pdf)
 - [builds/build-DB25-relay-HV-control.pdf](builds/build-DB25-relay-HV-control.pdf)
 - [builds/build-Front-Panel-Boards.pdf](builds/build-Front-Panel-Boards.pdf)
 - [builds/build-cold-board-mount-brackets.pdf](builds/build-cold-board-mount-brackets.pdf)
 - [builds/build-cold-microD-breakout.pdf](builds/build-cold-microD-breakout.pdf)
 - [builds/build-wood-board.pdf](builds/build-wood-board.pdf)
 - [builds/build-shield.pdf](builds/build-shield.pdf)
 - [builds/build-bud-box.pdf](builds/build-bud-box.pdf)
 - [builds/build-whole-system.pptx](builds/build-whole-system.pptx)
 - [builds/build-3dprinted-parts.pptx](builds/build-3dprinted-parts.pptx)
 - [builds/build-90V.docx](builds/build-90V.docx)
 - [builds/Arduino.pptx](builds/Arduino.pptx)
 - [builds/build-DB25-relay-HV-control.pptx](builds/build-DB25-relay-HV-control.pptx)
 - [builds/build-Front-Panel-Boards.pptx](builds/build-Front-Panel-Boards.pptx)
 - [builds/build-cold-board-mount-brackets.pptx](builds/build-cold-board-mount-brackets.pptx)
 - [builds/build-cold-microD-breakout.pptx](builds/build-cold-microD-breakout.pptx)
 - [builds/build-wood-board.pptx](builds/build-wood-board.pptx)
 - [builds/build-shield.pptx](builds/build-shield.pptx)
 - [builds/build-bud-box.pptx](builds/build-bud-box.pptx)

# Circuit Board Files

 - [9button-9neopixel Altium Schematic File](PCB_files/9button-9neopixel.schDoc)
 - [9button-9neopixel Altium Pcb File](PCB_files/9button-9neopixel.PcbDoc)
 - [9button-9neopixel Altium Project File](PCB_files/9button-9neopixel.PrjPcb)
 - [9button-9neopixel .zip of Gerber files](PCB_files/9button-9neopixel-gerbers.zip)
 - [8button-8neopixel Altium Schematic File](PCB_files/8button-8neopixel.schDoc)
 - [8button-8neopixel Altium Pcb File](PCB_files/8button-8neopixel.PcbDoc)
 - [8button-8neopixel Altium Project File](PCB_files/8button-8neopixel.PrjPcb)
 - [8button-8neopixel .zip of Gerber files](PCB_files/8button-8neopixel-gerbers.zip)
 - [6button-6neopixel Altium Schematic File](PCB_files/6button-6neopixel.schDoc)
 - [6button-6neopixel Altium Pcb File](PCB_files/6button-6neopixel.PcbDoc)
 - [6button-6neopixel Altium Project File](PCB_files/6button-6neopixel.PrjPcb)
 - [6button-6neopixel .zip of Gerber files](PCB_files/6button-6neopixel-gerbers.zip)
 - [arduino-to-headers-shield Altium Schematic File](PCB_files/arduino-to-headers-shield.schDoc)
 - [arduino-to-headers-shield Altium Project File](PCB_files/arduino-to-headers-shield.PrjPcb)
 - [arduino-to-headers-shield Altium Pcb File ](PCB_files/arduino-to-headers-shield.PcbDoc)
 - [arduino-to-headers-shield .zip of Gerber files](PCB_files/arduino-to-headers-shield-gerbers.zip)
 - [DB25-relay-HV-control Altium Schematic File](PCB_files/DB25-relay-HV-control.schDoc)
 - [DB25-relay-HV-control Altium Project File](PCB_files/DB25-relay-HV-control.PrjPcb)
 - [DB25-relay-HV-control Altium Pcb File](PCB_files/DB25-relay-HV-control.PcbDoc)
 - [DB25-relay-HV-control .zip of Gerber files](PCB_files/DB25-relay-HV-control-gerbers.zip)
 - [microd-header-adapter-board-rev2 Altium Schematic File](PCB_files/microd-header-adapter-board-rev2.schDoc)
 - [microd-header-adapter-board-rev2 Altium Project File](PCB_files/microd-header-adapter-board-rev2.PrjPcb)
 - [microd-header-adapter-board-rev2 Altium Pcb File](PCB_files/microd-header-adapter-board-rev2.PcbDoc)
 - [microd-header-adapter-board-rev2 .zip of Gerber files](PCB_files/microd-header-adapter-board-rev2-gerbers.zip)
 - [rectangle11board Altium Schematic File](PCB_files/rectangle11board.schDoc)
 - [rectangle11board Altium Project File](PCB_files/rectangle11board.PrjPcb)
 - [rectangle11board Altium Pcb File](PCB_files/rectangle11board.PcbDoc)
 - [rectangle11board .zip of Gerber files](PCB_files/rectangle11board.zip)
 - [cal-boards-panelization1 Bill of Materials](PCB_files/cal-boards-panelization1-BOM.xlsx)
 - [cal-boards-panelization1 Altium Pcb File](PCB_files/cal-boards-panelization1.PcbDoc)
 - [cal-boards-panelization1 .zip of Gerber files](PCB_files/cal-boards-panelization1-gerbers.zip)
 - [SchlibLafe.SchLib Library File](PCB_files/SchlibLafe.SchLib)
 - [PcbLibLafe.PcbLib Library File](PCB_files/PcbLibLafe.PcbLib)
 - [Fiducial.SchLib Library File](PCB_files/Fiducial.SchLib)
 - [Fiducial.PcbLib Library File](PCB_files/Fiducial.PcbLib)
 - [pogo_socket_2port.PcbDoc](PCB_files/pogo_socket_2port.PcbDoc)
 - [pogo_socket_6port.PcbDoc](PCB_files/pogo_socket_6port.PcbDoc)
 - [cal-boards-zip.zip](PCB_files/cal-boards-zip.zip)

# Circuit Board Drawings

![](PCB_files/9button-9neopixel-drawing.png)
![](PCB_files/8button-8neopixel-drawing.png)
![](PCB_files/6button-6neopixel-drawing.png)
![](PCB_files/microd-header-adapter-board-drawing.png)
![](PCB_files/rectangle11board-drawing.png)

# 3d Print Files

 - [front-panel-edge-bracket.STL](3dprint_files/front-panel-edge-bracket.STL)
 - [front-panel-center-bracket.STL](3dprint_files/front-panel-center-bracket.STL)
 - [arduino-bracket.STL](3dprint_files/arduino-bracket.STL)
 - [HV-DCDC-bracket.STL](3dprint_files/HV-DCDC-bracket.STL) 
 - [arduino-bracket.SLDPRT](3dprint_files/arduino-bracket.SLDPRT)
 - [front-panel-center-bracket.SLDPRT](3dprint_files/front-panel-center-bracket.SLDPRT)
 - [arduino-bracket.SLDPRT](3dprint_files/arduino-bracket.SLDPRT)
 - [HV-DCDC-bracket.SLDPRT](3dprint_files/HV-DCDC-bracket.SLDPRT) 

![](3dprint_files/arduino-bracket-drawing1.png)
![](3dprint_files/arduino-bracket-drawing2.png)
![](3dprint_files/front-panel-center-bracket-drawing.png)
![](3dprint_files/front-panel-edge-bracket-drawing.png)
![](3dprint_files/HV-DCDC-bracket-drawing.png)


# Machining Files


 - [.pdf Drawing for Box](machining_files/AN-1304-A-box-modifications.pdf)
 - [SolidWorks part file for Box](machining_files/AN-1304-A-box-modifications.SLDPRT)
 - [SolidWorks drawing file for Box](machining_files/AN-1304-A-box-modifications.SLDDRW)
 - [STEP file for Box](machining_files/AN-1304-A-box-modifications.STEP)
 - [.pdf Drawing for Lid](machining_files/AN-1304-A-lid-modifications.pdf)
 - [SolidWorks part file for Lid](machining_files/AN-1304-A-lid-modifications.SLDPRT)
 - [SolidWorks drawing file for Lid](machining_files/AN-1304-A-lid-modifications.SLDDRW)
 - [STEP file for Lid](machining_files/AN-1304-A-lid-modifications.STEP)
 - [.pdf Drawing for Outer Block](machining_files/outer-block.pdf)
 - [outer-block.SLDDRW](machining_files/outer-block.SLDDRW)
 - [outer-block.SLDPRT](machining_files/outer-block.SLDPRT)
 - [.pdf Drawing for Center Block](machining_files/center-block.pdf)
 - [SolidWorks Drawing for Center Block](machining_files/center-block.SLDDRW)
 - [SolidWorks Part File for Center Block](machining_files/center-block.SLDPRT)
 - [.pdf Drawing of H Bracket](machining_files/H-Bracket.pdf)
 - [SolidWorks Drawing for H Bracket](machining_files/H-Bracket.SLDDRW)
 - [SolidWorks Part File for H Bracket](machining_files/H-Bracket.SLDPRT)
 - [.pdf Drawing for T stand](machining_files/T-stand.pdf)
 - [SolidWorks Drawing File for T stand](machining_files/T-stand.SLDDRW)
 - [SolidWorks Part File for T Stand](machining_files/T-stand.SLDPRT)
 - [.pdf for Rack Mount Wood Board](machining_files/rack-mount-board.pdf)
 - [SolidWorks Drawing File for Rack Mount Wood Board](machining_files/rack-mount-board.SLDDRW)
 - [SolidWorks Part File for Rack Mount Wood Board](machining_files/rack-mount-board.SLDPRT)

![](machining_files/box-drawing.png)
![](machining_files/lid-drawing.png)
![](machining_files/outer-block-drawing.png)
![](machining_files/center-block-drawing.png)
![](machining_files/H-bracket-drawing.png)
![](machining_files/T-stand-drawing.png)
![](machining_files/rack-mount-board-drawing.png)




# Arduino Code

 - [9-port-controller/9-port-controller.ino](9-port-controller/9-port-controller.ino)
 - [8_port_ecal_controller/8_port_ecal_controller.ino](8_port_ecal_controller/8_port_ecal_controller.ino)
 - [6_port_controller_NIST_detector/6_port_controller_NIST_detector.ino](6_port_controller_NIST_detector/6_port_controller_NIST_detector.ino)

# Matlab Switch Control

 - [matlab/switch_control.m](matlab/switch_control.m)

# Jupyter Notebook with Python Control

 - [jupyter/switch_control.ipynb](jupyter/switch_control.ipynb)


# Control Panel PCB

This board both controls the state of the switches with a set of 9 buttons and indicates the current switch state with a set of 9 LED's.  

![](images/control-board-photo.jpg)

![](images/assembled-board-photo.jpg)

![](images/dimensions-drawing.png)

![](images/9button-9neopixels-pcbdoc-screenshot.png)

![](images/9button-9neopixels-schematic-screenshot.png)

![](images/button-schematic.svg)

## Bill of Materials

![](images/control-board-parts-photo.jpg)

 - [PCB's](https://www.pcbway.com)
 - [ Neopixels (9x)](https://www.adafruit.com/product/1559)
 - [10 k resistors (9x)](https://www.digikey.com/en/products/detail/yageo/MFR-25FBF52-10K/13219)
 - [4 pin header cable (1x)](https://www.amazon.com/ZYAMY-Dupont-Connector-Multicolor-Breadboard/dp/B0789F523N/)
 - [header strips (40 pins)](https://www.digikey.com/en/products/detail/amphenol-cs-commercial-products/G800W268018EU/17083164)
 - [buttons (9x)](https://www.digikey.com/en/products/detail/e-switch/TL59NF160Q/390533)

[Digkey Cart with everything but PCB's](https://www.digikey.com/short/jzc9cpp0)

## Files

 - [PCB_files/Altium Schematic .SchDoc](9button-9neopixel.schDoc)
 - [PCB_files/Altium project file .PrjPcb](9button-9neopixel.PrjPcb)
 - [PCB_files/Altium Pcb File .PcbDoc](9button-9neopixel.PrjPcb)
 - [PCB_files/.zip of Gerber files](9button-9neopixel-gerbers.zip)


# BUD Box

We use a diecast aluminum enclosure from [Bud Industries](https://www.budind.com/)(part number [AN-1304-A](https://www.budind.com/product/nema-ip-rated-boxes/an-a-series-style-a-aluminum-enclosure/an-1304/)) to enclose the high voltage driver for the MEMS switches used in the QNA system. 

This box can be modified yourself if you have access to a milling machine or you can get it modified by Bud or by some third party machine shop.  

 - [AN-1304-A Bud Box page at Bud Industries](https://www.budind.com/product/nema-ip-rated-boxes/an-a-series-style-a-aluminum-enclosure/an-1304/#group=series-products&external_dimensions_group=0&internal_dimensions=0&mounting_style_group=0)
 - [AN-1304 Bud Box at Digikey](https://www.digikey.com/en/products/detail/bud-industries/AN-1304-A/5804538)
 - [Standoffs from McMaster Carr, part number #91075A462](https://www.mcmaster.com/91075A462/)
 - [3/4" 4-40 brass screws from McMastrer Carr](https://www.mcmaster.com/93465A113/)
 - [#4 brass washers from McMastrer Carr](https://www.mcmaster.com/92916A320/)
 - [4-40 tap](https://www.mcmaster.com/25995A125/)
 - [tap wrench](https://www.mcmaster.com/25605A63/)
 - [#43 drill](https://www.mcmaster.com/3584A232)
 - [1/8" End Mill](https://www.mcmaster.com/3056A61/)
 - [.pdf drawing for Box](machining_files/AN-1304-A-lid-machined.pdf)
 - [SolidWorks part file for Box](machining_files/AN-1304-A-lid-machined.SLDPRT)
 - [SolidWorks drawing file for Box](machining_files/AN-1304-A-lid-machined.SLDDRW)
 - [STEP file for Box](machining_files/AN-1304-A-lid-machined.STEP)
 - [.pdf drawing file for lid](machining_files/AN-1304-A-machined-box.pdf)
 - [SolidWorks part file for lid](machining_files/AN-1304-A-machined-box.SLDPRT)
 - [SolidWorks drawing file for lid](machining_files/AN-1304-A-machined-box.SLDDRW)
 - [STEP file for lid](machining_files/AN-1304-A-machined-box.STEP)

![](images/bud-box-lid-top.jpg)

![](images/AN-1304-A-lid-machined.png)

![](images/AN-1304-A-box-machined.png)

![](images/AN-1304-A-photo.png)

![](images/AN-1304-A-drawing.png)

![](images/standoffs-DSUB-mcmaster-91076A462-full.png)

![](images/machining-quote-bud.png)

![](images/threequarter-4-40-screws.png)

![](images/number-4-washer.png)

![](images/bolts-in-wood.jpg)


# Wood Board


 - [Dimensioned drawing and templates rack-mount-board.pdf](rack-mount-board.pdf)
 - [Solidworks Drawing rack-mount-board.SLDDRW](rack-mount-board.SLDDRW)
 - [Solidworks part file for rack-mount-board.SLDPRT](rack-mount-board.SLDPRT)
 - [Link to buy board](https://ocoochhardwoods.com/detail/?i=124wo)
 - [Mouser link to buy nuts for rack](https://www.mouser.com/ProductDetail/Hammond-Manufacturing/1421NP25?qs=yc9RBI4tIALvGirsWAVfbg%3D%3D)
 - [Link to buy wood screws](https://www.mcmaster.com/98685A540/)
 - [Link to buy thumb screws](https://www.mcmaster.com/92421A645/)

We use white oak boards which can be purchased in convenient sizes and cut to fit a 19 inch rack.  

[![](images/white-oak-board.png)](https://ocoochhardwoods.com/detail/?i=124wo)

![](images/board-dimensioned-drawing.png)

![](images/wood.png)

![](images/wood-screw-drawing.png)

![](images/wood-screw-photo.png)

![](images/panel-board-front-no-pcb.jpg)

![](images/rack-screw-image.png)

![](images/rack-screw-drawing.png)

![](images/ruler-19inch-line.jpg)

![](images/bandsaw.jpg)

![](images/bandsaw2.jpg)

![](images/rough-edge.jpg)

![](images/sander.jpg)

![](images/sanded-edge.jpg)

![](images/drills.jpg)

![](images/paper-template-edge.jpg)

![](images/awl-punch.jpg)

![](images/sixteenth.jpg)

![](images/eighth.jpg)

![](images/finalbit.jpg)

![](images/rack-nut.jpg)

![](images/nuts-in-rack.jpg)

![](images/panel-in-rack-edge.jpg)

![](images/blank-board-in-rack.jpg)


# 3d Printed Files



![](images/all-3d-printed-parts.jpg)

These 3d printed parts are used to attach the control panel circuit board to the wood rack mount panel, to attach the Arduino to the back of the same panel, and to mount the high voltage DC-DC converter to the inside of the Bud Box.

 1. [front-panel-edge-bracket.STL, print 2, add inserts](3dprint_files/front-panel-edge-bracket.STL)
 2. [front-panel-center-bracket.STL, print 2](3dprint_files/front-panel-center-bracket.STL)
 3. [arduino-bracket.STL, print 1, add inserts](3dprint_files/arduino-bracket.STL)
 4. [HV-DCDC-bracket.STL, print 1, add inserts](3dprint_files/HV-DCDC-bracket.STL) 

## Thread Inserts

[![images/4-40-inserts.png](images/4-40-inserts.png)](https://www.3djake.com/ruthex/threaded-insert-4-40-unc-100-pieces)

## 4-40 Quarter Inch Screws

[![images/4-40-0.25-screw.png](images/4-40-0.25-screw.png)](https://www.mcmaster.com/90272A106/)

## #4 Wood Screws

[Mcmaster-Carr Part number 98685A540](https://www.mcmaster.com/98685A540/)

[![](images/wood-screw.png)](https://www.mcmaster.com/98685A540/)

## Arduino Bracket

Print one of these per controller.  This works for both Arduino UNO and Arduino Mega. Screw into wood using #4 wood screws.  

Use 4-40 brass thread inserts, press them in with a soldering iron. 

[![arduino-bracket.STL](images/arduino-bracket.png)](arduino-bracket.STL) 

[![arduino-bracket.STL](images/arduino-bracket.jpg)](arduino-bracket.STL) 


## DC DC converter Bracket

Use 4-40 brass thread inserts, press them in with a soldering iron

[![HV-DCDC-bracket.STL](images/HV-DCDC-bracket.png)](HV-DCDC-bracket.STL) 

[![HV-DCDC-bracket.STL](images/HV-DCDC-bracket.jpg)](HV-DCDC-bracket.STL)

## Front Panel Edge Bracket

Use 4-40 brass thread inserts, press them in with a soldering iron. Attach to wood with #4 wood screws. 

[![front-panel-edge-bracket.STL](images/front-panel-edge-bracket.png)](front-panel-edge-bracket.STL) 


[![front-panel-edge-bracket.STL](images/front-panel-edge-bracket.jpg)](front-panel-edge-bracket.STL) 

## Front Panel Center Bracket

place in center area of circuit board to prevent bowing, use #4 wood screws to mount.

[![front-panel-center-bracket.STL](images/front-panel-center-bracket.png)](front-panel-center-bracket.STL) 


[![front-panel-center-bracket.STL](images/front-panel-center-bracket.jpg)](front-panel-center-bracket.STL) 

## Assembly with Wood Board

![](images/panel-board-front-no-pcb.jpg)

## Arduino UNO Hole Pattern

![](images/uno-hole-dimensions.png)

# Arduino Shield Board

![](images/kit-photo.jpg)

![](images/board-photo.jpg)

## Bill of Materials

 - [330 ohm resistors](https://www.digikey.com/en/products/detail/stackpole-electronics-inc/CF18JT330R/1741683)
 - [100k resistors](https://www.digikey.com/en/products/detail/stackpole-electronics-inc/RNF14FTD100K/1706591)
 - [1000 uF Capacitors](https://www.digikey.com/en/products/detail/rubycon/16PK1000MEFC10X12-5/3563556)
 - [header strips (40 pins)](https://www.digikey.com/en/products/detail/amphenol-cs-commercial-products/G800W268018EU/17083164)


## Files

 - [Altium Schematic .SchDoc](PCB_files/arduino-to-headers-shield.schDoc)
 - [Altium project file .PrjPcb](PCB_files/arduino-to-headers-shield.PrjPcb)
 - [Altium Pcb File .PcbDoc](PCB_files/arduino-to-headers-shield.PcbDoc)
 - [.zip of Gerber files](PCB_files/arduino-to-headers-shield-gerbers.zip)

# DB25 Relay Board


![](images/board-photo-unstuffed.jpg)

![](images/board-photo.png)


## Bill of Materials

![](images/db25-relay-board-kit-photo.jpg)


 - [1 MOhm 1206 SMT resistors](https://www.digikey.com/en/products/detail/yageo/RC1206FR-071ML/728388)
 - [DB25 board mount connector](https://www.digikey.com/en/products/detail/assmann-wsw-components/A-DF-25-PP-Z/1241794)
 - [Comus 3570-1331-053 Relays](https://www.digikey.com/en/products/detail/comus-international/3570-1331-053/7497099)
 - [header strips (40 pins)](https://www.digikey.com/en/products/detail/amphenol-cs-commercial-products/G800W268018EU/17083164)


## Files

 - [Altium Schematic .SchDoc](PCB_files/DB25-relay-HV-control.schDoc)
 - [Altium project file .PrjPcb](PCB_files/DB25-relay-HV-control.PrjPcb)
 - [Altium Pcb File .PcbDoc](PCB_files/DB25-relay-HV-control.PcbDoc)
 - [.zip of Gerber files](PCB_files/DB25-relay-HV-control-gerbers.zip)


# 0.1 Inch Header Cables

![](images/2pin-cable-image.png)

![](images/4pin-cable-image.png)

![](images/8pin-cable-photo.png)

 - [2 wire](https://www.amazon.com/ZYAMY-Dupont-Connector-Multicolor-Breadboard/dp/B0B8Z23NWX/)
 - [4 wire](https://www.amazon.com/ZYAMY-Dupont-Connector-Multicolor-Breadboard/dp/B0789F523N/)
 - [8 wire](https://www.amazon.com/ZYAMY-Dupont-Connector-Multicolor-Breadboard/dp/B0789F2Y1T/)


# 90 Volt Power Supply

We use the 5 volt regulated supply on the Arduino UNO as a source for a pair of DC-DC converters. A pair of header pins on the [Arduino Uno Shield Board](../arduino_shield_pcb/) connect to a 2 wire cable which joins a 2 pin socket connector to the first DC-DC converter(5 volts to 12 volts), which in turn connects to the high voltage adjustable DC-DC converter which converts from 12 volts up to 90 volts.  This 90 volt signal connects to the [DB25 Relay Circuit Board](../DB25_relay_pcb/) via the other half of a split 2 wire connector.  

## [2 Wire Cable from Amazon](https://www.amazon.com/ZYAMY-Dupont-Connector-Multicolor-Breadboard/dp/B0B8Z23NWX/)

![](images/2pin-cable-image.png)

[![](images/2pin-cable-amazon.png)](https://www.amazon.com/ZYAMY-Dupont-Connector-Multicolor-Breadboard/dp/B0B8Z23NWX/)

## [5 V to 12 V boost from Amazon]((https://www.amazon.com/DROK-Boost-Converter-Regulator-Length/dp/B09M3LMSS3/))

[![](images/5v-12v-boost-amazon.png)](https://www.amazon.com/DROK-Boost-Converter-Regulator-Length/dp/B09M3LMSS3/)

## [12 V to variable HV Boost board from Amazon](https://www.amazon.com/Voltage-Converter-Vintage-Indicator-80V-380V/dp/B09D93QNYK)

[![](images/HV-boost-amazon.png)](https://www.amazon.com/Voltage-Converter-Vintage-Indicator-80V-380V/dp/B09D93QNYK)

![](images/dcdc-HV.PNG)

![](images/dcdc-HV-installation-photo.PNG)

# Arduino Code

 - [9-port-controller/9-port-controller.ino](9-port-controller/9-port-controller.ino)
 - [8_port_ecal_controller/8_port_ecal_controller.ino](8_port_ecal_controller/8_port_ecal_controller.ino)
 - [6_port_controller_NIST_detector/6_port_controller_NIST_detector.ino](6_port_controller_NIST_detector/6_port_controller_NIST_detector.ino)






