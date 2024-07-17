import sqlite3

conn = sqlite3.connect('mydatabase.db')
cursor = conn.cursor()

cursor.execute('''
    CREATE TABLE IF NOT EXISTS products (
        id INTEGER PRIMARY KEY,
        name TEXT NOT NULL,
        description TEXT,
        price REAL
    )
''')

cursor.execute("INSERT INTO products (name, description, price) VALUES (?, ?, ?)", ('Apple', 'A sweet red fruit', 1.00))
cursor.execute("INSERT INTO products (name, description, price) VALUES (?, ?, ?)", ('Banana', 'A yellow curved fruit', 0.50))
cursor.execute("INSERT INTO products (name, description, price) VALUES (?, ?, ?)", ('Milk', 'A white dairy drink', 2.50))
conn.commit()

while True:
    product_name = input("Enter a product name (or 'quit' to exit): ")
    if product_name == 'quit':
        break

    cursor.execute("SELECT * FROM products WHERE name=?", (product_name,))
    product = cursor.fetchone()

    if product:
        print("Product details:")
        print(f"  ID: {product[0]}")
        print(f"  Name: {product[1]}")
        print(f"  Description: {product[2]}")
        print(f"  Price: {product[3]}")
    else:
        print(f"Product '{product_name}' not found.")

conn.close()