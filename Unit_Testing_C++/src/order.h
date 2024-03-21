// order.h
#ifndef ORDER_H
#define ORDER_H

#include "customer.h"
#include "product.h"
#include <vector>

class Order {
private:
    int order_id;
    Customer customer;
    std::vector<std::pair<Product, int>> products;

public:
    Order(int order_id, Customer customer, std::vector<std::pair<Product, int>> products);
    double calculate_total() const;
    std::string display_info() const;
    Customer get_customer() const;
    std::vector<std::pair<Product, int>> get_products() const;

    // Add public member function to access customer
    //ustomer get_customer() const;
};

#endif // ORDER_H
