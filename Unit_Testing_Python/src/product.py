# product.py
class Product:
    def __init__(self, product_id, name, price, quantity):
        self.product_id = product_id
        self.name = name
        self.price = price
        self.quantity = quantity
        self.stock = quantity

    def display_info(self):
        return f"{self.name} - Price: ${self.price}, Quantity: {self.quantity}"

    def update_quantity(self, quantity):
        self.quantity += quantity
        self.stock += quantity
