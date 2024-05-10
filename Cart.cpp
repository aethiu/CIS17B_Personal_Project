/*
 * File:   Cart.cpp
 * Author: Theopolis Armstrong
 * 
 * Created on April 26, 2024, 10:59 AM
 */

#include "Cart.h"

#include <algorithm>

void Cart::add_item(const Item* item) {
  if (item == nullptr) { return; }
  if (quantities_.count(item->get_sku()) == 0) {
    items_.push_back(item);
  }
  quantities_[item->get_sku()]++;
}

const Item* Cart::remove_item(const Item* item) {
  if (item == nullptr) { return nullptr; }
  if (quantities_.count(item->get_sku()) == 0) { return nullptr; }
  if (quantities_[item->get_sku()] == 1) {
    // Remove item from cart
    items_.erase(std::find(items_.begin(), items_.end(), item));
    quantities_.erase(item->get_sku());
  } else {
    // Decrement quantity
    quantities_[item->get_sku()]--;
  }
  return item;
}

unsigned long Cart::set_quantity(const Item* item, unsigned long quantity) {
  if (item == nullptr) { return 0; }
  return set_quantity(item->get_sku(), quantity);
}

unsigned long Cart::set_quantity(unsigned int sku, unsigned long quantity) {
  if (quantities_.count(sku) == 0) { return 0; }
  quantities_[sku] = quantity;
  return quantities_[sku];
}

unsigned long Cart::get_quantity(unsigned int sku) const {
  if (quantities_.count(sku) == 0) {
    return 0;
  }
  return quantities_.at(sku);
}

size_t Cart::get_num_items() const noexcept {
  size_t num_items = 0;
  for (const auto& [sku, quantity] : quantities_) {
    num_items += quantity;
  }
  return num_items;
}

float Cart::get_subtotal() const noexcept {
  float subtotal = 0.0f;
  for (const auto& item : items_) {
    if (item != nullptr) {
      subtotal += item->get_price()*quantities_.at(item->get_sku());
    }
  }
  return subtotal;
};
