
/*
** Example Arduino sketch for SainSmart I2C LCD Screen 16x2
** based on https://bitbucket.org/celem/sainsmart-i2c-lcd/src/3adf8e0d2443/sainlcdtest.ino
** by
** Edward Comer
** LICENSE: GNU General Public License, version 3 (GPL-3.0)

** This example uses F Malpartida's NewLiquidCrystal library. Obtain from:
** https://bitbucket.org/fmalpartida/new-liquidcrystal

** Modified - Ian Brennan ianbren at hotmail.com 23-10-2012 to support Tutorial posted to Arduino.cc

** Written for and tested with Arduino 1.0
**
** NOTE: Tested on Arduino Uno whose I2C pins are A4==SDA, A5==SCL

*/
#include <Wire.h>
#include <LCD.h>
#include <LiquidCrystal_I2C.h>

#define I2C_ADDR    0x27 // <<----- Add your address here.  Find it from I2C Scanner
#define BACKLIGHT_PIN     3
#define En_pin  2
#define Rw_pin  1
#define Rs_pin  0
#define D4_pin  4
#define D5_pin  5
#define D6_pin  6
#define D7_pin  7

int n = 1;

LiquidCrystal_I2C  lcd(I2C_ADDR, En_pin, Rw_pin, Rs_pin, D4_pin, D5_pin, D6_pin, D7_pin);

void setup()
{
  lcd.begin (16, 2); //  <<----- My LCD was 16x2


  // Switch on the backlight
  lcd.setBacklightPin(BACKLIGHT_PIN, POSITIVE);
  lcd.setBacklight(HIGH);
  lcd.home (); // go home
  lcd.setBacklight(HIGH);
  lcd.print("         12:20 PM 24-Nov-2018    ");


}

void loop()
{
  lcd.setCursor (0, 1);       // go to start of 2nd line
  lcd.print("        DONT DRINK AND DRIVE");
  //  lcd.print("  DONT DRINK AND DRIVE        PIZZA HUT OFFER BUY1GET1 OFFER    WEAR HELMETS WHILE DRIVING");
  for (int PositionCount = 0; PositionCount < 20; PositionCount++) //loop for scrolling the LCD text
  {
    lcd.scrollDisplayLeft();//builtin command to scroll left the text
    delay(250);// delay of 150 msec
  }
  
  lcd.home (); // go home
  lcd.print("         12:20 PM 24-Nov-2018    ");
  lcd.setCursor (0, 1);
  lcd.print("         PIZZA HUT OFFER BUY1GET1 OFFER ");

    for (int PositionCount = 0; PositionCount < 25; PositionCount++) //loop for scrolling the LCD text
  {
    lcd.scrollDisplayLeft();//builtin command to scroll left the text
    delay(250);// delay of 150 msec
  }

  lcd.home (); // go home
  lcd.print("         12:20 PM 24-Nov-2018    ");
  lcd.setCursor (0, 1);
  lcd.print("         WEAR HELMETS WHILE DRIVING    ");

    for (int PositionCount = 0; PositionCount < 20; PositionCount++) //loop for scrolling the LCD text
  {
    lcd.scrollDisplayLeft();//builtin command to scroll left the text
    delay(250);// delay of 150 msec
  }

}
