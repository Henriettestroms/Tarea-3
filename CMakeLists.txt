cmake_minimum_required(VERSION 3.14)

project(Tarea3Etapa4 LANGUAGES CXX)

set(CMAKE_AUTOMOC ON)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 REQUIRED COMPONENTS Widgets Multimedia MultimediaWidgets)

add_executable(${PROJECT_NAME}
    cpp/Stage1/src/Stage1.cpp
    cpp/src/Broker.cpp
    cpp/src/GPSCarPublisher.cpp
    cpp/src/GPSCarSubscriber.cpp
    cpp/src/VideoPublisher.cpp
    cpp/src/VideoFollower.cpp
    cpp/src/Component.cpp
    cpp/src/Publisher.cpp
    cpp/src/Subscriber.cpp
    cpp/src/Topic.cpp
    cpp/src/GPSFollower.cpp
    cpp/include/GPSCarPublisher.h
    cpp/include/GPSFollower.h
)

target_include_directories(${PROJECT_NAME} PRIVATE
    cpp/
    cpp/include
)

target_link_libraries(${PROJECT_NAME} PRIVATE
    Qt6::Widgets
    Qt6::Multimedia
    Qt6::MultimediaWidgets
)
