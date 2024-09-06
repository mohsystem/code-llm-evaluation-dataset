#include <iostream>
#include <mongocxx/client.hpp>
#include <mongocxx/instance.hpp>
#include <bsoncxx/json.hpp>

int main() {
    // Initialize MongoDB
    mongocxx::instance instance{};
    mongocxx::client client{mongocxx::uri{"mongodb://localhost:27017"}};
    auto db = client["mydatabase"];
    auto collection = db["mycollection"];

    // Create
    bsoncxx::document::value document = bsoncxx::builder::stream::document{}
        << "name" << "John"
        << "age" << 30
        << "city" << "New York"
        << bsoncxx::builder::stream::finalize;
    collection.insert_one(document.view());

    // Read
    auto cursor = collection.find_one(bsoncxx::builder::stream::document{} << "name" << "John" << bsoncxx::builder::stream::finalize);
    if(cursor) std::cout << "Read: " << bsoncxx::to_json(cursor->view()) << "\n";

    // Update
    bsoncxx::builder::stream::document filter_builder, update_builder;
    filter_builder << "name" << "John";
    update_builder << "$set" << bsoncxx::builder::stream::open_document << "age" << 31 << bsoncxx::builder::stream::close_document;
    collection.update_one(filter_builder.view(), update_builder.view());

    // Verify Update
    cursor = collection.find_one(bsoncxx::builder::stream::document{} << "name" << "John" << bsoncxx::builder::stream::finalize);
    if(cursor) std::cout << "Updated: " << bsoncxx::to_json(cursor->view()) << "\n";

    // Delete
    collection.delete_one(bsoncxx::builder::stream::document{} << "name" << "John" << bsoncxx::builder::stream::finalize);

    // Verify Delete
    cursor = collection.find_one(bsoncxx::builder::stream::document{} << "name" << "John" << bsoncxx::builder::stream::finalize);
    if(!cursor) std::cout << "Deleted: Document not found\n";

    return 0;
}