<a href="https://107-systems.org/"><img align="right" src="https://raw.githubusercontent.com/107-systems/.github/main/logo/107-systems.png" width="15%"></a>
:floppy_disk: `107-Arduino-CriticalSection`
===========================================
[![Arduino Library Badge](https://www.ardu-badge.com/badge/107-Arduino-CriticalSection.svg?)](https://www.ardu-badge.com/107-Arduino-CriticalSection)
[![Compile Examples](https://github.com/107-systems/107-Arduino-CriticalSection/workflows/Compile%20Examples/badge.svg)](https://github.com/107-systems/107-Arduino-CriticalSection/actions?workflow=Compile+Examples)
[![Arduino Lint](https://github.com/107-systems/107-Arduino-CriticalSection/workflows/Arduino%20Lint/badge.svg)](https://github.com/107-systems/107-Arduino-CriticalSection/actions?workflow=Arduino+Lint)
[![keywords.txt Checks](https://github.com/107-systems/107-Arduino-CriticalSection/workflows/Extra%20Library%20Checks/badge.svg)](https://github.com/107-systems/107-Arduino-CriticalSection/actions?workflow=Extra+Library+Checks)
[![General Formatting Checks](https://github.com/107-systems/107-Arduino-CriticalSection/workflows/General%20Formatting%20Checks/badge.svg)](https://github.com/107-systems/107-Arduino-CriticalSection/actions?workflow=General+Formatting+Checks)
[![Spell Check](https://github.com/107-systems/107-Arduino-CriticalSection/workflows/Spell%20Check/badge.svg)](https://github.com/107-systems/107-Arduino-CriticalSection/actions?workflow=Spell+Check)

This library provides a consistent critical section interface over various Arduino platforms.

<p align="center">
  <a href="https://github.com/107-systems/l3xz"><img src="https://raw.githubusercontent.com/107-systems/.github/main/logo/l3xz-logo-memento-mori-github.png" width="40%"></a>
</p>

This library works for
* [ArduinoCore-samd](https://github.com/arduino/ArduinoCore-samd): [`Arduino Zero`](https://store.arduino.cc/arduino-zero), [`MKR 1000`](https://store.arduino.cc/arduino-mkr1000-wifi), [`MKR WiFi 1010`](https://store.arduino.cc/arduino-mkr-wifi-1010), [`Nano 33 IoT`](https://store.arduino.cc/arduino-nano-33-iot), [`MKR GSM 1400`](https://store.arduino.cc/arduino-mkr-gsm-1400-1415), [`MKR NB 1500`](https://store.arduino.cc/arduino-mkr-nb-1500-1413), [`MKR WAN 1300/1310`](https://store.arduino.cc/mkr-wan-1310) :heavy_check_mark:
* [ArduinoCore-mbed](https://github.com/arduino/ArduinoCore-mbed): [`Portenta H7`](https://store.arduino.cc/portenta-h7), [`Nano 33 BLE`](https://store.arduino.cc/arduino-nano-33-ble), [`Nano RP2040 Connect`](https://store.arduino.cc/nano-rp2040-connect), [`Edge Control`](https://store.arduino.cc/edge-control) :heavy_check_mark:
* [arduino-esp32](https://github.com/espressif/arduino-esp32): `ESP32 Dev Module`, `ESP32 Wrover Module`, ... :heavy_check_mark:
* [arduino-pico](https://github.com/earlephilhower/arduino-pico): [`Raspberry Pi Pico`](https://www.raspberrypi.org/products/raspberry-pi-pico), `Adafruit Feather RP2040`, ... :heavy_check_mark:
* [adafruit/ArduinoCore-samd](https://github.com/adafruit/ArduinoCore-samd): [`Adafruit Feather M4 CAN Express`](https://www.adafruit.com/product/4759), ... :heavy_check_mark:
* [ArduinoCore-renesas](https://github.com/arduino/ArduinoCore-renesas): [`Portenta C33`](https://store.arduino.cc/products/portenta-c33), [`Uno R4 WiFi`](https://store.arduino.cc/products/uno-r4-wifi), [`Uno R4 Minima`](https://store.arduino.cc/products/uno-r4-minima), ... :heavy_check_mark:

### Example
```C++
#include <107-Arduino-CriticalSection.h>

volatile int button_evt_counter = 0;

void setup() {
  Serial.begin(9600);
  while (!Serial) { }

  attachInterrupt(0, onButton_1_Pressed, RISING);
  attachInterrupt(1, onButton_2_Pressed, RISING);
}

void loop() {
  int copy_button_evt_counter;
  {
    /* Prevent change of button_evt_counter during readout. */
    CriticalSection crit_sec;
    copy_button_evt_counter = button_evt_counter;
  }
  Serial.println(copy_button_evt_counter);
}

void onButton_1_Pressed() {
  CriticalSection crit_sec;
  button_evt_counter++;
}

void onButton_2_Pressed() {
  CriticalSection crit_sec;
  button_evt_counter++;
}
```
