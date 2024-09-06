#include <iostream>
#include <bsoncxx/json.hpp>
#include <mongocxx/client.hpp>
#include <mongocxx/instance.hpp>

int main() {
    mongocxx::instance inst{};
    mongocxx::client conn{mongocxx::uri{}};

    auto database = conn["mydatabase"];
    auto collection = database["customers"];

    // Create
    bsoncxx::builder::stream::document document{};
    document << "name" << "John" << "address" << "Highway 37";
    collection.insert_one(document.view());

    // Read
    auto cursor = collection.find({});
    for (auto&& doc : cursor) {
        std::cout << bsoncxx::to_json(doc) << std::endl;
    }

    // Update
    collection.update_one(
        bsoncxx::builder::stream::document{} << "address" << "Valley 345" << bsoncxx::builder::stream::finalize,
        bsoncxx::builder::stream::document{} << "$set" << bsoncxx::builder::stream::open_document << "address" << "Canyon 123" << bsoncxx::builder::stream::close_document << bsoncxx::builder::stream::finalize
    );

    // Delete
    collection.delete_one(bsoncxx::builder::stream::document{} << "name" << "John" << bsoncxx::builder::stream::finalize);

    return 0;
}