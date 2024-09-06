# Python

# Assuming we have a dictionary as our product table
product_table = {
    "P123": {"name": "Product 1", "price": 10.99, "quantity": 100},
    "P456": {"name": "Product 2", "price": 20.99, "quantity": 50},
    # Add more products as needed
}

def get_product_details(product_id):
    if product_id in product_table:
        return product_table[product_id]
    else:
        return "Product not found"

# Get user input
product_id = input("Enter product ID: ")

# Get product details
product_details = get_product_details(product_id)

# Print product details
print(product_details)