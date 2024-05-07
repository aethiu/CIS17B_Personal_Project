/*
 * File:   ItemRepository.h
 * Author: Theopolis Armstrong
 *
 * Created on May 5, 2024, 11:52 AM
 */

#ifndef ITEMREPOSITORY_H
#define ITEMREPOSITORY_H

#include "Item.h"
#include "Repository.h"

#include <string>
#include <fstream>

class ItemRepository : public Repository<unsigned long, Item> {
public:
  ItemRepository() =default;
  ItemRepository(std::string db_filename) : Repository<unsigned long, Item>(std::move(db_filename)) { load(); }

private:
  void load_row(std::ifstream&) override;
  void save_row(std::ofstream&, const Item&) const override;
};

#endif /* ITEMREPOSITORY_H */

