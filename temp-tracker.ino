/* 
 * Arduino Temperature Tracker
 *
 * A temperature monitor for Arduino using a TMP36
 * temperature sensor and the SnowPlow Arduino
 * Tracker (https://github.com/snowplow/snowplow-arduino-tracker). 
 *
 * Adapted from:
 *
 * * http://learn.adafruit.com/tmp36-temperature-sensor/using-a-temp-sensor
 * * http://exosite.com/project/basic-arduino-temperature-web-monitor
 *
 * Copyright (c) 2012 Alexander Dean. All rights reserved.
 *
 * This program is licensed to you under the Apache License Version 2.0,
 * and you may not use this file except in compliance with the Apache License Version 2.0.
 * You may obtain a copy of the Apache License Version 2.0 at http://www.apache.org/licenses/LICENSE-2.0.
 *
 * Unless required by applicable law or agreed to in writing,
 * software distributed under the Apache License Version 2.0 is distributed on an
 * "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the Apache License Version 2.0 for the specific language governing permissions and limitations there under.
 */

#include <SPI.h>
#include <Ethernet.h>
#include <SnowPlowTracker.h>

/*
 * UPDATE THESE FOR YOUR SKETCH
 */

// MAC address of this Arduino
const byte kMac[] = { 0x90, 0xA2, 0xDA, 0x00, 0xF8, 0xA0 };

// SnowPlow CloudFront collector subdomain
const char kSnowplowCfSubdomain[] = "d3rkrsqld9gmqf";

// SnowPlow user ID (to identify this specific Arduino board if you have multiple ones)
const char kSnowplowUserId[] = "alex-study";

/*
 * (You probably won't have to update these)
 */

// The Arduino voltage (either 5.0 or a more accurate 3.3)
const float kArduinoV = 3.3;

// The analog pin to which the TMP36's Vout (sense) pin is connected
const int kSensorPin = 0;

// Frequency of taking temperature readings, in seconds
const int kReadingFreq = 60;

// SnowPlow app name
const char kSnowplowAppName[] = "arduino-temp-tracker";

// SnowPlow Tracker
SnowPlowTracker snowplow(&Ethernet, kMac, kSnowplowAppName);

/*
 * setup() runs once when you turn your
 * Arduino on: use it to initialize and
 * set any initial values.
 *
 * We initialize the serial connection
 * with the computer, the voltage to use
 * with ARef, and the SnowPlow Arduino
 * tracker.
 */
void setup()
{
  // Serial connection lets us debug on the computer
  Serial.begin(9600);

  // Required if setting the ARef to something other than 5v
  if (kArduinoV != 5.0)
  {
    analogReference(EXTERNAL);
  }

  // Setup SnowPlow Arduino tracker
  snowplow.initCf(kSnowplowCfSubdomain);
  snowplow.setUserId(kSnowplowUserId);
}
 
/*
 * loop() runs over and over again.
 * An empty loop() takes just a few
 * clock cycles to complete.
 *
 * We use loop() to measure the
 * temperature every minute and log
 * it to SnowPlow.
 */
void loop()
{
  // When did we run last? 
  static unsigned long prevTime = 0;

  if (millis() - prevTime >= (kReadingFreq * 1000))
  {
    // Get the temperature
    float tempC = readTempInC(kSensorPin, kArduinoV);
    
    // Debug
    Serial.print(tempC); Serial.println(" degrees C");

    // Track via SnowPlow: category, action, label, property, value, precision
    snowplow.trackStructEvent("readings", "temp", "C", NULL, tempC, 2);

    prevTime = millis();
  }
  delay(500); // Running loop twice a sec is fine
}

/*
 * Gets the temperature in Celsius from
 * a TMP36 temperature sensor.
 *
 * The resolution is 10 mV / degree
 * centigrade with a 500 mV offset
 * to allow for negative temperatures.
 *
 * sensorPin is the analog pin which the
 * TMP36's Vout (sense) pin is connected
 * to.
 *
 * arduinoVoltage is the voltage the
 * Arduino runs on.
 */
float readTempInC(int sensorPin, float arduinoVoltage)
{
  // Get the voltage reading from the TMP36
  int reading = analogRead(sensorPin);

  // Convert that reading to voltage
  float voltage = (reading * arduinoVoltage) / 1024;

  // Convert from 10 mv per degree with 500 mV offset
  // to degrees: (voltage - 500mV) times 100
  return (voltage - 0.5) * 100;
}
