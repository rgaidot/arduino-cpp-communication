
# Uses 2.8.8 features
CMAKE_MINIMUM_REQUIRED(VERSION 2.8.8)

# Configuring project
PROJECT(communication)

FILE(
   GLOB_RECURSE
   SOURCE_FILES
   src/*.cpp
)

SET(Boost_USE_STATIC_LIBS OFF)
SET(Boost_USE_MULTITHREADED ON)
SET(Boost_USE_STATIC_RUNTIME OFF)

FIND_PACKAGE(Boost 1.40.0 COMPONENTS system thread)

if(Boost_FOUND)

   INCLUDE_DIRECTORIES(${Boost_INCLUDE_DIRS})

        ADD_EXECUTABLE(
                ${PROJECT_NAME}
            ${SOURCE_FILES}    
        )

   TARGET_LINK_LIBRARIES(${PROJECT_NAME} ${Boost_LIBRARIES})
endif()

