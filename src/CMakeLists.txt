file(GLOB_RECURSE _sources ${CMAKE_CURRENT_LIST_DIR}/*.cc  CONFIGURE_DEPEND)
target_sources(cygenerate PRIVATE ${_sources})
unset(_sources)