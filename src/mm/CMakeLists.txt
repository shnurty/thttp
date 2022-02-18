add_library(mm "")
target_sources(mm PRIVATE mm.cpp PUBLIC ${CMAKE_CURRENT_LIST_DIR}/mm.h)
target_include_directories(mm PUBLIC ${PROJECT_INCLUDE_PATHS})
target_link_libraries(mm PUBLIC ${PROJECT_LIBRARIES})

set(PROJECT_LIBRARIES "${PROJECT_LIBRARIES};mm" PARENT_SCOPE)

