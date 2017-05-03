#include <Roboton.h>
#include <Ultrasonic.h>
#include <Ticker.h>
#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>
#include <ESP8266mDNS.h>

#define DISTANCE_RANGE 30
#define SIZE_BUFF_D 3

Ultrasonic leftHC(12, 13);
Ultrasonic centerHC(15, 3);
Ultrasonic rightHC(9, 10);

MOTOR MOTOR_FRWB = {16, 4 ,5};
MOTOR MOTOR_RGHL = {2, 14, 0};
Roboton robot(&MOTOR_FRWB, &MOTOR_RGHL);

bool offline = true;
uint8_t distance[SIZE_BUFF_D];
uint16_t prevMillis = 0;
uint16_t currentMillis = 0;

String webPage = "\
<style>\
a {\
  text-decoration: none;\
  font-size: 24px;\
}\
</style>\
<h1>Offline Robot</h1>\
<br>\
<button id=\"forward\"><a href=\"forward\">Forward</a></button>\
<button id=\"back\"><a href=\"back\">Back</a></button>\
<button id=\"right\"><a href=\"right\">Right</a></button>\
<button id=\"left\"><a href=\"left\">Left</a></button>\
<button id=\"stop\"><a href=\"stop\">Stop</a></button>\
<br>\
<br>\
<center><h6></h6></center>\
<script>\
var button = document.getElementsByTagName(\"button\");\
var h = document.querySelector(\"h6\");\
 for (var i = 0; i < button.length; i++)\
 {\
   (function(j){\
     button[j].addEventListener('click', function(e){\
      e.preventDefault();\ 
      var xhr = new XMLHttpRequest();\
      var url = button[j].id;\
      xhr.open('GET', \"'/' + url\", true);\
      xhr.onload = function(e){\
        h.innerHTML = xhr.responseText;\
      };\
      xhr.send();\  
     });\
   })(i);\
 }\
</script>\
";

Ticker tc_d;
Ticker tc_c;
Ticker tc_s;

const char* ssid = "YOUR_SSID";
const char* password = "YOUR_PASSWD";

ESP8266WebServer server(80);
MDNSResponder mdns;

void setup() {
    tc_d.attach_ms(12, getDistance);
    tc_c.attach_ms(17, checkCenter);
    tc_s.attach_ms(22, checkSide);
    WiFi.begin(ssid, password);
    while (WiFi.status() != WL_CONNECTED) {
        Serial.print("NOT CONNECTED YET");
    }
    Serial.begin(115200);
    Serial.print("Connected to ");
    Serial.println(ssid);
    Serial.print("IP address: ");
    Serial.println(WiFi.localIP());
    if (mdns.begin("esp8266", WiFi.localIP())) {
        Serial.println("MDNS responder started");
    }
    server.on("/", [](){
        server.send(200, "text/html", webPage);
        offline = false;
    });
    server.on("/forward", [](){
        server.send(200, "text/html", "Robot is moving forward");
        robot.stop_mv(&MOTOR_FRWB);
        robot.forward();
    });
    server.on("/back", [](){
        server.send(200, "text/html", "Robot is moving back");
        robot.stop_mv(&MOTOR_FRWB);
        robot.back();
    });
    server.on("/right", [](){
        server.send(200, "text/html", "Robot is turning right");
        robot.right();
    });
    server.on("/left", [](){
        server.send(200, "text/html", "Robot is turning left");
        robot.left();
    });
    server.on("/stop", [](){
        server.send(200, "text/html", "Robot stops");
        robot.stop_mv(&MOTOR_FRWB);
        robot.stop_mv(&MOTOR_RGHL);
    });
    server.begin();
    Serial.println("HTTP server started");

}
void loop() {
    server.handleClient();
}
void getDistance() {
    if (offline)
    {
        distance[0] = leftHC.Ranging(CM);
        distance[1] = centerHC.Ranging(CM);
        distance[2] = rightHC.Ranging(CM);
    } else robot.stop_mv(&MOTOR_FRWB);
}
void checkSide() {
    if (offline)
    {
        if (distance[0] < DISTANCE_RANGE && distance[2] > DISTANCE_RANGE) {
            robot.right();
        } 
        else if (distance[2] < DISTANCE_RANGE && distance[0] > DISTANCE_RANGE) {
            robot.left();
        } 
        else {
            robot.stop_mv(&MOTOR_RGHL);
        }
    } else robot.stop_mv(&MOTOR_RGHL);
}
void checkCenter() {
    if (offline)
    {
        if (distance[1] < DISTANCE_RANGE) {
        robot.stop_mv(&MOTOR_FRWB);
        robot.back();
        if ((currentMillis = millis()) - prevMillis > 200) {
            prevMillis = currentMillis;
            robot.stop_mv(&MOTOR_FRWB);
        }
        } 
        else {
            robot.forward();
        }
    }
}
