/*
 * File:   main.cpp
 * Author: Theopolis Armstrong
 *
 * Created on April 26, 2024, 10:29 AM
 */

#include "App.h"

#include "ItemRepository.h"

#include <filesystem>
#include <iostream>

int main(int argc, char** argv) {

    /* Repository test */
    // Note that these tests don't check the binary file being modified by the repo
    
    ItemRepository repo("item_db.bin");

    // Create/Read
    Item item(1, 1, 1.99, "New Item", "New Item Desc)"),
        item2(2, 5, 2.99, "New Item 2", "New Item 2 Description"),
        item3(3, 5, 3.99, "New Item 3", "New Item 3 Description"),
        item4(4, 5, 4.99, "New Item 4", "New Item 4 Description");
    repo.create_item(item);
    repo.create_item(item2);
    repo.create_item(item3);
    repo.create_item(item4);
    const Item* read_item = repo.read_item(item.get_sku());
    if (read_item->get_sku() == item.get_sku()) {
      std::cout << "Create test passed\n";
    } else {
      std::cout << "Create test failed\n";
    }

    // Update
    item.set_price(200.0);
    repo.update_item(item.get_sku(), item);
    read_item = repo.read_item(item.get_sku());
    if (read_item->get_price() == 200.0) {
      std::cout << "Update test passed\n";
    } else {
      std::cout << "Update test failed\n";
    }

    // Delete
    repo.delete_item(item.get_sku());
    read_item = repo.read_item(item.get_sku());
    if (!read_item) {
      std::cout << "Delete test passed\n";
    } else {
      std::cout << "Delete test failed\n";
    }

    App app {ServiceManager::instance()};

    app.run();

    return 0;
}

