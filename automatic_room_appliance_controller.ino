// automatic_room_appliance_controller.ino
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

