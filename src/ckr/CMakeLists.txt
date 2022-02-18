add_library(ckr "")
target_sources(ckr PRIVATE ckr.cpp PUBLIC ${CMAKE_CURRENT_LIST_DIR}/ckr.h)
target_include_directories(ckr PUBLIC ${PROJECT_INCLUDE_PATHS})
target_link_libraries(ckr PUBLIC ${PROJECT_LIBRARIES})

set(PROJECT_LIBRARIES "${PROJECT_LIBRARIES};ckr" PARENT_SCOPE)

