#include <jni.h>
#include <stdio.h>
#include <string.h>

// Declaration of the native methods
JNIEXPORT void JNICALL Java_MultiLangProgram_processStringC(JNIEnv *env, jobject obj, jstring input) {
    const char *inputStr = (*env)->GetStringUTFChars(env, input, 0);

    char safeStr[256];
    strncpy(safeStr, inputStr, sizeof(safeStr) - 1);
    safeStr[sizeof(safeStr) - 1] = '\0';  // Ensure null termination

    printf("You entered (C): %s
", safeStr);

    (*env)->ReleaseStringUTFChars(env, input, inputStr);
}