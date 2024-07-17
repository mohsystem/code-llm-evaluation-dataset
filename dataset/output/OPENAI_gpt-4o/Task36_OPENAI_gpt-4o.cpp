#include <iostream>
#include <fstream>
#include <jni.h>

extern "C"
JNIEXPORT void JNICALL Java_MultiLangFileReader_readFileInCpp(JNIEnv *env, jobject obj, jstring fileName) {
    const char *nativeString = env->GetStringUTFChars(fileName, 0);
    
    std::ifstream file(nativeString);
    if (!file.is_open()) {
        std::cout << "Error opening file" << std::endl;
        return;
    }

    std::string line;
    while (std::getline(file, line)) {
        std::cout << line << std::endl;
    }

    file.close();
    env->ReleaseStringUTFChars(fileName, nativeString);
}