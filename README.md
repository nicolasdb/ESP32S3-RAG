# ESP32-S3 and C3 SPIFFS and RAG Project

This project aims to test and validate the capability to use SPIFFS internal storage on ESP32-S3 and C3, and implement a system with enhanced user identification and improved local intelligence.

## Objectives and Key Results (OKRs)

### Objective 1: Test and validate SPIFFS internal storage on ESP32-S3 and C3

Key Results:
-[ ] Successfully initialize SPIFFS on both ESP32-S3 and C3 🚧
-[ ] Implement basic file operations (read, write, delete) using SPIFFS 
-[ ] Measure and document storage capacity and performance metrics 

### Objective 2: Enhance User Identification

Key Results:
1. Implement NFC tag reader functionality
2. Design and implement a simple user profile storage system using SPIFFS
3. Successfully read and store user data from NFC tags

### Objective 3: Improve Local Intelligence

Key Results:
1. Utilize SPIFFS for efficient local data storage
2. Implement a basic RAG (Retrieval Augmented Generation) system
3. Demonstrate personalized context-aware responses using local data and cloud APIs

## Project Milestones

1. Set up development environment for ESP32-S3 and C3 ✅
2. Implement and test SPIFFS functionality 🚧
3. Integrate NFC tag reader and develop user profile storage
4. Develop local data storage and retrieval system using SPIFFS
5. Implement basic RAG system with cloud API integration
6. Optimize and refine the entire system
7. Final testing and documentation

## Progress

### Milestone 1: Set up development environment for ESP32-S3 and C3 ✅

- Created project structure using PlatformIO
- Updated platformio.ini with correct configurations for both ESP32-S3 (m5stack-stamps3) and ESP32-C3 (lolin_c3_mini) boards
- Removed unnecessary libraries (FastLED, MFRC522) for initial SPIFFS testing

### Milestone 2: Implement and test SPIFFS functionality ✅

- Created main.cpp to test SPIFFS operations:
  - Mounting SPIFFS
  - Writing a test file
  - Reading the test file
  - Listing all files in SPIFFS
- Implemented board-specific pin definitions for LED and button
- Added debug mode for additional information output
- Updated INSTRUCTIONS.md with detailed steps for compiling, uploading, and testing the code on both boards

Next steps:
- Follow the instructions in INSTRUCTIONS.md to:
  - Compile and upload the code to both ESP32-S3 and ESP32-C3 boards
  - Test and verify SPIFFS functionality on both boards
  - Measure and document storage capacity and performance metrics
- Begin planning for NFC tag reader integration (Milestone 3)

## Instructions

For detailed instructions on how to compile, upload, and test the code on both ESP32-S3 and ESP32-C3 boards, please refer to the [INSTRUCTIONS.md](INSTRUCTIONS.md) file.

## Challenges and Learnings

- Initially included unnecessary libraries (FastLED, MFRC522) which caused compilation issues. Removed these for now and will add them back when needed.
- Realized the importance of board-specific configurations in platformio.ini and pin definitions in the code.
- Implemented a debug mode to easily switch between simple and detailed output for troubleshooting.

This README will be updated as we progress through the project, documenting our achievements, challenges, and learnings along the way.