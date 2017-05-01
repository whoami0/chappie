#ifndef Roboton_h
#define Roboton_h

#if defined(ARDUINO) && ARDUINO >= 100
  #include "Arduino.h"
#else
  #include "WProgram.h"
#endif 

struct MOTOR {
    uint8_t in1;
    uint8_t in2;
    int enable;
};

class Roboton {
    public:
        Roboton();
        Roboton(MOTOR* fb, MOTOR* rl);
        void forward(int speed = 1023);
        void back(int speed = 1023);
        void right();
        void left();
        void stop_mv(MOTOR* m);
        void setpwm(int pwm);
    private:
        void set_pins(MOTOR* m);
        void m_forward(MOTOR* m, int speed = 1023);
        void m_back(MOTOR* m, int speed = 1023);
        void m_right(MOTOR* m);
        void m_left(MOTOR* m);
        void m_stop_mv(MOTOR* m);
        MOTOR MOTOR_FB;
        MOTOR MOTOR_RL;
        int PWMRANGE_R = 1023;
};

#endif