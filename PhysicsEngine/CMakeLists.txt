file(GLOB_RECURSE HEADER_FILES include/*.h)
file(GLOB_RECURSE SOURCE_FILES src/*.cpp)

add_library(PhysicsEngine ${SOURCE_FILES} ${HEADER_FILES})

target_include_directories(PhysicsEngine
        PUBLIC    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        INTERFACE $<INSTALL_INTERFACE:include>)
target_link_libraries(PhysicsEngine PUBLIC ECS GameEngine)
