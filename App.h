/*
 * File:   App.h
 * Author: Theopolis Armstrong
 *
 * Created on April 27, 2024, 5:32 PM
 */

#ifndef APP_H
#define APP_H

#include "Controller.h"
#include "View.h"

class App {
public:
    App(ServiceManager &service_manager) : controller_{service_manager}, view_{controller_} { }
    void run();
private:
    Controller controller_;
    View view_;
};

#endif /* APP_H */

