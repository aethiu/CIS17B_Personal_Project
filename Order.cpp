/*
 * File:   Order.cpp
 * Author: Theopolis Armstrong
 * 
 * Created on April 26, 2024, 11:03 AM
 */

#include "Order.h"

#include <ctime>
#include <iomanip>

Order::Order(OrderNum order_num, const User &user, const Cart &cart)
        : cart_(&cart),
          user_(&user),
          total_(calculate_total(cart.get_subtotal())) {

  // Set time
  auto t = std::time(nullptr);
  std::stringstream ss;
  ss << std::put_time(std::gmtime(&t), "%FT%T");
  date_ = ss.str();
}

float Order::calculate_total(float subtotal) const noexcept {
  float total = subtotal;
  total += total*tax_rate_ + shipping_cost_;
  return total;
}
