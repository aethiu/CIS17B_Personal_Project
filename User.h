/*
 * File:   User.h
 * Author: Theopolis Armstrong
 *
 * Created on April 26, 2024, 10:56 AM
 */

#ifndef USER_H
#define USER_H

#include <string>
#include <utility>

#include "Cart.h"

class User {
public:
    User(ItemService &item_service, std::string username, std::string password, bool is_admin)
        : cart_{item_service}, username_(std::move(username)), password_(std::move(password)), is_admin_(is_admin) { }
    const std::string& get_username() const noexcept { return username_; }
    Cart& get_cart() noexcept { return cart_; }
private:
    unsigned int id_ = 0;
    bool is_admin_ = false;
    std::string username_;
    std::string password_;
    Cart cart_;
};

#endif /* USER_H */

