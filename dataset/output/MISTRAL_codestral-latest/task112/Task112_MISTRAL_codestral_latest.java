// Java
import com.mongodb.client.MongoClients;
import com.mongodb.client.MongoClient;
import com.mongodb.client.MongoDatabase;
import com.mongodb.client.MongoCollection;
import org.bson.Document;
import com.mongodb.client.model.Filters;
import com.mongodb.client.model.Updates;

public class Task112_MISTRAL_codestral_latest {
    public static void main(String[] args) {
        // Create a connection
        MongoClient mongoClient = MongoClients.create("mongodb://localhost:27017");

        // Create a database
        MongoDatabase database = mongoClient.getDatabase("test-database");

        // Create a collection
        MongoCollection<Document> collection = database.getCollection("test-collection");

        // Insert a document
        Document document = new Document("name", "John").append("age", 30);
        collection.insertOne(document);

        // Read a document
        System.out.println(collection.find(Filters.eq("name", "John")).first());

        // Update a document
        collection.updateOne(Filters.eq("name", "John"), Updates.set("age", 31));

        // Delete a document
        collection.deleteOne(Filters.eq("name", "John"));

        // Close the connection
        mongoClient.close();
    }
}