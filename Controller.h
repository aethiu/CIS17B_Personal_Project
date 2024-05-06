/*
 * File:   Controller.h
 * Author: Theopolis Armstrong
 *
 * Created on April 27, 2024, 5:57 PM
 */

#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "ServiceManager.h"
#include "User.h"

class Controller {
public:
    Controller(ServiceManager &service_manager) : service_manager_(&service_manager), cart_(*service_manager.get_item_service()) { }
    bool login_user(std::string username, std::string password) {
        // TODO this is a mock implementation
        static User user(1, true, "test", "test");
        current_user_ = &user;
        return true;
    }
    void register_user(std::string username, std::string password);
    void add_to_cart(const Item *item) { cart_.add_item(item); }
    void create_order();
    void submit_order();

    const User* get_current_user() noexcept { return current_user_; }
private:
    ServiceManager *service_manager_;
    User* current_user_;
    Cart cart_;
};

#endif /* CONTROLLER_H */

