set(SUB_LIBRARY_NAME 24CXX)

add_library(${SUB_LIBRARY_NAME} STATIC)

set(LIBRARY_SOURCE 
        ${CMAKE_CURRENT_SOURCE_DIR}/src/24cxx.c)

set(LIBRARY_INCLUDE_DIR
        ${CMAKE_CURRENT_SOURCE_DIR}/inc)


target_sources(${SUB_LIBRARY_NAME} PRIVATE
${LIBRARY_SOURCE})

target_include_directories(${SUB_LIBRARY_NAME} PUBLIC 
${LIBRARY_INCLUDE_DIR})


target_link_libraries(${SUB_LIBRARY_NAME} PRIVATE
        STM32_Drivers
        MY_IIC
)

