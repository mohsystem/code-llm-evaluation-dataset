
#include <iostream>
#include <bsoncxx/json.hpp>
#include <mongocxx/client.hpp>
#include <mongocxx/instance.hpp>
#include <bsoncxx/builder/stream/document.hpp>

int main() {
    mongocxx::instance inst{};
    mongocxx::client conn{mongocxx::uri{"mongodb://localhost:27017"}};

    auto db = conn["testdb"];
    auto collection = db["users"];

    // Create
    auto builder = bsoncxx::builder::stream::document{};
    bsoncxx::document::value doc_value = builder
        << "name" << "John Doe"
        << "age" << 30
        << "city" << "New York"
        << bsoncxx::builder::stream::finalize;
    collection.insert_one(doc_value.view());
    std::cout << "Document inserted" << std::endl;

    // Read
    auto cursor = collection.find(bsoncxx::builder::stream::document{} << "name" << "John Doe" << bsoncxx::builder::stream::finalize);
    for (auto&& doc : cursor) {
        std::cout << "Found document: " << bsoncxx::to_json(doc) << std::endl;
    }

    // Update
    collection.update_one(
        bsoncxx::builder::stream::document{} << "name" << "John Doe" << bsoncxx::builder::stream::finalize,
        bsoncxx::builder::stream::document{} << "$set" << bsoncxx::builder::stream::open_document
            << "age" << 31
        << bsoncxx::builder::stream::close_document << bsoncxx::builder::stream::finalize
    );
    std::cout << "Document updated" << std::endl;

    // Delete
    collection.delete_one(bsoncxx::builder::stream::document{} << "name" << "John Doe" << bsoncxx::builder::stream::finalize);
    std::cout << "Document deleted" << std::endl;

    return 0;
}
