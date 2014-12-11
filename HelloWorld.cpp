#include "jvm_loader.hpp"

int main() {
    jvm_loader loader;
    loader.load(".");
    loader.unload();
}