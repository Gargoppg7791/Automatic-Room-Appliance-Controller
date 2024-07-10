# Automatic Room Appliances Controller Using Arduino and PIR Sensor

## Project Title
Automatic Room Appliances Controller Using Arduino and PIR Sensor

## Problem Statement
Traditional room appliance control systems require manual operation, leading to inefficiencies in energy usage and user inconvenience. There is a need for an automated system that can detect human presence and control appliances accordingly to enhance energy efficiency and user comfort.

## Brief Description
This project involves creating an automatic room appliance controller using an Arduino microcontroller and a Passive Infrared (PIR) sensor. The system will detect human presence and control various electrical appliances like lights, fans, and air conditioners automatically, reducing energy consumption and improving convenience.

## Objective and Scope
**Objective:**
- Develop a system to automate the control of room appliances based on human presence.
- Enhance energy efficiency by ensuring appliances are only active when needed.
- Improve user convenience by reducing the need for manual control.

**Scope:**
- Design and implement a system using Arduino and PIR sensors.
- Integrate the system with common household appliances.
- Ensure reliable detection and response to human presence.
- Test and validate the system's performance in various scenarios.

## Project Contribution
This project enhances energy efficiency by automatically controlling room appliances based on human presence, reducing energy wastage and lowering electricity bills. It provides significant user convenience by enabling hands-free operation and ensuring a comfortable environment. The system contributes to technological advancement in home automation with its scalable and adaptable design. Environmentally, it supports sustainability by decreasing unnecessary energy consumption and promoting sustainable living practices. Additionally, the project offers educational value by providing practical learning opportunities in microcontroller programming and sensor integration. Economically, it presents cost savings through reduced electricity usage and offers an affordable automation solution. Furthermore, it enhances safety by preventing potential fire hazards and can be integrated with security systems for added protection.

## Methodology
1. Design the circuit using Arduino, PIR sensor, and LED (or relay module).
2. Write the Arduino code to control the appliances based on sensor input.
3. Assemble the hardware components.
4. Upload the code to the Arduino.
5. Test the system to ensure it works as expected.
6. Make adjustments to improve performance and reliability.

## Hardware and Software Requirements
**Hardware:**
- Arduino Uno
- PIR Sensor (HC-SR501)
- LED (or relay module for controlling actual appliances)
- Resistor (220 ohms for LED)
- Breadboard and jumper wires

**Software:**
- Arduino IDE

## Technologies
- Arduino Programming
- Sensor Integration
- Home Automation

## Testing Techniques
- Unit testing for individual components.
- Integration testing to ensure all components work together.
- Functional testing to verify the system's behavior under different scenarios.

## Installation and Setup
1. **Assemble the Circuit:**
   - Connect the VCC pin of the PIR sensor to the 5V pin on the Arduino.
   - Connect the GND pin of the PIR sensor to the GND pin on the Arduino.
   - Connect the OUT pin of the PIR sensor to digital pin 2 on the Arduino.
   - Connect the longer leg (anode) of the LED to digital pin 13 on the Arduino through a 220-ohm resistor.
   - Connect the shorter leg (cathode) of the LED to GND on the Arduino.

2. **Upload the Code:**
   - Open the Arduino IDE.
   - Copy and paste the following code into the IDE:

```cpp
// Define the pins
const int pirPin = 2; // PIR sensor pin
const int ledPin = 13; // LED pin (simulating an appliance)
int pirState = LOW; // PIR state
int val = 0; // Variable to store the PIR sensor status

void setup() {
  pinMode(ledPin, OUTPUT); // Set LED pin as output
  pinMode(pirPin, INPUT); // Set PIR pin as input
  Serial.begin(9600); // Initialize serial communication
}

void loop() {
  val = digitalRead(pirPin); // Read the state of the PIR sensor
  if (val == HIGH) { // If motion is detected
    digitalWrite(ledPin, HIGH); // Turn on the LED
    if (pirState == LOW) {
      Serial.println("Motion detected!");
      pirState = HIGH;
    }
  } else {
    digitalWrite(ledPin, LOW); // Turn off the LED
    if (pirState == HIGH) {
      Serial.println("Motion ended!");
      pirState = LOW;
    }
  }
}
