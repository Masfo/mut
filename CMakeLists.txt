
cmake_minimum_required (VERSION 3.26)

set(CMAKE_DISABLE_SOURCE_CHANGES ON)
set(CMAKE_DISABLE_IN_SOURCE_BUILD ON)

# Enable experimental modules support
# https://gitlab.kitware.com/cmake/cmake/-/blob/master/Help/dev/experimental.rst?ref_type=heads
set(CMAKE_EXPERIMENTAL_CXX_MODULE_CMAKE_API "aa1f7df0-828a-4fcd-9afc-2dc80491aca7")
set(CMAKE_EXPERIMENTAL_CXX_MODULE_DYNDEP 1)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_CURRENT_SOURCE_DIR}/CMake")
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(CMAKE_CXX_STANDARD          23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS        OFF)

# VCPKG
if(DEFINED ENV{VCPKG_ROOT})
    set(VCPKG_TARGET_TRIPLET x64-windows-static)
    set(VCPKG_HOST_TRIPLET x64-windows-static)
    include($ENV{VCPKG_ROOT}/scripts/buildsystems/vcpkg.cmake)
else()
    message(WARNING "VCPKG_ROOT is not set")
endif()

# Tests
set(RUN_TESTS                   ON)

include(SetupMSVC)

project(mut LANGUAGES CXX)

#
add_executable (mut )

set_target_properties(mut PROPERTIES POSITION_INDEPENDENT_CODE ON)
set_target_properties(mut PROPERTIES INTERPROCEDURAL_OPTIMIZATION TRUE)

setup_project(mut "")


#
add_subdirectory(src)

enable_testing()
add_subdirectory(tests)



#
target_compile_options(mut PRIVATE 
       
    /wd5039 # pointer or reference to potentially throwing function passed to 'extern "C"' function under -EHc.
    
    /wd5262 # implicit fall-through occurs here; are you missing a break statement? Use [[fallthrough]] when a break 
            # statement is intentionally omitted between cases
    /wd4710 # function not inlined
    /wd4711 # function selected for automatic inline expansion
    /wd5045 # Compiler will insert Spectre mitigation for memory load if /Qspectre switch specified
    /wd5050 # Possible incompatible environment while importing module

    /wd4820 # bytes padding added after data member

    /wd4626 # assignment operator was implicitly defined as deleted
    /wd5027 # move assignment operator was implicitly defined as deleted
    /wd4061 # switch of enum is not explicitly handled by a case label

)

 
