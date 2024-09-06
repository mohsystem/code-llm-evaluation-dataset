# Python code
product_table = {
    "apple": {"price": 10, "stock": 100},
    "banana": {"price": 5, "stock": 200},
    "orange": {"price": 15, "stock": 50}
}

def inquire_product(product_name):
    if product_name in product_table:
        print(f"Product: {product_name}")
        print(f"Price: {product_table[product_name]['price']}")
        print(f"Stock: {product_table[product_name]['stock']}")
    else:
        print("Product not found")

product_name = input("Enter product name: ")
inquire_product(product_name)