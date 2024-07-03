#include <LiquidCrystal_I2C.h>

#include <Wire.h>

const int buttonPin = 2; // setup button pin

int buttonState = 0;  // variable for reading the pushbutton status

LiquidCrystal_I2C lcd(0x27,  16, 2); // initialize lcd display, i2c address and then width by height

void setup() {
  // initialize the pushbutton pin as an input:
  pinMode(buttonPin, INPUT);
  // initialize the builtin LED as an output:
  pinMode(LED_BUILTIN, OUTPUT);
  // initialize lcd
  lcd.init();
  // turn on lcd backlight
  lcd.backlight();
}

void loop() {
  // read current output of pushbutton
  buttonState = digitalRead(buttonPin);

  // set cursor to top left of lcd
  lcd.setCursor(0,0);

  // print stationary message on lcd screen
  lcd.print("Is the button pressed?");

  // set cursor to bottom row in prep for dynamic messages
  lcd.setCursor(0,1);

  // lets see if the button is pressed or not
  if (buttonState == HIGH) {
    // turn led on:
    digitalWrite(LED_BUILTIN, HIGH);
    // print message on lcd to show status
    lcd.print("Yes!");
  } else {
    // turn led off:
    digitalWrite(LED_BUILTIN, LOW);
    // print message on lcd to show status
    lcd.print("No..");
  }
}
