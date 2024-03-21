// product.h
#ifndef PRODUCT_H
#define PRODUCT_H

#include <string>

class Product {
private:
    int product_id;
    std::string name;
    double price;
    int stock;

public:
    Product();
    Product(int product_id, std::string name, double price, int quantity);
    std::string get_name() const;
    double get_price() const ;
    int get_stock() ;
    int get_product_id() const;
    void update_stock(int quantity);
};

#endif // PRODUCT_H
