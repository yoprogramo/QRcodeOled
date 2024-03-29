#include <Arduino.h>
/* *********************************************************************************
 * ESP8266 QRcode
 * dependency library :
 *   ESP8266 Oled Driver for SSD1306 display by Daniel Eichborn, Fabrice Weinberg
 *
 * SDA --> D6
 * SCL --> D7
***********************************************************************************/
#define OLEDDISPLAY

#include <qrcodeoled.h>
#include <SH1106Wire.h>

SH1106Wire  display(0x3c, 21, 22); // Only change

QRcodeOled qrcode (&display);


void setup() {

    Serial.begin(115200);
    Serial.println("");
    Serial.println("Starting...");

    display.init();
    display.clear();
    display.display();


    // enable debug qrcode
    // qrcode.debug();

    // Initialize QRcode display using library
    qrcode.init();
    // create qrcode
    qrcode.create("Hello world.");

}

void loop() { }