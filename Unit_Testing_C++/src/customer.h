// customer.h
#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <string>

class Customer {
private:
    int customer_id;
    std::string name;
    std::string email;
    int credit_limit;

public:
    //Customer(int customer_id, std::string name, std::string email, int credit_limit = 0);
    //Customer(int customer_id, const char* name, const char* email, int credit_limit = 0);
    Customer();
    Customer(int customer_id, const std::string& name, const std::string& email, const int credit_limit);
    std::string get_name() const;
    std::string display_info() const;
    std::string get_email() const;
    int get_customer_id() const;
    int get_credit_limit() const;
};

#endif // CUSTOMER_H
