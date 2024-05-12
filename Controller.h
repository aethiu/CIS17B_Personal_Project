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
    Controller(ServiceManager &service_manager) : service_manager_(&service_manager) { }

    /** \brief Login a user as the current user
     *
     * @param username User account's username
     * @param password User account's password
     * @return True if login is successful or false otherwise
     */
    bool login(std::string username, std::string password) {
        auto user = service_manager_->get_user_service()->find_user(username, password);
        if (user == nullptr) return false;
        current_user_ = user;
        return true;
    }
    const User* register_user(std::string username, std::string password);
    void add_to_cart(const Item *item) { cart_.add_item(item); }
    const Item* remove_from_cart(const Item *item) { return cart_.remove_item(item); }
    const Order* create_order() noexcept;
    void submit_order();

    // Admin actions
    const Item* add_item(const Item &item) { return service_manager_->get_item_service()->add_item(item); }
    void remove_item(unsigned int sku) { service_manager_->get_item_service()->remove_item(sku); }
    void remove_user(unsigned int id) { service_manager_->get_user_service()->remove_user(id); }

    ServiceManager& get_service_manager() noexcept { return *service_manager_; };
    const Order* get_order() const { return &order_; }
    const Cart& get_cart() const { return cart_; }
    const User* get_current_user() const { return current_user_; }

    bool is_logged_in() const noexcept { return current_user_ != nullptr; }

private:
    ServiceManager *service_manager_ = nullptr;
    const User* current_user_ = nullptr;
    Cart cart_;
    Order order_;
};

#endif /* CONTROLLER_H */
