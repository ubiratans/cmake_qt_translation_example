# QT AGENDA - MAIN CMAKE FILE

# Specify cmake version compatibility that will be used
cmake_minimum_required(VERSION 2.8.11)

set(CMAKE_AUTOMOC ON)

# Set project and it's name
set(PROJECT_NAME "translation_example")
project(${PROJECT_NAME})

if(NOT DEFINED m64)
    message(FATAL_ERROR "ERROR: System architeture is mandatory! Use -Dm64=TRUE/FALSE")
elseif((NOT ${m64} STREQUAL TRUE) AND (NOT ${m64} STREQUAL FALSE))
    message(FATAL_ERROR "ERROR: Use -Dm64=TRUE/FALSE")
endif()

# Set current platform
message(STATUS "> Identifying platform...")

if(WINDOWS)
    set(platform "win")

elseif(APPLE)
    set(platform "mac")

elseif(UNIX)
    # get linux distro
    if(EXISTS "/etc/issue")
        file(READ "/etc/issue" contents)
        string(TOLOWER ${contents} contents)

        if(${contents} MATCHES "ubuntu")
            set(platform "ubuntu")

        elseif(${contents} MATCHES "debian")
            set(platform "debian")

        elseif(${contents} MATCHES "RedHat")
            set(platform "redhat")

        else()
            message(FATAL_ERROR "This linux distro (${contents}) is not supported!\nSupported distros are: Ubuntu, Debian and Red Hat.")
        endif()

   else(EXISTS "/etc/issue")
        message(FATAL_ERROR "Platform not supported! The platforms supporteds are: Windows 7 and below, Ubuntu, Red Hat, Debian and Mac")
   endif(EXISTS "/etc/issue")

endif(WINDOWS)

if (${m64} STREQUAL "TRUE")
    set(system_architeture 64)
else()
    set(system_architeture 32)
endif()

set(platform "${platform}_x${system_architeture}")
message(STATUS "> Platform: ${platform}\n")

# Set the library and executable directories for the binary tree
if(${CMAKE_BUILD_TYPE} MATCHES "RELEASE" )
    set( EXECUTABLE_OUTPUT_PATH ${CMAKE_CURRENT_LIST_DIR}/Build/Release/${platform} )
    set( LIBRARY_OUTPUT_PATH ${CMAKE_CURRENT_LIST_DIR}/Build/Release/${platform} )
else(${CMAKE_BUILD_TYPE} MATCHES "RELEASE" )
    set( EXECUTABLE_OUTPUT_PATH ${CMAKE_CURRENT_LIST_DIR}/Build/Debug/${platform} )
    set( LIBRARY_OUTPUT_PATH ${CMAKE_CURRENT_LIST_DIR}/Build/Debug/${platform} )
endif()

# Set C++ compile and specify to use c++11
if(UNIX AND NOT APPLE)
    set(CMAKE_CXX_COMPILER "g++")
endif()

set(CMAKE_CXX_FLAGS "-std=c++11 ${CMAKE_CXX_FLAGS}")

# Find QT5 package
find_package(Qt5 REQUIRED COMPONENTS Widgets Core LinguistTools)

# include custom functions
include(CMakeFunctions.txt)

# Set application version
include(CMakeProjectVersion.txt)

configure_file(
    "${PROJECT_SOURCE_DIR}/version.h.in"
    "${PROJECT_SOURCE_DIR}/version.h"
)

# Add the current directory to the list of paths to search for a file
include_directories(".")

# Set translation's languages
set(translation_languages pt_BR en_US de_DE)

get_target_property(QtLupdateLocation Qt5::lupdate LOCATION)
get_target_property(QtLreleaseLocation Qt5::lrelease LOCATION)

# Add subdirectories
add_subdirectory(core)
add_subdirectory(view)

# Generate QM files
set(language_path ${EXECUTABLE_OUTPUT_PATH}/lang)

set(qm_file_list "")

foreach (language ${translation_languages})
    FILE(GLOB_RECURSE language_ts_files "*_${language}.ts")

    message(STATUS ${language_ts_files})

    set(qm_file "translation_package_${language}.qm")
    LIST(APPEND qm_file_list ${qm_file})

    add_custom_command(
                        OUTPUT "translation_package_${language}.qm"
                        COMMAND ${CMAKE_COMMAND} ARGS -E make_directory ${language_path}
                        COMMAND ${QtLreleaseLocation} ARGS ${language_ts_files} -qm ${language_path}/${qm_file}
                       )

endforeach(language ${translation_languages})

add_custom_target(run ALL DEPENDS ${qm_file_list})
