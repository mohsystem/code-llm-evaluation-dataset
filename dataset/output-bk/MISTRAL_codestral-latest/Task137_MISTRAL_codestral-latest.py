# Python

# Assuming we have a dictionary as our product table
product_table = {
    'product1': {'price': 10, 'quantity': 50},
    'product2': {'price': 20, 'quantity': 30},
    # Add more products as needed
}

def get_product_details(product_name):
    return product_table.get(product_name, 'Product not found')

product_name = input('Enter product name: ')
print(get_product_details(product_name))