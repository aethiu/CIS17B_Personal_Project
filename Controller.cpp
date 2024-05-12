/*
 * File:   Controller.cpp
 * Author: Theopolis Armstrong
 * 
 * Created on April 27, 2024, 5:57 PM
 */

#include "Controller.h"

const Order* Controller::create_order() noexcept {
  order_ = std::move(service_manager_->get_order_service().create_order(*current_user_, cart_));
  return &order_;
}

const User* Controller::register_user(std::string username, std::string password) {
  User user(service_manager_->get_user_service().get_new_id(), false, username, password);
  return service_manager_->get_user_service().add_user(user);
}

void Controller::submit_order() {
  service_manager_->get_order_service().submit_order(order_);
  cart_ = Cart();
}
