#include <LiquidCrystal.h>

/*
  LiquidCrystal Library - Hello World

  This code is included with the files for Arduino Labs Hello World by 
  Matthew Riehl and is in the public domain.  I have only modified the
  code to better support the laboratory exercise.
 
 Demonstrates the use a 16x2 LCD display.  The LiquidCrystal
 library works with all LCD displays that are compatible with the
 Hitachi HD44780 driver. There are many of them out there, and you
 can usually tell them by the 16-pin interface.

 This sketch prints "Hello World!" to the LCD
 and shows the elapsed time since reset.  Then it demonstrates
 some other commands that can be used with the LCD.  

  Note that the pin assignments are NOT the same as found on many Arduino 
  pages.  They have been moved around to make the wiring more intuitive 
  and easier to troubleshoot.
  
  The circuit:
 * LCD RS pin to digital pin 7
 * LCD Enable pin to digital pin 8
 * LCD D4 pin to digital pin 9
 * LCD D5 pin to digital pin 10
 * LCD D6 pin to digital pin 11
 * LCD D7 pin to digital pin 12
 * LCD Backlight (pin 15 on LCD) to pin 13 on Arduino (might need to add a 220 ohm series resistor)
 * LCD R/W pin to ground
 * LCD VSS pin to ground
 * LCD VCC pin to 5V
 * 10K potentiostat:
 * ends to +5V and ground
 * wiper to LCD VO pin (pin 3)

 Library originally added 18 Apr 2008
 by David A. Mellis
 library modified 5 Jul 2009
 by Limor Fried (http://www.ladyada.net)
 example added 9 Jul 2009
 by Tom Igoe
 modified 22 Nov 2010
 by Tom Igoe
 modified 7 Nov 2016
 by Arturo Guadalupi

 This example code is in the public domain.  The code was assembled 
 and tested by Matthew Riehl from:

 http://www.arduino.cc/en/Tutorial/LiquidCrystalHelloWorld
 http://www.arduino.cc/en/Tutorial/LiquidCrystalAutoscroll
 http://www.arduino.cc/en/Tutorial/LiquidCrystalScroll
 
 More commands and documentation can be found at  
 https://www.arduino.cc/en/Reference/LiquidCrystal
*/

// include the library code:
#include <LiquidCrystal.h>

// initialize the library by associating any needed LCD interface pin
// with the arduino pin number it is connected to
const int rs = 7, en = 8, d4 = 9, d5 = 10, d6 = 11, d7 = 12;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
#define backlightPin 13         // This allows the user to turn the back light on and off.


/* This code sets up the display and prints a brief message. */ 
void setup() {
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  // Print a message to the LCD.
  pinMode(backlightPin, OUTPUT);
  digitalWrite(backlightPin, HIGH);
  lcd.print("Hello, World!");       // Change this to something cool
  delay(2000);                      // message will display for 2000 milliseconds
}

/* The following loop runs forever.  Note the comments following the code */
/* First part of the loop prints a new messge and tells you how many seconds since reset. */
void loop() {  
  lcd.clear();                      // display is cleared
  digitalWrite(backlightPin, LOW);   // backlight is turned off  
  delay(2000);                      // for 2000 milliseconds  
  digitalWrite(backlightPin, HIGH); 
  lcd.print("I'm awake!");          // Change this to something better  
  // set the cursor to column 0, line 1        
  // (note: line 1 is the second row, since counting begins with 0):          
  lcd.setCursor(0, 1);
  // print the number of seconds since reset:
  lcd.print("Reset ");
  lcd.print(millis() / 1000);
  lcd.print(" s ago");
  delay(2000);

/* Second parr of the sequence contains loops to print the digits 0-9
  and scroll across the screen. */
  lcd.clear();
  // set the cursor to (0,0):
  lcd.setCursor(0, 0);
  // print from 0 to 9:
  for (int thisChar = 0; thisChar < 10; thisChar++) {
    lcd.print(thisChar);
    delay(500);
  }
  // set the cursor to (16,1):
  lcd.setCursor(16, 1);
  // set the display to automatically scroll:
  lcd.autoscroll();
  // print from 0 to 9:
  for (int thisChar = 0; thisChar < 10; thisChar++) {
    lcd.print(thisChar);
    delay(500);
  }
  // turn off automatic scrolling
  lcd.noAutoscroll();

  
/* Finally, some text is scrolled both left and right. */
  lcd.clear();
   lcd.print("Fun time now!");
   delay(1000);
    // scroll 13 positions (string length) to the left
  // to move it offscreen left:
  for (int positionCounter = 0; positionCounter < 13; positionCounter++) {
    // scroll one position left:
    lcd.scrollDisplayLeft();
    // wait a bit:
    delay(250);
  }

  // scroll 29 positions (string length + display length) to the right
  // to move it offscreen right:
  for (int positionCounter = 0; positionCounter < 29; positionCounter++) {
    // scroll one position right:
    lcd.scrollDisplayRight();
    // wait a bit:
    delay(250);
  }

  // scroll 16 positions (display length + string length) to the left
  // to move it back to center:
  for (int positionCounter = 0; positionCounter < 16; positionCounter++) {
    // scroll one position left:
    lcd.scrollDisplayLeft();
    // wait a bit:
    delay(250);
  }

  // delay at the end of the full loop:
  delay(1000);
}
