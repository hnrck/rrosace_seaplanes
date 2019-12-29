# Additional target for code linting with clang-tidy.

set(SRCS_DIR ${CMAKE_SOURCE_DIR}/src/)
set(INCS_DIR ${CMAKE_SOURCE_DIR}/include/)
set(TEMPLATES_DIR ${CMAKE_SOURCE_DIR}/templates/)

file(GLOB_RECURSE SRCS ${SRCS_DIR}/*.cpp)
file(GLOB_RECURSE INCS ${INCS_DIR}/*.h)

find_program(CLANG-FORMAT clang-format)

if (CLANG-FORMAT)
    set(CLANG-FORMAT-STYLE LLVM)
    add_custom_target(format COMMAND ${CLANG-FORMAT} -style=${CLANG-FORMAT-STYLE} -i ${SRCS} ${INCS})
endif (CLANG-FORMAT)
