#include <Roboton.h>
#include <Ultrasonic.h>
#include <Ticker.h>

#define DISTANCE_RANGE 30
#define SIZE_BUFF_D 3

Ultrasonic leftHC(12, 13);
Ultrasonic centerHC(15, 3);
Ultrasonic rightHC(9, 10);

MOTOR MOTOR_FRWB = {16, 4 ,5};
MOTOR MOTOR_RGHL = {2, 14, 0};
Roboton robot(&MOTOR_FRWB, &MOTOR_RGHL);

uint8_t distance[SIZE_BUFF_D];
uint16_t prevMillis = 0;
uint16_t currentMillis = 0;
Ticker tc_d;
Ticker tc_c;
Ticker tc_l;
Ticker tc_r;

void setup() {
    tc_d.attach_ms(15, getDistance);
    tc_c.attach_ms(27, checkCenter);
    tc_r.attach_ms(34, checkRight);
    tc_l.attach_ms(41, checkLeft);
}
void loop() {
    
}
void getDistance() {
    distance[0] = leftHC.Ranging(CM);
    distance[1] = centerHC.Ranging(CM);
    distance[2] = rightHC.Ranging(CM);
}
void checkLeft() {
    if (distance[0] < DISTANCE_RANGE) {
        robot.right();
    } 
    else {
        robot.stop_mv(&MOTOR_RGHL);
    }
}
void checkCenter() {
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
    if (distance[0] < DISTANCE_RANGE && distance[2] < DISTANCE_RANGE) {
        robot.stop_mv(&MOTOR_RGHL);
    }
}
void checkRight() {
    if (distance[2] < DISTANCE_RANGE) {
        robot.left();
    } 
    else {
        robot.stop_mv(&MOTOR_RGHL);
    }
}
