// CPP
// Note: C++ does not have a built-in MongoDB driver. You need to use a third-party library like mongocxx.
// This example uses mongocxx.
#include <mongocxx/client.hpp>
#include <mongocxx/stdx.hpp>
#include <mongocxx/uri.hpp>
#include <bsoncxx/builder/stream/document.hpp>
#include <bsoncxx/json.hpp>

int main() {
    // Create a connection
    mongocxx::uri uri("mongodb://localhost:27017");
    mongocxx::client client(uri);

    // Create a database
    auto database = client["test-database"];

    // Create a collection
    auto collection = database["test-collection"];

    // Insert a document
    bsoncxx::builder::stream::document document{};
    document << "name" << "John" << "age" << 30;
    collection.insert_one(document.view());

    // Read a document
    auto result = collection.find_one(bsoncxx::builder::stream::document{} << "name" << "John");
    if (result) {
        std::cout << bsoncxx::to_json(*result) << std::endl;
    }

    // Update a document
    bsoncxx::builder::stream::document update_document{};
    update_document << "$set" << bsoncxx::builder::stream::document{} << "age" << 31;
    collection.update_one(bsoncxx::builder::stream::document{} << "name" << "John", update_document.view());

    // Delete a document
    collection.delete_one(bsoncxx::builder::stream::document{} << "name" << "John");

    return 0;
}