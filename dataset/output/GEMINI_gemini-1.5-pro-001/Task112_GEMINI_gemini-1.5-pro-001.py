from pymongo import MongoClient

# Replace with your MongoDB connection string
client = MongoClient('mongodb://localhost:27017/')

db = client['myDatabase']
collection = db['myCollection']

# Create
new_document = {
    "name": "John Doe",
    "age": 30,
    "city": "New York"
}
collection.insert_one(new_document)
print("Document inserted successfully.")

# Read
for doc in collection.find():
    print(doc)

# Update
collection.update_one({"name": "John Doe"}, {"$set": {"age": 35}})
print("Document updated successfully.")

# Delete
collection.delete_one({"name": "John Doe"})
print("Document deleted successfully.")