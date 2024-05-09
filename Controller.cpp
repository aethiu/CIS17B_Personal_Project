/*
 * File:   Controller.cpp
 * Author: Theopolis Armstrong
 * 
 * Created on April 27, 2024, 5:57 PM
 */

#include "Controller.h"

const Order* Controller::create_order() noexcept {
//  order_ = new Order(*current_user_, cart_);
//  return order_;
  return nullptr;
}

const User* Controller::register_user(std::string username, std::string password) {
  User user(service_manager_->get_user_service()->get_new_id(), false, username, password);
  return service_manager_->get_user_service()->add_user(user);
}
