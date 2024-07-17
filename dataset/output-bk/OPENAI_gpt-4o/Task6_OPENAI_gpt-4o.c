#include <jni.h>
#include <stdio.h>

JNIEXPORT jdouble JNICALL Java_UnifiedSourceCode_findUniqC (JNIEnv *env, jobject obj, jdoubleArray arr, jint size) {
    jdouble *carr = (*env)->GetDoubleArrayElements(env, arr, 0);
    if (carr[0] != carr[1] && carr[0] != carr[2]) return carr[0];
    for (int i = 0; i < size; i++) if (carr[i] != carr[0]) return carr[i];
    return -1; // Just a default case, won't reach here
}