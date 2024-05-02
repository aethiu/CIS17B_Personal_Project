/* 
 * File:   View.h
 * Author: Theopolis Armstropng
 *
 * Created on May 1, 2024, 6:29 PM
 */

#ifndef VIEW_H
#define VIEW_H

#include "Controller.h"

class View {
public:
    View(Controller& controller) : controller_(&controller) {}
    void show();
private:
    Controller *controller_ ;

    enum MenuState {
        MAIN,
        LOGIN,
        REGISTER,
        CATALOG,
        CART,
        CHECKOUT,
        ADMIN,
        EXIT
    } state_ = MenuState::MAIN;

    bool exit_ = false;

    void menu_state();
    void login_state();
    void register_state();
    void catalog_state();
    void cart_state();
    void checkout_state();
    void admin_state();
};

#endif /* VIEW_H */

