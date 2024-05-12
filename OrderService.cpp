/* 
 * File:   OrderService.cpp
 * Author: Theopolis Armstrong
 * 
 * Created on May 6, 2024, 10:03 PM
 */

#include "OrderService.h"

#include <ctime>
#include <iomanip>

Order OrderService::create_order(const User& user, const Cart& cart) {
  // Get current time
  auto t = std::time(nullptr);
  std::stringstream ss;
  ss << std::put_time(std::gmtime(&t), "%FT%T");
  std::string date = ss.str();

  float subtotal = cart.get_subtotal(),
        tax = cart.get_subtotal()*tax_rate_,
        shipping = shipping_cost_,
        total = subtotal+tax+shipping;

  Order order(get_new_order_num(),
              user.get_id(),
              subtotal,
              tax,
              shipping,
              total,
              date,
              cart.get_quantities());
  return std::move(order);
}

Order::OrderNum OrderService::get_new_order_num() const {
  unsigned int order_num = rand()%10000; // should be changed max possible ID
  if (repo_.read_row(order_num) == nullptr) {
    return order_num;
  }
  return get_new_order_num();
}

const Order* OrderService::submit_order(const Order& order) {
  // Check order for validity
  for (const auto& [sku, quantity] : order.get_items()) {
    const auto& item = item_service_.get_item(sku);
    if (item == nullptr) { return nullptr; }
    if (quantity > item->get_quantity()) { return nullptr; }
  }

  // Execute order
  auto res = repo_.create_row(order.get_order_num(), order);
  if (res == nullptr) { return nullptr; }
  for (const auto& [sku, quantity] : order.get_items()) {
      Item item = *item_service_.get_item(sku);
      item.set_quantity(item.get_quantity() - quantity);
      item_service_.update_item(item);
  }

  return repo_.create_row(order.get_order_num(), order);
}
