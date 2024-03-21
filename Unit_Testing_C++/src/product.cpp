// product.cpp
#include "product.h"

// Implement default constructor
Product::Product() {
    // Initialize default values or leave empty
}

Product::Product(int product_id, std::string name, double price, int stock)
    : product_id(product_id), name(name), price(price), stock(stock) {}

std::string Product::get_name() const {
    return name;
}

double Product::get_price() const {
    return price;
}


int Product::get_stock() {
    return stock;
}

int Product::get_product_id() const {
    return product_id;
}

void Product::update_stock(int quantity) {
    this->stock -= quantity;
}
