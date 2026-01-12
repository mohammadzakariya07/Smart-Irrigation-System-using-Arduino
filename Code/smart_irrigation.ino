#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

int moisturePin = A0;
int relayPin = 7;

int dryValue = 1023;
int wetValue = 300;

void displayMessage(String line1, String line2, int delayTime) {
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print(line1);
  lcd.setCursor(0,1);
  lcd.print(line2);
  delay(delayTime);
}

void setup() {
  lcd.init();
  lcd.backlight();
  pinMode(relayPin, OUTPUT);
  digitalWrite(relayPin, HIGH);

  displayMessage("SMART IRRIGATION", "     SYSTEM", 2500);
  displayMessage("B.Tech ECE", "3rd Year", 2500);
  lcd.clear();
}

void loop() {
  int sensorValue = analogRead(moisturePin);
  int moisturePercent = map(sensorValue, dryValue, wetValue, 0, 100);
  moisturePercent = constrain(moisturePercent, 0, 100);

  lcd.setCursor(0,0);
  lcd.print("Moisture: ");
  lcd.print(moisturePercent);
  lcd.print("%   ");

  if (moisturePercent < 30) {
    digitalWrite(relayPin, LOW);
    lcd.setCursor(0,1);
    lcd.print("Pump: ON     ");
  } else {
    digitalWrite(relayPin, HIGH);
    lcd.setCursor(0,1);
    lcd.print("Pump: OFF    ");
  }

  delay(800);
}
