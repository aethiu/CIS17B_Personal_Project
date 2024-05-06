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
#include "Order.h"

class Controller {
public:
    Controller(ServiceManager &service_manager) : service_manager_(&service_manager), cart_(*service_manager.get_item_service()) { }

    /** \brief Login a user as the current user
     *
     * @param username User account's username
     * @param password User account's password
     * @return True if login is successful or false otherwise
     */
    bool login_user(std::string username, std::string password) {
        // TODO this is a mock implementation
        return true;
    }
    const User* register_user(std::string username, std::string password);
    void add_to_cart(const Item *item) { cart_.add_item(item); }
    const Order* create_order() noexcept;
    void submit_order() { }

    ServiceManager& get_service_manager() noexcept { return *service_manager_; };
    const Order* get_order() const { return order_; }
    const Cart& get_cart() const { return cart_; }
    const User* get_current_user() const { return current_user_; }

    bool is_logged_in() const noexcept { return current_user_ != nullptr; }
private:
    ServiceManager *service_manager_;
    // TODO this is a mock implementation
    User* current_user_ = new User(1, true, "test", "test");
    Cart cart_;
    Order* order_ = nullptr;
};

#endif /* CONTROLLER_H */

