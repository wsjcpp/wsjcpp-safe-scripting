cmake_minimum_required(VERSION 3.0)

project(wsjcpp-safe-scripting C CXX)

include(${CMAKE_CURRENT_SOURCE_DIR}/src.wsjcpp/CMakeLists.txt)

set(CMAKE_CXX_STANDARD 11)
set(EXECUTABLE_OUTPUT_PATH ${wsjcpp-safe-scripting_SOURCE_DIR})

# include header dirs
list (APPEND WSJCPP_INCLUDE_DIRS "src")

list (APPEND WSJCPP_SOURCES "src/main.cpp")
list (APPEND WSJCPP_SOURCES "src/wsjcpp_safe_scripting.h")
list (APPEND WSJCPP_SOURCES "src/wsjcpp_safe_scripting.cpp")

#### BEGIN_WSJCPP_APPEND
list (APPEND WSJCPP_SOURCES "./src/safe_scripting_proc_test_proc.h")
list (APPEND WSJCPP_SOURCES "./src/safe_scripting_proc_test_proc.cpp")
#### END_WSJCPP_APPEND

include_directories(${WSJCPP_INCLUDE_DIRS})

add_executable (wsjcpp-safe-scripting ${WSJCPP_SOURCES})

target_link_libraries(wsjcpp-safe-scripting ${WSJCPP_LIBRARIES})

install(
    TARGETS
        wsjcpp-safe-scripting
    RUNTIME DESTINATION
        /usr/bin
)


