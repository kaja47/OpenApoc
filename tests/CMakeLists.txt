PROJECT (OpenApoc_Tests CXX C)
CMAKE_MINIMUM_REQUIRED(VERSION 3.1)

set (TEST_LIST test_rect test_voxel test_tilemap test_rng test_images
		test_unicode)
		
foreach(TEST ${TEST_LIST})
		add_executable(${TEST} ${TEST}.cpp)
		# Just add all libs?
		target_link_libraries(${TEST} OpenApoc_Library OpenApoc_Framework
				OpenApoc_GameState)
		target_compile_definitions(${TEST} PRIVATE -DUNIT_TEST)
		add_test(NAME ${TEST} COMMAND ${EXECUTABLE_OUTPUT_PATH}/${TEST}
				--Framework.CD=${CD_PATH} --Framework.Data=${CMAKE_SOURCE_DIR}/data)
endforeach()

# test_serialize requires args so needs to be slightly separate	
set(TEST test_serialize)
add_executable(${TEST} ${TEST}.cpp)
# Just add all libs?
target_link_libraries(${TEST} OpenApoc_Library OpenApoc_Framework
		OpenApoc_GameState)
target_compile_definitions(${TEST} PRIVATE -DUNIT_TEST)
add_test(NAME ${TEST}_difficulty1 COMMAND ${EXECUTABLE_OUTPUT_PATH}/${TEST}
		${CMAKE_SOURCE_DIR}/data/difficulty1_patched
		${CMAKE_SOURCE_DIR}/data/gamestate_common
		--Framework.CD=${CD_PATH} --Framework.Data=${CMAKE_SOURCE_DIR}/data)

# MSVC is bad at detecting utf8
if (MSVC)
	set_source_files_properties(test_unicode.cpp PROPERTIES COMPILE_FLAGS /utf-8)
endif()
