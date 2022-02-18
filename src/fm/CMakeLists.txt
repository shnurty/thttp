add_library(fm "")
target_sources(fm PRIVATE fm.cpp PUBLIC ${CMAKE_CURRENT_LIST_DIR}/fm.h)
target_include_directories(fm PUBLIC ${PROJECT_INCLUDE_PATHS})

set(PROJECT_LIBRARIES "${PROJECT_LIBRARIES};fm" PARENT_SCOPE)

