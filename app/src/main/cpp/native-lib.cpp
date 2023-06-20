#include <jni.h>
#include <string>

/**
 * C++实现Java层定义的Native方法。
 */
extern "C" JNIEXPORT jstring JNICALL
Java_com_example_jni_MainActivity_stringFromJNI(
        JNIEnv* env,
        jobject /* this */) {
    std::string hello = "Hello from C++";
    return env->NewStringUTF(hello.c_str());
}



extern "C"
JNIEXPORT void JNICALL
Java_com_example_jni_MainActivity_changeName(JNIEnv *env, jobject thiz) {
    jclass jclass1 = env->FindClass("com/example/jni/MainActivity");

    jfieldID jfieldId = env->GetFieldID(jclass1, "name", "Ljava/lang/String;");

    jstring value = env->NewStringUTF("renjiayi");
    env->SetObjectField(thiz, jfieldId, value);


}

extern "C"
JNIEXPORT void JNICALL
Java_com_example_jni_MainActivity_changeInt(JNIEnv *env, jclass clazz) {


    jfieldID jfieldId = env->GetStaticFieldID(clazz, "age", "I");

    env->SetStaticIntField(clazz, jfieldId, 10);
}


extern "C"
JNIEXPORT jint JNICALL
Java_com_example_jni_MainActivity_callAdd(JNIEnv *env, jobject thiz) {
    jclass  jclass1 = env->GetObjectClass(thiz);

    jmethodID jmethodId = env->GetMethodID(jclass1, "add", "(II)I");
    jint value = env->CallIntMethod(thiz, jmethodId, 10, 15);
    return value;
}