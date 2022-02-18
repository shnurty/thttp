add_library(log "")
target_sources(log PRIVATE log.cpp PUBLIC ${CMAKE_CURRENT_LIST_DIR}/log.h)
target_include_directories(log PUBLIC ${PROJECT_INCLUDE_PATHS})
target_link_libraries(log PUBLIC ${PROJECT_LIBRARIES})

set(PROJECT_LIBRARIES "${PROJECT_LIBRARIES};log" PARENT_SCOPE)

