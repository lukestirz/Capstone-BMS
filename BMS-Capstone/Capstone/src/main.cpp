#include <Arduino.h>

// Read 7 analog channels every 100 ms and print values.

const uint8_t NUM_V = 7;
const uint8_t NUM_T = 3;

const unsigned long READ_INTERVAL_MS = 1000;

unsigned long lastReadMs = 0;
float voltages[NUM_V];
float temp[NUM_T];
const uint8_t voltagePins[NUM_V] = {A0, A1, A2, A3, A4, A5, A6}; 
const uint8_t tempPins[NUM_T] = {A7, A8, A9}; 
float formatV(int V);


void setup() {
  Serial.begin(9600);
  delay(100);
}

void loop() {
  unsigned long now = millis();
  if (now - lastReadMs >= READ_INTERVAL_MS) {
    lastReadMs = now;

    Serial.println("\n VOLTAGE");

    for (uint8_t i = 0; i < NUM_V; ++i) {
      voltages[i] = formatV(analogRead(voltagePins[i]));
      Serial.print(voltages[i]);
      if (i + 1 < NUM_V) Serial.print(',');
    }
    Serial.println("\n TEMP");

    for (uint8_t i = 0; i < NUM_T; ++i){
      temp[i] = formatV(analogRead(tempPins[i]));
      Serial.print(temp[i]);
      if (i + 1 < NUM_T) Serial.print(',');

    }
  }
}

float formatV(int V){
  // scale ADC reading to volts (assumes 0-1023 ADC range and 5V reference)
  float f = (V * 5.0f) / 1023.0f;
  return f;
}


