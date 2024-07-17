from pymongo import MongoClient

client = MongoClient("mongodb://localhost:27017")
db = client["mydatabase"]
collection = db["mycollection"]

# Create
doc = {"name": "John", "age": 30}
collection.insert_one(doc)

# Read
found_doc = collection.find_one()
print(found_doc)

# Update
collection.update_one(found_doc, {"$set": {"age": 31}})

# Delete
collection.delete_one(found_doc)
client.close()