
#
target_sources(${CMAKE_PROJECT_NAME} PRIVATE
	main.cpp
)

add_subdirectory(Deckard)
add_deckard(${CMAKE_PROJECT_NAME} Deckard)





