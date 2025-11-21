set(SUB_LIBRARY_NAME ota_uart)

add_library(${SUB_LIBRARY_NAME} STATIC)

set(OTA_UART_SOURCE 
        ${CMAKE_CURRENT_SOURCE_DIR}/src/ota_uart.c)

set(OTA_UART_INCLUDE_DIR
        ${CMAKE_CURRENT_SOURCE_DIR}/inc)


target_sources(${SUB_LIBRARY_NAME} PRIVATE
${OTA_UART_SOURCE})

target_include_directories(${SUB_LIBRARY_NAME} PUBLIC 
${OTA_UART_INCLUDE_DIR})


target_link_libraries(${SUB_LIBRARY_NAME} PRIVATE
        STM32_Drivers)

