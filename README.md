# Arduino Temperature Tracker

## Introduction

![arduino-logo] [arduino-logo] 

This is a simple Arduino sketch to take a room's temperature every minute and log it to [SnowPlow] [snowplow] using the [SnowPlow Arduino Tracker] [snowplow-arduino-tracker].

## Installation

## 1. Requirements

To run this sketch, you will need the following hardware:

1. An Arduino (I used an [Arduino Uno] [arduino-uno])
2. An Ethernet or WiFi shield for Arduino (I used an [Ethernet shield] [ethernet-shield])
3. An [TMP36] [tmp36] temperature sensor (mine came in the [Oomlout Starter Kit] [oomlout-starter-kit])

In software terms, you will need:

1. The sketch in this repository, `temp-tracker.ino`
2. The [SnowPlow Arduino Tracker] [snowplow-arduino-tracker] library
2. A [SnowPlow event collector] [snowplow-collectors] (to receive events sent by the Arduino Tracker)

## 2. Making

First, attach your Arduino Ethernet or WiFi shield onto your Arduino. Then wire your TMP36 into your Arduino Ethernet or WiFi shield like so:

![schematic] [schematic]

Some notes on this setup:

* It's very important that you wire the TMP36 in the right way around, or else the TMP36 will malfunction and get very hot
* We use 3.3V (connecting ARef to the same) for a more precise temperature reading than 5V will give us
* This schematic was produced using [Fritzing] [fritzing] - the source file is `docs/arduino-schematic.fzz`

Finally, connect your Arduino board to your computer via USB, and connect your Ethernet or WiFi shield to your network.

Once you have done this, your hardware configuration should look something like this:

![photo] [photo]

## 3. Running

### 3.1 SnowPlow Arduino Tracker library

You will need the [SnowPlow Arduino Tracker] [snowplow-arduino-tracker] library installed in the Arduino "libraries" folder on the computer connected to your Arduino.

To install this library, please check out the guide here: [Arduino Tracker Setup] [tracker-setup-guide] on the SnowPlow wiki.

### 3.2 SnowPlow event collector

If you are not already running SnowPlow, you can setup the CloudFront-based event collector, which is SnowPlow's simplest collector. Checkout the guide here: [Setting up the Cloudfront Collector] [cf-collector-setup] on the SnowPlow wiki. 

### 3.3 The sketch

Download the `[temp-tracker.ino] [sketch]` sketch in this GitHub repository and open it in

Right, ...

## Roadmap

Nothing planned. Hopefully this project inspires you to try monitoring your own home/office/factory/shop using Arduino and SnowPlow!

## Copyright and license

Arduino Temperature Tracker is copyright 2013 Alexander Dean.

Licensed under the [Apache License, Version 2.0] [license] (the "License");
you may not use this software except in compliance with the License.

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.

[arduino-logo]: https://raw.github.com/alexanderdean/arduino-temp-tracker/master/docs/arduino-logo.png

[snowplow]: http://snowplowanalytics.com/
[snowplow-arduino-tracker]: https://github.com/snowplow/snowplow-arduino-tracker

[arduino-uno]: http://arduino.cc/en/Main/arduinoBoardUno
[ethernet-shield]: http://arduino.cc/en/Main/ArduinoEthernetShield
[tmp36]: http://adafruit.com/products/165
[oomlout-starter-kit]: http://oomlout.co.uk/starter-kit-for-arduino-ardx-p-183.html

[schematic]: https://raw.github.com/alexanderdean/arduino-temp-tracker/master/docs/temp-tracker-schematic.png
[fritzing]: http://fritzing.org/download/
[photo]: https://raw.github.com/alexanderdean/arduino-temp-tracker/master/docs/temp-tracker-photo.jpg

[cf-collector-setup]: https://github.com/snowplow/snowplow/wiki/setting-up-the-cloudfront-collector
[tracker-setup-guide]: https://github.com/snowplow/snowplow/wiki/Arduino-Tracker-Setup
[snowplow-collectors]: https://github.com/snowplow/snowplow/wiki/Setting-up-a-collector

[sketch]: https://raw.github.com/alexanderdean/arduino-temp-tracker/master/temp-tracker.ino

[license]: http://www.apache.org/licenses/LICENSE-2.0
