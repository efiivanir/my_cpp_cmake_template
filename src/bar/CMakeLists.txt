set(LIBRARY_SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/bar.cc")
set(LIBRARY_HEADERS "${CMAKE_CURRENT_SOURCE_DIR}/bar.h")

add_library("LibBar" STATIC ${LIBRARY_SOURCES} ${LIBRARY_HEADERS})
target_include_directories("LibBar" PUBLIC ${LIBRARY_INCLUDES})
target_link_libraries(
    "LibBar"
    PRIVATE nlohmann_json::nlohmann_json
            fmt::fmt
            spdlog::spdlog
            cxxopts::cxxopts)

if(${ENABLE_WARNINGS})
    target_set_warnings(
        "LibBar"
        ${ENABLE_WARNINGS}
        ${ENABLE_WARNINGS_AS_ERRORS})
endif()

if(${ENABLE_LTO})
    target_enable_lto(
        TARGET
        "LibBar"
        ENABLE
        ON)
endif()

if(${ENABLE_CLANG_TIDY})
    add_clang_tidy_to_target("LibBar")
endif()
