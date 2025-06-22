cmake_minimum_required(VERSION 3.5)
project(Stage1)
set(CMAKE_CXX_STANDARD 14)
find_package(Qt5 COMPONENTS Widgets REQUIRED)
add_executable(Stage1
    src/Stage1.cpp
    ../src/Topic.cpp
    ../src/Broker.cpp
    ../src/Component.cpp
    ../src/Publisher.cpp
    ../src/Subscriber.cpp
    ../src/VideoPublisher.cpp
    ../src/VideoFollower.cpp
)
target_include_directories(Stage1 PRIVATE ../include)
target_link_libraries(Stage1 Qt5::Widgets)
