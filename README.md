# **SMART KITCHEN**

An IoT project utilizing the **ARDUINO UNO R3** board.

---

## **1. Introduction**

Welcome to my IoT project **"Smart Kitchen"** which I personally researched and designed. This project **focuses mainly on the automatic fire prevention and extinguishing system in the kitchen** with some simple functions such as automatic fan opening, automatic pump opening, automatic alarm ringing, and more. In addition, users can also control the electrical lighting system through a dashboard **from anywhere as long as there is an Internet connection** *(dashboard provided by Blynk)*.

The project consists of two important components, the ***Arduino Uno R3*** and ***nodeMCU2102 ESP8266***:

- The Arduino board plays the role of processing information received from analog ports connected to sensors, and then generates events to handle specific situations.
- As for the nodeMcu2102 ESP8266, this board manages the kitchen lighting system and also serves as a means to upload information to the dashboard because it is the only component in the project that can connect to the Internet. NodeMcu2102 ESP8266 manages the status of the lights and uploads them to the dashboard, while also receiving information that Arduino Uno R3 synthesizes and transmits.

In this project, I designed **nodeMcu2102 ESP8266** and **Arduino Uno R3** to be **able to communicate with each other** through **SoftwareSerial**.

$\to$ With this project, I hope to contribute to the development of smarter and safer kitchen solutions.

## **2. Installation**

## **3. Hardware Setup**

## **4. Usage**

## **5. Code Organization**

## **6. Contributors**

## **7. Issues**
