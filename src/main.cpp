#include <Arduino.h>
#include <SPIFFS.h>

// Debug mode: 0 for simple output, 1 for full debug
#define DEBUG_MODE 1

// Pin definitions for different boards
#if defined(CONFIG_IDF_TARGET_ESP32C3)
    #define PIN_BUTTON 9
    #define PIN_LED 2
#elif defined(ARDUINO_M5STACK_STAMPS3)
    #define PIN_BUTTON 0
    #define PIN_LED 21
#else
    #error "Unsupported board selected"
#endif

void setup() {
    Serial.begin(115200);
    while (!Serial) {
        ; // wait for serial port to connect. Needed for native USB port only
    }
    
    // Initialize LED pin as an output
    pinMode(PIN_LED, OUTPUT);
    // Initialize BUTTON pin as an input with internal pull-up resistor
    pinMode(PIN_BUTTON, INPUT_PULLUP);

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
    File root = SPIFFS.open("/");
    File foundFile = root.openNextFile();
    while (foundFile) {
        Serial.print("File: ");
        Serial.println(foundFile.name());
        foundFile = root.openNextFile();
    }

    #if DEBUG_MODE
    Serial.println("Board-specific information:");
    Serial.print("PIN_BUTTON: ");
    Serial.println(PIN_BUTTON);
    Serial.print("PIN_LED: ");
    Serial.println(PIN_LED);
    #endif
}

void loop() {
    // Blink the LED
    digitalWrite(PIN_LED, HIGH);
    delay(1000);
    digitalWrite(PIN_LED, LOW);
    delay(1000);

    // Check if button is pressed
    if (digitalRead(PIN_BUTTON) == LOW) {
        Serial.println("Button pressed!");
        delay(200); // debounce
    }
}