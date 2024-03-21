// ecommerce_platform.cpp
#include "ecommerce_platform.h"
#include "order.h"
#include <iostream>

ECommercePlatform::ECommercePlatform(std::string name)
    : name(name), order_counter(0) {}

void ECommercePlatform::add_product(Product product) {
    products.push_back(product);
}

void ECommercePlatform::add_customer(Customer customer) {
    customers.push_back(customer);
}

Order ECommercePlatform::create_order(int customer_id, std::vector<Product> products, std::vector<int> quantities) {
    Customer* customer = nullptr;
    std::vector<std::pair<Product, int>> productsMap;
    for (auto& cust : customers) {
        if (cust.get_customer_id() == customer_id) {
            customer = &cust;
            break;
        }
    }
    if (customer == nullptr || products.size()==0) {
        // Return a null order object if customer not found
      
        return Order(0, Customer(0, "", "", 0), {});
        //return NULL;
    }
    double total_cost=0.0;
    int order_counter = 0;
    for (size_t i = 0; i < products.size(); ++i) {
        int price = products[i].get_price();
        int quantity = quantities[i];
        if (products[i].get_stock() < quantity) {
            // Return a null order object if insufficient stock
            return Order(0, Customer(0, "", "", 0), {});
            //return NULL;
        }
        total_cost+= (price * quantity);
        products[i].update_stock(-quantity);
        productsMap.push_back({products[i],quantities[i]});
    }

    if (total_cost > customer->get_credit_limit()) {
        // Return a null order object if credit limit exceeded
        return Order(0, Customer(0, "", "", 0), {});
        //return NULL;
    }
    //orders.push_back(order);
    return Order(customer_id,* customer, productsMap);
    //return NULL;
}

