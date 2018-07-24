#include <Arduino.h>
#include "vector.cpp"
#include "controller.h"

class Dashboard{
  private:
    static Vector<Controller> controllers;
    static String dashMessage;

    static bool isMessage;
    static char nextChar;
    static int controllerIndex;
    static int axisIndex;
    static int buttonIndex;
    static int POVIndex;
    static float newVal;
    static String message;
    static bool logging;
    Dashboard();
  public:
    /**
     * Opens communication between dashboard program and arduino
     */
    static void begin();
    static Controller& getController(int ID);
    static void startLogging();
    static void stopLogging();
    static String getMessage();
    static void clearMessage();
    static void println(String toPrint);
    /**
     * Updates controller data sent by dashboard. Must be called within loop().
     */
    static void updateData();
};

