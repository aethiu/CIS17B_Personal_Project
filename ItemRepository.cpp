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

ItemRepository::ItemRepository(std::string db_file) : db_filename_(db_file) {
  load();
}

void ItemRepository::create_item(const Item& item) {
  items_.emplace_back(item);
  save();
}

const Item* ItemRepository::read_item(unsigned int sku) const {
  auto it = std::find_if(items_.begin(), items_.end(), [&](const auto &item) {
    return item.get_sku() == sku;
  });
  return it == items_.end() ? nullptr : &(*it);
}

void ItemRepository::update_item(unsigned int sku, const Item& item) {
  for (auto& i : items_) {
    if (i.get_sku() == sku) {
      i = item;
      return;
    }
  }
  create_item(item);
}

void ItemRepository::delete_item(unsigned int sku) {
  items_.erase(std::remove_if(items_.begin(), items_.end(), [&](const auto &item) {
    return item.get_sku() == sku;
  }));
  save();
}

void ItemRepository::load() {
  std::fstream db(db_filename_, std::ios::in | std::ios::binary);
  if (!db) { std::cerr << "Could not open binary file\n"; }
  db.seekg(0, std::ios::beg);
  size_t num_items = 0;
  db.read(reinterpret_cast<char*>(&num_items), sizeof(num_items));
  if (db) {
    items_.clear();
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
    }
  }
  db.close();
}

void ItemRepository::save() {
  std::fstream db(db_filename_, std::ios::out | std::ios::binary);
  if (!db) { std::cerr << "Could not open binary file\n"; }
  db.seekp(0, std::ios::beg);
  size_t num_items = items_.size();
  db.write(reinterpret_cast<char*>(&num_items), sizeof(num_items));
  for (const auto& item : items_) {
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
