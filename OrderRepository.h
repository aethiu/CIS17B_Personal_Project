/* 
 * File:   OrderRepository.h
 * Author: Theopolis Armstrong
 *
 * Created on May 7, 2024, 9:39 AM
 */

#ifndef ORDERREPOSITORY_H
#define ORDERREPOSITORY_H

#include "Repository.h"
#include "Order.h"

#include <string>

class OrderRepository : Repository<Order::OrderNum , Order> {
public:
    OrderRepository(std::string db_filename) : Repository<Order::OrderNum, Order>(db_filename) { }

private:
  void load_row(std::ifstream&) override;
  void save_row(std::ofstream&, const Order&) const override;

};

#endif /* ORDERREPOSITORY_H */

