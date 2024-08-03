# [MEMSduino: Arduino-Based Controller for MEMS Switches](https://github.com/lafefspietz/MEMSduino/)

# Visual Abstract

#Abstract

# Background

Measurement of microwave signals in the quantum regime is of increasing interest due the growth of superconducting quantum information technology, dark matter studies, and fundamental microwave quantum optics studies.  In order to observer microwaves in the quantum regime, the circuits being measured must be cooled to temperatures well below hf/k, where f is the frequency, h is the Planck constant, and k is the Boltzmann constant.  For the frequency range from 1 to 10 GHz typical in superconducting quantum information technology, if we want kT to be more than 10 times below hf, this means we need temperatures in the range from 0.005 to 0.05 kelvin.  This is generally accomplished with a dilution refrigerator, which uses the entropy of mixing of the two isotopes of liquid helium to cool large volumes(up to of order 1 cubic meter) of electronics down to approximately 0.01 kelvin.  


If we are to have a circuit thermalize to these low temperatures, we need to attenuate power going into the dilution refrigerator by several orders of magnitude.  In order to not overwhelm the extremely small quantum signals(<1 fW) with noise, these circuits generally also have cryogenic amplifiers inside the dilution refrigerator, which amplify the signal also by several orders of magnitude in power.  These amplifiers are expensive, bulky, and add to the heat load of the system. 

If researchers want to measure large numbers of samples in a single signal path, calibrate the noise, or calibrate the scattering parameters, they need to have the ability to switch a single signal line between a choice of multiple lines while the apparatus is cold.  At room temperature there are many solutions for this, but at low temperature the three known solutions are solenoid-based cryogenic electro-mechanical switches, piezo-based probe manipulators, and MEMS-based electro-mechanical switches.  The solenoid-based switches require large current pulses which heat up the whole cryostat, requiring on the order of an hour after each switching event. Also, they have been anecdotally and intermittently shown to destroy cryogenic HEMT amplifiers, which are several thousand dollars to replace, with potentially long lead times.  It is unknown at this time exactly what would be involved in preventing this from happening.  The piezo-based probe manipulators have been shown to be good for doing cryogenic on-wafer calibrations, but are slow and difficult to use, and are not compatible with many of the enclosures which are used in quantum information science experiments.  

This work concerns how to control the third of these solutions, the MEMS-based microwave switches from Menlo Microwave.  These switches have been shown to work at dilution refrigerator temperatures, and multiple commercial products exist today which are used for this.  Unlike the cryogenic solenoid-based switches, these switches are very compact, and are sold as a square surface mount package approximately 2.5mm on a side. These can be integrated into large and complex systems of interconnected circuit boards to make a wide range of possible experiments and products.  



# Bill of Materials

 - 1 Arduino UNO
 - 9 Single Neopixel boards
 - 9 Buttons
 - 1 4"x24"x1/2" white oak board
 - 4 knurled thumb screws
 - wood screws
 - 4-40 Phillips screws
 - 4-40 cap screws(various sizes)
 - 3d printed arduino mounting bracket
 - 3d printed DC-DC converter mounting bracket
 - 3d printed edge bracket for front panel pcb
 - 3d printed middle bracket for front panel pcb
 - Brass thread inserts
 - front panel pcb
 - arduino shield board
 - DB 25 relay board
 - DC Micro-D breakout board
 - RF switch board
 - RF calibration board panel
 - Bud Box
 - DB25 to Fischer connector cable
 - Machined brass H bracket to mount to fridge mixing chamber plate
 - Machined brass H bracket standoff
 - Machined brass center block outside
 - Machined brass center block
 - hex standoffs
 - 5 volt to 12 volt DC DC converter
 - 12 volt to variable high voltage DC DC converter
 - 2 wire cables
 - 4 wire cables
 - 8 wire cables
 - DB25 connector
 - relays
 - 330 ohm resistors
 - 10 k resistors
 - 100 k resistors
 - 1 M resistors
 - 0.1" headers
 - Micro-D board mont connectors
 - 75 k resistors
 - 90 degree limited detent SMP
 - Straight smooth bore SMP
 - SMP barrels

# Build Instructions

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




