import com.mongodb.MongoClient;
import com.mongodb.client.MongoCollection;
import com.mongodb.client.MongoDatabase;
import org.bson.Document;
import static com.mongodb.client.model.Filters.eq;

public class MongoDBCRUD {
    public static void main(String[] args) {
        MongoClient mongoClient = new MongoClient("localhost", 27017);
        MongoDatabase database = mongoClient.getDatabase("mydb");
        MongoCollection<Document> collection = database.getCollection("test");

        // Create
        Document doc = new Document("name", "John Doe").append("age", 30);
        collection.insertOne(doc);

        // Read
        Document myDoc = collection.find(eq("name", "John Doe")).first();
        System.out.println(myDoc.toJson());

        // Update
        collection.updateOne(eq("name", "John Doe"), new Document("$set", new Document("age", 31)));

        // Delete
        collection.deleteOne(eq("name", "John Doe"));

        mongoClient.close();
    }
}