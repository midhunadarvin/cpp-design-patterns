/**
 * C++ shared module that can be imported in python
 * Build : python3 setup.py build
 * 
 * The shared object file ( or dll ) will be generated in build folder
 * 
 * Eg. build/lib.macosx-14-arm64-cpython-311/mysum.cpython-311-darwin.so
*/

/** 
 * Compute the sum an array
 * @param n number of elements
 * @param array input array
 * @return sum
 */
extern "C" // required when using C++ compiler
long long mysum(int n, int* array) {
    // return type is 64 bit integer
    long long res = 0;
    for (int i = 0; i < n; ++i) {
        res += array[i];
    }
    return res;
}
