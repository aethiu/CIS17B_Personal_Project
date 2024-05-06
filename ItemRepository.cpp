/*
 * File:   ItemRepository.cpp
 * Author: Theopolis Armstrong
 * 
 * Created on May 5, 2024, 11:52 AM
 */

#include "ItemRepository.h"

#include <algorithm>
#include <fstream>
#include <iostream>

ItemRepository::ItemRepository(std::string db_filename) : Repository(db_filename) {
  load();
}

void ItemRepository::create_item(const Item& item) {
  items_.insert({item.get_sku(), item});
  save();
}

const Item* ItemRepository::read_item(unsigned int sku) const {
  auto it = items_.find(sku);
  return it == items_.end() ? nullptr : &(it->second);
}

void ItemRepository::update_item(unsigned int sku, const Item& item) {
  if (items_.count(sku) != 0) {
    items_[sku] = item;
    if (sku != item.get_sku()) {
      // Move value to new key to avoid invalidating pointers returned by read_item()
      items_.insert({item.get_sku(), std::move(items_[sku])});
    }
  } else {
    create_item(item);
  }
}

void ItemRepository::delete_item(unsigned int sku) {
  items_.erase(sku);
  save();
}

void ItemRepository::load() {
  std::fstream db(db_filename_, std::ios::in | std::ios::binary);
  if (!db) { throw new db_exception; }
  db.seekg(0, std::ios::beg);
  items_.clear();

  // Read header
  size_t num_items = 0;
  db.read(reinterpret_cast<char*>(&num_items), sizeof(num_items));

  // Read items
  unsigned int sku = 0;
  unsigned long quantity = 0;
  float price = 0;
  std::string name, description, img;
  for (size_t i = 0; i < num_items; i++) {
    db.read(reinterpret_cast<char*>(&sku), sizeof(sku));
    db.read(reinterpret_cast<char*>(&quantity), sizeof(quantity));
    db.read(reinterpret_cast<char*>(&price), sizeof(price));
    std::getline(db, name, '\0');
    std::getline(db, description, '\0');
    std::getline(db, img, '\0');
    items_.try_emplace(sku, sku, quantity, price, name, description);
  }
  db.close();
}

void ItemRepository::save() const {
  std::fstream db(db_filename_, std::ios::out | std::ios::binary);
  if (!db) { throw new db_exception; }
  db.seekp(0, std::ios::beg);

  // Write header
  size_t num_items = items_.size();
  db.write(reinterpret_cast<char*>(&num_items), sizeof(num_items));
  // Write items
  for (const auto& [_, item] : items_) {
    unsigned int sku = item.get_sku();
    unsigned long quantity = item.get_quantity();
    float price = item.get_price();
    db.write(reinterpret_cast<char*>(&sku), sizeof(sku));
    db.write(reinterpret_cast<char*>(&quantity), sizeof(quantity));
    db.write(reinterpret_cast<char*>(&price), sizeof(price));
    db.write(reinterpret_cast<const char*>(item.get_name().c_str()), item.get_name().length()+1);
    db.write(reinterpret_cast<const char*>(item.get_description().c_str()), item.get_description().length()+1);
    db.write(reinterpret_cast<const char*>(item.get_img().c_str()), item.get_img().length()+1);
  }
  db.close();
}
