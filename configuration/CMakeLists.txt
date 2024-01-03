

include_directories(${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_CURRENT_BINARY_DIR})

execute_process(COMMAND
    flex -o ${CMAKE_CURRENT_BINARY_DIR}/config_lexer.cpp ${CMAKE_CURRENT_SOURCE_DIR}/config_lexer.l)

execute_process(COMMAND
    bison -o ${CMAKE_CURRENT_BINARY_DIR}/config_parser.cpp ${CMAKE_CURRENT_SOURCE_DIR}/config_parser.y)

add_executable(configuration
    ${CMAKE_CURRENT_BINARY_DIR}/main.cpp
    ${CMAKE_CURRENT_BINARY_DIR}/config_lexer.cpp
    ${CMAKE_CURRENT_BINARY_DIR}/config_parser.cpp
    ${CMAKE_CURRENT_BINARY_DIR}/ConfigAST.cpp
    ${CMAKE_CURRENT_BINARY_DIR}/DefinePinName.cpp
    ${CMAKE_CURRENT_BINARY_DIR}/DefinePowerSupply.cpp
    ${CMAKE_CURRENT_BINARY_DIR}/ParallelSiteEnable.cpp
    ${CMAKE_CURRENT_BINARY_DIR}/CONFGuration.cpp
    ${CMAKE_CURRENT_BINARY_DIR}/DefineGroup.cpp
    ${CMAKE_CURRENT_BINARY_DIR}/PowerSupplyLoadCapacitance.cpp
    ${CMAKE_CURRENT_BINARY_DIR}/PowerSupplySafetyLimits.cpp
    )

target_link_libraries(configuration PUBLIC
    -lm)
    