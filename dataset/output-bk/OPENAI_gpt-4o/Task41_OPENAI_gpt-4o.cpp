#include <jni.h>
#include <iostream>
#include <string>

extern "C"
JNIEXPORT void JNICALL Java_MultiLangProgram_processStringCpp(JNIEnv *env, jobject obj, jstring input) {
    const char *inputStr = env->GetStringUTFChars(input, nullptr);
    
    std::string safeStr(inputStr);
    
    std::cout << "You entered (C++): " << safeStr << std::endl;
    
    env->ReleaseStringUTFChars(input, inputStr);
}