/* 
 * File:   OrderService.h
 * Author: Theopolis Armstrong
 *
 * Created on May 6, 2024, 10:03 PM
 */

#ifndef ORDERSERVICE_H
#define ORDERSERVICE_H

#include "ItemService.h"
#include "Order.h"
#include "OrderRepository.h"

class OrderService {
public:
    OrderService(OrderRepository& repository, const ItemService &item_service)
    : item_service_(item_service)
    , repo_(repository)
    { }

    const Order* create_order() { return nullptr; }

private:
    OrderRepository repo_;
     const ItemService& item_service_;

};

#endif /* ORDERSERVICE_H */

