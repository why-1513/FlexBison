

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
    ${CMAKE_CURRENT_BINARY_DIR}/src/TimingAST.cpp
    ${CMAKE_CURRENT_BINARY_DIR}/src/LoggerManager.cpp
    ${CMAKE_CURRENT_BINARY_DIR}/src/PinClock.cpp
    ${CMAKE_CURRENT_BINARY_DIR}/src/ClockResolution.cpp
    ${CMAKE_CURRENT_BINARY_DIR}/src/BreakWaveformDefinitionString.cpp
    ${CMAKE_CURRENT_BINARY_DIR}/src/EdgeTimingDefinitionString.cpp
    ${CMAKE_CURRENT_BINARY_DIR}/src/DeviceCycleDefault.cpp
    ${CMAKE_CURRENT_BINARY_DIR}/src/TimingSetsUsedEXtended.cpp
    )

target_link_libraries(timing PUBLIC
    -lm)
