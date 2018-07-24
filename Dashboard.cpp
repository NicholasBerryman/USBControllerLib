#include "Dashboard.h"

Vector<Controller> Dashboard::controllers;
String Dashboard::dashMessage = "";
bool Dashboard::isMessage = false;
char Dashboard::nextChar;
int Dashboard::controllerIndex;
int Dashboard::axisIndex;
int Dashboard::buttonIndex;
float Dashboard::newVal;
String Dashboard::message = "";
bool Dashboard::logging = false;

void Dashboard::begin(){
  Serial.begin(115200);
}
void Dashboard::startLogging(){
  logging = true;
}
void Dashboard::stopLogging(){
  logging = false;
}
Controller& Dashboard::getController(int ID){
  while (controllerIndex > controllers.getLength()){
    controllers.add(Controller());  
  }
  return controllers.get(ID);
}
String Dashboard::getMessage(){
  return dashMessage;
}
void Dashboard::clearMessage(){
  dashMessage = "";
}
void Dashboard::println(String toPrint){
  Serial.println(toPrint);
}

void Dashboard::updateData(){
  while (Serial.available() > 0){
    nextChar = (char)Serial.read();
    isMessage = isMessage || (message.length() == 0 && nextChar == 'M');
    if (nextChar != '\n'){
      message += nextChar;
      if (!isMessage){
        switch(nextChar){
          case 'C':
            controllerIndex = message.substring(0,
                                message.indexOf('C')).toInt();
            message = "";
            break;
          case 'B':
            buttonIndex = message.substring(0,
                                message.indexOf('B')).toInt();
            message = "";
            break;
          case 'A':
            axisIndex = message.substring(0,
                                message.indexOf('A')).toInt();
            message = "";
            break;
          case 'V':
            newVal = message.substring(0,
                                message.indexOf('V')).toFloat();
            message = "";
            break;
        }
      }
    }
    else{
      if (isMessage){
        message = message.substring(1);
        dashMessage = "Arduino recieved: "+message;
      }
      else{
        while (controllerIndex >= controllers.getLength()){
          controllers.add(Controller());
        }
        if (axisIndex > -1){
          controllers.get(controllerIndex).setAxis(axisIndex, newVal);
        }
        else{
          controllers.get(controllerIndex).setButton(buttonIndex, newVal);
        }
        if (logging){
          String logMessage = "";
          logMessage = "Controller: "+String(controllerIndex)+"\n";
          if (axisIndex > -1) logMessage += "Axis: "+String(axisIndex)+"\n";
          else logMessage += "Button: "+String(buttonIndex)+"\n";
          logMessage += "Value: "+String(newVal);
          
          Dashboard::println("");
          Dashboard::println(logMessage);
        }
      }
      
      isMessage = false;
      axisIndex = -1;
      buttonIndex = -1;
      
      message = "";
     }
  }
}

