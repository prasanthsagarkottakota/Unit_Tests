// order.cpp
#include "order.h"

Order::Order(int order_id, Customer customer, std::vector<std::pair<Product, int>> products)
    : order_id(order_id), customer(customer), products(products) {}

double Order::calculate_total() const {
    double total = 0.0;
    for (const auto& pair : products) {
        total += pair.first.get_price() * pair.second;
    }
    return total;
}

std::string Order::display_info() const {
    std::string product_list;
    for (const auto& pair : products) {
        product_list += pair.first.get_name() + " - $" + std::to_string(pair.first.get_price()) + ", Quantity: " + std::to_string(pair.second) + "\n";
    }
    return "Order ID: " + std::to_string(order_id) + "\nCustomer: " + customer.display_info() + "\nProducts:\n" + product_list + "\nTotal: $" + std::to_string(calculate_total());
}

Customer Order::get_customer() const {
    return customer;
}

std::vector<std::pair<Product, int>> Order::get_products() const {
    return products;
}
