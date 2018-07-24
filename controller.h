#pragma once

#include "vector.cpp"
class Controller{
  private:
    Vector<bool> buttons;
    Vector<float> axes;
	Vector<float> POVs;
  public:
    void setButton(int ID, bool on);
    void setAxis(int ID, float value);
	  void setPOV(int ID, float value);
   
    float getAxis(int ID);
    bool getButton(int ID);
	  float getPOV(int ID);
};

