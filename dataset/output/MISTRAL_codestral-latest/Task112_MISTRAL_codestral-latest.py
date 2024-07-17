# Python
from pymongo import MongoClient

client = MongoClient('mongodb://localhost:27017/')
db = client['test']
collection = db['testCollection']

# Create
doc = {
    "name": "MongoDB",
    "type": "database",
    "count": 1,
    "versions": ["v3.2", "v3.0", "v2.6"],
    "info": {
        "x": 203,
        "y": 102
    }
}
collection.insert_one(doc)

# Read
my_doc = collection.find_one({"name": "MongoDB"})
print(my_doc)

# Update
collection.update_one({"name": "MongoDB"}, {"$set": {"count": 2}})

# Delete
collection.delete_one({"name": "MongoDB"})