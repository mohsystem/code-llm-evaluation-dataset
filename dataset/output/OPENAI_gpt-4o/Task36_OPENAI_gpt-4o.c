#include <stdio.h>
#include <jni.h>

JNIEXPORT void JNICALL Java_MultiLangFileReader_readFileInC(JNIEnv *env, jobject obj, jstring fileName) {
    const char *nativeString = (*env)->GetStringUTFChars(env, fileName, 0);
    FILE *file = fopen(nativeString, "r");
    if (file == NULL) {
        printf("Error opening file
");
        return;
    }
    char line[256];
    while (fgets(line, sizeof(line), file)) {
        printf("%s", line);
    }
    fclose(file);
    (*env)->ReleaseStringUTFChars(env, fileName, nativeString);
}