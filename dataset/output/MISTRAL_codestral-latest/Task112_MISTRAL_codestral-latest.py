# Python
from pymongo import MongoClient

# Create a connection
client = MongoClient('localhost', 27017)

# Create a database
db = client['test-database']

# Create a collection
collection = db['test-collection']

# Insert a document
document = {"name": "John", "age": 30}
collection.insert_one(document)

# Read a document
print(collection.find_one({"name": "John"}))

# Update a document
collection.update_one({"name": "John"}, {"$set": {"age": 31}})

# Delete a document
collection.delete_one({"name": "John"})