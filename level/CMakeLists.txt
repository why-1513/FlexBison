

include_directories(${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_CURRENT_BINARY_DIR})

execute_process(COMMAND
    flex -o ${CMAKE_CURRENT_BINARY_DIR}/level_lexer.cpp ${CMAKE_CURRENT_SOURCE_DIR}/level_lexer.l)

execute_process(COMMAND
    bison -o ${CMAKE_CURRENT_BINARY_DIR}/level_parser.cpp ${CMAKE_CURRENT_SOURCE_DIR}/level_parser.y)

add_executable(level
    ${CMAKE_CURRENT_BINARY_DIR}/main.cpp
    ${CMAKE_CURRENT_BINARY_DIR}/level_lexer.cpp
    ${CMAKE_CURRENT_BINARY_DIR}/level_parser.cpp
    ${CMAKE_CURRENT_BINARY_DIR}/LevelAST.cpp
    ${CMAKE_CURRENT_BINARY_DIR}/LoggerManager.cpp)

target_link_libraries(level PUBLIC
    -lm)
