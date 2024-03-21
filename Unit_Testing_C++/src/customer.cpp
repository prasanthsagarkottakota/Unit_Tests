// customer.cpp
#include "customer.h"

//Customer::Customer(int customer_id, std::string name, std::string email, int credit_limit)
//    : customer_id(customer_id), name(name), email(email), credit_limit(credit_limit) {}
//Customer::Customer(int customer_id, const char* name, const char* email, int credit_limit)
//    : customer_id(customer_id), name(name), email(email), credit_limit(credit_limit) {}

//Customer::Customer() {
    // Initialize default values or leave empty
//}

Customer::Customer(int customer_id, const std::string& name, const std::string& email, const int credit_limit)
    : customer_id(customer_id), name(name), email(email), credit_limit(credit_limit) {}


std::string Customer::display_info() const {
    return "Customer: " + name + " (ID: " + std::to_string(customer_id) + "), Email: " + email;
}

std::string Customer::get_name() const {
    return name;
}

std::string Customer::get_email() const {
    return email;
}

int Customer::get_customer_id() const {
    return customer_id;
}

int Customer::get_credit_limit() const {
    return credit_limit;
}
