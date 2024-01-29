

include_directories(${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_CURRENT_BINARY_DIR})

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)

execute_process(COMMAND
    flex -o ${CMAKE_CURRENT_BINARY_DIR}/level_lexer.cpp ${CMAKE_CURRENT_SOURCE_DIR}/src/level_lexer.l)

execute_process(COMMAND
    bison -o ${CMAKE_CURRENT_BINARY_DIR}/level_parser.cpp ${CMAKE_CURRENT_SOURCE_DIR}/src/level_parser.y)

add_executable(level
    ${CMAKE_CURRENT_BINARY_DIR}/src/main.cpp
    ${CMAKE_CURRENT_BINARY_DIR}/level_lexer.cpp
    ${CMAKE_CURRENT_BINARY_DIR}/level_parser.cpp
    ${CMAKE_CURRENT_BINARY_DIR}/src/LevelAST.cpp
    ${CMAKE_CURRENT_BINARY_DIR}/src/LoggerManager.cpp
    ${CMAKE_CURRENT_BINARY_DIR}/src/PowerSupplyLevel.cpp
    ${CMAKE_CURRENT_BINARY_DIR}/src/DriveLevel.cpp
    ${CMAKE_CURRENT_BINARY_DIR}/src/ReceiveLevel.cpp
    ${CMAKE_CURRENT_BINARY_DIR}/src/TERMinationMode.cpp
    ${CMAKE_CURRENT_BINARY_DIR}/src/ClampLevel.cpp
    ${CMAKE_CURRENT_BINARY_DIR}/src/LevelSetsUsedExtended.cpp
    ${CMAKE_CURRENT_BINARY_DIR}/src/EquationSpecificationTransfer.cpp)

target_link_libraries(level PUBLIC
    -lm)
