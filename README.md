# DE-Engineering-Capstone
CHS Capstone 2022-2023

# Guitar Hero Controller

<img src="GHC.png?raw=true" width="325">

## Project Proposal

### Summary of Project Idea
Teachers these days are underpaid and underappreciated. Due to chaotic students and the pandemic, Teacher's stress levels are at a all time high. 
Our solution to this issue is to make a portable Guitar Hero Station for teachers to use, so that they can take a break from the stress that comes with teaching. This helps out our school because this would cause the stress levels of the teachers to decrease, which would lead to a happier learning/teaching environment. We are satisfied with our produce, if we are able to make multiple working controllers that check off the essential requirments, as well as fulfill a teachers inner desire to shred on guitar.

Essential Requirements Include...

- 2-4 Working Controllers
- Portable
- Haptic Feedback
- USB Compatible
- Comparable, if not better than the original controller.

Non-Essential Requirements Include...

- Easy and Satisfying to use
- Able to Fix with relative ease
- Cool Design
- Use the new equipment in the Sigma Lab
- Make a controller that's Console Compatible

### Timeline
We plan on accomplishing at least one facet of the project each week, as well as documentation. We'll gives ourselves leeway if certain things turn out to be harder than previously thought. We can complete each step by making the controllers top to bottom. Headstock, frets, neck, body, etc. If we narrow down each step by parts (one week, we'll work on LEDs), we could complete a step weekly.

#### Rough Idea
Week 1 - Planning

Week 2 - Buttons

Week 3 - Buttons Pt 2.

Week 4 - ???

Week 5 - ???

### Materials/Budget

- [Arduino Leonardo Micro 2x](https://www.tinyosshop.com/index.php?route=product/product&product_id=930) $17.6
- [Low Profile mechanical keyboard switches (1 Pack of 10)](https://mechanicalkeyboards.com/shop/index.php?l=product_detail&p=6337) $9
- 3D printed Material
- Resin printed Material
- Acrylic
- Wires and Breadboard
- USB Cables
### Deliverables/Measuring Success
We will give a Presentation and Demo to present our finish product. We'll show how it works, show to process, and teach the audience every they would want to know about our creation. after that, we'll show it working and our new huge a** monitors. If we can create a controller that works, and enjoyable to use, then we consider that a success.

### Plan/Jobs

#### Dylan will work on...
- Internals of Controller.
- Coding
- Mild CAD Work
- Assembly

#### Owen will work on...
- Externals of Controller
- CAD
- Cosmetic/Design
- Assembly

### References

- [3D Models for Reference](https://www.printables.com/model/227773-les-paul-clone-hero-controller)
- [Modded GH Controller for Inspiration](https://www.youtube.com/watch?v=94CGaIXZXsg)
- [What is Haptic Feedback?](https://www.youtube.com/watch?v=cK9qsdLf58I)

_______________________________________________________________________________________________________________________________________________________________

## Documentation

### Week 0

### Weekly Update.

- This week, we researched and found different ways to make/modify Guitar Hero Controllers
- We've decided on what some of the materials should be. (what parts should be 3D printed and laser cut)
- We've found a few resources that shows how others created their own controllers. Plus a source that explains how haptic feedback works.
- Nothing has gone wrong so far because there hasn't enough time for things to go wrong.
- Next week, we'll expand on our proposal, to make it more detailed.

### CAD Documentation

<img src="CADGuitar.png?raw=true" width="325">

- This is the first Onshape model of the guitar. It only shows the top view of the guitar but had all the necessary holes cut for various buttons.

### Code Documentation

- [Sudo Code](https://docs.google.com/document/d/1tnJP5Gdml1hMjWnqwg-ny66CEVMGbJx_VUMggTS5P58/edit?usp=sharing)

_________________________________________________________________________________________________________________________________________________________________

### Week 1

#### Customer Meeting Summary

- Our meeting with our Customer (Mr. Helmstetter) was very productive. We have more Of a thought out plan and we've thought more ideas we can implement into our project. We are planning on making a very basic prototype that will be due before Thanksgiving. Our goal then, is to learn how to make a USD device. As well as having a working controller using 9 to 10 low profile keyboard buttons and an Arduino Leonardo Micro. If we are able to make a working controller by then, we can continue to add on haptic feedback, LED control, and a more advanced shell to contain the brain of the controller. Additional ideas include haing an interchangeable body plate to change the design of the guitar. We are also thinking about increasing the amount of 3D/resin material and machined parts to the final assembly to make it more durable. Lastly, another test we could use to test the quality of our controller, suggested by Mr. Helmstetter, would be to give them to his kids to test (for durability). This is sopposed to be a better controller than the original, so why not put our craftmanship to the test.

### CAD Documentation

<img src="CADGuitar2.png?raw=true" width="450">
<img src="CADGuitarButtons.png?raw=true" width="450">

This week we have put a lot of work into the CAD guitar. We have finished the shell of the guitar and are still working on the buttons throughout the guitar. We plan to make the entire neck and head of the guitar out of acrylic as well as the top and bottom of the body. We will need to use a 3D printer for the sides of the body and the various buttons and button holders. Our next step is to finish the rest of the buttons and then put this into action and create a first model.

### Code Documentation

#### Wiring Diagram for controller
<img src="Wiring%20Diagram%201%20(2).png?raw=true" width="350">

- 5 Main Buttons on Fretboard for playing
- 2 or 1 Buttons for Strum Bar
- 2 Buttons for Generic use. *Customizable
- 1 LED strip
- 1 Motor for Haptic Feedback
- 1 Potentiometer for Whammy Bar
- 1 USB Cable

<details><summary>Theoretical LED Sudo Code</summary>
 
 ``` Arduino
G = Green Button
R = Red Button
Y = Yellow Button
B = Blue Button
O = Orange Button
SP = Star Power

G = #00FF00
R = #FF0000
Y = #FFFF00
B = #0000FF
O = #FFA500

When LED is ON, Toggle Brightness (Ripple Effect)
If Whammy bar is used, Toggle brightness (Fade in, Fade out)

If One Button is Pressed, 100% LED #__
If Two Buttons are Pressed 50% LED #__ and 50% LED #__
If Three Buttons are Pressed 30% LED #__, 30% LED #__, and 30% LED #__
If Four Buttons are Pressed 25% LED #__, 25% LED #__, 25% LED #__, and 25% LED #__
If Five Buttons are Pressed, 20% LED #__ 20% LED #__, 20% LED #__, 20% LED #__, and 20% LED #__

If Star Power is Pressed, 100% LED #7DF9FF for 15 sec.

```
 
</details>



<details><summary>Theoretical Controller Code</summary>
 
 
 ``` Arduino
 #include <Joystick.h>

#define PLAYER_1 0x03

Joystick_ Guitar(

  PLAYER_1,               // Change this for each controller connected to one computer

  JOYSTICK_TYPE_GAMEPAD,

  9, 0,                   // 9 buttons, no hat switches

  false, false, false,    // No X, Y or Z axis

  false, false, false,    // Yes Rx, No Ry, or Rz

  false, false,           // No rudder or throttle

  false, false, false     // No accelerator, brake, or steering

);

void setup() {

  Serial.begin(9600);

  // Initialize Button Pins

  pinMode(0, INPUT_PULLUP);

  pinMode(1, INPUT_PULLUP);

  pinMode(2, INPUT_PULLUP);

  pinMode(3, INPUT_PULLUP);

  pinMode(4, INPUT_PULLUP);

  pinMode(5, INPUT_PULLUP);

  pinMode(6, INPUT_PULLUP);

  pinMode(7, INPUT_PULLUP);

  pinMode(8, INPUT_PULLUP);

  // Initialize Joystick Library

  Guitar.begin();

}

// Constant that maps the phyical pin to the joystick button.

const int pinToButtonMap = 1;

// Last state of the button

int lastButtonState[9] = {0,0,0,0,0,0,0,0,0};

void loop() {

  // Read pin values

  for (int index = 0; index < 9; index++)

  {

    int currentButtonState = !digitalRead(index + pinToButtonMap);

    if (currentButtonState != lastButtonState[index])

    {

      Guitar.setButton(index, currentButtonState);

      lastButtonState[index] = currentButtonState;
    }

  }

  delay(10);
}

```
 
</details>

- [Possible source of code that we should learn from](https://www.makeuseof.com/tag/make-custom-shortcut-buttons-arduino/)
