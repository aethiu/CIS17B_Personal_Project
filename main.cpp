/*
 * File:   main.cpp
 * Author: Theopolis Armstrong
 *
 * Created on April 26, 2024, 10:29 AM
 */

#include "App.h"

using namespace std;

int main(int argc, char** argv) {
    App app {ServiceManager::instance()};

    app.run();

    return 0;
}

