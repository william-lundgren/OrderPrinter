#include <SoftwareSerial.h>

SoftwareSerial printer(10, 11); // RX, TX

void setup() {
    Serial.begin(115200);

    // Replace 9600 with the printer's configured baud rate
    printer.begin(9600);

    delay(1000);

    for (byte n = 1; n <= 4; n++) {
        Serial.print("Status ");
        Serial.print(n);
        Serial.print(": ");

        printer.write(0x10); // DLE
        printer.write(0x04); // EOT
        printer.write(n);

        // Wait for printer response
        unsigned long start = millis();

        while (millis() - start < 500) {
            if (printer.available()) {
                byte response = printer.read();

                Serial.print("0x");
                if (response < 16) Serial.print("0");
                Serial.println(response, HEX);

                break;
            }
        }

        if (!printer.available()) {
            Serial.println("No response (or timeout)");
        }

        delay(100);
    }
}

void loop() {
}