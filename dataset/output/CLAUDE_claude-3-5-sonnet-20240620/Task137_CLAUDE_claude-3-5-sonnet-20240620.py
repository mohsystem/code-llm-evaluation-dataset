
import sqlite3

def create_table():
    conn = sqlite3.connect('products.db')
    cursor = conn.cursor()
    cursor.execute('''CREATE TABLE IF NOT EXISTS products\n                      (id INTEGER PRIMARY KEY,\n                       name TEXT,\n                       price REAL)''')
    conn.commit()
    conn.close()

def add_product(name, price):
    conn = sqlite3.connect('products.db')
    cursor = conn.cursor()
    cursor.execute("INSERT INTO products (name, price) VALUES (?, ?)", (name, price))
    conn.commit()
    conn.close()

def get_product(product_id):
    conn = sqlite3.connect('products.db')
    cursor = conn.cursor()
    cursor.execute("SELECT * FROM products WHERE id=?", (product_id,))
    product = cursor.fetchone()
    conn.close()
    return product

def main():
    create_table()

    while True:
        print("\\n1. Add product")
        print("2. Get product details")
        print("3. Exit")
        choice = input("Enter your choice: ")

        if choice == '1':
            name = input("Enter product name: ")
            price = float(input("Enter product price: "))
            add_product(name, price)
            print("Product added successfully!")
        elif choice == '2':
            product_id = int(input("Enter product ID: "))
            product = get_product(product_id)
            if product:
                print(f"ID: {product[0]}, Name: {product[1]}, Price: ${product[2]:.2f}")
            else:
                print("Product not found.")
        elif choice == '3':
            break
        else:
            print("Invalid choice. Please try again.")

if __name__ == "__main__":
    main()
