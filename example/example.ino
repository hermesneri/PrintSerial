#include "PrintSerial.h"

PrintSerial SerialPrint;

void setup() {
    // Initialize serial communication and configure print level
    SerialPrint.begin(115200, 1); // 115200 baud rate, print level 1 (all messages)

    // Examples of all print options

    // DONE message
    SerialPrint.done("Setup completed");

    // LOG message
    SerialPrint.log("Starting configuration...");

    // LOG message with a new line
    SerialPrint.logln("Configuration in progress...");

    // WARNING message
    SerialPrint.warning("This is a warning. Check your settings.");

    // ERROR message
    SerialPrint.error("Failed to connect to the server.");

    // INFO message
    SerialPrint.infos("Connected to the WiFi network.");

    // Message with background color
    SerialPrint.backg("Message with background color.");
}

void loop() {
    // Your code here
}
