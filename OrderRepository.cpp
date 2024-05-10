/* 
 * File:   OrderRepository.cpp
 * Author: Theopolis Armstrong
 * 
 * Created on May 7, 2024, 9:39 AM
 */

#include "OrderRepository.h"

#include <map>

void OrderRepository::load_row(std::ifstream &db) {
  Order::OrderNum order_num = 0;
  unsigned int id = 0;
  float subtotal, tax, shipping, total;
  subtotal = tax = shipping = total = 0.0f;
  std::string date;
  short num_items;
  std::map<unsigned int, unsigned long> items;
  db.read(reinterpret_cast<char*>(&order_num), sizeof(order_num));
  db.read(reinterpret_cast<char*>(&id), sizeof(id));
  db.read(reinterpret_cast<char*>(&subtotal), sizeof(subtotal));
  db.read(reinterpret_cast<char*>(&tax), sizeof(tax));
  db.read(reinterpret_cast<char*>(&shipping), sizeof(shipping));
  db.read(reinterpret_cast<char*>(&total), sizeof(total));
  std::getline(db, date, '\0');
  db.read(reinterpret_cast<char*>(&num_items), sizeof(num_items));

  // Read items
  unsigned int sku;
  unsigned long quantity;
  for (size_t i=0; i<num_items; i++) {
    db.read(reinterpret_cast<char*>(&sku), sizeof(sku));
    db.read(reinterpret_cast<char*>(&quantity), sizeof(quantity));
    items.insert({sku, quantity});
  }

  table_.try_emplace(order_num, order_num, id, subtotal, tax, shipping, total, date, items);
}

void OrderRepository::save_row(std::ofstream &db, const Order& order) const {
  Order::OrderNum order_num = order.get_order_num();
  unsigned int id = order.get_user_id();
  float subtotal = order.get_subtotal();
  float tax = order.get_tax();
  float shipping = order.get_shipping();
  float total = order.get_total();
  auto items_ = order.get_items();
  short num_items = items_.size();
          db.write(reinterpret_cast<char*>(&order_num), sizeof(order_num));
  db.write(reinterpret_cast<char*>(&id), sizeof(id));
  db.write(reinterpret_cast<char*>(&subtotal), sizeof(subtotal));
  db.write(reinterpret_cast<char*>(&tax), sizeof(tax));
  db.write(reinterpret_cast<char*>(&shipping), sizeof(shipping));
  db.write(reinterpret_cast<char*>(&total), sizeof(total));
  db.write(order.get_date().c_str(), order.get_date().length()+1);
  db.write(reinterpret_cast<char*>(&num_items), sizeof(num_items));

  // Write items
  for (const auto& [sku, quantity] : items_) {
    db.write(reinterpret_cast<const char*>(&sku), sizeof(sku));
    db.write(reinterpret_cast<const char*>(&quantity), sizeof(quantity));
  }
}
