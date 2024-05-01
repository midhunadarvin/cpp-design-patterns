/**
 * Compile : g++ -c -fPIC -I"$JAVA_HOME/include" -I"$JAVA_HOME/include/darwin" -o HelloJNI.o HelloJNI.c
 * Link    : g++ -dynamiclib -o libnative.dylib HelloJNI.o -lc
*/

// Save as "HelloJNI.c"
#include <jni.h>        // JNI header provided by JDK
#include <iostream>      // C Standard IO Header
#include "HelloJNI.h"   // Generated
 
// Implementation of the native method sayHello()
JNIEXPORT void JNICALL Java_HelloJNI_sayHello(JNIEnv *env, jobject thisObj) {
   std::cout << "Hello from C++ !!" << std::endl;
   return;
}