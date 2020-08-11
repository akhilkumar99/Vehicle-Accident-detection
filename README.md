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
* These sensors output data is collected and sent to the cloud i.e., an open source cloud for data storage and analysis namely –THINGSPEAK. At ThingSpeak these sensors data are analysed and a graph is plotted and vehicle performance analysis is done monthly and weekly depending on the requirement. By this when the vehicle needs service can be estimated and a tweet can be sent through twitter(only if the details of one's twitter account are shared in the thingspeak's channel settings).
 
This project can be extended with the help of GSM and GPS modules to give the precise location of the vehicle in order to detect any accident.

&nbsp;
> ## Connection of Arduino Uno to ESP8266
![alt text](https://labbh.files.wordpress.com/2016/05/firmware.png?w=1108)
> ## Pinout of ESP8266
![alt text](https://encrypted-tbn0.gstatic.com/images?q=tbn%3AANd9GcTtBJ7LjUMHzgehvLo43ppoZvt1vRH7hb222Q&usqp=CAU)

We can add upto 18 different digital sensors to a single arduino controller at once(with the help of an I2C module), and we can add upto 6 analog sensors. One can add any valid sensor available to him/her to this project to make it a unique project, because the functionality of the ESP8266 and arduino remains same irrespective of their problem statement.

&nbsp;
> ## Small tutorial to set up a ThingSpeak Account and to upload the sensor data

