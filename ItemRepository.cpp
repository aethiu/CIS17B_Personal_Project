/*
 * File:   ItemRepository.cpp
 * Author: Theopolis Armstrong
 * 
 * Created on May 5, 2024, 11:52 AM
 */

#include "ItemRepository.h"

void ItemRepository::load_row(std::ifstream &db) {
    unsigned int sku = 0;
    unsigned long quantity = 0;
    float price = 0;
    std::string name, description, img;
    db.read(reinterpret_cast<char*>(&sku), sizeof(sku));
    db.read(reinterpret_cast<char*>(&quantity), sizeof(quantity));
    db.read(reinterpret_cast<char*>(&price), sizeof(price));
    std::getline(db, name, '\0');
    std::getline(db, description, '\0');
    std::getline(db, img, '\0');
    table_.try_emplace(sku, sku, quantity, price, name, description);
}

void ItemRepository::save_row(std::ofstream &db, const Item& item) const {
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
