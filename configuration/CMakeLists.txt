

include_directories(${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_CURRENT_BINARY_DIR})

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)

execute_process(COMMAND
    flex -o ${CMAKE_CURRENT_BINARY_DIR}/config_lexer.cpp ${CMAKE_CURRENT_SOURCE_DIR}/src/config_lexer.l)

execute_process(COMMAND
    bison -o ${CMAKE_CURRENT_BINARY_DIR}/config_parser.cpp ${CMAKE_CURRENT_SOURCE_DIR}/src/config_parser.y)

add_executable(configuration
    ${CMAKE_CURRENT_BINARY_DIR}/src/main.cpp
    ${CMAKE_CURRENT_BINARY_DIR}/config_lexer.cpp
    ${CMAKE_CURRENT_BINARY_DIR}/config_parser.cpp
    ${CMAKE_CURRENT_BINARY_DIR}/src/ConfigAST.cpp
    ${CMAKE_CURRENT_BINARY_DIR}/src/DefinePinName.cpp
    ${CMAKE_CURRENT_BINARY_DIR}/src/DefinePowerSupply.cpp
    ${CMAKE_CURRENT_BINARY_DIR}/src/ParallelSiteEnable.cpp
    ${CMAKE_CURRENT_BINARY_DIR}/src/CONFGuration.cpp
    ${CMAKE_CURRENT_BINARY_DIR}/src/DefineGroup.cpp
    ${CMAKE_CURRENT_BINARY_DIR}/src/PowerSupplyLoadCapacitance.cpp
    ${CMAKE_CURRENT_BINARY_DIR}/src/PowerSupplySafetyLimits.cpp
    ${CMAKE_CURRENT_BINARY_DIR}/src/LoggerManager.cpp
    )

target_link_libraries(configuration PUBLIC
    -lm)
    