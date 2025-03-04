cmake_minimum_required(VERSION 3.10)
project(ftxui_example)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)
FetchContent_Declare(
    ftxui
    GIT_REPOSITORY https://github.com/ArthurSonzogni/FTXUI.git
    GIT_TAG        main
)
FetchContent_MakeAvailable(ftxui)

add_executable(tmui src/main.cpp src/sys_monitor.cpp)

target_link_libraries(tmui PRIVATE ftxui::dom ftxui::screen ftxui::component)
