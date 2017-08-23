# Stand-alone Robot Chappie

[![NodeMCU](http://docs.thinger.io/arduino/assets/nodemcu.png)](https://nodesource.com/products/nsolid)

Microcontroller autonomous robot engine management system based on the platform NodeMCU 1.0 ESP-12E (based on the microcontroller [ESP8266](https://ru.wikipedia.org/wiki/ESP8266)).

## Features

  - Bypass obstacles by yourself;  
  - Manage the robot through the web interface over Wi-Fi.


The project is designed as a problem of course work on computer systems, the author of which is [Liashchynskyi Petro](https://www.linkedin.com/in/rainbowmrx/).

## Technologies

The following open-source libraries were used to develop the project:

* [Arduino IDE](https://www.arduino.cc/) - The open-source Arduino Software (IDE) makes it easy to write code and upload it to the board. It runs on Windows, Mac OS X, and Linux.(https://uk.wikipedia.org/wiki/C%2B%2B)
* [Fritzing](http://fritzing.org/home/) - Open source software for virtual simulation of electric circuits and electronic equipment.
* [NodeMCU](https://github.com/nodemcu/nodemcu-firmware) - Open [IoT](https://ru.wikipedia.org/wiki/%D0%98%D0%BD%D1%82%D0%B5%D1%80%D0%BD%D0%B5%D1%82_%D0%B2%D0%B5%D1%89%D0%B5%D0%B9) platform. 

## Libraries

Additional and own libraries that are used to design a project.

| LIBRARY | LINK |
| ------ | ------ |
| Ultrasonic-HC-SR04 | [JRodrigoTech/Ultrasonic-HC-SR04](https://github.com/JRodrigoTech/Ultrasonic-HC-SR04) |
| Roboton | [libs/Roboton] [Roboton] |
| Ticker | [Arduino/Ticker] [Ticker] |

> These libraries need to be installed in folder
> **%UserDocuments%/Arduino/libraries**
> You can read more about installing libraries **[here](https://www.arduino.cc/en/Guide/Libraries)**.

Using **Windows CMD** (Win+R ---> cmd ---> Enter ) you can do this:
```sh
$ xcopy Path:\To\Project\Libs\Directory Documents\Arduino\libraries /S
```

## Used components


| Component | Quantity |
| ------ | ------ |
| NodeMCU 1.0 ESP-12E | 1 |
| DC Motor | 2 | 
| L293D | 1 |
| LM317 | 2 |
| HC-SR04 | 3 |
| Батарея 9В | 1 |
| Резистор 120 Ом | 2 |
| Резистор 360 Ом | 2 |

Since the NodeMCU can supply voltage only **3.3 volts**, and to power the electrical components requires **5 volts** -- then I **[calculated](http://cxem.net/calc/lm317_calc.php)** the voltage regulator based on [LM317](http://www.ti.com/lit/ds/symlink/lm317.pdf). 

![LM317 Voltage Regulator](http://cxem.net/calc_tmp/lm317calc/2b3686b7389d6545f0b080dad0a4a9bf.png)


## Connection scheme

[![Схема підключення](http://i.imgur.com/q7xibg6.png)](https://drive.google.com/file/d/0B6GGJ0EN8hsVNzBRTG9VN2Z3MUE/view)

[![Схема підключення](http://i.imgur.com/vxpdzoQ.png)](https://drive.google.com/file/d/0B6GGJ0EN8hsVZGFOZHQ3Q2RZVkE/view)

***
**Rear engine**:

  - Out1
  - Out2

**Front engine**:

  - Out3
  - Out4
  
**L293D:**

 - Input 1 -> *GPIO16* -> (D0)
 - Input 2 -> *GPIO4* -> (D2)
 - Enable 1 -> *GPIO5* -> (D1)
 - Input 3 -> *GPIO2* -> (D4)
 - Input 4 -> *GPIO14* -> (D5)
 - Enable 2 -> *GPIO0* -> (D3)

**HC-SR04**:

 - Trig Left -> *GPIO12* -> (D6)
 - Echo Left -> *GPIO13* -> (D7)
 - Trig Center -> *GPIO15* -> (D8)
 - Echo Center -> *GPIO3* -> (RX)
 - Trig Right -> *GPIO9* -> (SD2)
 - Echo Right -> *GPIO10* -> (SD3)



[![Model](http://i.imgur.com/DEJvBMN.png)](https://drive.google.com/file/d/0B6GGJ0EN8hsVOHpucU82UTZmeEU/view?usp=sharing)

## Firmware

Before the first start, you need to open **off-robot.ino** and edit the following lines:

```c
const char* ssid = "YOUR_SSID"; // Wi-Fi name
const char* password = "YOUR_PASSWD"; // PASSWORD
```
After that, save the file and flash the NodeMCU. How to do that, as well as how to add a card to the Arduino IDE is written **[here](http://www.instructables.com/id/Programming-ESP8266-ESP-12E-NodeMCU-Using-Arduino-/)**.




[//]: # (These are reference links used in the body of this note and get stripped out when the markdown processor does its job. There is no need to format nicely because it shouldn't be seen. Thanks SO - http://stackoverflow.com/questions/4823468/store-comments-in-markdown-syntax)


   [Roboton]: <https://github.com/liashchynskyi/chappie/tree/master/libs/Roboton>
   [Ticker]: <https://github.com/esp8266/Arduino/tree/master/libraries/Ticker>


# License

This project is licensed under the GPL-3.0. For more see **LICENSE** file.
