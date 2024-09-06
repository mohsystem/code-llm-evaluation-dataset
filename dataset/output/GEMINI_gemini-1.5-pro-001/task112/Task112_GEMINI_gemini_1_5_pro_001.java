import com.mongodb.MongoClient;
import com.mongodb.client.MongoCollection;
import com.mongodb.client.MongoDatabase;
import org.bson.Document;

public class Task112_GEMINI_gemini_1_5_pro_001 {

    public static void main(String[] args) {
        // Replace with your MongoDB connection string
        String connectionString = "mongodb://localhost:27017";

        try (MongoClient mongoClient = new MongoClient(connectionString)) {
            MongoDatabase database = mongoClient.getDatabase("mydatabase");
            MongoCollection<Document> collection = database.getCollection("customers");

            // Create
            Document document = new Document("name", "John").append("address", "Highway 37");
            collection.insertOne(document);

            // Read
            for (Document doc : collection.find()) {
                System.out.println(doc.toJson());
            }

            // Update
            collection.updateOne(new Document("address", "Valley 345"),
                    new Document("$set", new Document("address", "Canyon 123")));

            // Delete
            collection.deleteOne(new Document("name", "John"));
        }
    }
}