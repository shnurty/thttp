add_library(ckr "")
target_sources(ckr PRIVATE ckr.cpp PUBLIC ${CMAKE_CURRENT_LIST_DIR}/ckr.h)

set(PROJECT_LIBRARIES "${PROJECT_LIBRARIES};ckr" PARENT_SCOPE)

