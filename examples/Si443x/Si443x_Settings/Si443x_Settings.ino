/*
   RadioLib Si443x Settings Example

   This example shows how to change all the properties of RF69 radio.
   RadioLib currently supports the following settings:
    - pins (SPI slave select, nIRQ, shutdown)
    - carrier frequency
    - bit rate
    - receiver bandwidth
    - frequency deviation
    - output power during transmission
    - sync word

   For full API reference, see the GitHub Pages
   https://jgromes.github.io/RadioLib/
*/

// include the library
#include <RadioLib.h>

// Si4432 has the following connections:
// nSEL pin:  10
// nIRQ pin:  2
// SDN pin:   9
Si4432 fsk1 = new Module(10, 2, 9);

// Si4432 has the following connections:
// nSEL pin:  8
// nIRQ pin:  3
// SDN pin:   7
Si4432 fsk2 = new Module(8, 3, 7);

// or using RadioShield
// https://github.com/jgromes/RadioShield
//Si4432 fsk3 = RadioShield.ModuleB;

void setup() {
  Serial.begin(9600);

  // initialize Si4432 with default settings
  Serial.print(F("[Si4432] Initializing ... "));
  // carrier frequency:           434.0 MHz
  // bit rate:                    48.0 kbps
  // frequency deviation:         50.0 kHz
  // Rx bandwidth:                225.1 kHz
  // output power:                11 dBm
  // sync word:                   0x2D  0x01
  int state = fsk1.begin();
  if (state == ERR_NONE) {
    Serial.println(F("success!"));
  } else {
    Serial.print(F("failed, code "));
    Serial.println(state);
    while (true);
  }

  // initialize Si4432 with non-default settings
  Serial.print(F("[Si4432] Initializing ... "));
  // carrier frequency:           868.0 MHz
  // bit rate:                    200.0 kbps
  // frequency deviation:         60.0 kHz
  // Rx bandwidth:                335.5 kHz
  // output power:                17 dBm
  // sync word:                   0x2D  0x01
  state = fsk2.begin(868.0, 200.0, 60.0, 335.5, 17);
  if (state == ERR_NONE) {
    Serial.println(F("success!"));
  } else {
    Serial.print(F("failed, code "));
    Serial.println(state);
    while (true);
  }

  // you can also change the settings at runtime
  // and check if the configuration was changed successfully

  // set carrier frequency to 433.5 MHz
  if (fsk1.setFrequency(433.5) == ERR_INVALID_FREQUENCY) {
    Serial.println(F("[Si4432] Selected frequency is invalid for this module!"));
    while (true);
  }

  // set bit rate to 100.0 kbps
  state = fsk1.setBitRate(100.0);
  if (state == ERR_INVALID_BIT_RATE) {
    Serial.println(F("[Si4432] Selected bit rate is invalid for this module!"));
    while (true);
  } else if (state == ERR_INVALID_BIT_RATE_BW_RATIO) {
    Serial.println(F("[Si4432] Selected bit rate to bandwidth ratio is invalid!"));
    Serial.println(F("[Si4432] Increase receiver bandwidth to set this bit rate."));
    while (true);
  }

  // set receiver bandwidth to 284.8 kHz
  state = fsk1.setRxBandwidth(284.8);
  if (state == ERR_INVALID_RX_BANDWIDTH) {
    Serial.println(F("[Si4432] Selected receiver bandwidth is invalid for this module!"));
    while (true);
  }

  // set frequency deviation to 10.0 kHz
  if (fsk1.setFrequencyDeviation(10.0) == ERR_INVALID_FREQUENCY_DEVIATION) {
    Serial.println(F("[Si4432] Selected frequency deviation is invalid for this module!"));
    while (true);
  }

  // set output power to 2 dBm
  if (fsk1.setOutputPower(2) == ERR_INVALID_OUTPUT_POWER) {
    Serial.println(F("[Si4432] Selected output power is invalid for this module!"));
    while (true);
  }

  // up to 4 bytes can be set as sync word
  // set sync word to 0x01234567
  uint8_t syncWord[] = {0x01, 0x23, 0x45, 0x67};
  if (fsk1.setSyncWord(syncWord, 4) == ERR_INVALID_SYNC_WORD) {
    Serial.println(F("[Si4432] Selected sync word is invalid for this module!"));
    while (true);
  }

  Serial.println(F("[Si4432] All settings changed successfully!"));
}

void loop() {
  // nothing here
}