cmake_minimum_required(VERSION 3.0.0)
set(CMAKE_CXX_STANDARD 14)

project(SFML-Engine VERSION 0.1.0)

set(SFML_ENGINE_SOURCES
    main.cpp
    Node.cpp
    Node.hpp
    Node2D.hpp
    Node2D.cpp
    Collection.hpp
    Collection.cpp
    RectCollisionShape.hpp
    RectCollisionShape.cpp
    CircleCollisionShape.hpp
    CircleCollisionShape.cpp
    CollisionShape.hpp
    CollisionShape.cpp
    "Message.hpp"
    Component.hpp
    Component.cpp
    PhysicsComponent.hpp
    PhysicsComponent.cpp
    GraphicsComponent.hpp
    GraphicsComponent.cpp
    Physics.hpp
    Physics.cpp
    Graphics.hpp
    Graphics.cpp
    Circle.hpp
    Input.hpp
    Input.cpp
    Game.cpp
    Game.hpp
    MyGame.hpp
    MyGame.cpp
    SpriteStack.hpp
    SpriteStack.cpp
    MyStack.hpp
    MyStack.cpp
    Tree.hpp
    AnimatedSprite.hpp
    InputComponent.hpp
    InputComponent.cpp
    # Processor.hpp
)

#add_library(SFML-Engine SHARED ${SFML_ENGINE_SOURCES})
#add_library(SFML-Engine STATIC ${SFML_ENGINE_SOURCES})
add_executable(SFML-Engine ${SFML_ENGINE_SOURCES})
target_include_directories(SFML-Engine PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(SFML-Engine -lsfml-graphics -lsfml-window -lsfml-system)