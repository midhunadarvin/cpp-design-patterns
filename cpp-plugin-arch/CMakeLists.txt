cmake_minimum_required(VERSION 3.10)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

project(CppPluginArch VERSION 1.0)

# Get the value of an environment variable and set it as a preprocessor definition
# Use $ENV{VAR_NAME} to access the value of the environment variable VAR_NAME
# and set it as a preprocessor definition
add_definitions(-DPLUGINS_FOLDER_PATH="$ENV{PLUGINS_FOLDER_PATH}")
add_definitions(-DCONFIG_FILE="$ENV{CONFIG_FILE}")

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