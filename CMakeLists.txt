# file CMakeLists.txt
# author Henrick Deschamps
# version 1.0.0
# date 2019-12-29

#-----------------------------------------------------------------------------------------------------------------------
# Project configuration

# Project name
project(rrosace_seaplanes CXX)

# CMake minimum version required set by default, might be changed.
cmake_minimum_required(VERSION 3.8)

# Description summary of the project.
set(PACKAGE_NAME rrosace_seaplanes)
set(DESCRIPTION_SUMMARY "RROSACE seaplanes.")

# RROSACE configuration.
set(RROSACE_FOM "rrosace.fed")
set(RROSACE_FEDERATION "RROSACE")
set(RROSACE_SYNC_POINT "syncPoint")
set(RROSACE_TIME_LIMITE "50.")
set(STD_FSTREAM "1")
set(CERTI_MESSAGE_BUFFER "0")

# Application Binary Interface version for library/application interfacing.
set(ABI_VERSION_MAJOR "0")
set(ABI_VERSION_MINOR "0")
set(ABI_VERSION_PATCH "1")
set(ABI_VERSION "${ABI_VERSION_MAJOR}.${ABI_VERSION_MINOR}.${ABI_VERSION_PATCH}")

# Setting compilation options.
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wpedantic")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wextra")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Weffc++")

# CXX flags depending on the build type.
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -O0 -g")
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -O3 -DNDEBUG")
set(CMAKE_CXX_FLAGS_RELWITHDEBINFO "${CMAKE_CXX_FLAGS_RELWITHDEBINFO} -O2 -g")
set(CMAKE_CXX_FLAGS_MINSIZEREL "${CMAKE_CXX_FLAGS_MINSIZEREL} -Os")

# Default build type if none provided.
if (NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE RelWithDebInfo)
endif ()

# Location for the RROSACE SEAPlanes binary build.
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY usr/bin)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY usr/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY usr/lib)

#-----------------------------------------------------------------------------------------------------------------------

#-----------------------------------------------------------------------------------------------------------------------
# Extra modules

# Allowing alternatives for compilations.
option(COVERAGE "Allow code coverage. (requires GCOV. Optionnaly LCOV and genhtml for reports)." OFF)

# Adding CMake extra modules for code linting/formatting.
set(CMAKE_EXTRA_MODULES_DIR ${CMAKE_SOURCE_DIR}/cmake-extra-modules)
set(CMAKE_EXTRA_MODULES clang-format clang-tidy)
foreach (CMAKE_EXTRA_MODULE ${CMAKE_EXTRA_MODULES})
    include(${CMAKE_EXTRA_MODULES_DIR}/${CMAKE_EXTRA_MODULE}.cmake)
endforeach ()
#-----------------------------------------------------------------------------------------------------------------------

#-----------------------------------------------------------------------------------------------------------------------
# Build

if (APPLE)
    set(CMAKE_MACOSX_RPATH ON)
    find_library(SEAPLANES_LIB seaplanes ENV DYLD_LIBRARY_PATH)
    find_library(RROSACE_LIB rrosace ENV DYLD_LIBRARY_PATH)
    find_library(RTI_LIB RTI-NG ENV DYLD_LIBRARY_PATH)
    if (NOT RTI_LIB) # FIX(h.deschamps) When NAMES finaly works, change this
        find_library(RTI_LIB RTI-NGd ENV DYLD_LIBRARY_PATH)
    endif ()
else ()
    find_library(SEAPLANES_LIB seaplanes ENV LIBRARY_PATH)
    find_library(RROSACE_LIB rrosace ENV LIBRARY_PATH)
    find_library(RTI_LIB RTI-NG ENV LIBRARY_PATH)
    if (NOT RTI_LIB) # FIX(h.deschamps) When NAMES finaly works, change this
        find_library(RTI_LIB RTI-NGd ENV LIBRARY_PATH)
    endif ()
endif ()


set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -DFEDERATION_NAME='\"${RROSACE_FEDERATION}\"'")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -DFEDERATION_FILE='\"${RROSACE_FOM}\"'")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -DFEDERATION_SYNC_POINT_NAME='\"${RROSACE_SYNC_POINT}\"'")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -DUSE_CERTI_MESSAGE_BUFFER='${CERTI_MESSAGE_BUFFER}'")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -DRTI_USES_STD_FSTREAM='${STD_FSTREAM}'")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -DTIME_LIMIT='${RROSACE_TIME_LIMITE}'")

include_directories(${CMAKE_SOURCE_DIR}/include)

set(RROSACE_SEAPLANES_SRCS
        ${CMAKE_SOURCE_DIR}/src/Federate.cpp
        ${CMAKE_SOURCE_DIR}/src/Configuration.cpp
        ${CMAKE_SOURCE_DIR}/src/FederateBuilder.cpp
        ${CMAKE_SOURCE_DIR}/src/ModelFactory.cpp
        ${CMAKE_SOURCE_DIR}/src/Updaters.cpp
        ${CMAKE_SOURCE_DIR}/src/Retrievers.cpp
        ${CMAKE_SOURCE_DIR}/src/main.cpp)

add_executable(rrosace_federate ${RROSACE_SEAPLANES_SRCS})

target_link_libraries(rrosace_federate ${RTI_LIB} ${RROSACE_LIB} ${SEAPLANES_LIB})
if (APPLE)
    target_link_libraries(rrosace_federate ${FEDTIME_LIB} ${HLA_LIB})
endif ()


#-----------------------------------------------------------------------------------------------------------------------

#-----------------------------------------------------------------------------------------------------------------------
# Installation
set(RROSACE_FOM_PATH usr/share/${PROJECT_NAME}/fom)
install(FILES ${CMAKE_SOURCE_DIR}/res/${RROSACE_FOM} DESTINATION ${RROSACE_FOM_PATH})

# Federates installation
set(RROSACE_BINARY_PATH ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/${PROJECT_NAME})

install(TARGETS rrosace_federate DESTINATION ${RROSACE_BINARY_PATH})

# Path configuration for RROSACE SEAPlanes.
set(RROSACE_SEAPLANES_PATHS_CONF rrosaceseaplanespathsrc)
file(WRITE ${CMAKE_BINARY_DIR}/${RROSACE_SEAPLANES_PATHS_CONF}
        "export PATH=$PATH:${CMAKE_INSTALL_PREFIX}/${RROSACE_BINARY_PATH}/\n"
        "export CERTI_FOM_PATH=$CERTI_FOM_PATH:${CMAKE_INSTALL_PREFIX}/${RROSACE_FOM_PATH}/\n"
        )

# Configurations to install.
set(RROSACE_SEAPLANES_CONFS ${CMAKE_BINARY_DIR}/${RROSACE_SEAPLANES_PATHS_CONF})

# The RROSACE SEAPlanes executables configuration files.
set(CONFS_INSTALL_DIR etc/${PROJECT_NAME})
install(FILES ${RROSACE_SEAPLANES_CONFS} DESTINATION ${CONFS_INSTALL_DIR}/)

# If in debug, coverage report can be generated with <cmake> ... -DCOVERAGE=ON and <make> coverage
if (CMAKE_BUILD_TYPE MATCHES "Debug")
    if (COVERAGE)
        find_program(MAKE_DIR mkdir)
        find_program(LCOV lcov)
        find_program(GEN_HTML genhtml)
        find_program(PRINT echo)
        set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fprofile-arcs -ftest-coverage")
        if ("${CMAKE_C_COMPILER_ID}" STREQUAL "Clang")
            set_property(TARGET ${PROJECT_NAME} APPEND_STRING PROPERTY LINK_FLAGS "--coverage ")
        endif ()
        target_link_libraries(${PROJECT_NAME} gcov)
        set(COVERAGE_DIR ${CMAKE_BINARY_DIR}/coverage)
        set(CMAKE_COV
                ${MAKE_DIR} -p ${COVERAGE_DIR}
                && ${LCOV} -c
                -b ${CMAKE_BINARY_DIR}/CMakeFiles/${PROJECT_NAME}.dir/src
                -d ${CMAKE_BINARY_DIR}/CMakeFiles/${PROJECT_NAME}.dir/src
                -o ${COVERAGE_DIR}/coverage.run
                && ${GEN_HTML} -o ${COVERAGE_DIR} ${COVERAGE_DIR}/coverage.run
                && ${PRINT} "Coverage report generated. Please open ${COVERAGE_DIR}/index.html with a browser.")
        add_custom_target(coverage COMMAND ${CMAKE_COV})
    endif ()
else ()
    if (COVERAGE)
        message(WARNING
                "coverage is only available with Debug build type."
                )
    endif ()
endif ()

# Special install_seaplanes target for certain IDE.
add_custom_target(install_${PROJECT_NAME}
        "${CMAKE_COMMAND}" --build "${CMAKE_BINARY_DIR}" --target install
        DEPENDS ${PROJECT_NAME}
        COMMENT "Installing ${PROJECT_NAME} in ${CMAKE_INSTALL_PREFIX}"
        )
#-----------------------------------------------------------------------------------------------------------------------

#-----------------------------------------------------------------------------------------------------------------------
# Documentation, with Doxygen

find_package(Doxygen)
option(BUILD_DOCUMENTATION "Create and install the HTML based API documentation (requires Doxygen)" ${DOXYGEN_FOUND})

if (BUILD_DOCUMENTATION)
    set(doxyfile_in ${CMAKE_CURRENT_SOURCE_DIR}/doc/Doxyfile.in)
    set(doxyfile ${CMAKE_CURRENT_BINARY_DIR}/doc/Doxyfile)

    configure_file(${doxyfile_in} ${doxyfile} @ONLY)

    add_custom_target(doc
            COMMAND ${DOXYGEN_EXECUTABLE} ${doxyfile}
            WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
            COMMENT "Generating API documentation with Doxygen"
            VERBATIM)
endif ()
#-----------------------------------------------------------------------------------------------------------------------

#-----------------------------------------------------------------------------------------------------------------------
# Project summary for CMake run

string(TOUPPER "${CMAKE_BUILD_TYPE}" BUILD_TYPE)

message(STATUS "+------------------------------------")
message(STATUS "|   ${PROJECT_NAME} built summary")
message(STATUS "+------------------------------------")
message(STATUS "| Description:")
message(STATUS "| ${DESCRIPTION_SUMMARY}")
message(STATUS "+------------------------------------")
message(STATUS "| ")
message(STATUS "| library ABI version: ${ABI_VERSION}")
message(STATUS "| generator:           ${CMAKE_GENERATOR}")
message(STATUS "| build type:          ${CMAKE_BUILD_TYPE}")
message(STATUS "| ")
message(STATUS "| CXX:                 ${CMAKE_CXX_COMPILER}")
message(STATUS "| CXXFLAGS:            ${CMAKE_CXX_FLAGS} ${CMAKE_CXX_FLAGS_${BUILD_TYPE}}")
message(STATUS "| LDFLAGS:             ${LDFLAGS}")
message(STATUS "| ")
message(STATUS "| source directory:    ${CMAKE_CURRENT_SOURCE_DIR}")
message(STATUS "| build directory:     ${CMAKE_CURRENT_BINARY_DIR}")
message(STATUS "| install prefix:      ${CMAKE_INSTALL_PREFIX}")
message(STATUS "| binary directory:    ${CMAKE_INSTALL_PREFIX}/${BINARY_INSTALL_DIR}")
message(STATUS "| confs directory:     ${CMAKE_INSTALL_PREFIX}/${CONFS_INSTALL_DIR}")
message(STATUS "| ")
if (CMAKE_BUILD_TYPE MATCHES "Debug")
    message(STATUS "| coverage:            ${COVERAGE}")
endif ()
message(STATUS "+------------------------------------")
#-----------------------------------------------------------------------------------------------------------------------
