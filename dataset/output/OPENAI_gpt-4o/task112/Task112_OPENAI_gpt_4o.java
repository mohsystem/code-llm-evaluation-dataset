import com.mongodb.MongoClient;
import com.mongodb.client.MongoCollection;
import com.mongodb.client.MongoDatabase;
import org.bson.Document;

public class Task112_OPENAI_gpt_4o {
    public static void main(String[] args) {
        // Connection to MongoDB
        MongoClient mongoClient = new MongoClient("localhost", 27017);
        MongoDatabase database = mongoClient.getDatabase("mydatabase");
        MongoCollection<Document> collection = database.getCollection("mycollection");

        // Create
        Document document = new Document("name", "John")
                .append("age", 30)
                .append("city", "New York");
        collection.insertOne(document);

        // Read
        Document query = new Document("name", "John");
        Document result = collection.find(query).first();
        System.out.println("Read: " + result);

        // Update
        Document newValues = new Document("$set", new Document("age", 31));
        collection.updateOne(query, newValues);

        // Verify Update
        result = collection.find(query).first();
        System.out.println("Updated: " + result);

        // Delete
        collection.deleteOne(query);

        // Verify Delete
        result = collection.find(query).first();
        System.out.println("Deleted: " + result);

        mongoClient.close();
    }
}