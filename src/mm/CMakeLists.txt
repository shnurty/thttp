add_library(mm SHARED mm.cpp)
target_sources(mm PRIVATE mm.cpp PUBLIC ${CMAKE_CURRENT_LIST_DIR}/mm.h)

set(PROJECT_LIBRARIES "${PROJECT_LIBRARIES};mm" PARENT_SCOPE)

