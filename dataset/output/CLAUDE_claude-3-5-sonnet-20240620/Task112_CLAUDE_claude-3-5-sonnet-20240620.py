
from pymongo import MongoClient

# Connect to MongoDB
client = MongoClient('mongodb://localhost:27017/')
db = client['mydatabase']
collection = db['mycollection']

# Create
def create_document(data):
    result = collection.insert_one(data)
    print(f"Inserted document with ID: {result.inserted_id}")

# Read
def read_documents():
    documents = collection.find()
    for doc in documents:
        print(doc)

# Update
def update_document(query, new_values):
    result = collection.update_one(query, {"$set": new_values})
    print(f"Modified {result.modified_count} document(s)")

# Delete
def delete_document(query):
    result = collection.delete_one(query)
    print(f"Deleted {result.deleted_count} document(s)")

# Example usage
if __name__ == "__main__":
    # Create
    create_document({"name": "John", "age": 30})
    
    # Read
    print("All documents:")
    read_documents()
    
    # Update
    update_document({"name": "John"}, {"age": 31})
    
    # Read again to see the update
    print("After update:")
    read_documents()
    
    # Delete
    delete_document({"name": "John"})
    
    # Read again to confirm deletion
    print("After deletion:")
    read_documents()

client.close()
