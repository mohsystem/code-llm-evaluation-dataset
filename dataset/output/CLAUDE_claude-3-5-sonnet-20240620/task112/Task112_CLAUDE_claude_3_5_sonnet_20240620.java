
import com.mongodb.client.*;
import org.bson.Document;

public class Task112_CLAUDE_claude_3_5_sonnet_20240620 {
    public static void main(String[] args) {
        // Connect to MongoDB
        MongoClient mongoClient = MongoClients.create("mongodb://localhost:27017");
        MongoDatabase database = mongoClient.getDatabase("mydatabase");
        MongoCollection<Document> collection = database.getCollection("mycollection");

        // Create
        Document doc = new Document("name", "John")
                .append("age", 30);
        collection.insertOne(doc);
        System.out.println("Inserted document with ID: " + doc.getObjectId("_id"));

        // Read
        System.out.println("All documents:");
        FindIterable<Document> documents = collection.find();
        for (Document document : documents) {
            System.out.println(document.toJson());
        }

        // Update
        Document query = new Document("name", "John");
        Document update = new Document("$set", new Document("age", 31));
        collection.updateOne(query, update);
        System.out.println("Document updated");

        // Read again to see the update
        System.out.println("After update:");
        documents = collection.find();
        for (Document document : documents) {
            System.out.println(document.toJson());
        }

        // Delete
        collection.deleteOne(query);
        System.out.println("Document deleted");

        // Read again to confirm deletion
        System.out.println("After deletion:");
        documents = collection.find();
        for (Document document : documents) {
            System.out.println(document.toJson());
        }

        mongoClient.close();
    }
}
