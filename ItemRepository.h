/*
 * File:   ItemRepository.h
 * Author: Theopolis Armstrong
 *
 * Created on May 5, 2024, 11:52 AM
 */

#ifndef ITEMREPOSITORY_H
#define ITEMREPOSITORY_H

#include <string>
#include <vector>

#include "Item.h"
#include "Order.h"
#include "User.h"

class ItemRepository {
public:
  ItemRepository() =default;
  ItemRepository(std::string database_file);

  void create_item(const Item& item);
  const Item* read_item(unsigned int sku) const;
  void update_item(unsigned int sku, const Item& item);
  void delete_item(unsigned int sku);

private:
  std::string db_filename_;

  std::vector<Item> items_;
  std::vector<User> users_;
  std::vector<Order> orders_;

  void load();
  void save();
};

#endif /* ITEMREPOSITORY_H */

