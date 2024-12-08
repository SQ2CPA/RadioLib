#if !defined(_RADIOLIB_H)
#define _RADIOLIB_H

/*!
  \mainpage RadioLib Documentation

  Universal wireless communication library for embedded devices.

  \par Currently Supported Wireless Modules and Protocols
  - CC1101 FSK module
  - LLCC68 LoRa/FSK module
  - LR11x0 LoRa/FSK/LR-FHSS module
  - nRF24 FSK module
  - RF69 FSK module
  - RFM2x FSK module
  - Si443x FSK module
  - SX126x LoRa/FSK module
  - SX127x LoRa/FSK module
  - SX128x LoRa/GFSK/BLE/FLRC module
  - SX1231 FSK module
  - PhysicalLayer protocols
    - RTTY (RTTYClient)
    - Morse Code (MorseClient)
    - AX.25 (AX25Client)
    - SSTV (SSTVClient)
    - Hellschreiber (HellClient)
    - 4-FSK (FSK4Client)
    - APRS (APRSClient)
    - POCSAG (PagerClient)
    - LoRaWAN (LoRaWANNode)

  \par Quick Links
  Documentation for most common methods can be found in its reference page (see the list above).\n
  Some methods (mainly configuration) are also overridden in derived classes, such as SX1272, SX1278, RFM96 etc. for SX127x.\n
  \ref status_codes have their own page.\n
  Some modules implement methods of one or more compatibility layers, loosely based on the ISO/OSI model:
  - PhysicalLayer - FSK and LoRa radio modules

  \see https://github.com/jgromes/RadioLib

  \copyright  Copyright (c) 2019 Jan Gromes
*/

#include "TypeDef.h"
#include "Module.h"

#include "Hal.h"
#if defined(RADIOLIB_BUILD_ARDUINO)
#include "hal/Arduino/ArduinoHal.h"
#endif


// warnings are printed in this file since BuildOpt.h is compiled in multiple places

// check God mode
#if RADIOLIB_GODMODE
  #warning "God mode active, I hope it was intentional. Buckle up, lads."
#endif

// print debug info
#if RADIOLIB_DEBUG
  #pragma message(RADIOLIB_INFO)
#endif

// check unknown/unsupported platform
#if defined(RADIOLIB_UNKNOWN_PLATFORM)
  #warning "RadioLib might not be compatible with this Arduino board - check supported platforms at https://github.com/jgromes/RadioLib!"
#endif

// print warning for low-end platforms
#if defined(RADIOLIB_LOWEND_PLATFORM)
  #warning "Low-end platform detected, stability issues are likely!"
#endif

#include "modules/SX127x/SX1278.h"

// physical layer protocols
#include "protocols/PhysicalLayer/PhysicalLayer.h"
#include "protocols/AFSK/AFSK.h"
#include "protocols/AX25/AX25.h"
#include "protocols/Morse/Morse.h"
#include "protocols/FSK4/FSK4.h"
#include "protocols/APRS/APRS.h"
#include "protocols/Print/Print.h"
#include "protocols/BellModem/BellModem.h"
#include "protocols/LoRaWAN/LoRaWAN.h"

// utilities
#include "utils/CRC.h"
#include "utils/Cryptography.h"

#endif
