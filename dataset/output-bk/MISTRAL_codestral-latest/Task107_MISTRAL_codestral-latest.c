#include <stdio.h>
#include <naming.h>

int main() {
    JNDIEnvironment *env;
    JNDIContext *ctx;
    JNDIObject *obj;

    env = jndi_create_environment();
    ctx = jndi_context_new(env);

    obj = jndi_context_lookup(ctx, "java:comp/env/jdbc/MyDB");
    if (obj != NULL) {
        printf("Object found: %p
", obj);
    } else {
        fprintf(stderr, "Lookup failed
");
    }

    jndi_context_destroy(ctx);
    jndi_environment_destroy(env);

    return 0;
}