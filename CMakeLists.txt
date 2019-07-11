cmake_minimum_required(VERSION 2.8)

project(DS)

add_subdirectory(tree)
add_subdirectory(bitmap)
add_subdirectory(pfc)

add_subdirectory(tree_test)
add_subdirectory(test_bitmap)
add_subdirectory(dict)
add_subdirectory(dict_test)
add_subdirectory(list)
add_subdirectory(list_test)
add_subdirectory(leetcode)


# specify the target.
add_executable(${PROJECT_NAME} "main.cpp")

# add link library
target_link_libraries(${PROJECT_NAME} tree)
target_link_libraries(${PROJECT_NAME} bitmap)
target_link_libraries(${PROJECT_NAME} pfc)
#target_link_libraries(${PROJECT_NAME} dict)
#target_link_libraries(${PROJECT_NAME} tree_test)

#set(CMAKE_BUILD_TYPE Debug)
