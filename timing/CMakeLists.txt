

include_directories(${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_CURRENT_BINARY_DIR})

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)

execute_process(COMMAND
    flex -o ${CMAKE_CURRENT_BINARY_DIR}/timing_lexer.cpp ${CMAKE_CURRENT_SOURCE_DIR}/src/timing_lexer.l)

execute_process(COMMAND
    bison -o ${CMAKE_CURRENT_BINARY_DIR}/timing_parser.cpp ${CMAKE_CURRENT_SOURCE_DIR}/src/timing_parser.y)

add_executable(timing
    ${CMAKE_CURRENT_BINARY_DIR}/src/main.cpp
    ${CMAKE_CURRENT_BINARY_DIR}/timing_lexer.cpp
    ${CMAKE_CURRENT_BINARY_DIR}/timing_parser.cpp
    ${CMAKE_CURRENT_BINARY_DIR}/src/TimingAST.cpp)

target_link_libraries(timing PUBLIC
    -lm)
