import com.mongodb.client.MongoClients;
import com.mongodb.client.MongoClient;
import com.mongodb.client.MongoCollection;
import com.mongodb.client.MongoDatabase;
import org.bson.Document;

public class Task112_PERPLEXITY_llama_3_sonar_large_32k_chat {
    public static void main(String[] args) {
        MongoClient client = MongoClients.create("mongodb://localhost:27017/");
        MongoDatabase db = client.getDatabase("mydatabase");
        MongoCollection<Document> collection = db.getCollection("mycollection");

        // Create
        Document data = new Document("name", "John").append("age", 30);
        collection.insertOne(data);

        // Read
        Document readData = collection.find(new Document("name", "John")).first();
        System.out.println(readData);

        // Update
        collection.updateOne(new Document("name", "John"), new Document("$set", new Document("age", 31)));

        // Delete
        collection.deleteOne(new Document("name", "John"));
    }
}