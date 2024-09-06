import pymongo

client = pymongo.MongoClient("mongodb://localhost:27017/")
db = client["mydatabase"]
collection = db["mycollection"]

# Create
data = {"name": "John", "age": 30}
collection.insert_one(data)

# Read
data = collection.find_one({"name": "John"})
print(data)

# Update
collection.update_one({"name": "John"}, {"$set": {"age": 31}})

# Delete
collection.delete_one({"name": "John"})