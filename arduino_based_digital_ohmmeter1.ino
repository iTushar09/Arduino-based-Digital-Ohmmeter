#include <LiquidCrystal.h>

// Initialize LCD: rs, en, d4, d5, d6, d7
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

const int analogPin = A0;    // Analog input pin
const float vin = 5.0;       // Supply voltage
const float R2 = 470.0;      // Known resistor in ohms
float R1 = 0;                // Unknown resistor
int analogVal = 0;
float vout = 0;

void setup() {
  lcd.begin(16, 2);          // Set up the LCD's number of columns and rows
  lcd.print("Ohmmeter Ready");
  delay(1000);
  lcd.clear();
}

void loop() {
  analogVal = analogRead(analogPin);
  vout = analogVal * (vin / 1023.0);

  if (vout > 0.5) { // Avoid divide-by-zero and noise
    R1 = R2 * ((vin / vout) - 1);
    lcd.setCursor(0, 0);
    lcd.print("  Resistance:   ");
    lcd.setCursor(0, 1);

    if (R1 >= 1000) {
      lcd.print(R1 / 1000, 2);
      lcd.print(" K ohm      ");
    } else {
      lcd.print(R1, 0);
      lcd.print(" ohm        ");
    }
  } else {
    lcd.setCursor(0, 0);
    lcd.print("Insert Resistor");
    lcd.setCursor(0, 1);
    lcd.print("                ");
  }

  delay(1000);
}
