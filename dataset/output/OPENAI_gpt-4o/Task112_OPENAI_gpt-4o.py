from pymongo import MongoClient

def main():
    # Connection to MongoDB
    client = MongoClient('localhost', 27017)
    db = client['mydatabase']
    collection = db['mycollection']

    # Create
    document = {"name": "John", "age": 30, "city": "New York"}
    collection.insert_one(document)

    # Read
    result = collection.find_one({"name": "John"})
    print("Read:", result)

    # Update
    query = {"name": "John"}
    new_values = {"$set": {"age": 31}}
    collection.update_one(query, new_values)
    
    # Verify update
    result = collection.find_one({"name": "John"})
    print("Updated:", result)

    # Delete
    collection.delete_one({"name": "John"})

    # Verify delete
    result = collection.find_one({"name": "John"})
    print("Deleted:", result)

if __name__ == "__main__":
    main()