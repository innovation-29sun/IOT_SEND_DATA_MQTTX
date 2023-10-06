# IOT_SEND_DATA_MQTTX
ESP32 Light Sensor Value and Some Randam Humidity Data 

This involves an ESP32 microcontroller, an LDR sensor, and a 100K ohms resistor to measure light intensity and simulate humidity data. The data is sent to an MQTT broker every 30 seconds.
Table of Contents

    Introduction
    Components Needed
    Hardware Setup
    Software Programming
    Sending Data
    Repository Structure
    How to Use


Introduction

This aims to demonstrate how to measure light intensity using an LDR sensor, simulate humidity data, and send this information to an MQTT broker using an ESP32 microcontroller.
Components Needed

    ESP32 microcontroller
    LDR sensor
    100K ohms resistor
    MQTT Broker (broker.emqx.io)

Hardware Setup

Connect the components as follows:

    Connect one end of the LDR sensor to 3.3V on the ESP32.
    Connect the other end of the LDR sensor to a point between the LDR and the 100K ohms resistor.
    Connect one end of the 100K ohms resistor to the same point as the LDR's other end.
    Connect the other end of the 100K ohms resistor to the GND on the ESP32.
    Connect a wire from the point between the LDR and the resistor to GPIO pin 34 on the ESP32.

Software Programming

The code is structured as follows:

  This is the Arduino sketch file. It reads the analog value from pin 34, maps it to a range of 0-100, generates a random humidity value, and sends the data to the MQTT broker in JSON format.

Sending Data

The ESP32 sends the data to the MQTT broker every 30 seconds. The JSON payload format is as follows:

json
{
  "deviceId": "1233-12as-ty12",
  "data": {
    "light_value_in_%": 87,
    "humidity": 47
  },
  "tags": [
    "light_sensor"
  ]
}


How to Use

    Set up the hardware as per the provided instructions.
    Upload the code in src/main.ino to your ESP32 microcontroller.
    Ensure that your ESP32 is connected to a power source.
    The ESP32 will start sending data to the MQTT broker.

Video in Drive link :https://drive.google.com/file/d/1cXk9LMG5fBnn9SbI3dE62LAJb6CEszJ6/view?usp=drive_link
![image](https://github.com/innovation-29sun/IOT_SEND_DATA_MQTTX/assets/84526146/97c68422-a696-47ed-b0f7-7d7861c73076)

