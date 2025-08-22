find_package(unitree_sdk2 REQUIRED)

add_executable(test_publisher1 
    publisher.cpp 
    HelloWorldData.cpp
)
target_link_libraries(test_publisher1 unitree_sdk2)

add_executable(test_subscriber1 
    subscriber.cpp 
    HelloWorldData.cpp
)
target_link_libraries(test_subscriber1 unitree_sdk2)