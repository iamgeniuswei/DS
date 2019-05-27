# add all the source file to the "DIR_TREE_SRCS"
aux_source_directory(. DIR_TREE_TEST_SRCS)
file(GLOB_RECURSE DIR_TREE_TEST_SRCS
    ${DIR_TREE_TEST_SRCS}
    "${CMAKE_CURRENT_SOURCE_DIR}/*.h"
    "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp")
#add_library(tree_test STATIC ${DIR_TREE_TEST_SRCS})
#set_target_properties(tree_test PROPERTIES LINKER_LANGUAGE CXX)

#enable_testing()
# specify the target.
add_executable(test_tree "test.cpp")
target_link_libraries(test_tree tree)
