#include <Keyboard.h>

// Define the pins for the joystick
const int joyX = A0; // Joystick X-axis connected to analog pin A0
const int joyY = A1; // Joystick Y-axis connected to analog pin A1
const int joyButton = 2; // Joystick button connected to digital pin 2

// Threshold for detecting significant movement
const int threshold = 100;

void setup() {
  // Initialize the joystick button pin as input
  pinMode(joyButton, INPUT_PULLUP);

  // Begin keyboard emulation
  Keyboard.begin();
}

void loop() {
  // Read the joystick X and Y positions
  int xValue = analogRead(joyX);
  int yValue = analogRead(joyY);

  // Read the state of the joystick button
  int buttonState = digitalRead(joyButton);

  // Map joystick movement to keyboard keys
  if (xValue < 512 - threshold) {
    Keyboard.press('A'); // Move left
  } else if (xValue > 512 + threshold) {
    Keyboard.press('D'); // Move right
  } else {
    Keyboard.release('A');
    Keyboard.release('D');
  }

  if (yValue < 512 - threshold) {
    Keyboard.press('W'); // Move up
  } else if (yValue > 512 + threshold) {
    Keyboard.press('S'); // Move down
  } else {
    Keyboard.release('W');
    Keyboard.release('S');
  }

  // Map joystick button to a keyboard key
  if (buttonState == LOW) {
    Keyboard.press(' '); // Press space when the joystick button is pressed
  } else {
    Keyboard.release(' ');
  }

  // Small delay to avoid rapid keypresses
  delay(50);
}
