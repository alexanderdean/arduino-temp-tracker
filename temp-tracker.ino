// Copyright Alex Dean (c) 2012
// Original code taken from: http://learn.adafruit.com/tmp36-temperature-sensor/using-a-temp-sensor

// The analog pin to which the TMP36's Vout (sense) pin is connected
int sensorPin = 0;

// The Arduino voltage (either 5.0 or a more accurate 3.3)
float arduinoV = 5.0;
 
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
  analogReference(arduinoV);

  // Setup SnowPlow Arduino tracker
  // TODO
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
  // Get the temperature
  float tempC = getTMP36TempInC(sensorPin, arduinoV);
  
  // Debug
  Serial.print(temperatureC); Serial.println(" degrees C");

  // Track via SnowPlow
  // TODO

  delay(60000); // Wait a minute
  // TODO: fix this so it runs every minute, not a minute between runs (not the same thing)
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
float getTMP36TempInC(int sensorPin, float arduinoVoltage)
{
  // Get the voltage reading from the TMP36
  int voltage = analogRead(sensorPin);

  // Convert that reading to voltage
  float voltage = (reading * arduinoVoltage) / 1024;

  // Convert from 10 mv per degree with 500 mV offset
  // to degrees: (voltage - 500mV) times 100
  float tempC = (voltage - 0.5) * 100 ;
  return tempC;
}