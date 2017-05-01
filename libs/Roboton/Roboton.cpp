#ifndef Roboton_cpp
#define Roboton_cpp

#include "Roboton.h"

Roboton::Roboton() {
    
}
Roboton::Roboton(MOTOR* fb, MOTOR* rl) {
    if (fb) {
        MOTOR_FB.in1 = fb->in1;
        MOTOR_FB.in2 = fb->in2;
        MOTOR_FB.enable = fb->enable;
        set_pins(fb);
    }
    if (rl) {
        MOTOR_RL.in1 = rl->in1;
        MOTOR_RL.in2 = rl->in2;
        MOTOR_RL.enable = rl->enable;
        set_pins(rl);
    }
}
void Roboton::forward(int speed) {
    m_forward(&MOTOR_FB, speed);
}
void Roboton::back(int speed) {
    m_back(&MOTOR_FB, speed);
}
void Roboton::right() {
    m_right(&MOTOR_RL);
}
void Roboton::left() {
    m_left(&MOTOR_RL);
}
void Roboton::stop_mv(MOTOR* m) {
    m_stop_mv(m);
}
void Roboton::setpwm(int pwm) {
    PWMRANGE_R = pwm;
}
void Roboton::set_pins(MOTOR* m) {
    if (m) {
        pinMode(m->in1, OUTPUT);
        pinMode(m->in2, OUTPUT);
        pinMode(m->enable, OUTPUT);
    }
}
void Roboton::m_forward(MOTOR* m, int speed) {
    if (m) {
        digitalWrite(m->in1, HIGH);
		digitalWrite(m->in2, LOW);
		analogWrite(m->enable, speed);
    }
}
void Roboton::m_back(MOTOR* m, int speed) {
    digitalWrite(m->in1, LOW);
	digitalWrite(m->in2, HIGH);
	analogWrite(m->enable, speed);
}
void Roboton::m_right(MOTOR* m) {
    digitalWrite(m->in1, HIGH);
	digitalWrite(m->in2, LOW);
	analogWrite(m->enable, PWMRANGE);
}
void Roboton::m_left(MOTOR* m) {
    digitalWrite(m->in1, LOW);
	digitalWrite(m->in2, HIGH);
	analogWrite(m->enable, PWMRANGE);
}
void Roboton::m_stop_mv(MOTOR* m) {
    analogWrite(m->enable, 0);
}

#endif