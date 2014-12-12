#include "jvm_loader.hpp"

int main() {
    jvm_loader loader;
    loader.load(".");
    loader.call("HelloWorld", "main", "([Ljava/lang/String;)V");
    loader.unload();
}