
#
target_sources(${CMAKE_PROJECT_NAME} PRIVATE
	main.cpp
)



set(MUT_SRCS
 $<$<CONFIG:Release>:${CMAKE_CURRENT_SOURCE_DIR}/buildnumber.ixx>
)


target_sources(${CMAKE_PROJECT_NAME} 
	PUBLIC
    FILE_SET CXX_MODULES 
	FILES ${MUT_SRCS}
)




target_link_libraries(${CMAKE_PROJECT_NAME} Deckard)



