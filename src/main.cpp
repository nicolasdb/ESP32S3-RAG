#include <Arduino.h>
#include <SPIFFS.h>

void testSPIFFS() {
    Serial.println("\n--- SPIFFS Test ---");

    if (!SPIFFS.begin(true)) {
        Serial.println("An error has occurred while mounting SPIFFS");
        return;
    }
    
    Serial.println("SPIFFS mounted successfully");

    // Write a test file
    File file = SPIFFS.open("/test.txt", FILE_WRITE);
    if (!file) {
        Serial.println("Failed to open file for writing");
        return;
    }
    if (file.print("Hello, SPIFFS!")) {
        Serial.println("File written");
    } else {
        Serial.println("Write failed");
    }
    file.close();

    // Read the test file
    file = SPIFFS.open("/test.txt", FILE_READ);
    if (!file) {
        Serial.println("Failed to open file for reading");
        return;
    }
    Serial.println("File Content:");
    while (file.available()) {
        Serial.write(file.read());
    }
    Serial.println();
    file.close();

    // List files
    Serial.println("Files in SPIFFS:");
    File root = SPIFFS.open("/");
    File foundFile = root.openNextFile();
    while (foundFile) {
        Serial.print("  ");
        Serial.println(foundFile.name());
        foundFile = root.openNextFile();
    }

    Serial.println("--- SPIFFS Test Complete ---\n");
}

void setup() {
    Serial.begin(115200);
    delay(1000);  // Give some time for the serial connection to establish
    
    Serial.println("\n\n--- ESP32-C3 Boot Complete ---");
    Serial.println("If you can see this message, serial communication is working.");
    Serial.println("Press the reset button on the board to test auto-reconnection.");
    
    testSPIFFS();
}

void loop() {
    delay(5000);  // Wait 5 seconds before repeating the test
    testSPIFFS();
}