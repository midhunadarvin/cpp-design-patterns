cmake_minimum_required(VERSION 3.10)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

project(Commands)

set(PLUGIN_SOURCES
    "OrdinaryCitizenCommand.cpp"
    "SeniorCitizenCommand.cpp"
)

foreach(PLUGIN_SOURCE ${PLUGIN_SOURCES})
    string(REPLACE ".cpp" "" LIB_NAME ${PLUGIN_SOURCE})
    set(LIB_NAMES ${LIB_NAMES} ${LIB_NAME})
    add_library(${LIB_NAME} SHARED ${PLUGIN_SOURCE} "ComputationContext.cpp")
endforeach(PLUGIN_SOURCE ${PLUGIN_SOURCES})