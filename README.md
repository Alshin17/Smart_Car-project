## Smart Car Automation Project Using Arduino

**Overview**
This project builds a smart car automation system using Arduino for autonomous navigation, obstacle avoidance, and accident detection. It uses ultrasonic sensors for detecting obstacles, a GSM module for sending emergency alerts, and a vibration sensor to detect collisions.

## **Programming Language Used**
**C/C++ (Arduino IDE)**: The code is written using the Arduino programming language, which is based on C/C++.

## **Components Used**

**Arduino Uno**: Main microcontroller for controlling the system.

**Ultrasonic Sensor**: Detects obstacles and calculates the distance.

**DC Motors and L298 Motor Driver**: Controls the wheels for movement and obstacle avoidance.

**GSM Module (SIM800)**: Sends SMS alerts to a predefined contact in emergencies.

**Vibration Sensor**: Detects collisions or accidents.

**Battery Pack:** Powers the car and all modules.

## Working Principle
**Obstacle Detection and Avoidance:**

The ultrasonic sensor calculates the distance to objects.

If an obstacle is detected within 30 cm, the car stops and decides whether to turn left, right, or reverse.
Navigation:

The car moves forward when no obstacles are detected. It decides whether to turn or reverse based on obstacle proximity.

**Accident Detection and Emergency Alert:**

The vibration sensor detects collisions.

When an accident is detected, the GSM module sends an SMS alert to a predefined emergency contact.

**Wiring and Pin Connections**

**Ultrasonic Sensor:**

Trig Pin: Digital Pin 12.

Echo Pin: Digital Pin 13.

**Vibration Sensor:** 

Digital Pin 2.

**Motor Driver (L298):**

Motor 1 (IN1 & IN2): Digital Pins 3 & 4.

Motor 2 (IN3 & IN4): Digital Pins 5 & 6.

**GSM Module:**

RX Pin: Digital Pin 8.

TX Pin: Digital Pin 9.

## How to Run the Project

**Connect the Components:**

1. Wire the sensors, motors, and GSM module as per the pin connections above.
   
2. **Upload the Code:** Use the Arduino IDE to upload the code.
   
3. **Power the System:** Connect the battery pack securely.
   
4. **Test Obstacle Avoidance:** Test with obstacles to verify detection and avoidance.
   
5. **Test Accident Detection:** Simulate a vibration to test the GSM alert system.
