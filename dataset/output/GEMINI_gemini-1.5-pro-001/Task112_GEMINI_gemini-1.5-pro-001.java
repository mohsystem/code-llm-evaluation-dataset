import com.mongodb.client.*;
import com.mongodb.client.model.Filters;
import com.mongodb.client.model.Updates;
import org.bson.Document;

public class MongoDBExample {

    public static void main(String[] args) {
        // Replace with your MongoDB connection string
        String connectionString = "mongodb://localhost:27017";
        try (MongoClient mongoClient = MongoClients.create(connectionString)) {
            MongoDatabase database = mongoClient.getDatabase("myDatabase");
            MongoCollection<Document> collection = database.getCollection("myCollection");

            // Create
            Document newDocument = new Document("name", "John Doe")
                    .append("age", 30)
                    .append("city", "New York");
            collection.insertOne(newDocument);
            System.out.println("Document inserted successfully.");

            // Read
            FindIterable<Document> documents = collection.find();
            for (Document doc : documents) {
                System.out.println(doc.toJson());
            }

            // Update
            collection.updateOne(Filters.eq("name", "John Doe"), Updates.set("age", 35));
            System.out.println("Document updated successfully.");

            // Delete
            collection.deleteOne(Filters.eq("name", "John Doe"));
            System.out.println("Document deleted successfully.");
        }
    }
}