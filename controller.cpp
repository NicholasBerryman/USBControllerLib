#include "controller.h"
#include <Arduino.h>

float Controller::getAxis(int ID){
  while (axes.getLength() <= ID){
    axes.add(0.0f);
  }
  return axes.get(ID);
}
bool Controller::getButton(int ID){
  while (buttons.getLength() <= ID){
    buttons.add(0.0f);
  }
  return buttons.get(ID);
}
float Controller::getPOV(int ID){
  while (POVs.getLength() <= ID){
    POVs.add(0.0f);
  }
  return POVs.get(ID);
}

void Controller::setAxis(int ID, float value){
  while (axes.getLength() <= ID){
    axes.add(0.0f);
  }
  axes.get(ID) = value;
}
void Controller::setButton(int ID, bool on){
  while (buttons.getLength() <= ID){
    buttons.add(0.0f);
  }
  buttons.get(ID) = on;
}
void Controller::setPOV(int ID, float value){
  while (POVs.getLength() <= ID){
    POVs.add(0.0f);
  }
  POVs.get(ID) = value;
}
