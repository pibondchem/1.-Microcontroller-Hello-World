"""
    Simple test for monochromatic character LCD

    This code is included with the files for Adafruit Labs Hello World by
    Matthew Riehl and is in the public domain.  I have only modified the
    code to better support the laboratory exercise.

    Demonstrates the use a 16x2 LCD display.  The LiquidCrystal
    library works with all LCD displays that are compatible with the
    Hitachi HD44780 driver. There are many of them out there, and you
    can usually tell them by the 16-pin interface.

    This program prints "Hello World!" to the LCD
    and shows the number of seconds since reset.


  The circuit:
 * LCD RS pin to digital pin 7
 * LCD Enable pin to digital pin 8
 * LCD D4 pin to digital pin 9
 * LCD D5 pin to digital pin 10
 * LCD D6 pin to digital pin 11
 * LCD D7 pin to digital pin 12
 * LCD Backlight (pin 15 on LCD) to pin 13 on Adafruit (add a 220 ohm series resistor)
 * LCD R/W pin to ground
 * LCD VSS pin to ground
 * LCD VCC pin to 5V
 * 10K potentiostat:
 * ends to +5V and ground
 * wiper to LCD VO pin (pin 3)

    See https://learn.adafruit.com/character-lcds/python-circuitpython for more information.

"""
import time
import board
import digitalio
import adafruit_character_lcd.character_lcd as characterlcd


# Modify this if you have a different sized character LCD
lcd_columns = 16
lcd_rows = 2

# Metro M0/M4 Pin Config:
lcd_rs = digitalio.DigitalInOut(board.D7)
lcd_en = digitalio.DigitalInOut(board.D8)
lcd_d7 = digitalio.DigitalInOut(board.D12)
lcd_d6 = digitalio.DigitalInOut(board.D11)
lcd_d5 = digitalio.DigitalInOut(board.D10)
lcd_d4 = digitalio.DigitalInOut(board.D9)
lcd_backlight = digitalio.DigitalInOut(board.D13)

# Initialise the LCD class
lcd = characterlcd.Character_LCD_Mono(
    lcd_rs, lcd_en, lcd_d4, lcd_d5, lcd_d6, lcd_d7, lcd_columns, lcd_rows, lcd_backlight
)

start = time.time()
lcd.clear()
lcd.backlight = True
lcd.message = "Hello, World!"  # Change this to something cooler.

while True: # This loop continues forever.
    now = time.time()
    lcd.message = ('\n{}  seconds'.format(int(now-start)))

