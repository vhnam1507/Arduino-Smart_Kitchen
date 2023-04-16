# **SMART KITCHEN**

An IoT project utilizing the **ARDUINO UNO R3** board.

> "Well, to be honest, I don't think you can replicate my project exactly, and I also don't think you should try to. My code is just for reference, and the hardware issues in this project are just for your reference too. The following instructions will just help you avoid the hassle of starting from scratch when programming IoT."

---

## **1. Introduction**

Welcome to my IoT project **"Smart Kitchen"** which I personally researched and designed. This project **focuses mainly on the automatic fire prevention and extinguishing system in the kitchen** with some simple functions such as automatic fan opening, automatic pump opening, automatic alarm ringing, and more. In addition, users can also control the electrical lighting system through a dashboard **from anywhere as long as there is an Internet connection** *(dashboard provided by Blynk)*.

The project consists of two important components, the ***Arduino Uno R3*** and ***nodeMCU2102 ESP8266***:

- The Arduino board plays the role of processing information received from analog ports connected to sensors, and then generates events to handle specific situations.
- As for the nodeMcu2102 ESP8266, this board manages the kitchen lighting system and also serves as a means to upload information to the dashboard because it is the only component in the project that can connect to the Internet. NodeMcu2102 ESP8266 manages the status of the lights and uploads them to the dashboard, while also receiving information that Arduino Uno R3 synthesizes and transmits.

In this project, I designed **nodeMcu2102 ESP8266** and **Arduino Uno R3** to be **able to communicate with each other** through **SoftwareSerial**.

$\to$ With this project, I hope to contribute to the development of smarter and safer kitchen solutions.

## **2. Installation**

### **2.1 Code**

> Just for reference.

Please follow the steps below to install and set up the code:

1. Connect the [Arduino UNO]() and [NodeMCU2102 ESP 8266]() to your computer.
2. Open the Arduino IDE and select "Arduino UNO" board and the appropriate port from the "Tools" menu.
3. Open the "**Arduino_Program.ino**" file from the downloaded code and upload it to the ***Arduino UNO board.***
4. Open the "**NodeMCU_Program.ino**" file from the downloaded code and upload it to the ***NodeMCU2102 ESP 8266 board***.
5. Connect the gas sensor, flame sensor, DHT sensor, servo motor, buzzer, L298N module, pump motor, fan motor, and LCD display to their respective pins as indicated in the "Arduino_Program.ino" file.
6. Power on the Arduino UNO board and the NodeMCU2102 ESP 8266 board.
7. Install the necessary libraries for the code to work. You will need the following libraries:**"dht.h" and "LiquidCrystal_I2C.h"**. To install the libraries, go to the "*Sketch*" menu, select *"Include Library"*, then select *"Manage Libraries"*. Search for the libraries and click *"Install"*.
8. Connect your device to the "Smart Kitchen" IoT system through a wireless network.
9. Run the code and monitor the output from the sensors on the LCD display and through the serial monitor.

### **2.2 Blynk's Dashboard**

Here's a guide on how to set up your Blynk dashboard to display information from the code:

1. First, You can use **Website or download the Blynk app** on your smartphone or tablet from the App Store or Google Play Store. Once installed, create an account and log in.

2. Create a new project by clicking on the "+" icon **in the top right corner of the screen**. Choose the hardware model you are using and give your project a name.

3. Once your project is created, you'll be taken to the project dashboard. Click on the "+" icon to add a new widget. Choose the type of widget you want to add, such as a gauge, graph, or value display.

4. Configure the widget by giving it a name and selecting the pin that it will be linked to. You can also customize the color and style of the widget.

5. In the **nodeMCU_Program.ino**, i added include the Blynk library and connect to the Blynk server using your **authentication token**. Then, use the *Blynk.virtualWrite()* function to send data to your widgets.

6. Upload the code to your hardware device and open the Blynk app. Make sure your device is connected to the internet and that you have selected the correct project in the app.

7. Your widgets should now display the data that you are sending from code. You can also use the Blynk app to control your hardware device by adding widgets such as buttons and sliders.

## **3. Hardware Setup**

Regarding the hardware, I don't think there will be any imposition on your part. In this project, I have assembled and designed the hardware with two "main" components, which are Arduino UNO R3 and NodeMCU2102 ESP 8266.

- With Arduino UNO R3, I use it to manage the monitoring and explosion prevention system. 
- With NodeMCU2102 ESP 8266, I use it to manage the lighting system and perform information synthesis, communicate with Arduino UNO R3, and transmit/receive data with the server.

In addition, I also use some components to ensure the convenience of the user as well as to ensure the ability to collect information from the environment in the kitchen, to ensure the ability to upgrade and manage, and to optimize the ports of Arduino UNO R3 and NodeMCU2102:

- MQ2 gas sensor module
- DTH11 environmental sensor module
- Fire detection sensor module
- Alarm chip
- Simple motor for making a fan
- SG90 servo
- 8mm Water Pipe
- Mini 120L/H 3V/5V/6V Submersible Pump Motor: Water pump when detecting fire
- L298N module: controls 2 DC motors, which are the submersible pump and the fan
- LCD 1602 Integrated Circuit Board I2C
- LEDs
- Buttons
- IC 74HC595

With these devices, you can build a smart kitchen project for yourself, and of course, these devices will focus on fire prevention and control more than utilities related to kitchen operation.

Anyway, this is just a suggestion, right?

## **4. Contributors**

> （；へ：）Sadly, this IoT project was my first, but I was the only one in the team who actually did anything (LOL). Seriously man, from the research phase to hardware assembly, software programming, dashboard design, testing, and even writing the report, I did everything, even coming up with the project idea. But hey, they helped me make the slides. (¬◡¬)✧

Code: Vũ Hoàng Nam

Hardware: Vũ Hoàng Nam

Testing: Vũ Hoàng Nam

Documenting: Vũ Hoàng Nam

Design: Vũ Hoàng Nam

Translation: Vũ Hoàng Nam

Slides: Bùi Anh Tuấn & Lê Đăng Khoa
