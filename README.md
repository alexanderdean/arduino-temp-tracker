# Arduino Temperature Tracker

## Introduction

This is a simple Arduino sketch to take a room's temperature every minute and log it to [SnowPlow] [snowplow] using the [SnowPlow Arduino Tracker] [snowplow-arduino-tracker].

## Installation

## 1. Requirements

To run this sketch, you will need the following hardware:

* 1 x Arduino (I used an [Arduino Uno] [arduino-uno])
* 1 x Ethernet or WiFi shield for Arduino (I used an [Ethernet shield] [ethernet-shield])
* 1 x [TMP36] [tmp36] temperature sensor

Many Arduino starter kits include the TMP36 sensor and instructions on configuring it (e.g. the [Oomlout Starter Kit] [oomlout-starter-kit]).

In software terms, you will need:

* <<Something about SnowPlow library>>
* A running SnowPlow event collector (to receive events sent by the Arduino Tracker)

If you are not already running SnowPlow, we recommend setting up the CloudFront-based event collector, which is SnowPlow's simplest collector. Checkout the guide here: [Setting up the Cloudfront Collector] [cf-collector-setup]. 

## 2. Making

First, attach your Arduino Ethernet or WiFi shield onto your Arduino. Then wire your TMP36 into your Arduino Ethernet or WiFi shield like so:

![schematic] [schematic]

A couple of notes on this setup:

* We are using 3.3V (and connecting ARef to the same) to get a more precise temperature reading than the standard 5V will
* It's very important that you wire the TMP36 in the right way around, or else the TMP36 will malfunction and get very hot
* This schematic was produced using the excellent [Fritzing desktop app] [fritzing] - for the source file see `/docs/arduino-temp-tracker.fzz`

Once you have done this, your configuration should look something like this:

![photo] [photo]

## 3. Running

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

[snowplow]: http://snowplowanalytics.com/
[snowplow-arduino-tracker]: https://github.com/snowplow/snowplow-arduino-tracker

[arduino-uno]: http://arduino.cc/en/Main/arduinoBoardUno
[ethernet-shield]: http://arduino.cc/en/Main/ArduinoEthernetShield
[tmp36]: http://adafruit.com/products/165
[oomlout-starter-kit]: http://oomlout.co.uk/starter-kit-for-arduino-ardx-p-183.html

[schematic]: https://raw.github.com/alexanderdean/arduino-temp-tracker/master/docs/arduino-temp-tracker.png
[fritzing]: http://fritzing.org/download/
[photo]: xxx

[cf-collector-setup]: https://github.com/snowplow/snowplow/wiki/setting-up-the-cloudfront-collector

[license]: http://www.apache.org/licenses/LICENSE-2.0
