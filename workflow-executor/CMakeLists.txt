cmake_minimum_required(VERSION 3.10)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

project(Graphs VERSION 1.0)

find_package(tinyxml2 CONFIG REQUIRED)
include_directories(${tinyxml2_INCLUDE_DIRS})

# Find Python
find_package(Python COMPONENTS Interpreter Development)
if (Python_FOUND)
    message(STATUS "Python found: ${Python_EXECUTABLE}")
else()
    message(FATAL_ERROR "Python not found.")
endif()
include_directories(${Python_INCLUDE_DIRS})

add_executable(
        Graphs

        main.cpp
        model/Graph.h
        model/DAG.h
        model/Tree.h
        parser/XmlTreeParser.h

        commands/PythonCommand.cpp
        util/PythonInterpreter.cpp
        commands/ComputationContext.cpp
        execution-engine/WorkflowExecutor.h)

target_link_libraries(Graphs
        PRIVATE tinyxml2::tinyxml2
        ${Python_LIBRARIES}
        )
