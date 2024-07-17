// Java
import com.mongodb.client.MongoClients;
import com.mongodb.client.MongoClient;
import com.mongodb.client.MongoDatabase;
import com.mongodb.client.MongoCollection;
import org.bson.Document;
import java.util.Arrays;
import com.mongodb.client.model.Filters;
import com.mongodb.client.model.Updates;

public class MongoDBExample {
    public static void main(String[] args) {
        MongoClient mongoClient = MongoClients.create("mongodb://localhost:27017");
        MongoDatabase database = mongoClient.getDatabase("test");
        MongoCollection<Document> collection = database.getCollection("testCollection");

        // Create
        Document doc = new Document("name", "MongoDB")
            .append("type", "database")
            .append("count", 1)
            .append("versions", Arrays.asList("v3.2", "v3.0", "v2.6"))
            .append("info", new Document("x", 203).append("y", 102));
        collection.insertOne(doc);

        // Read
        Document myDoc = collection.find(Filters.eq("name", "MongoDB")).first();
        System.out.println(myDoc.toJson());

        // Update
        collection.updateOne(Filters.eq("name", "MongoDB"), Updates.set("count", 2));

        // Delete
        collection.deleteOne(Filters.eq("name", "MongoDB"));

        mongoClient.close();
    }
}