//Copyright Stewart Henderson (2014)
#pragma once

#include <iostream>
#include <string>
#include <jni.h>
#include "time.hpp"

/**
 * This class loads a JVM into an application.  It presently lacks
 * error checking, logging, etc.
 */
class jvm_loader {
public:
    void load(const char * classpathA);
    void call(const char * classNameA, const char * methodNameA);
    void unload();
private:
    JavaVM *jvm;
    JNIEnv *env;
};

void jvm_loader::load(const char * classpathA) {
    std::cout << __func__ << std::endl;
    point t0 = get_now();
    JavaVMOption options[1];
    //TODO: Set the real classpath here.
    options[0].optionString = (char *) "-Djava.class.path=.";
    //NOTE: Only supporting the latest version.
    JavaVMInitArgs vm_args;
    vm_args.version = JNI_VERSION_1_6;
    vm_args.nOptions = 1;
    vm_args.options = options;
    vm_args.ignoreUnrecognized = false;
    JNI_CreateJavaVM(&jvm, (void**)&env, &vm_args);
    print_delta(t0, get_now());
}

void jvm_loader::call(const char * classNameA, const char * methodNameA) {
    std::cout << __func__ << std::endl;
    point t0 = get_now();
    jclass javaClass = env->FindClass(classNameA);
    jmethodID methodId = env->GetStaticMethodID(javaClass, "call", "(I)V");
    /**
     * NOTE: If you need to pass varargs to the method, you can still
     * do this by simply adding them after the methodId below.
     */
    env->CallStaticVoidMethod(javaClass, methodId);
    print_delta(t0, get_now());
}

void jvm_loader::unload() {
    std::cout << __func__ << std::endl;
    point t0 = get_now();
    jvm->DestroyJavaVM();
    print_delta(t0, get_now());
}