cmake_minimum_required (VERSION 2.8)

PROJECT (DEMO)

ADD_DEFINITIONS("-g -Wall -DNDEBUG -ggdb3")

INCLUDE_DIRECTORIES ("/home/kouyan/proj/leveldb/include")
LINK_DIRECTORIES ("/home/kouyan/proj/leveldb")

LINK_LIBRARIES(leveldb)

AUX_SOURCE_DIRECTORY("./" DIR_SRCS)
ADD_EXECUTABLE(demo ${DIR_SRCS})
