/*
 * File:   Item.h
 * Author: Theopolis Armstrong
 *
 * Created on April 26, 2024, 10:36 AM
 */

#ifndef ITEM_H
#define ITEM_H

#include <string>

class Item {
public:
    Item() =default;
    Item(unsigned int sku,
         unsigned long quantity,
         float price,
         std::string name,
         std::string description);

    unsigned int get_sku() const noexcept { return sku_; };
    unsigned long get_quantity() const noexcept { return quantity_; };
    float get_price() const noexcept { return price_; };
    const std::string& get_name() const noexcept { return name_ ;}
    const std::string& get_description() const noexcept { return description_ ;}
    const std::string& get_img() const noexcept { return img_; }

    void set_sku(unsigned int sku) noexcept { sku_ = sku; }
    void set_quantity(unsigned long quantity) noexcept { quantity_ = quantity; }
    void set_price(float price) noexcept { price_ = price; }
    void set_name(std::string& name) noexcept { name_ = name; }
    void set_description(std::string& description) noexcept { description_ = description; }
    void set_img(std::string& img) noexcept { img_ = img; }

    bool operator==(unsigned long rhs) const { return sku_ == rhs; }

private:
    unsigned int sku_ = 0;
    unsigned long quantity_ = 0;
  float price_ = 0.0f;
    std::string name_;
    std::string description_;
    std::string img_;
};

#endif /* ITEM_H */

