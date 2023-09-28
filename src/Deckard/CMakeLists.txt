

target_sources(${CMAKE_PROJECT_NAME}
		PRIVATE
		FILE_SET modules 
		TYPE CXX_MODULES
		FILES
		Deckard.ixx
		BR.ixx
)
