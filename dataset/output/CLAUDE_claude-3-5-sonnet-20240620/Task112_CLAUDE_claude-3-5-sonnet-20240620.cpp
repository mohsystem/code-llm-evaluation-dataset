
#include <iostream>
#include <bsoncxx/json.hpp>
#include <mongocxx/client.hpp>
#include <mongocxx/instance.hpp>

int main() {
    // Initialize the MongoDB C++ driver
    mongocxx::instance inst{};
    mongocxx::client conn{mongocxx::uri{"mongodb://localhost:27017"}};

    auto db = conn["mydatabase"];
    auto collection = db["mycollection"];

    // Create
    auto doc = bsoncxx::builder::stream::document{} << "name" << "John" << "age" << 30 << bsoncxx::builder::stream::finalize;
    auto result = collection.insert_one(doc.view());
    std::cout << "Inserted document with ID: " << result->inserted_id().get_oid().value.to_string() << std::endl;

    // Read
    std::cout << "All documents:" << std::endl;
    auto cursor = collection.find({});
    for (auto&& doc : cursor) {
        std::cout << bsoncxx::to_json(doc) << std::endl;
    }

    // Update
    auto filter = bsoncxx::builder::stream::document{} << "name" << "John" << bsoncxx::builder::stream::finalize;
    auto update = bsoncxx::builder::stream::document{} << "$set" << bsoncxx::builder::stream::open_document << "age" << 31 << bsoncxx::builder::stream::close_document << bsoncxx::builder::stream::finalize;
    collection.update_one(filter.view(), update.view());
    std::cout << "Document updated" << std::endl;

    // Read again to see the update
    std::cout << "After update:" << std::endl;
    cursor = collection.find({});
    for (auto&& doc : cursor) {
        std::cout << bsoncxx::to_json(doc) << std::endl;
    }

    // Delete
    collection.delete_one(filter.view());
    std::cout << "Document deleted" << std::endl;

    // Read again to confirm deletion
    std::cout << "After deletion:" << std::endl;
    cursor = collection.find({});
    for (auto&& doc : cursor) {
        std::cout << bsoncxx::to_json(doc) << std::endl;
    }

    return 0;
}
