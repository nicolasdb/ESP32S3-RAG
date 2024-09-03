#include <Arduino.h>
#include <SPIFFS.h>

const char* CONFIG_FILE = "/config.json";
const char* LOG_FILE = "/sensor_log.txt";

void initSPIFFS() {
    if (!SPIFFS.begin(true)) {
        Serial.println("An error has occurred while mounting SPIFFS");
        return;
    }
    Serial.println("SPIFFS mounted successfully");
}

void saveConfig(const char* ssid, const char* password) {
    File file = SPIFFS.open(CONFIG_FILE, FILE_WRITE);
    if (!file) {
        Serial.println("Failed to open config file for writing");
        return;
    }
    
    String config = "{\"ssid\":\"" + String(ssid) + "\",\"password\":\"" + String(password) + "\"}";
    if (file.print(config)) {
        Serial.println("Config saved");
    } else {
        Serial.println("Config save failed");
    }
    file.close();
}

bool loadConfig(String &ssid, String &password) {
    File file = SPIFFS.open(CONFIG_FILE, FILE_READ);
    if (!file) {
        Serial.println("No config file found");
        return false;
    }
    
    String config = file.readString();
    file.close();
    
    int ssidStart = config.indexOf("\"ssid\":\"") + 8;
    int ssidEnd = config.indexOf("\"", ssidStart);
    int passStart = config.indexOf("\"password\":\"") + 12;
    int passEnd = config.indexOf("\"", passStart);
    
    if (ssidStart == -1 || ssidEnd == -1 || passStart == -1 || passEnd == -1) {
        Serial.println("Config file format error");
        return false;
    }
    
    ssid = config.substring(ssidStart, ssidEnd);
    password = config.substring(passStart, passEnd);
    
    Serial.println("Config loaded");
    return true;
}

void logSensorData(float temperature, float humidity) {
    File file = SPIFFS.open(LOG_FILE, FILE_APPEND);
    if (!file) {
        Serial.println("Failed to open log file for appending");
        return;
    }
    
    String logEntry = String(millis()) + ",temp:" + String(temperature) + ",hum:" + String(humidity) + "\n";
    if (file.print(logEntry)) {
        Serial.println("Sensor data logged");
    } else {
        Serial.println("Sensor data logging failed");
    }
    file.close();
}

void printLogFile() {
    File file = SPIFFS.open(LOG_FILE, FILE_READ);
    if (!file) {
        Serial.println("No log file found");
        return;
    }
    
    Serial.println("Log file contents:");
    while (file.available()) {
        Serial.write(file.read());
    }
    file.close();
}

void setup() {
    Serial.begin(115200);
    delay(1000);  // Give some time for the serial connection to establish
    
    Serial.println("\n\n--- ESP32 Boot Complete ---");
    Serial.println("If you can see this message, serial communication is working.");
    
    initSPIFFS();
    
    // Example usage of new functions
    saveConfig("MyWiFi", "MyPassword");
    
    String ssid, password;
    if (loadConfig(ssid, password)) {
        Serial.println("Loaded SSID: " + ssid);
        Serial.println("Loaded Password: " + password);
    }
    
    // Simulate sensor readings
    logSensorData(23.5, 60.0);
    logSensorData(24.0, 59.5);
    
    printLogFile();
}

void loop() {
    delay(10000);  // Wait 10 seconds
    
    // Simulate a sensor reading every 10 seconds
    float temp = random(200, 300) / 10.0;  // Random temperature between 20.0 and 30.0
    float hum = random(500, 700) / 10.0;   // Random humidity between 50.0 and 70.0
    
    logSensorData(temp, hum);
    Serial.printf("Logged: Temperature %.1f°C, Humidity %.1f%%\n", temp, hum);
}