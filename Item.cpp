/*
 * File:   Item.cpp
 * Author: Theopolis Armstrong
 * 
 * Created on April 26, 2024, 10:36 AM
 */

#include "Item.h"

Item::Item(unsigned int sku,
           unsigned long quantity,
           std::string name,
           std::string description,
           float price)
           : sku_(sku),
           quantity_(quantity),
           name_(name),
           description_(description),
           img_(std::to_string(sku)),
           price_(price) {
}
