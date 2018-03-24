#include "Adafruit_VL53L0X.h"

//VL53LOX to run LEDS for specified distances or run on Robot

Adafruit_VL53L0X lox = Adafruit_VL53L0X();
int greenLed = 10;
int redLed = 14;

void setup() {
  pinMode(greenLed, OUTPUT);
  pinMode(redLed, OUTPUT);
  Serial.begin(115200);

//  // wait until serial port opens for native USB devices
//  while (! Serial) {
//    delay(1);
//  }

  Serial.println("Adafruit VL53L0X test");
  if (!lox.begin()) {
    Serial.println(F("Failed to boot VL53L0X"));
    while (1);
  }
  // power
  Serial.println(F("VL53L0X API Simple Ranging example\n\n"));


}


void loop() {
  VL53L0X_RangingMeasurementData_t measure;

  //Serial.print("Reading a measurement... ");
  lox.rangingTest(&measure, false); // pass in 'true' to get debug data printout!

//  if (measure.RangeStatus != 4) {  // phase failures have incorrect data
//    Serial.print("Distance (mm): "); Serial.println(measure.RangeMilliMeter);
//  } else {
//    Serial.println(" out of range ");
//  }
  if (measure.RangeMilliMeter < 30) {
    digitalWrite(redLed, HIGH);
  }
  else {
    digitalWrite(redLed, LOW);
  }
  if (measure.RangeMilliMeter < 180) {
    digitalWrite(greenLed, HIGH);
  }
  else {
    digitalWrite(greenLed, LOW);
  }
  delay(250);

}

