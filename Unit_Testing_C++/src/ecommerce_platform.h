// ecommerce_platform.h
#ifndef ECOMMERCE_PLATFORM_H
#define ECOMMERCE_PLATFORM_H

#include "product.h"
#include "customer.h"
#include "order.h"
#include <string>
#include <vector>

class ECommercePlatform {
private:
    std::string name;
    std::vector<Product> products;
    std::vector<Customer> customers;
    std::vector<Order> orders;
    int order_counter;

public:
    ECommercePlatform(std::string name);
    void add_product(Product product);
    void add_customer(Customer customer);
    //std::string create_order(int customer_id, std::vector<int> product_ids, std::vector<int> quantities);
    Order create_order(int customer_id, std::vector<Product> products, std::vector<int> quantities);
    double get_product_price(int product_id) const;
};

#endif // ECOMMERCE_PLATFORM_H
