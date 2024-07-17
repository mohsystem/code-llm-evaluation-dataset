#include <stdio.h>
#include <jni.h>

int main() {
    JavaVM *jvm;   
    JNIEnv *env;   
    JavaVMInitArgs vm_args; 
    JavaVMOption options[2];

    options[0].optionString = "-Djava.class.path=.";
    vm_args.version = JNI_VERSION_1_6;
    vm_args.nOptions = 1;
    vm_args.options = options;
    vm_args.ignoreUnrecognized = 0;

    JNI_CreateJavaVM(&jvm, (void**)&env, &vm_args);

    jclass cls = (*env)->FindClass(env, "JNDILookup");
    jmethodID mid = (*env)->GetStaticMethodID(env, cls, "main", "([Ljava/lang/String;)V");
    (*env)->CallStaticVoidMethod(env, cls, mid, NULL);

    (*jvm)->DestroyJavaVM(jvm);
    return 0;
}