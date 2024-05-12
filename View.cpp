/* 
 * File:   View.cpp
 * Author: Theopolis Armstrong
 * 
 * Created on May 1, 2024, 6:29 PM
 */

#include "View.h"

#include <iostream>
#include <iomanip>

void View::show() {
    while (!exit_) {
        switch (state_) {
            case MenuState::MAIN: { menu_state(); break; }
            case MenuState::LOGIN: { login_state(); break; }
            case MenuState::REGISTER: { register_state(); break; }
            case MenuState::CATALOG: { catalog_state(); break; }
            case MenuState::CART: { cart_state(); break; }
            case MenuState::CART_REMOVE_ITEM: { cart_remove_item_state(); break; }
            case MenuState::CART_ADD_ITEM: { cart_add_item_state(); break; }
            case MenuState::CHECKOUT: { checkout_state(); break; }
            case MenuState::ADMIN: { admin_state(); break; }
            case MenuState::EXIT: {
                std::cout << "Goodbye\n";
                exit_ = true;
                break;
            }
        }
        std::cout << std::endl;
    }
}

void View::menu_state() {
    std::cout << "Welcome to Catalog:\n";
    std::cout << "1. Login\n"
              << "2. Register\n"
              << "3. View Catalog\n"
              << "4. Admin Panel\n"
              << "0. Exit\n";
    int input = -1;
    std::cin >> input;
    switch (input) {
        case 1: transition(MenuState::LOGIN); break;
        case 2: transition(MenuState::REGISTER); break;
        case 3: { transition(MenuState::CATALOG); break; }
        case 4: transition(MenuState::ADMIN); break;
        case 0: transition(state_ = MenuState::EXIT); break;
        default: std::cout << "Invalid input " << input << std::endl; break;
    }
}

void View::login_state() {
    std::string username, password;
    std::cout << "Enter username: ";
    std::cin >> username;
    std::cout << "Enter password: ";
    std::cin >> password;
    std::cout << std::endl;

    if (controller_.login(username, password)) {
      std::cout << "Successfully logged in as " << controller_.get_current_user()->get_username() << std::endl;
    } else {
      std::cout << "Invalid username or password.\n";
    }
    transition(previous_state_);
}

void View::register_state() {
    std::string username, password;
    std::cout << "Enter username: ";
    std::cin >> username;
    std::cout << "Enter password: ";
    std::cin >> password;

    controller_.register_user(username, password);

    transition(MenuState::MAIN);
}

void View::catalog_state() {
  if (previous_state_ != MenuState::CART_ADD_ITEM && previous_state_ != MenuState::CATALOG) {
    // Display catalog items
    std::cout << "Catalog:\n";
    std::cout << std::left
              << std::setw(8) << "SKU"
              << std::setw(16) << "Item Name"
              << std::setw(8) << "Qty."
              << std::setw(8) << "Price"
              << std::setw(64) << "Description"
              << std::endl;
    auto items = controller_.get_service_manager().get_item_service()->get_all_items();
    for (const auto &item: items) {
      std::cout << std::setw(8) << item->get_sku()
                << std::setw(16) << item->get_name()
                << std::setw(8) << item->get_quantity()
                << std::setw(8) << item->get_price()
                << std::setw(64) << item->get_description()
                << std::endl;
    }
  }

  // Prompt for input
  std::cout << "1. Add item to cart\n"
            << "2. View cart\n"
            << "3. Return to main menu\n";

  // Process input
  int input = -1;
  std::cin >> input;
  switch (input) {
      case 1: { transition(MenuState::CART_ADD_ITEM); break; }
      case 2: { transition(MenuState::CART); break; }
      case 3: { transition(MenuState::MAIN); break; }
      default: { std::cout << "Invalid input " << input << std::endl; break; }
  }

}

void View::cart_state() {
  std::cout << "Your cart:\n";
  print_cart();
  std::cout << "Subtotal: " << controller_.get_cart().get_subtotal() << std::endl;
  std::cout << std::endl;

  // Prompt for input
  std::cout << "1. Checkout\n"
            << "2. Remove item\n"
            << "3. Return to catalog\n"
            << "4. Return to main menu\n";
  int input = -1;
  std::cin >> input;

  // Transition
  switch (input) {
    case 1: {
      if (controller_.is_logged_in()) {
        transition(MenuState::CHECKOUT);
      } else {
        transition(MenuState::LOGIN);
      }
      break;
    }
    case 2: { transition(MenuState::CART_REMOVE_ITEM); break; }
    case 3: { transition(MenuState::CATALOG); break; }
    case 4: { transition(MenuState::MAIN); break; }
    default: { std::cout << "Invalid input " << input << std::endl; break; }
  }
}

void View::cart_add_item_state() {
  auto item_service = controller_.get_service_manager().get_item_service();

  std::cout << "Enter SKU to add to your cart: ";
  unsigned long sku;
  std::cin >> sku;

  // Find item by SKU and add to cart
  auto item = item_service->get_item(sku);
  if (item == nullptr) {
    std::cout << "Could not find item with SKU " << sku << std::endl;
  } else {
    controller_.add_to_cart(item_service->get_item(sku));
    std::cout << "Added " << item->get_name() << " to your cart\n";
  }

  transition(previous_state_);
}

void View::cart_remove_item_state() {
  auto item_service = controller_.get_service_manager().get_item_service();

  std::cout << "Enter a SKU to remove from your cart: ";
  unsigned long sku;
  std::cin >> sku;

  // Find item by SKU and remove from cart
  auto item = item_service->get_item(sku);
  if (item == nullptr) {
    std::cout << "Could not find item with SKU " << sku << std::endl;
  } else {
    if (controller_.remove_from_cart(item_service->get_item(sku))) {
      std::cout << "Removed " << item->get_name() << " from your cart\n";
    } else {
      std::cout << "Could not find item with SKU " << sku << " in your cart.\n";
    }
  }

  transition(previous_state_);
}

void View::checkout_state() {
    const Order* order = controller_.create_order();
    if (order == nullptr) {
      std::cout << "Could not create order.\n";
      transition(previous_state_);
      return;
    }
    std::cout << "Current order:\n";
    print_cart();
    std::cout << "Subtotal: " << order->get_subtotal() << std::endl
              << "Tax: " << order->get_tax() << std::endl
              << "Shipping: " << order->get_shipping() << std::endl
              << "Total: " << order->get_total() << std::endl;


    std::cout << std::endl
              << "1. Submit order\n"
              << "2. Cancel order and return to cart\n";
    int input = -1;
    std::cin >> input;
    switch (input) {
      case 1: {
        controller_.submit_order();
        // TODO confirm order submission
        std::cout << "Order #" << order->get_order_num() << " submitted.\n";
        transition(MenuState::CART);
        break;
      }
      case 2: { transition(MenuState::CART); break; }
      default: { std::cout << "Invalid input: " << input << std::endl; break; }
    }
}

void View::admin_state() {
  if (!controller_.is_logged_in() || !controller_.get_current_user()->is_admin()) {
    std::cout << "You must be logged in as an admin to view the admin panel.\n";
    transition(previous_state_);
    return;
  }
    std::cout << "Admin Panel\n"
              << "-----------\n"
              << '\n'
              << "Item Actions:\n"
              << "1. Add item to catalog\n"
              << "2. Edit item in catalog\n"
              << "3. Remove item from catalog\n"
              << '\n'
              << "User Actions:\n"
              << "4. Edit user\n"
              << "5. Remove user\n"
              << '\n'
              << "6. Exit admin panel\n";

  transition(MenuState::MAIN);
}

void View::print_cart() const noexcept {
  const auto& items = controller_.get_cart().get_items();
  std::cout << std::left
            << std::setw(8) << "SKU"
            << std::setw(16) << "Item Name"
            << std::setw(8) << "Qty."
            << std::setw(8) << "Price"
            << std::setw(64) << "Description"
            << std::endl;
  for (auto item : items) {
    if (item == nullptr) {
      std::cout << "Unknown item\n";
    } else {
      std::cout << std::setw(8) << item->get_sku()
                << std::setw(16) << item->get_name()
                << std::setw(8) << controller_.get_cart().get_quantity(item->get_sku())
                << std::setw(8) << item->get_price()
                << std::setw(64) << item->get_description()
                << std::endl;
    }
  }
}

void View::transition(MenuState state) noexcept {
    previous_state_ = state_;
    state_ = state;
}
