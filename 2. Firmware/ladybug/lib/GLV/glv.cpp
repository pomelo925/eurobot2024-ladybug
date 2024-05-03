#include <glv.h>
#include <Arduino.h>

GLV Glv;

bool GLV::get_glv_l(){
  return digitalRead(_GLV_PIN_L);
}

bool GLV::get_glv_r(){
  return digitalRead(_GLV_PIN_R);
}


void GLV::setup() {
  pinMode(_GLV_PIN_R, INPUT);
  pinMode(_GLV_PIN_L, INPUT);
}

void GLV::read() {
  Serial.print("Right: ");
  Serial.print(digitalRead(_GLV_PIN_R));
  Serial.print(" Left: ");
  Serial.println(digitalRead(_GLV_PIN_L));
}