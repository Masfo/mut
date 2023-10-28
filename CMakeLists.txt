
cmake_minimum_required (VERSION 3.28)

set(CMAKE_DISABLE_SOURCE_CHANGES ON)
set(CMAKE_DISABLE_IN_SOURCE_BUILD ON)


set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_CURRENT_SOURCE_DIR}/CMake")
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)





set(CMAKE_CXX_STANDARD          23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS        OFF)
set(CMAKE_CXX_SCAN_FOR_MODULES  ON)

# VCPKG
if(DEFINED ENV{VCPKG_ROOT})
    set(VCPKG_TARGET_TRIPLET x64-windows-static)
    set(VCPKG_HOST_TRIPLET x64-windows-static)
    include($ENV{VCPKG_ROOT}/scripts/buildsystems/vcpkg.cmake)
else()
    message(WARNING "VCPKG_ROOT is not set")
endif()

# 3rd party
include(FetchContent)

FetchContent_Declare(
  Deckard
  GIT_REPOSITORY https://github.com/Masfo/Deckard.git
  GIT_TAG main
  GIT_SHALLOW 1
  #GIT_TAG v.0.0.262
)
FetchContent_MakeAvailable(Deckard)






# Tests
set(RUN_TESTS                   OFF)

include(SetupMSVC)
#include(std_modules)


project(mut LANGUAGES CXX)


#
add_executable(${CMAKE_PROJECT_NAME})


setup_project(${CMAKE_PROJECT_NAME} "")

set_target_properties(${CMAKE_PROJECT_NAME} PROPERTIES POSITION_INDEPENDENT_CODE ON)
set_target_properties(${CMAKE_PROJECT_NAME} PROPERTIES INTERPROCEDURAL_OPTIMIZATION TRUE)



#
add_subdirectory(src)
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

 

