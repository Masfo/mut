 							   

add_library(ModuleTest STATIC)
set_property(TARGET ModuleTest PROPERTY CXX_STANDARD          23)
set_property(TARGET ModuleTest PROPERTY CXX_STANDARD_REQUIRED ON)
set_property(TARGET ModuleTest PROPERTY CXX_EXTENSIONS        OFF)

if(MSVC)
    #set_property(TARGET ModuleTest PROPERTY MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>DLL")
    set_property(TARGET ModuleTest PROPERTY MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>")
endif()

#target_include_directories(ModuleTest PRIVATE ${CMAKE_CURRENT_LIST_DIR})


target_sources(ModuleTest PRIVATE 
               FILE_SET cxx_modules 
               TYPE CXX_MODULES 
               FILES 

               module.ixx
)

											
