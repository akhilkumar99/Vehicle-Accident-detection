# Vehicle Accident Detection and Monitoring using Arduino UNO and ESP8266
&nbsp;

> ## Introduction

Yearly the road accident rate increases, and drivers are to blame as well as the road or weather conditions. Bad Vehicle drivers can't be helped, but the vehicle can be made smart enough to alert the ambulance about the location
We can also monitor the status of the vehicle and one can view the changes in the sensor data accordingly on the ThingSpeak Cloud in the Field section.

&nbsp;
> ## Components Required
* Arduino Uno
* Wi-Fi module(ESP8266)
* Vibration Sensor
* Temperature Sensor(LM35)
* Jumper Wires (Male-to-Male and Male-to-Female)
* Breadboard or PCB
* Few Red LED's and Green LED's

&nbsp;
> ## Working of the System
* The Internet of Things (IoT) is a network of electronic and physical devices, vehicles, sensors which enables them to collect and exchange data.
* Our prototype consists of a Vibration sensor, temperature sensor and any additional sensor (like accelerometer) attached to a vehicle. Vehicle consists of a microcontroller (Arduino) and a Wi-Fi module(ESP8266).
* These sensors output data is collected and sent to the cloud i.e., an open source cloud for data storage and analysis namely –THINGSPEAK. At ThingSpeak these sensors data are analysed and a graph is plotted and vehicle performance analysis is done monthly and weekly depending on the requirement. By this when the vehicle needs service can be estimated and a tweet can be sent through twitter.
 
This project can be extended with the help of GSM and GPS modules to give the precise location of the vehicle in order to detect any accident.

&nbsp;
> ## Connection of Arduino Uno to ESP8266
![alt text](https://hackster.imgix.net/uploads/attachments/533124/circuit_jRmiSWSOwQ.jpg?auto=compress%2Cformat&w=1280&h=960&fit=max)


