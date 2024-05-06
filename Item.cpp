/*
 * File:   Item.cpp
 * Author: Theopolis Armstrong
 * 
 * Created on April 26, 2024, 10:36 AM
 */

#include "Item.h"

Item::Item(unsigned int sku,
           unsigned long quantity,
           float price,
           std::string name,
           std::string description)
           : sku_(sku),
           quantity_(quantity),
           name_(name),
           description_(description),
           img_("items/"+std::to_string(sku)+".jpg"),
           price_(price) {
}
