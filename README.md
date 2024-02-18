# Ahmad Scroll
This is the code and technical documentation for my ESP32 Art Installation as a part of COMS3930

# Materials
- TTGO T1
- USB C cable
- Small envelope with cutout for screen
- Lithium battery
- Popsicle Stick

# Code
The code is loosely derived from an example included in the tt_espi library.
Major edits include:
- changing the orientation and position of the text
- changing the font and size
- adding randomness to the position of the text, the color, as well as what text is displayed
- adding a timing function that alternates between dimming the backlight and lighting it up every 5 mins
The code was loaded onto the TTGO T1 using the Arduino IDE

# Installation
First, drill a small hole into the popsicle stick. Make another hole in the top of the envelope. Tie a 
long length of string to the popsicle stick and the envelope using the holes you made earlier. The excess string can be 
wrapped around the stick. Attach the battery to the TTGO (if you do not have the right connector on your battery you will
need to create one yourself). The TTGO should turn on at this point and start displaying the message. place the TTGO and the
battery in the envelope ensuring the screen is visible through the cutout. Attach the popsicle stick to the roof by placing
it in an air vent or taping it. An example of what the setup looks like before being attached to the roof can be seen below.


![image](https://github.com/ahmadrawwagah/Ahmad_Scroll/assets/96959925/cee83359-cb2a-46fb-ac80-88dbd85ce5b9)
