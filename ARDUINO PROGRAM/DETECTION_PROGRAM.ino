#include <Wire.h>
#include <LiquidCrystal_I2C.h>
// Define analog input
#define SIGNAL_PIN A0
// Floats for ADC voltage & Input voltage
float adc_voltage = 0.0;
float in_voltage = 0.0;
// Floats for resistor values in divider (in ohms)
float R1 = 30000.0;
float R2 = 7500.0;
// Float for Reference Voltage
float ref_voltage = 5.0;
// Integer for ADC value
int adc_value = 0;
// Initialize the LCD library with I2C address and LCD size
LiquidCrystal_I2C lcd (0x27, 16,2);
void setup()
      {
      // Setup Serial Monitor 
      Serial.begin(9600);
      Serial.println ("Voltage sensor Test");
      // Initialize the LCD connected
      lcd. init ();
      // Turn on the backlight on LCD.
      lcd. backlight ();
      lcd.print ("ARDUINO");
      lcd. setCursor (0, 1);
      lcd.print ("VOLTAGE SENSOR..");
      delay(3000);
      lcd.clear();
      }
void loop() 
      {
      // Read the Analog Input
      adc_value = analogRead(SIGNAL_PIN);
      // Determine voltage at ADC input
      adc_voltage = (adc_value * ref_voltage) / 1024.0;
      // Calculate voltage at divider input
      in_voltage = adc_voltage / (R2 / (R1 + R2)) ;
      // Print results to Serial Monitor to 2 decimal places
      Serial.print("Input Voltage = ");
      Serial.println(in_voltage, 2);
      lcd. setCursor (0, 0); 
      lcd.print ("VOLTAGE MEASURED");
      //Here cursor is placed on second line
      lcd. setCursor (0, 1);
      lcd.print (in_voltage, 2);
      lcd.print (" volts");
      Serial.println(" ");
      Delay(1000);
      }