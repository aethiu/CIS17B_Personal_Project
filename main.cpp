/*
 * File:   main.cpp
 * Author: Theopolis Armstrong
 *
 * Created on April 26, 2024, 10:29 AM
 */

#include "App.h"

int main(int argc, char** argv) {
    srand(time(nullptr));

    App app {ServiceManager::instance()};

    app.run();

    return 0;
}

