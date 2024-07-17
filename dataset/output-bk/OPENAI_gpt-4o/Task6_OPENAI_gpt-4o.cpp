#include <jni.h>
#include <iostream>

extern "C" {
    JNIEXPORT jdouble JNICALL Java_UnifiedSourceCode_findUniqCpp(JNIEnv *env, jobject obj, jdoubleArray arr) {
        jdouble *carr = env->GetDoubleArrayElements(arr, 0);
        jsize size = env->GetArrayLength(arr);
        if (carr[0] != carr[1] && carr[0] != carr[2]) return carr[0];
        for (int i = 0; i < size; i++) if (carr[i] != carr[0]) return carr[i];
        return -1; // Just a default case, won't reach here
    }
}