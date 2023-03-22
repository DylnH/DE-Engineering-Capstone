#include <Joystick.h>

int potentiometer = A0;

#define motor_output 13

#define PLAYER_1 0x03

Joystick_ Guitar(

  PLAYER_1,               // Change this for each controller connected to one computer

  JOYSTICK_TYPE_GAMEPAD,

 12, 0,                   // 13 buttons, no hat switches

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
  
  pinMode(9, INPUT_PULLUP);

  pinMode(10, INPUT_PULLUP);

  pinMode(11, INPUT_PULLUP);
  
  pinMode(12, INPUT_PULLUP);
  
  pinMode(potentiometer, OUTPUT);

  // Initialize Joystick Library

  Guitar.begin();

}

// Constant that maps the phyical pin to the joystick button.

const int pinToButtonMap = 1;

// Last state of the button

int lastButtonState[12] = {0,0,0,0,0,0,0,0,0,0,0,0};


void loop() {

  // Read pin values

  for (int index = 0; index < 12; index++)

  {
    int currentButtonState = !digitalRead(index + pinToButtonMap);

    if (currentButtonState != lastButtonState[index])

    {
      {
      Guitar.setButton(index, currentButtonState);

      lastButtonState[index] = currentButtonState;
      {

  int control_motor = analogRead(potentiometer/4);

  analogWrite(motor_output, control_motor);
    }

  }
  }
  }
  delay(10);
  }
