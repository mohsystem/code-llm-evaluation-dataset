# Python code using sqlite3 module
import sqlite3

# Connect to the SQLite database
conn = sqlite3.connect('my_database.db')

# Create a cursor object
cursor = conn.cursor()

# Get username from user
username = input("Enter username: ")

# Execute the query
cursor.execute("SELECT * FROM users WHERE username = ?", (username,))

# Fetch the results
results = cursor.fetchall()

# Print the results
for row in results:
    print(row)

# Close the connection
conn.close()