#include <NewPing.h>
#include <LiquidCrystal_I2C.h>

#define TRIG_PIN 12
#define ECHO_PIN 10
#define MAX_DISTANCE 200

NewPing sonar(TRIG_PIN, ECHO_PIN, MAX_DISTANCE);
LiquidCrystal_I2C lcd(0x27, 16, 2);

float resetDistance;

void setup() {
  lcd.init();
  lcd.backlight();
  Serial.begin(9600);
}

void loop() {
  float distance = sonar.ping_cm();

  if (distance > 0 && distance < 14) {
    resetDistance = 12.50 - distance;

    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("SHAHANA IoT project");
    lcd.setCursor(0, 1);
    lcd.print(resetDistance);
    lcd.print(" cm");
    Serial.println(resetDistance);
  }

  delay(150);
}
