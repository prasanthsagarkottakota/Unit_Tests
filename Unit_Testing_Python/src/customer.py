# customer.py
class Customer:
    def __init__(self, customer_id, name, email, credit_limit=0):
        self.customer_id = customer_id
        self.name = name
        self.email = email
        self.credit_limit = credit_limit

    def display_info(self):
        return f"Customer: {self.name} (ID: {self.customer_id}), Email: {self.email}"
