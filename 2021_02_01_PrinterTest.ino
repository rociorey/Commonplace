/*------------------------------------------------------------------------
  Example sketch for Adafruit Thermal Printer library for Arduino.
  Demonstrates a few text styles & layouts, bitmap printing, etc.

  IMPORTANT: DECLARATIONS DIFFER FROM PRIOR VERSIONS OF THIS LIBRARY.
  This is to support newer & more board types, especially ones that don't
  support SoftwareSerial (e.g. Arduino Due).  You can pass any Stream
  (e.g. Serial1) to the printer constructor.  See notes below.

  You may need to edit the PRINTER_FIRMWARE value in Adafruit_Thermal.h
  to match your printer (hold feed button on powerup for test page).
  ------------------------------------------------------------------------*/
#include "Adafruit_Thermal.h"
#include "adalogo.h"
#include "adaqrcode.h"


// Here's the new syntax when using SoftwareSerial (e.g. Arduino Uno) ----
// If using hardware serial instead, comment out or remove these lines:

#include "SoftwareSerial.h"
#define TX_PIN 6 // Arduino transmit  YELLOW WIRE  labeled RX on printer
#define RX_PIN 5 // Arduino receive   GREEN WIRE   labeled TX on printer



//from Adafruit_Thermal import *
//import textwrap

SoftwareSerial mySerial(RX_PIN, TX_PIN); // Declare SoftwareSerial obj first
Adafruit_Thermal printer(&mySerial);     // Pass addr to printer constructor



//printer.upsideDownOn();

char readChars;
String inputString = "";


//
//
//
//def textWrapped(text, maxColumn):
//  textWrapped = textwrap.wrap(text, width=maxColumn)
//  for i in range(len(textWrapped)):
//        textWrapped[i]+='\n'
//
//  textWrappedReversed = textWrapped[::-1]
//  stringForPrinter = ''.join(list(textWrappedReversed))
//  return stringForPrinter


void setup() {
    Serial.begin(9600);
  //    Serial.println("hi");

  // This line is for compatibility with the Adafruit IotP project pack,
  // which uses pin 7 as a spare grounding point.  You only need this if
  // wired up the same way (w/3-pin header into pins 5/6/7):
  //  pinMode(7, OUTPUT); digitalWrite(7, LOW);
  //printer.reset();
  // NOTE: SOME PRINTERS NEED 9600 BAUD instead of 19200, check test page.
  mySerial.begin(19200);  // Initialize SoftwareSerial
  //Serial1.begin(19200); // Use this instead if using hardware serial
  printer.begin();        // Init printer (same regardless of serial type)
//  printer.reset();

  printer.setLineHeight(64);
  //      printer.underlineOn();
  //  printer.inverseOn();
//  printer.setSize('S');
//  //  printer.inverseOn();
//  printer.justify('L');
//    printer.boldOn();
//  printer.println();
//    printer.println();
//  printer.println("C O M M O N P L A C E");
//  //    printer.inverseOff();
//  //      printer.underlineOff();
////
////  printer.boldOn();
//
//  printer.setLineHeight(40);
//  printer.setSize('S');
//  printer.underlineOn();
//  printer.println("Emotions in a pandemic ");
//  printer.boldOff();
//  printer.underlineOff();
//
//  printer.setLineHeight(30);
//  printer.setSize('S');
//  printer.justify('L');
//  printer.println("A collective emotional journal\nover the course of one day\nduring the COVID-19 pandemic.");
//  printer.println();
//  printer.println();
//  printer.println();





  // Test character double-height on & off
  //  printer.doubleHeightOn();
  //  printer.println(F("Double Height ON"));
  //  printer.doubleHeightOff();
  //
  //  // Set text justification (right, center, left) -- accepts 'L', 'C', 'R'
  //  printer.justify('R');
  //  printer.println(F("Right justified"));
  //  printer.justify('C');
  //  printer.println(F("Center justified"));
  //  printer.justify('L');
  //  printer.println(F("Left justified"));
  //
  //  // Test more styles
  //  printer.boldOn();
  //  printer.println(F("Bold text"));
  //  printer.boldOff();
  //
  //  printer.underlineOn();
  //  printer.println(F("Underlined text"));
  //  printer.underlineOff();
  //
  //  printer.setSize('L');        // Set type size, accepts 'S', 'M', 'L'
  //  printer.println(F("Large"));
  //  printer.setSize('M');
  //  printer.println(F("Medium"));
  //  printer.setSize('S');
  //  printer.println(F("Small"));
  //
  //  printer.justify('C');
  //  printer.println(F("normal\nline\nspacing"));
  //  printer.setLineHeight(50);
  //  printer.println(F("Taller\nline\nspacing"));
  //  printer.setLineHeight(); // Reset to default
  //  printer.justify('L');
  //
  //  // Barcode examples:
  //  // CODE39 is the most common alphanumeric barcode:
  //  printer.printBarcode("ADAFRUT", CODE39);
  //  printer.setBarcodeHeight(100);
  //  // Print UPC line on product barcodes:
  //  printer.printBarcode("123456789123", UPC_A);
  //
  //  // Print the 75x75 pixel logo in adalogo.h:
  //  printer.printBitmap(adalogo_width, adalogo_height, adalogo_data);
  //
  //  // Print the 135x135 pixel QR code in adaqrcode.h:
  //  printer.printBitmap(adaqrcode_width, adaqrcode_height, adaqrcode_data);
  //  printer.println(F("Adafruit!"));
  //  printer.feed(2);

  //  printer.sleep();      // Tell printer to sleep
  //  delay(3000);         // Sleep for 3 seconds
  //  printer.wake();       // MUST wake() before printing again, even if reset
  //  printer.setDefault(); // Restore printer to defaults
}

void loop() {

  if (Serial.available()) {
    //            Serial.println("available");
    readChars = Serial.read();
    if (readChars != 'Z') {
      inputString += readChars;
//      delay(300);

    } else {
      printer.setSize('S');
      printer.setLineHeight(20);
      //      Serial.print("this is from arduino:" + inputString);
      printer.println(inputString);
      printer.println();
      printer.println();
      inputString = "";
    }
  }

}
