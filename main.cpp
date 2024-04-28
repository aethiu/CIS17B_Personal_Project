/*
 * File:   main.cpp
 * Author: Theopolis Armstrong
 *
 * Created on April 26, 2024, 10:29 AM
 */

#include <iostream>

#include "ItemService.h"
#include "Cart.h"

using namespace std;

int main(int argc, char** argv) {

    // Cart test

    Item *items[] = {
        new Item(1, 20, "Test item 1", "Test item 1 desc", 19.95),
        new Item(2, 50, "Test item 2", "Test item 2 desc", 5.89)
    };
    ItemService service(items, 2);
    Cart cart(&service);
    auto print_items = [](const std::vector<const Item*>& items, size_t size){
        for (size_t i=0; i<size; i++) {
            cout << "Name: " << items[i]->get_name() << endl;
            cout << "Description: " << items[i]->get_description() << endl;
            cout << "Price: " << items[i]->get_price() << endl;
        }
    };

    cout << "Cart:\n";
    cart.add_item(service.get_item(1));
    print_items(cart.get_items(), cart.get_num_items());
    cout << "\nAdd item:\n";
    cart.add_item(service.get_item(2));
    print_items(cart.get_items(), cart.get_num_items());
    cout << "\nRemove item:\n";
    cart.remove_item(items[1]);
    print_items(cart.get_items(), cart.get_num_items());

    return 0;
}

