add_library(cm SHARED cm.cpp)
target_sources(cm PRIVATE cm.cpp PUBLIC ${CMAKE_CURRENT_LIST_DIR}/cm.h)

set(PROJECT_LIBRARIES "${PROJECT_LIBRARIES};cm" PARENT_SCOPE)

