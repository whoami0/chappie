# Offline Robot

[![NodeMCU](http://visystem.ddns.net:7442/imagenes/nodemcu-logos.png)](https://nodesource.com/products/nsolid)

Мікроконтролерна система управління двигунами автономного робота на базі платформи NodeMCU 1.0 ESP-12E основою якої є мікроконтролер [ESP8266](https://ru.wikipedia.org/wiki/ESP8266)

## Можливості

  - Об'їзд перешкод в автономному режимі;
  - Керування роботом через веб-інтерфейс по Wi-Fi.


Проект розроблений в межах курсової роботи з комп'ютерних систем, автором якої є [Лящинський Петро](https://www.linkedin.com/in/rainbowmrx/), ст. гр. КСМ-32

## Технології

Для розробки Offline Robot було використано наступні open-source проекти:

* [Arduino IDE](https://www.arduino.cc/) - середовище розробки програм для Arduino і не тільки, на мові програмування, що є підмножиною [C/C++](https://uk.wikipedia.org/wiki/C%2B%2B)
* [Fritzing](http://fritzing.org/home/) - програмне забезпечення з відкритим кодом для віртуального моделювання електричних кіл і схем та електронного обладнання
* [NodeMCU](https://github.com/nodemcu/nodemcu-firmware) - відкрита [IoT](https://ru.wikipedia.org/wiki/%D0%98%D0%BD%D1%82%D0%B5%D1%80%D0%BD%D0%B5%D1%82_%D0%B2%D0%B5%D1%89%D0%B5%D0%B9) платформа 

## Бібліотеки

Додаткові та власні бібліотеки, які використані для розробки проекту.

| LIBRARY | LINK |
| ------ | ------ |
| Ultrasonic-HC-SR04 | [JRodrigoTech/Ultrasonic-HC-SR04](https://github.com/JRodrigoTech/Ultrasonic-HC-SR04) |
| Roboton | [libs/Roboton] [Roboton] |
| TickerScheduler | [libs/TickerScheduler] [Ticker] |

> Бібліотеки потрібно встановлювати у папку
> %UserDocuments%/Arduino/libraries
> Детальніше про встановлення бібліотек можна прочитати [тут](http://arduino.ua/ru/guide/Libraries).

З допомогою **Windows CMD** (Win+R ---> cmd ) це можна зробити наступним чином:
```sh
$ xcopy Path:\To\Project\Libs\Directory Documents\Arduino\libraries /S
```

## Схема підключення

![Схема підключення](https://bytebucket.org/Rainbow-MRX/off-robot/raw/77597cc638fb3b88a39a59cf9581fa18817b0bb5/fritzing-tpl/off-robot.png)
***
**Задній двигун**:

  - Out1
  - Out2

**Передній двигун**:

  - Out3
  - Out4
***
**L293D:**

 - Input 1 -> *GPIO16* -> (D0)
 - Input 2 -> *GPIO4* -> (D2)
 - Enable 1 -> *GPIO5* -> (D1)
 - Input 3 -> *GPIO2* -> (D4)
 - Input 4 -> *GPIO14* -> (D5)
 - Enable 2 -> *GPIO0* -> (D3)
***
**HC-SR04**:

 - Trig Left -> *GPIO12* -> (D6)
 - Echo Left -> *GPIO13* -> (D7)
 - Trig Center -> *GPIO15* -> (D8)
 - Echo Center -> *GPIO3* -> (RX)
 - Trig Right -> *GPIO9* -> (SD2)
 - Echo Right -> *GPIO10* -> (SD3)

Елементи використані у схемі:

   1. **NodeMCU 1.0 ESP-12E** - 1 шт.
   2. **DC Motor** - 2 шт.
   3. **L293D** - 1 шт.
   4. **LM317** - 2 шт.
   5. **HC-SR04** - 3 шт.
   6. **Батарея 9В** - 1 шт.
   7. **Резистор 120Ом** - 2 шт.
   8. **Резистор 360Ом** - 2 шт.

## Перший запуск

Перед першим запуском потрібно відкрити файл **off-robot.ino** та відредагувати наступні стрічки:

```c
const char* ssid = "YOUR_SSID";
const char* password = "YOUR_PASSWD";
```
Після чого зберегти файл і прошити плату NodeMCU.

#### Building for source
For production release:
```sh
$ gulp build --prod
```
Generating pre-built zip archives for distribution:
```sh
$ gulp build dist --prod
```
### Docker
Dillinger is very easy to install and deploy in a Docker container.

By default, the Docker will expose port 80, so change this within the Dockerfile if necessary. When ready, simply use the Dockerfile to build the image.

```sh
cd dillinger
docker build -t joemccann/dillinger:${package.json.version}
```
This will create the dillinger image and pull in the necessary dependencies. Be sure to swap out `${package.json.version}` with the actual version of Dillinger.

Once done, run the Docker image and map the port to whatever you wish on your host. In this example, we simply map port 8000 of the host to port 80 of the Docker (or whatever port was exposed in the Dockerfile):

```sh
docker run -d -p 8000:8080 --restart="always" <youruser>/dillinger:${package.json.version}
```

Verify the deployment by navigating to your server address in your preferred browser.

```sh
127.0.0.1:8000
```

#### Kubernetes + Google Cloud

See [KUBERNETES.md](https://github.com/joemccann/dillinger/blob/master/KUBERNETES.md)


### Todos

 - Write MOAR Tests
 - Add Night Mode

License
----

MIT


**Free Software, Hell Yeah!**

[//]: # (These are reference links used in the body of this note and get stripped out when the markdown processor does its job. There is no need to format nicely because it shouldn't be seen. Thanks SO - http://stackoverflow.com/questions/4823468/store-comments-in-markdown-syntax)


   [Roboton]: <https://bitbucket.org/Rainbow-MRX/off-robot/src//libs/Roboton/?at=master>
   [Ticker]: <https://github.com/Toshik/TickerScheduler>

