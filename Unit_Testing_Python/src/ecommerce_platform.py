# ecommerce_platform.py
from order import Order
class ECommercePlatform:
    def __init__(self, name):
        self.name = name
        self.products = []
        self.customers = []
        self.orders = []
        self.order_counter = 0

    def add_product(self, product):
        self.products.append(product)

    def add_customer(self, customer):
        self.customers.append(customer)

    def create_order(self, customer_id, product_ids, quantities):
        print("List of customers:", self.customers)  # Print list of customers
        print("Customer ID:", customer_id)  # Print customer ID
        customer = next((c for c in self.customers if c.customer_id == customer_id),None)
        if not customer:
            return "Customer not found."

        

        products = []
        for product_id, quantity in zip(product_ids, quantities):
            product = next((p for p in self.products if p.product_id == product_id), None)
            if product:
                if product.stock >= quantity:
                    products.append((product, quantity))
                    product.stock -= quantity
                else:
                    return f"Insufficient stock for product {product_id}. Available stock: {product.stock}"
            else:
                return f"Product with ID {product_id} not found."
        
        # Check if the total order cost exceeds the customer's credit limit
        total_cost = sum(self._get_product_price(product_id) * quantity for product_id, quantity in zip(product_ids, quantities))
        if total_cost > customer.credit_limit:
            return "Customer credit limit exceeded."

        if products:
            self.order_counter += 1
            order = Order(self.order_counter, customer, products)
            self.orders.append(order)
            return order
        else:
            return "No valid products in the order."

    def _get_product_price(self, product_id):
        product = next((p for p in self.products if p.product_id == product_id), None)
        return product.price if product else 0
