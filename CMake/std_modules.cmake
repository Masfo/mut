
macro(add_std_module TARGET)

if(MSVC)
	set(CMAKE_DISABLE_SOURCE_CHANGES OFF)
	configure_file(	
	        $ENV{VCToolsInstallDir}modules/std.ixx
	        ${CMAKE_CURRENT_LIST_DIR}/std.ixx
	        COPYONLY
	)
	set(CMAKE_DISABLE_SOURCE_CHANGES ON)
	
	
	target_sources(${TARGET} 
		PUBLIC 
		FILE_SET std_module 
		TYPE CXX_MODULES 
		FILES 
		std.ixx
	 )
 endif()

endmacro()