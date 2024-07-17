import sqlite3

conn = sqlite3.connect(':memory:')
c = conn.cursor()
c.execute('''CREATE TABLE product (id INTEGER PRIMARY KEY, name TEXT, price REAL)''')
c.execute("INSERT INTO product (name, price) VALUES ('Apple', 1.0)")
c.execute("INSERT INTO product (name, price) VALUES ('Banana', 0.5)")
c.execute("INSERT INTO product (name, price) VALUES ('Cherry', 2.0)")
conn.commit()

product_name = input("Enter product name: ")
c.execute("SELECT * FROM product WHERE name=?", (product_name,))
product = c.fetchone()
if product:
    print(f"Product ID: {product[0]}, Name: {product[1]}, Price: {product[2]}")
else:
    print("Product not found.")

conn.close()