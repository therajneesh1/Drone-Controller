#include <Bluefruit.h>  // Include the Adafruit Bluefruit library

BLEService myService("180F");  // BLE service UUID (Battery Service)
BLECharacteristic myCharacteristic("87654321-4321-4321-4321-abcdefabcdef", BLERead | BLEWrite, 20); // Characteristic UUID

void setup() {
  Serial.begin(115200);  // Initialize serial communication for debugging
  while (!Serial);       // Wait for the serial port to open

  // Initialize Bluefruit LE
  if (!Bluefruit.begin()) {
    Serial.println("Error initializing Bluefruit!");
    while (1);  // Halt the program if initialization fails
  }

  Bluefruit.setTxPower(4);  // Optional: Set BLE TX power
  Bluefruit.setName("RP2040_BLE");  // Set the BLE device name

  // Add service and characteristic to Bluefruit
  myService.addCharacteristic(myCharacteristic);
  Bluefruit.addService(myService);

  // Start advertising BLE service
  Bluefruit.advertise();
  Serial.println("Advertising BLE service...");
}

void loop() {
  Bluefruit.poll();  // Poll BLE events
}
