#include "vector.cpp"
class Controller{
  private:
    Vector<bool> buttons;
    Vector<float> axes;
  public:
    void setButton(int ID, bool on);
    void setAxis(int ID, float value);
    float getAxis(int ID);
    bool getButton(int ID);
};

