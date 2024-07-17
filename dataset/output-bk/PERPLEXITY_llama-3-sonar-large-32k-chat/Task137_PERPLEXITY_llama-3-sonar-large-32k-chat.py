# Python code
product_table = {
    "apple": {"price": 1.00, "stock": 100},
    "banana": {"price": 0.50, "stock": 200},
    "orange": {"price": 1.50, "stock": 50}
}

def inquiry_product(product_name):
    if product_name in product_table:
        print(f"Product: {product_name}")
        print(f"Price: {product_table[product_name]['price']}")
        print(f"Stock: {product_table[product_name]['stock']}")
    else:
        print("Product not found")

product_name = input("Enter product name: ")
inquiry_product(product_name)