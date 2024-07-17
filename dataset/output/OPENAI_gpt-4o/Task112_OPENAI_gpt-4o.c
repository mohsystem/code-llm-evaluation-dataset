#include <stdio.h>
#include <mongoc/mongoc.h>

int main() {
    mongoc_client_t *client;
    mongoc_collection_t *collection;
    bson_t *doc, *query, *update;
    bson_error_t error;

    mongoc_init();

    client = mongoc_client_new("mongodb://localhost:27017/");
    collection = mongoc_client_get_collection(client, "mydb", "test");

    // Create
    doc = bson_new();
    BSON_APPEND_UTF8(doc, "name", "John Doe");
    BSON_APPEND_INT32(doc, "age", 30);
    if (!mongoc_collection_insert_one(collection, doc, NULL, NULL, &error)) {
        fprintf(stderr, "%s
", error.message);
    }
    bson_destroy(doc);

    // Read
    query = bson_new();
    BSON_APPEND_UTF8(query, "name", "John Doe");
    doc = mongoc_collection_find_with_opts(collection, query, NULL, NULL);
    const bson_t *found_doc;
    if (mongoc_cursor_next(doc, &found_doc)) {
        char *str = bson_as_canonical_extended_json(found_doc, NULL);
        printf("%s
", str);
        bson_free(str);
    }
    bson_destroy(query);

    // Update
    update = BCON_NEW("$set", "{", "age", BCON_INT32(31), "}");
    if (!mongoc_collection_update_one(collection, query, update, NULL, NULL, &error)) {
        fprintf(stderr, "%s
", error.message);
    }
    bson_destroy(update);

    // Delete
    if (!mongoc_collection_delete_one(collection, query, NULL, NULL, &error)) {
        fprintf(stderr, "%s
", error.message);
    }
    bson_destroy(query);
    mongoc_collection_destroy(collection);
    mongoc_client_destroy(client);
    mongoc_cleanup();

    return 0;
}