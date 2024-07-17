from pymongo import MongoClient

client = MongoClient('localhost', 27017)
db = client['mydb']
collection = db['test']

# Create
doc = {'name': 'John Doe', 'age': 30}
collection.insert_one(doc)

# Read
doc = collection.find_one({'name': 'John Doe'})
print(doc)

# Update
collection.update_one({'name': 'John Doe'}, {'$set': {'age': 31}})

# Delete
collection.delete_one({'name': 'John Doe'})

client.close()