/*
 * File:   ItemRepository.h
 * Author: Theopolis Armstrong
 *
 * Created on May 5, 2024, 11:52 AM
 */

#ifndef ITEMREPOSITORY_H
#define ITEMREPOSITORY_H

#include <string>
#include <unordered_map>

#include "Item.h"
#include "Repository.h"

class ItemRepository : public Repository {
public:
  ItemRepository() =default;
  ItemRepository(std::string db_filename);

  void create_item(const Item& item);
  const Item* read_item(unsigned int sku) const;
  void update_item(unsigned int sku, const Item& item);
  void delete_item(unsigned int sku);

private:
  std::unordered_map<unsigned int, Item> items_;

  void load() override;
  void save() const override;
};

#endif /* ITEMREPOSITORY_H */

