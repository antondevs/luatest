cmake_minimum_required(VERSION 3.0.0 FATAL_ERROR)

set(PROJECTNAME luatest)

project(${PROJECTNAME})

set(CMAKE_LIBRARY_PATH /lib)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(CURL REQUIRED)

if(APPLE)
    include_directories(
      /usr/local/include
    )

    link_directories(
      ${CMAKE_CURRENT_SOURCE_DIR}/lib
      /usr/local/lib
    )

    link_directories(/usr/local/lib)

    SET(CMAKE_FIND_LIBRARY_PREFIXES "cyg" "lib")
    SET(CMAKE_FIND_LIBRARY_SUFFIXES ".dll" ".dll.a" ".a")

    set(MACOSX_BUNDLE YES)
    set(EXECUTABLE_TYPE MACOSX_BUNDLE)
endif(APPLE)
if(LINUX)
    set(EXECUTABLE_TYPE "")
endif(LINUX)

file(GLOB LIB_LUA "lualib/src/*.*")

include_directories(
    ${CMAKE_CURRENT_SOURCE_DIR}/sources/lualib/src
)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY_DEBUG ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY_RELEASE ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY_DEBUG ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY_RELEASE ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE ${CMAKE_BINARY_DIR}/bin)

file(
	GLOB_RECURSE SRCS RELATIVE
	"${CMAKE_CURRENT_SOURCE_DIR}"
	sources/*.*
)
list(REMOVE_DUPLICATES SRCS)

foreach(source IN LISTS SRCS)
    get_filename_component(source_path "${source}" PATH)
    string(REPLACE "/" "\\" source_path_msvc "${source_path}")
    source_group("${source_path_msvc}" FILES "${source}")
endforeach()  
message(STATUS "Tree reorganized")

list(REMOVE_ITEM SRCS "sources/lualib/src/lua.c")
list(REMOVE_ITEM SRCS "sources/lualib/src/luac.c")

add_executable(${PROJECTNAME} ${SRCS} ${LIB_LUA})

TARGET_LINK_LIBRARIES(${PROJECTNAME})

file(GLOB DATA_FILES
  "data/*.*"
)

file(COPY ${DATA_FILES} DESTINATION ${CMAKE_BINARY_DIR}/bin)