
cmake_minimum_required(VERSION 3.16)
project(wx_demo)
find_package(wxWidgets REQUIRED COMPONENTS core base)
include(${wxWidgets_USE_FILE})
add_executable(wxapp main.cpp)
target_link_libraries(wxapp ${wxWidgets_LIBRARIES})
