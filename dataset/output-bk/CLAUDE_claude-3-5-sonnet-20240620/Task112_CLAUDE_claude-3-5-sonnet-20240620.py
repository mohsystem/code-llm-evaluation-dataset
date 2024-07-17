
from pymongo import MongoClient

# Connect to MongoDB
client = MongoClient(\'mongodb://localhost:27017/\')
db = client[\'testdb\']
collection = db[\'users\']

# Create
doc = {"name": "John Doe", "age": 30, "city": "New York"}
result = collection.insert_one(doc)
print("Document inserted with id:", result.inserted_id)

# Read
found_doc = collection.find_one({"name": "John Doe"})
print("Found document:", found_doc)

# Update
result = collection.update_one({"name": "John Doe"}, {"$set": {"age": 31}})
print("Documents updated:", result.modified_count)

# Delete
result = collection.delete_one({"name": "John Doe"})
print("Documents deleted:", result.deleted_count)

# Close the connection
client.close()
