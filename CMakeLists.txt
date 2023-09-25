

set(SRC "${CMAKE_CURRENT_SOURCE_DIR}/src")
set(INCLUDES "${CMAKE_CURRENT_SOURCE_DIR}/include")


set(MRSE_SRCS
    "${SRC}/core/config.cpp"
    "${SRC}/core/decoder.cpp"
    "${SRC}/core/encoder.cpp"
    "${SRC}/core/translator.cpp"
    "${SRC}/mrse_utility.cpp"
    "${SRC}/validator.cpp"
    "${SRC}/engine.cpp"
)


add_library(MRSE-ENGINE STATIC ${MRSE_SRCS})
target_include_directories(MRSE-ENGINE PUBLIC "${INCLUDES}")