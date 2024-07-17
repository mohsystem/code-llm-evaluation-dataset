#include <iostream>
#include <naming.h>

int main() {
    JNDIEnvironment *env;
    JNDIContext *ctx;
    JNDIObject *obj;

    env = jndi_create_environment();
    ctx = jndi_context_new(env);

    obj = jndi_context_lookup(ctx, "java:comp/env/jdbc/MyDB");
    if (obj != NULL) {
        std::cout << "Object found: " << obj << std::endl;
    } else {
        std::cerr << "Lookup failed" << std::endl;
    }

    jndi_context_destroy(ctx);
    jndi_environment_destroy(env);

    return 0;
}