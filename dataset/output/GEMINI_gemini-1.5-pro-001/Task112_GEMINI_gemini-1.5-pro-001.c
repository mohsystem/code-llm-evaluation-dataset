/*
 * This code requires the libmongoc-dev and libbson-dev packages to be installed.
 * You can install them on Ubuntu with:
 * sudo apt-get install libmongoc-dev libbson-dev
 */
#include <bson/bson.h>
#include <mongoc/mongoc.h>
#include <stdio.h>

int main(int argc, char *argv[]) {
    mongoc_client_t *client;
    mongoc_collection_t *collection;
    bson_error_t error;
    bson_oid_t oid;
    bson_t *doc;

    mongoc_init();

    client = mongoc_client_new("mongodb://localhost:27017/");
    collection = mongoc_client_get_collection(client, "mydatabase", "customers");

    // Create
    doc = bson_new();
    bson_append_utf8(doc, "name", -1, "John", -1);
    bson_append_utf8(doc, "address", -1, "Highway 37", -1);
    if (!mongoc_collection_insert_one(collection, doc, NULL, NULL, &error)) {
        fprintf(stderr, "%s\n", error.message);
    }
    bson_destroy(doc);

    // Read
    mongoc_cursor_t *cursor = mongoc_collection_find(collection, MONGOC_QUERY_NONE, 0, 0, 0, NULL, NULL, NULL);
    const bson_t *doc_read;
    while (mongoc_cursor_next(cursor, &doc_read)) {
        char *str = bson_as_json(doc_read, NULL);
        printf("%s\n", str);
        bson_free(str);
    }
    mongoc_cursor_destroy(cursor);

    // Update
    bson_t *query = bson_new();
    bson_append_utf8(query, "address", -1, "Valley 345", -1);
    bson_t *update = BCON_NEW(
        "$set", "{", "address", "Canyon 123", "}");
    if (!mongoc_collection_update_one(collection, query, update, NULL, NULL, &error)) {
        fprintf(stderr, "%s\n", error.message);
    }
    bson_destroy(query);
    bson_destroy(update);

    // Delete
    bson_t *del_query = bson_new();
    bson_append_utf8(del_query, "name", -1, "John", -1);
    if (!mongoc_collection_delete_one(collection, del_query, NULL, NULL, &error)) {
        fprintf(stderr, "%s\n", error.message);
    }
    bson_destroy(del_query);

    mongoc_collection_destroy(collection);
    mongoc_client_destroy(client);
    mongoc_cleanup();

    return 0;
}