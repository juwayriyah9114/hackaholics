#include <Wire.h>
#include <LiquidCrystal_I2C.h>

/*
 * Project: Arduino Alert System
 * File: AlertSystem.ino
 */

// Initialize the LCD (Address 0x27)
LiquidCrystal_I2C lcd(0x27, 16, 2);

// Pin Definitions
const int greenLED = 6;
const int yellowLED = 7;
const int redLED = 8;
const int buzzer = 9;

void setup() {
  // Set pin modes
  pinMode(greenLED, OUTPUT);
  pinMode(yellowLED, OUTPUT);
  pinMode(redLED, OUTPUT);
  pinMode(buzzer, OUTPUT);
  
  // LCD Initialization
  lcd.init();
  lcd.backlight();
  lcd.clear();
  
  // Startup Message
  lcd.setCursor(0, 0);
  lcd.print("System Testing");
  lcd.setCursor(0, 1);
  lcd.print("Ready...");
  delay(2000);
}

void loop() {
  // --- STATE 1: GREEN (SAFE) ---
  digitalWrite(greenLED, HIGH);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("STATUS: SAFE");
  lcd.setCursor(0, 1);
  lcd.print("GREEN LIGHT ON");
  delay(2000);
  digitalWrite(greenLED, LOW);
  
  // --- STATE 2: YELLOW (WARNING) ---
  digitalWrite(yellowLED, HIGH);
  tone(buzzer, 1000, 200); // Short beep
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("STATUS: WARN");
  lcd.setCursor(0, 1);
  lcd.print("YELLOW LIGHT ON");
  delay(2000);
  digitalWrite(yellowLED, LOW);
  
  // --- STATE 3: RED (DANGER) ---
  digitalWrite(redLED, HIGH);
  tone(buzzer, 2000, 500); // Longer, higher beep
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("STATUS: DANGER!");
  lcd.setCursor(0, 1);
  lcd.print("RED LIGHT ON");
  delay(2000);
  digitalWrite(redLED, LOW);
  
  delay(1000); // Short pause before restarting
}