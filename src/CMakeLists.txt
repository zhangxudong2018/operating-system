aux_source_directory(. SRC_LIST)
aux_source_directory(algorithm ALGORITHM)

include_directories(../include)

# add_executable(main ${SRC_LIST} ${ALGORITHM})

add_executable(trie test_trie.c ${ALGORITHM})

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)