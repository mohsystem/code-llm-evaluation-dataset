// Note: MongoDB C driver is not officially supported, so this code is not tested and may not work as expected.

#include <mongoc/mongoc.h>
#include <bson/bson.h>

int main() {
    mongoc_client_t *client;
    mongoc_collection_t *collection;
    bson_t *doc;

    // Create
    client = mongoc_client_new("mongodb://localhost:27017/");
    collection = mongoc_client_get_collection(client, "mydatabase", "mycollection");
    doc = bson_new();
    BSON_APPEND_UTF8(doc, "name", "John");
    BSON_APPEND_INT32(doc, "age", 30);
    mongoc_collection_insert_one(collection, doc, NULL, NULL, NULL);
    bson_destroy(doc);

    // Read
    bson_t *filter;
    filter = bson_new();
    BSON_APPEND_UTF8(filter, "name", "John");
    mongoc_cursor_t *cursor;
    cursor = mongoc_collection_find_with_opts(collection, filter, NULL, NULL);
    const bson_t *doc_read;
    while (mongoc_cursor_next(cursor, &doc_read)) {
        bson_print(doc_read);
    }
    bson_destroy(filter);
    mongoc_cursor_destroy(cursor);

    // Update
    bson_t *update;
    update = bson_new();
    BSON_APPEND_UTF8(update, "$set", "age");
    BSON_APPEND_INT32(update, "age", 31);
    mongoc_collection_update_one(collection, filter, update, NULL, NULL);
    bson_destroy(update);

    // Delete
    mongoc_collection_delete_one(collection, filter, NULL, NULL);
    bson_destroy(filter);
    mongoc_collection_destroy(collection);
    mongoc_client_destroy(client);

    return 0;
}