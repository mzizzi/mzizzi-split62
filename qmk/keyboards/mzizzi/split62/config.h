#pragma once

// To flash the correct handedness option to the controller on each halve using:
// qmk flash -kb mzizzi/split62 -km default -bl (uf2-split-left|uf2-split-right)
// https://docs.qmk.fm/features/split_keyboard#handedness-by-eeprom
#define EE_HANDS

#define SERIAL_USART_FULL_DUPLEX    // Enable full duplex operation mode.
#define SERIAL_USART_TX_PIN GP0     // USART TX pin
#define SERIAL_USART_RX_PIN GP1     // USART RX pin

// The pcb is mirrored. Swap tx/rx in software:
// https://docs.qmk.fm/drivers/serial#pin-configuration-2e
#define SERIAL_USART_PIN_SWAP

#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET
#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET_TIMEOUT 1000U

// Set different matrix positions for right hand keyboard. These set the bootmagic
// key to the key closest to the usb port on the microcontroller. Keys "5" and "6"
// using the default keymap.
// https://docs.qmk.fm/features/bootmagic#bootmagic
#define BOOTMAGIC_ROW 0
#define BOOTMAGIC_COLUMN 5
#define BOOTMAGIC_ROW_RIGHT 6
#define BOOTMAGIC_COLUMN_RIGHT 5

