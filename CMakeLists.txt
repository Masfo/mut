
cmake_minimum_required (VERSION 3.29)

set(CMAKE_DISABLE_SOURCE_CHANGES ON)
set(CMAKE_DISABLE_IN_SOURCE_BUILD ON)


set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_CURRENT_SOURCE_DIR}/CMake")
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)





set(CMAKE_CXX_STANDARD          23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS        OFF)
set(CMAKE_CXX_SCAN_FOR_MODULES  ON)

#set(CMAKE_INSTALL_PREFIX ${CMAKE_CURRENT_BINARY_DIR}/bin)





project(mut LANGUAGES CXX)
add_executable(mut)


set_property(TARGET mut PROPERTY CXX_STANDARD          23)
set_property(TARGET mut PROPERTY CXX_STANDARD_REQUIRED ON)
set_property(TARGET mut PROPERTY CXX_EXTENSIONS        OFF)

set_target_properties(mut PROPERTIES 
    RUNTIME_OUTPUT_DIRECTORY_DEBUG ${CMAKE_SOURCE_DIR}/bin
    RUNTIME_OUTPUT_DIRECTORY_RELEASE ${CMAKE_SOURCE_DIR}/bin
    RUNTIME_OUTPUT_DIRECTORY_RELWITHDEBINFO ${CMAKE_SOURCE_DIR}/bin
    PDB_NAME mut
    PDB_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/pdb"
)


target_compile_definitions(mut PRIVATE UNICODE)
target_compile_definitions(mut PRIVATE _UNICODE)

target_compile_definitions(mut PRIVATE NOMINMAX)
target_compile_definitions(mut PRIVATE WIN32_LEAN_AND_MEAN)
target_compile_definitions(mut PRIVATE WIN32_EXTRA_LEAN)



target_compile_options(mut PRIVATE /nologo)
target_compile_options(mut PRIVATE -Zc:__cplusplus /Zc:alignedNew)
target_compile_options(mut PRIVATE /utf-8)
target_compile_options(mut PRIVATE /EHsc)
#target_compile_options(mut PRIVATE /Za)

target_compile_options(mut  PRIVATE /fp:precise)
target_compile_options(mut PRIVATE /diagnostics:caret)


#target_compile_options(mut PRIVATE /experimental:module)
target_compile_options(mut PRIVATE /Zc:preprocessor)
target_compile_options(mut PRIVATE /permissive-)
target_compile_options(mut PRIVATE /std:c++latest)
target_compile_options(mut PRIVATE /Zc:__cplusplus)

target_compile_options(mut PRIVATE /W4)

      # Debug
    if (${CMAKE_BUILD_TYPE} MATCHES "Debug")

        target_compile_options(mut  PRIVATE /JMC)    # Just my debugging
        target_compile_definitions(mut PRIVATE -DDEBUG)

        target_compile_options(mut  PRIVATE /Od)

        target_compile_options(mut  PRIVATE /RTC1)
        target_compile_options(mut  PRIVATE /GS)
        target_compile_options(mut  PRIVATE /Zi)     # /ZI edit/continue

        target_link_options(mut PRIVATE /DEBUG)
        #target_link_options(mut PRIVATE /ALIGN:16)
    endif()

    # Release
    if (${CMAKE_BUILD_TYPE} MATCHES "Release")
       #set_target_properties(mut PROPERTIES INTERPROCEDURAL_OPTIMIZATION ON)

        target_compile_definitions(mut PRIVATE -DNDEBUG)

        target_compile_options(mut  PRIVATE /O2  /Os)
        target_compile_options(mut  PRIVATE /GS-)

        target_link_options(mut PRIVATE /Release)
        target_link_options(mut PRIVATE /INCREMENTAL:NO)


        target_link_options(mut PRIVATE /OPT:REF /OPT:ICF)
    endif()

set_target_properties(mut PROPERTIES MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>")

set_target_properties(mut PROPERTIES DEBUG_POSTFIX "d")
set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>")






add_subdirectory(src)


set(MODULE_SOURCES
         $<$<CONFIG:Release>:buildnumber.ixx>


)

target_sources(mut
	PUBLIC
    FILE_SET CXX_MODULES 
	FILES ${MODULE_SOURCES}
)





find_program(BUILDINC_TOOL "buildinc")
if(BUILDINC_TOOL)
    add_custom_command(TARGET mut
                       PRE_BUILD
                       COMMAND ${BUILDINC_TOOL} ${CMAKE_CURRENT_SOURCE_DIR}/buildnumber.ixx mut -q -m
                       WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/src
    )
endif()




#
# enable_testing()





#
target_compile_options(${CMAKE_PROJECT_NAME} PRIVATE 
       
    #/wd5039 # pointer or reference to potentially throwing function passed to 'extern "C"' function under -EHc.
    #
    #/wd5262 # implicit fall-through occurs here; are you missing a break statement? Use [[fallthrough]] when a break 
    #        # statement is intentionally omitted between cases
    #/wd4710 # function not inlined
    #/wd4711 # function selected for automatic inline expansion
    #/wd5045 # Compiler will insert Spectre mitigation for memory load if /Qspectre switch specified
    #/wd5050 # Possible incompatible environment while importing module
    #
    #/wd4820 # bytes padding added after data member
    #
    #/wd4626 # assignment operator was implicitly defined as deleted
    #/wd5027 # move assignment operator was implicitly defined as deleted
    #/wd5026 # move constructor was implicitly defined as deleted
    #/wd4061 # switch of enum is not explicitly handled by a case label
    #
    #/wd4355 # 'this': used in base member initializer list
    #/wd4625 # copy constructor was implicitly defined as deleted
    #/wd5220 # a non-static data member with a volatile qualified type no longer implies
    #        # that compiler generated copy/move constructors and copy/move assignment operators are not trivial
    #/wd5204 # class has virtual functions, but its trivial destructor is not virtual; instances of 
    #        # objects derived from this class may not be destructed correctly
    #
    #/wd4686 # possible change in behavior, change in UDT return calling convention
    #
    /wd4324 # structure was padded due to alignment specifier
    #/wd5246 # the initialization of a subobject should be wrapped in braces

)

 
