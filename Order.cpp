/*
 * File:   Order.cpp
 * Author: Theopolis Armstrong
 * 
 * Created on April 26, 2024, 11:03 AM
 */

#include "Order.h"

#include <utility>

Order::Order(OrderNum order_num, unsigned int user_id, float subtotal, float tax, float shipping, float total, std::string date, std::map<unsigned int, unsigned long> items)
        : user_id_(user_id)
        , subtotal_(subtotal)
        , tax_(tax)
        , shipping_(shipping)
        , total_(total)
        , date_(std::move(date))
        , items_(std::move(items)) {
}
