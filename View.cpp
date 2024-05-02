/* 
 * File:   View.cpp
 * Author: Theopolis Armstrong
 * 
 * Created on May 1, 2024, 6:29 PM
 */

#include "View.h"

#include <iostream>

void View::show() {
    std::cout << "Welcome to Catalog:\n";
    while (!exit_) {
        switch (state_) {
            case MenuState::MAIN: { menu_state(); break; }
            case MenuState::LOGIN: { login_state(); break; }
            case MenuState::REGISTER: { register_state(); break; }
            case MenuState::CATALOG: { catalog_state(); break; }
            case MenuState::CART: { cart_state(); break; }
            case MenuState::CHECKOUT: { checkout_state(); break; }
            case MenuState::ADMIN: { admin_state(); break; }
            case MenuState::EXIT: {
                std::cout << "\nGoodbye\n";
                exit_ = true;
                break;
            }
        }
    }
}

void View::menu_state() {
    std::cout << "1. Login\n"
              << "2. Register\n"
              << "3. View Catalog\n"
              << "4. Admin Panel\n"
              << "0. Exit\n";
    int input = -1;
    std::cin >> input;
    switch (input) {
        case 1: state_ = MenuState::LOGIN; break;
        case 2: state_ = MenuState::REGISTER; break;
        case 3: state_ = MenuState::CATALOG; break;
        case 4: state_ = MenuState::ADMIN; break;
        case 0: state_ = MenuState::EXIT; break;
        default: std::cout << "Invalid input " << input << std::endl; break;
    }
}

void View::login_state() {
    std::string username, password;
    std::cout << "Enter username: ";
    std::cin >> username;
    std::cout << "Enter password: ";
    std::cin >> password;
    std::cout << std::endl;

    if (!controller_->login_user(username, password)) {
        std::cout << "Invalid username or password.\n";
    } else {
        std::cout << "Successfully logged in as " << controller_->get_current_user()->get_username() << std::endl;
    }
    std::cout << std::endl;

    state_ = MenuState::MAIN;
}

void View::register_state() {
    std::string username, password;
    std::cout << "Enter username: ";
    std::cin >> username;
    std::cout << "Enter password: ";
    std::cin >> password;

//    controller_->register_user(username, password);

    state_ = MenuState::MAIN;
}

void View::catalog_state() {

}

void View::cart_state() {

}

void View::checkout_state() {

}

void View::admin_state() {

}
