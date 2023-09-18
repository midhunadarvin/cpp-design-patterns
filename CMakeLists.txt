cmake_minimum_required(VERSION 3.10)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

project(CppPluginArch VERSION 1.0)

include_directories(lib/tinyxml2)

add_executable(
    CppPluginArch 
        main.cpp
        commands/ComputationContext.cpp
        ObjectFactory.cpp
        util/XMLHelper.cpp
        util/libnameothy.cpp
        util/globothy.cpp
        TypeFactory.cpp
)

target_link_libraries(
    CppPluginArch 
        ${CMAKE_SOURCE_DIR}/lib/tinyxml2/build/libtinyxml2.a
)