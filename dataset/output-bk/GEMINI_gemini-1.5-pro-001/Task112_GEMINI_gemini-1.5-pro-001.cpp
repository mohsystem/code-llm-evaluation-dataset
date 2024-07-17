#include <iostream>
#include <bsoncxx/builder/stream/document.hpp>
#include <bsoncxx/json.hpp>
#include <mongocxx/client.hpp>
#include <mongocxx/instance.hpp>
#include <mongocxx/uri.hpp>

using bsoncxx::builder::stream::document;
using bsoncxx::builder::stream::open_document;
using bsoncxx::builder::stream::close_document;

int main() {
    // Replace with your MongoDB connection string
    mongocxx::instance inst{};
    mongocxx::client conn{mongocxx::uri{"mongodb://localhost:27017"}};

    mongocxx::database db = conn["myDatabase"];
    mongocxx::collection coll = db["myCollection"];

    // Create
    bsoncxx::document::value new_document = document{}
        << "name" << "John Doe"
        << "age" << 30
        << "city" << "New York" << close_document;
    coll.insert_one(new_document.view());
    std::cout << "Document inserted successfully." << std::endl;

    // Read
    mongocxx::cursor cursor = coll.find({});
    for (auto&& doc : cursor) {
        std::cout << bsoncxx::to_json(doc) << std::endl;
    }

    // Update
    coll.update_one(
        document{} << "name" << "John Doe" << close_document,
        document{} << "$set" << open_document << "age" << 35 << close_document << close_document
    );
    std::cout << "Document updated successfully." << std::endl;

    // Delete
    coll.delete_one(document{} << "name" << "John Doe" << close_document);
    std::cout << "Document deleted successfully." << std::endl;

    return 0;
}