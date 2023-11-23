

include_directories(${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_CURRENT_BINARY_DIR})

execute_process(COMMAND
    flex -o ${CMAKE_CURRENT_BINARY_DIR}/config_lexer.cpp ${CMAKE_CURRENT_SOURCE_DIR}/config_lexer.l)

execute_process(COMMAND
    bison -o ${CMAKE_CURRENT_BINARY_DIR}/config_parser.cpp ${CMAKE_CURRENT_SOURCE_DIR}/config_parser.y)

add_executable(configuration
    ${CMAKE_CURRENT_BINARY_DIR}/config_lexer.cpp
    ${CMAKE_CURRENT_BINARY_DIR}/config_parser.cpp)

target_link_libraries(configuration PUBLIC
    -lm)
