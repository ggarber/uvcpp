file (GLOB_RECURSE SRCS . *.cpp)

add_library (${PROJECT_NAME}
    ${SRCS}
)

add_dependencies (${PROJECT_NAME} ${EXTERNAL_PROJECTS})

add_executable (Main
    Main.cpp
)

target_link_libraries (Main
    # Add libraries here
    ${PROJECT_NAME}
    ${EXTERNAL_LIBRARIES}
)

install (
  DIRECTORY ${CMAKE_SOURCE_DIR}/src/
  DESTINATION include/${PROJECT_NAME}
  FILES_MATCHING PATTERN "*.hpp"
)
install (
  TARGETS ${PROJECT_NAME}
  DESTINATION lib
)
