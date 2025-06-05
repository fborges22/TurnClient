# FindTURNClient.cmake

find_path(TURNCLIENT_INCLUDE_DIR TurnMsgLib.h
          PATH_SUFFIXES turnclient
          DOC "Path to TURNClient include directory")

find_library(TURNCLIENT_LIBRARY NAMES turnclient
             DOC "Path to TURNClient library")

include(FindPackageHandleStandardArgs)
find_package_handle_standard_args(TURNClient
    REQUIRED_VARS TURNCLIENT_INCLUDE_DIR TURNCLIENT_LIBRARY
    VERSION_VAR TURNCLIENT_VERSION)

mark_as_advanced(TURNCLIENT_INCLUDE_DIR TURNCLIENT_LIBRARY)
