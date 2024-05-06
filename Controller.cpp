/*
 * File:   Controller.cpp
 * Author: Theopolis Armstrong
 * 
 * Created on April 27, 2024, 5:57 PM
 */

#include "Controller.h"

const Order* Controller::create_order() noexcept {
  order_ = new Order(*current_user_, cart_);
  return order_;
}
