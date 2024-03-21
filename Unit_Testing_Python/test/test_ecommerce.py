import sys
import os

import pytest

# Get the absolute path of the 'src' directory
src_path = os.path.abspath(os.path.join(os.path.dirname(__file__), '..', 'src'))

# Add the 'src' directory to the Python path
sys.path.append(src_path)

# Print all paths
print("Current Python paths:")
for path in sys.path:
    print(path)

# Now try to import modules
try:
    from product import Product
    from customer import Customer
    from order import Order
    from ecommerce_platform import ECommercePlatform

    print("Modules imported successfully!")
except ImportError as e:
    print("Error importing modules:", e)

# Your tests continue here...


@pytest.fixture
def platform():
    platform = ECommercePlatform("CampusStore")

    product1 = Product(1, "Laptop", 999, 10)
    product2 = Product(2, "Headphones", 99, 20)
    platform.add_product(product1)
    platform.add_product(product2)

    customer1 = Customer(1, "Alice", "alice@syr.edu", credit_limit = 10000)
    customer2 = Customer(2, "Bob", "bob@syr.edu", credit_limit = 10000)
    platform.add_customer(customer1)
    platform.add_customer(customer2)

    return platform

def test_create_order(platform):
    order = platform.create_order(1, [1, 2], [5, 3])
    if order is not None:  # Check if order is not None
        assert order.customer.name == "Alice"
        assert len(order.products) == 2
        assert order.calculate_total() == 5 * 999 + 3 * 99
    else:
        assert False, "Customer not found."


def test_create_order_invalid_customer(platform):
    assert platform.create_order(3, [1, 2], [1, 1]) == "Customer not found."

def test_create_order_invalid_product(platform):
    assert platform.create_order(1, [3, 4], [1, 1]) == "Product with ID 3 not found."

def test_create_order_invalid_quantities(platform):
    assert platform.create_order(1, [1, 2], [20, 30]) == "Insufficient stock for product 1. Available stock: 10"

def test_create_order_out_of_stock(platform):
    assert platform.create_order(1, [1, 2], [9, 25]) == "Insufficient stock for product 2. Available stock: 20"

def test_create_order_stock_updated(platform):
    platform.create_order(1, [1], [5])
    assert platform.products[0].stock == 5  # Stock should be updated after order creation

def test_create_order_exceed_credit_limit(platform):
    customer = Customer(3, "Charlie", "charlie@syr.edu", credit_limit=1000)
    platform.add_customer(customer)
    assert platform.create_order(3, [1, 2], [6, 6]) == "Customer credit limit exceeded."

if __name__ == "__main__":
    pytest.main()