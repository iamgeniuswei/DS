cmake_minimum_required(VERSION 2.8)

project(DS)

add_subdirectory(tree)
add_subdirectory(tree_test)

# specify the target.
add_executable(${PROJECT_NAME} "main.cpp")

# add link library
target_link_libraries(${PROJECT_NAME} tree)
#target_link_libraries(${PROJECT_NAME} tree_test)

#set(CMAKE_BUILD_TYPE Debug)
