#include <iostream>
#include <mongocxx/client.hpp>
#include <mongocxx/instance.hpp>
#include <mongocxx/uri.hpp>
#include <mongocxx/collection.hpp>
#include <bsoncxx/json.hpp>
#include <bsoncxx/builder/stream/document.hpp>

int main() {
    mongocxx::instance instance{};
    mongocxx::client client{mongocxx::uri{"mongodb://localhost:27017"}};
    mongocxx::database db = client["mydb"];
    mongocxx::collection coll = db["test"];

    // Create
    bsoncxx::builder::stream::document document{};
    document << "name" << "John Doe" << "age" << 30;
    coll.insert_one(document.view());

    // Read
    auto maybe_result = coll.find_one(bsoncxx::builder::stream::document{} << "name" << "John Doe" << bsoncxx::builder::stream::finalize);
    if (maybe_result) {
        std::cout << bsoncxx::to_json(*maybe_result) << std::endl;
    }

    // Update
    coll.update_one(bsoncxx::builder::stream::document{} << "name" << "John Doe" << bsoncxx::builder::stream::finalize,
                    bsoncxx::builder::stream::document{} << "$set" << bsoncxx::builder::stream::open_document << "age" << 31 << bsoncxx::builder::stream::close_document << bsoncxx::builder::stream::finalize);

    // Delete
    coll.delete_one(bsoncxx::builder::stream::document{} << "name" << "John Doe" << bsoncxx::builder::stream::finalize);

    return 0;
}