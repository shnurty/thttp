add_library(cm SHARED cm.cpp)
target_sources(cm PRIVATE cm.cpp PUBLIC ${CMAKE_CURRENT_LIST_DIR}/cm.h)
target_include_directories(cm PUBLIC ${PROJECT_INCLUDE_PATHS} ${PROJECT_GEN_DIR})

set(PROJECT_LIBRARIES "${PROJECT_LIBRARIES};cm" PARENT_SCOPE)

