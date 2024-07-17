
import com.mongodb.client.*;
import org.bson.Document;
import static com.mongodb.client.model.Filters.*;
import static com.mongodb.client.model.Updates.*;

public class MongoDBCRUD {
    public static void main(String[] args) {
        try (MongoClient mongoClient = MongoClients.create("mongodb://localhost:27017")) {
            MongoDatabase database = mongoClient.getDatabase("testdb");
            MongoCollection<Document> collection = database.getCollection("users");

            // Create
            Document doc = new Document("name", "John Doe")
                    .append("age", 30)
                    .append("city", "New York");
            collection.insertOne(doc);
            System.out.println("Document inserted");

            // Read
            Document foundDoc = collection.find(eq("name", "John Doe")).first();
            System.out.println("Found document: " + foundDoc.toJson());

            // Update
            collection.updateOne(eq("name", "John Doe"), set("age", 31));
            System.out.println("Document updated");

            // Delete
            collection.deleteOne(eq("name", "John Doe"));
            System.out.println("Document deleted");
        }
    }
}
