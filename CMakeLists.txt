# The following lines of boilerplate have to be in your project's
# CMakeLists in this exact order for cmake to work correctly
cmake_minimum_required(VERSION 3.16)

set(CMAKE_CXX_STANDARD 14)
set(EXTRA_COMPONENT_DIRS ./components)

set(SDKCONFIG "sdkconfig")
set(SDKCONFIG_DEFAULTS "sdkconfig.defaults")

include($ENV{IDF_PATH}/tools/cmake/project.cmake)

project(arduino_ble_provisioning)

idf_build_set_property(COMPILE_OPTIONS "-Wall" APPEND)
idf_build_set_property(COMPILE_OPTIONS "-Wextra" APPEND)
# idf_build_set_property(COMPILE_OPTIONS "-Werror" APPEND)
idf_build_set_property(COMPILE_OPTIONS "-Werror=unused-variable" APPEND)
idf_build_set_property(COMPILE_OPTIONS "-Wdisabled-optimization" APPEND)
idf_build_set_property(COMPILE_OPTIONS "-Winit-self" APPEND)
idf_build_set_property(COMPILE_OPTIONS "-Wmissing-include-dirs" APPEND)
idf_build_set_property(CXX_COMPILE_OPTIONS "-Wnoexcept" APPEND)
idf_build_set_property(CXX_COMPILE_OPTIONS "-Woverloaded-virtual" APPEND)
idf_build_set_property(CXX_COMPILE_OPTIONS "-Wstrict-null-sentinel" APPEND)
idf_build_set_property(COMPILE_OPTIONS "-Wno-error=overloaded-virtual" APPEND)
idf_build_set_property(CXX_COMPILE_OPTIONS "-Wno-error=overloaded-virtual" APPEND)