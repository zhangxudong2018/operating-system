aux_source_directory(. SRC_LIST)
aux_source_directory(algorithm ALGORITHM)

include_directories(../include)

# add_executable(main ${SRC_LIST} ${ALGORITHM})

if (TEST_TRIE)
        message(STATUS "TEST_TRIE ON.")
        add_executable(trie test_trie.c ${ALGORITHM})
endif()

if (TEST_INST)
        message(STATUS "TEST_INST ON.")
        add_executable(inst test_inst.c ${ALGORITHM})
endif()

# add_executable(trie test_trie.c ${ALGORITHM})

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)