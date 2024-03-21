# order.py
class Order:
    def __init__(self, order_id, customer, products):
        self.order_id = order_id
        self.customer = customer
        self.products = products

    def calculate_total(self):
        return sum(product.price * quantity for product, quantity in self.products)

    def display_info(self):
        product_list = "\n".join([f"{product.name} - ${product.price}, Quantity: {quantity}" for product, quantity in self.products])
        return f"Order ID: {self.order_id}\nCustomer: {self.customer.name}\nProducts:\n{product_list}\nTotal: ${self.calculate_total()}"
