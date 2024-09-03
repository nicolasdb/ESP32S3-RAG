# Instructions for Testing SPIFFS Functionality

Follow these steps to compile, upload, and test the SPIFFS functionality on both ESP32-S3 and ESP32-C3 boards.

## Prerequisites

- PlatformIO IDE installed (preferably as a VSCode extension)
- ESP32-S3 (m5stack-stamps3) board
- ESP32-C3 (lolin_c3_mini) board
- USB cables for connecting the boards to your computer

## Steps

1. **Open the project in PlatformIO IDE**
   - Launch VSCode with PlatformIO extension
   - Open the project folder

2. **Upload SPIFFS filesystem**
   - In the PlatformIO sidebar, click on the "Project Tasks" dropdown
   - Expand the "stampC3U" environment (for ESP32-C3) or "stampS3" environment (for ESP32-S3)
   - Click on "Build Filesystem Image" to build the SPIFFS data
   - Click on "Upload Filesystem Image" to upload the SPIFFS data

3. **Compile and Upload for ESP32-C3**
   - Connect the ESP32-C3 board to your computer via USB
   - In the PlatformIO sidebar, expand the "stampC3U" environment
   - Click on "Build" to compile the code
   - Click on "Upload" to flash the code to the board

4. **Test ESP32-C3**
   - Open the Serial Monitor in PlatformIO (stampC3U > General > Monitor)
   - Reset the board if necessary
   - Observe the output to verify SPIFFS operations:
     - SPIFFS mounting
     - File writing
     - File reading
     - File listing
   - The built-in LED (GPIO 2) should blink every second
   - Press the button (GPIO 9) to see "Button pressed!" in the serial monitor

5. **Compile and Upload for ESP32-S3**
   - Disconnect the ESP32-C3 board
   - Connect the ESP32-S3 (M5Stack StampS3) board to your computer via USB
   - In the PlatformIO sidebar, expand the "stampS3" environment
   - Click on "Build" to compile the code
   - Click on "Upload" to flash the code to the board

6. **Test ESP32-S3**
   - Open the Serial Monitor in PlatformIO (stampS3 > General > Monitor)
   - Reset the board if necessary
   - Observe the output to verify SPIFFS operations:
     - SPIFFS mounting
     - File writing
     - File reading
     - File listing
   - The built-in LED (GPIO 21) should blink every second
   - Press the button (GPIO 0) to see "Button pressed!" in the serial monitor

7. **Debugging**
   - If you need more detailed output, change the `DEBUG_MODE` to 1 in the `main.cpp` file:
     ```cpp
     #define DEBUG_MODE 1
     ```
   - This will print additional board-specific information during setup

8. **Troubleshooting**
   - If you encounter any issues with SPIFFS mounting, ensure that the SPIFFS data is correctly uploaded to the board using the "Upload Filesystem Image" task in PlatformIO.
   - If serial output is not visible, double-check the baud rate in the Serial Monitor settings (should be 115200).
   - Make sure you're using the correct USB port and have the necessary drivers installed for your board.
   - If the board is not responding, try pressing the reset button or disconnecting and reconnecting the USB cable.

After completing these steps, you should have a good understanding of SPIFFS functionality on both ESP32-S3 and ESP32-C3 boards. Document your findings, including any differences in performance or behavior between the two boards, and update the README.md file with your results.