# Off-line Robot

[![NodeMCU](http://visystem.ddns.net:7442/imagenes/nodemcu-logos.png)](https://nodesource.com/products/nsolid)

Мікроконтролерна система управління двигунами автономного робота на базі платформи NodeMCU 1.0 ESP-12E основою якої є мікроконтролер [ESP8266](https://ru.wikipedia.org/wiki/ESP8266)

### Можливості

  - Об'їзд перешкод в автономному режимі;
  - Керування роботом через веб-інтерфейс по Wi-Fi.


Проект розроблений в межах курсової роботи з комп'ютерних систем, автором якої є [Лящинський Петро](https://www.linkedin.com/in/rainbowmrx/), ст. гр. КСМ-32

### Технології

Для розробки Off-line Robot було використано наступні open-source проекти:

* [Arduino IDE](https://www.arduino.cc/) - середовище розробки програм для Arduino і не тільки, на мові програмування, що є підмножиною [C/C++](https://uk.wikipedia.org/wiki/C%2B%2B)
* [Fritzing](http://fritzing.org/home/) - програмне забезпечення з відкритим кодом для віртуального моделювання електричних кіл і схем та електронного обладнання
* [NodeMCU](https://github.com/nodemcu/nodemcu-firmware) - відкрита [IoT](https://ru.wikipedia.org/wiki/%D0%98%D0%BD%D1%82%D0%B5%D1%80%D0%BD%D0%B5%D1%82_%D0%B2%D0%B5%D1%89%D0%B5%D0%B9) платформа 

### Installation

Dillinger requires [Node.js](https://nodejs.org/) v4+ to run.

Install the dependencies and devDependencies and start the server.

```sh
$ cd dillinger
$ npm install -d
$ node app
```

For production environments...

```sh
$ npm install --production
$ npm run predeploy
$ NODE_ENV=production node app
```

### Бібліотеки

Додаткові та власні бібліотеки, які використані для розробки проекту.

| Lib | README |
| ------ | ------ |
| Ultrasonic-HC-SR04 | [JRodrigoTech/Ultrasonic-HC-SR04](https://github.com/JRodrigoTech/Ultrasonic-HC-SR04) |
| Motor | [libs/motor/README.md] [PlGd] |
| Roboton | [plugins/googledrive/README.md] [PlGd] |



### Схема підключення

![Схема підключення](https://bytebucket.org/Rainbow-MRX/off-robot/raw/77597cc638fb3b88a39a59cf9581fa18817b0bb5/fritzing-tpl/off-robot.png)

First Tab:
```sh
$ node app
```

Second Tab:
```sh
$ gulp watch
```

(optional) Third:
```sh
$ karma test
```
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


   [dill]: <https://github.com/joemccann/dillinger>
   [git-repo-url]: <https://github.com/joemccann/dillinger.git>
   [john gruber]: <http://daringfireball.net>
   [df1]: <http://daringfireball.net/projects/markdown/>
   [markdown-it]: <https://github.com/markdown-it/markdown-it>
   [Ace Editor]: <http://ace.ajax.org>
   [node.js]: <http://nodejs.org>
   [Twitter Bootstrap]: <http://twitter.github.com/bootstrap/>
   [jQuery]: <http://jquery.com>
   [@tjholowaychuk]: <http://twitter.com/tjholowaychuk>
   [express]: <http://expressjs.com>
   [AngularJS]: <http://angularjs.org>
   [Gulp]: <http://gulpjs.com>

   [PlDb]: <https://github.com/joemccann/dillinger/tree/master/plugins/dropbox/README.md>
   [PlGh]: <https://github.com/joemccann/dillinger/tree/master/plugins/github/README.md>
   [PlGd]: <https://github.com/joemccann/dillinger/tree/master/plugins/googledrive/README.md>
   [PlOd]: <https://github.com/joemccann/dillinger/tree/master/plugins/onedrive/README.md>
   [PlMe]: <https://github.com/joemccann/dillinger/tree/master/plugins/medium/README.md>
   [PlGa]: <https://github.com/RahulHP/dillinger/blob/master/plugins/googleanalytics/README.md>
