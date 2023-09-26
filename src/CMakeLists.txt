
#
target_sources(${CMAKE_PROJECT_NAME} PRIVATE
	main.cpp
)

add_subdirectory(ModuleTest)
target_link_libraries(${CMAKE_PROJECT_NAME} PRIVATE ModuleTest)


# Hack STD module in
file(COPY $ENV{VCToolsInstallDir}/modules/std.ixx
  DESTINATION ${CMAKE_CURRENT_SOURCE_DIR}/
)


# Modules here
target_sources(${CMAKE_PROJECT_NAME} PUBLIC 

	FILE_SET modules TYPE CXX_MODULES FILES
	std.ixx
)




