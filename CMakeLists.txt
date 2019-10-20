cmake_minimum_required(VERSION 3.0.0)
project(HelloWorld VERSION 0.1.0)

set(CMAKE_CXX_STANDARD 14)

add_executable(
    HelloWorld
    main.cpp
    GameWindow.cpp
    GameWindow.hpp
    Node.cpp
    Node.hpp
    Collection.hpp
    Collection.cpp
    RectCollisionShape.hpp
    RectCollisionShape.cpp
    CircleCollisionShape.hpp
    CircleCollisionShape.cpp
    CollisionShape.hpp
)
target_link_libraries (HelloWorld sfml-graphics sfml-window sfml-system)