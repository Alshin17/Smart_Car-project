#include <Ultrasonic.h>
#include <SoftwareSerial.h>

// Pin Definitions
const int trigPin = 12;
const int echoPin = 13;
const int vibrationPin = 2;
const int motorPin1 = 3; // L298 IN1
const int motorPin2 = 4; // L298 IN2
const int motorPin3 = 5; // L298 IN3
const int motorPin4 = 6; // L298 IN4

// Ultrasonic sensor setup
Ultrasonic ultrasonic(trigPin, echoPin);

// GSM Module setup
SoftwareSerial GSM(8, 9); // RX, TX

void setup() {
  Serial.begin(9600);
  GSM.begin(9600);
  pinMode(vibrationPin, INPUT);
  pinMode(motorPin1, OUTPUT);
  pinMode(motorPin2, OUTPUT);
  pinMode(motorPin3, OUTPUT);
  pinMode(motorPin4, OUTPUT);
}

void loop() {
  int distance = ultrasonic.Ranging(CM);
  Serial.print("Distance: ");
  Serial.println(distance);

  if (distance < 30) {
    navigateObstacle(distance);
  } else {
    moveForward(); // Move forward if no obstacles are detected
  }
  
  int vibrationValue = digitalRead(vibrationPin);
  if (vibrationValue == HIGH) {
    sendAccidentAlert();
    delay(10000); // Wait for 10 seconds before checking again
  }
}

void moveForward() {
  digitalWrite(motorPin1, HIGH); // Move forward
  digitalWrite(motorPin2, LOW);
  digitalWrite(motorPin3, HIGH);
  digitalWrite(motorPin4, LOW);
}

void stop() {
  digitalWrite(motorPin1, LOW); // Stop the motors
  digitalWrite(motorPin2, LOW);
  digitalWrite(motorPin3, LOW);
  digitalWrite(motorPin4, LOW);
}

void navigateObstacle(int distance) {
  stop(); // Stop the car when an obstacle is detected
  delay(500); // Pause for half a second to stabilize

  if (distance < 20) {
    reverse();
    delay(1000); // Reverse for 1 second
  } else {
    if (shouldTurnLeft()) {
      turnLeft();
      delay(500); // Turn left for half a second
    } else {
      turnRight();
      delay(500); // Turn right for half a second
    }
  }

  moveForward(); // After avoiding the obstacle, move forward again
}

void turnRight() {
  digitalWrite(motorPin1, LOW); // Turn right
  digitalWrite(motorPin2, HIGH);
  digitalWrite(motorPin3, HIGH);
  digitalWrite(motorPin4, LOW);
}

void turnLeft() {
  digitalWrite(motorPin1, HIGH); // Turn left
  digitalWrite(motorPin2, LOW);
  digitalWrite(motorPin3, LOW);
  digitalWrite(motorPin4, HIGH);
}

void reverse() {
  digitalWrite(motorPin1, LOW); // Reverse
  digitalWrite(motorPin2, HIGH);
  digitalWrite(motorPin3, LOW);
  digitalWrite(motorPin4, HIGH);
}

bool shouldTurnLeft() {
  return random(0, 2) == 0; // 50% chance to turn left or right
}

void sendAccidentAlert() {
  GSM.print("AT+CMGS=\"+1234567890\"\r"); // Replace with the emergency contact number
  delay(100);
  GSM.print("Accident detected! Immediate assistance needed.");
  delay(100);
  GSM.write(26); // ASCII code for CTRL+Z to send SMS
}
