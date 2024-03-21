// test_ecommerce_platform.cpp
#include <gtest/gtest.h>
#include "src/product.h"
#include "src/customer.h"
#include "src/order.h"
#include "src/ecommerce_platform.h"


TEST (ECommercePlatformTest, CreateValidOrder) {
    ECommercePlatform platform("CampusStore");

    // Add products to the platform
    Product product1(1, "Laptop", 999, 10);
    Product product2(2, "Headphones", 99, 20);
    platform.add_product(product1);
    platform.add_product(product2);

    // Add customers to the platform
    //Customer customer1(1, "Alice", "alice@syr.edu", 10000);
    //Customer customer1(1, std::string("Alice"), std::string("alice@syr.edu"), 10000);
    Customer customer1(1, std::string("Alice"), std::string("alice@syr.edu"), 10000);


    Customer customer2(2, "Bob", "bob@syr.edu", 10000);
    platform.add_customer(customer1);
    platform.add_customer(customer2);

    // Test case: Valid order
    //std::vector<int> product_ids = {1, 2};
    std::vector<Product> products = {product1, product2};
    std::vector<int> quantities = {5, 3};

    Order order = platform.create_order(1, products , quantities);

    ASSERT_EQ(order.get_customer().get_name(), "Alice");
    ASSERT_EQ(order.get_products().size(), 2);
    ASSERT_DOUBLE_EQ(order.calculate_total(), 5 * 999 + 3 * 99);
}

// Test case: Create order with wrong customer ID
TEST (ECommercePlatformTest, CreateOrderWrongCustomerID) {
    // Setup: Add platform, products, and customers
    ECommercePlatform platform("CampusStore");
    Product product1(1, "Laptop", 999, 10);
    Product product2(2, "Headphones", 99, 20);
    platform.add_product(product1);
    platform.add_product(product2);
    Customer customer1(1, "Alice", "alice@syr.edu", 10000);
    platform.add_customer(customer1);

    // Action: Create order with wrong customer ID
    std::vector<Product> products = {product1, product2};
    std::vector<int> quantities = {5, 3};
    Order order_wrong_customer = platform.create_order(3, products, quantities);

    // Assertion: Check order is empty
    ASSERT_EQ(order_wrong_customer.get_customer().get_name(), "");
    ASSERT_EQ(order_wrong_customer.get_products().size(), 0);
    ASSERT_DOUBLE_EQ(order_wrong_customer.calculate_total(), 0);
}

// Test case: Creditlimitexceed
TEST (ECommercePlatformTest, Creditlimitexceed) {
    // Setup: Add platform, products, and customers
    ECommercePlatform platform("CampusStore");
    Product product1(1, "Laptop", 999, 10);
    Product product2(2, "Headphones", 99, 20);
    platform.add_product(product1);
    platform.add_product(product2);
    Customer customer1(1, "Alice", "alice@syr.edu", 1000);
    platform.add_customer(customer1);

    // Action: Create order with wrong customer ID
    std::vector<Product> products = {product1, product2};
    std::vector<int> quantities = {5, 3};
    Order Creditlimitexceed = platform.create_order(1, products, quantities);

    // Assertion: Check order is empty
    ASSERT_EQ(Creditlimitexceed.get_customer().get_name(), "");
    ASSERT_EQ(Creditlimitexceed.get_products().size(), 0);
    ASSERT_DOUBLE_EQ(Creditlimitexceed.calculate_total(), 0);
}

// Test case: quantityexceed
TEST (ECommercePlatformTest, quantityexceed) {
    // Setup: Add platform, products, and customers
    ECommercePlatform platform("CampusStore");
    Product product1(1, "Laptop", 999, 10);
    Product product2(2, "Headphones", 99, 20);
    platform.add_product(product1);
    platform.add_product(product2);
    Customer customer1(1, "Alice", "alice@syr.edu", 10000);
    platform.add_customer(customer1);

    // Action: Create order with wrong customer ID
    std::vector<Product> products = {product1, product2};
    std::vector<int> quantities = {5, 40};
    Order quantityexceed = platform.create_order(1, products, quantities);

    // Assertion: Check order is empty
    ASSERT_EQ(quantityexceed.get_customer().get_name(), "");
    ASSERT_EQ(quantityexceed.get_products().size(), 0);
    ASSERT_DOUBLE_EQ(quantityexceed.calculate_total(), 0);
}
// Add more test cases as needed

// Entry point for the test program
int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}