import com.mongodb.client.MongoClients;
import com.mongodb.client.MongoClient;
import com.mongodb.client.MongoCollection;
import com.mongodb.client.MongoDatabase;
import org.bson.Document;

public class MongoDBCRUD {
    public static void main(String[] args) {
        MongoClient client = MongoClients.create("mongodb://localhost:27017");
        MongoDatabase database = client.getDatabase("mydatabase");
        MongoCollection<Document> collection = database.getCollection("mycollection");

        // Create
        Document doc = new Document("name", "John").append("age", 30);
        collection.insertOne(doc);

        // Read
        Document foundDoc = collection.find().first();
        System.out.println(foundDoc.toJson());

        // Update
        collection.updateOne(foundDoc, new Document("$set", new Document("age", 31)));

        // Delete
        collection.deleteOne(foundDoc);
        client.close();
    }
}