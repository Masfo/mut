
include(FetchContent)
FetchContent_Declare(
  Deckard
  GIT_REPOSITORY https://github.com/Masfo/Deckard.git
  GIT_TAG main
)
FetchContent_MakeAvailable(Deckard)




#
target_sources(mut PRIVATE
	main.cpp
)

target_link_libraries(mut PUBLIC deckard)





