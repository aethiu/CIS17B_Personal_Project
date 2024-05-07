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
    View(Controller &controller) : controller_(controller) {}
    void show();
private:
    Controller &controller_ ;

    bool exit_ = false;

    enum MenuState {
        MAIN,
        LOGIN,
        REGISTER,
        CATALOG,
        CART,
        CART_REMOVE_ITEM,
        CHECKOUT,
        ADMIN,
        ADMIN_EDIT_USER,
        EXIT
    } state_ = MenuState::MAIN;

    void menu_state();
    void login_state();
    void register_state();
    void catalog_state();
    void cart_state();
    void cart_remove_item_state();
    void checkout_state();
    void admin_state();

    void print_cart() const noexcept;
};

#endif /* VIEW_H */

