
#
target_sources(${CMAKE_PROJECT_NAME} PRIVATE
	main.cpp
)

#add_subdirectory(Deckard)


set(MUT_SRCS
)

if (${CMAKE_BUILD_TYPE} MATCHES "Release")
	set(MUT_SRCS buildnumber.ixx)
endif()

target_sources(${CMAKE_PROJECT_NAME} 
	PUBLIC
    FILE_SET CXX_MODULES 
	FILES ${MUT_SRCS}
)




target_link_libraries(${CMAKE_PROJECT_NAME} Deckard)



