# add all the source file to the "DIR_TREE_SRCS"
aux_source_directory(. DIR_PFC_SRCS)
file(GLOB_RECURSE DIR_PFC_SRCS
    ${DIR_PFC_SRCS}
    "${CMAKE_CURRENT_SOURCE_DIR}/*.h"
    "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp")
add_library(pfc STATIC ${DIR_PFC_SRCS})
set_target_properties(pfc PROPERTIES LINKER_LANGUAGE CXX)
target_link_libraries(pfc tree)
target_link_libraries(pfc bitmap)
