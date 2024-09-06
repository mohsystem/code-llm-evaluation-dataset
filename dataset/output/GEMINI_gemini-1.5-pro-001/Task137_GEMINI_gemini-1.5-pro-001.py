products = {
    "001": {"name": "Apple", "price": 1.00, "stock": 100},
    "002": {"name": "Banana", "price": 0.50, "stock": 50},
    "003": {"name": "Orange", "price": 1.20, "stock": 75},
}

def get_product_details(product_id):
    product = products.get(product_id)
    if product:
        return f"Product Name: {product['name']}\nPrice: ${product['price']:.2f}\nStock: {product['stock']}"
    else:
        return "Product not found."

while True:
    product_id = input("Enter product ID (or 'q' to quit): ")
    if product_id == 'q':
        break
    print(get_product_details(product_id))