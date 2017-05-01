#include <Roboton.h>
#include <Ultrasonic.h>
#include <TickerScheduler.h>

#define DISTANCE_RANGE 30
#define SIZE_BUFF_D 3

Ultrasonic leftHC(12, 13);
Ultrasonic centerHC(15, 3);
Ultrasonic rightHC(9, 10);

MOTOR MOTOR_FRWB = {16, 4 ,5};
MOTOR MOTOR_RGHL = {2, 14, 0};
Roboton robot(&MOTOR_FRWB, &MOTOR_RGHL);

uint8_t distance[SIZE_BUFF_D];



void setup() {
    
}
void loop() {
  distance[0] = leftHC.Ranging(CM);
  distance[1] = centerHC.Ranging(CM);
  distance[2] = rightHC.Ranging(CM);
 

}
