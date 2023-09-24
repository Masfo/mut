

if(RUN_TESTS)

	find_package(catch2 CONFIG REQUIRED)

	add_executable(tests)

	target_sources(tests PRIVATE
		"test-main.cpp"
	)

	set_target_properties(tests PROPERTIES 
		RUNTIME_OUTPUT_DIRECTORY_DEBUG ${CMAKE_SOURCE_DIR}/bin
		RUNTIME_OUTPUT_DIRECTORY_RELEASE ${CMAKE_SOURCE_DIR}/bin
		RUNTIME_OUTPUT_DIRECTORY_RELWITHDEBINFO ${CMAKE_SOURCE_DIR}/bin
        PDB_NAME tests
        PDB_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/pdb"
	)

	set_property(TARGET tests PROPERTY MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>")
    target_link_options(tests PRIVATE /INCREMENTAL:NO)
    target_link_options(tests PRIVATE /MANIFEST:NO)

	include(CTest)
	include(Catch)
	catch_discover_tests(tests)

	target_link_libraries(tests PRIVATE Catch2::Catch2 Catch2::Catch2WithMain)

endif()
