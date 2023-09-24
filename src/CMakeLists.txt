
#
target_sources(mut PRIVATE
	main.cpp
)

add_subdirectory(ModuleTest)

target_link_libraries(mut PRIVATE ModuleTest)

target_include_directories(mut PRIVATE ${CMAKE_CURRENT_LIST_DIR})


# Modules here
target_sources(mut 
    PRIVATE 
	FILE_SET cxx_modules TYPE CXX_MODULES FILES
    
)



