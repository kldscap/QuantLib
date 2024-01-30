cmake_minimum_required(VERSION 3.15.0)

project(quantlibjl)

# ore CMAKE helpers
# include("../cmake/writeAll.cmake")
# include("../cmake/commonSettings.cmake")

if (MSVC)
  add_compile_options(/bigobj)
else ()
  add_compile_options(-Wa,-mbig-obj)
endif ()

find_package(JlCxx REQUIRED)
get_target_property(JlCxx_location JlCxx::cxxwrap_julia LOCATION)
get_filename_component(JlCxx_location ${JlCxx_location} DIRECTORY)
set(CMAKE_INSTALL_RPATH "${CMAKE_INSTALL_PREFIX}/lib;${JlCxx_location}")

# need to include Julia and JLCxx include files 
# set(JLCXX_INCLUDE_DIR C:/Users/asadu/.julia/dev/libcxxwrap_julia_jll/override/include)
include_directories(${Julia_INCLUDE_DIRS} ${JLCXX_INCLUDE_DIR} )

# set jlcxx link libraries
set(JLCXX_TARGET cxxwrap_julia)
set(JLCXX_STL_TARGET cxxwrap_julia_stl)
# link_directories("C:/Users/asadu/.julia/dev/libcxxwrap_julia_jll/override/lib")

# quantlib include 
include_directories(${QUANTLIB_SOURCE_DIR})

# quantlib libraries
# add_link_directory_if_exists("${QUANTLIB_SOURCE_DIR}/build/ql")

IF (JlCxx_FOUND)
    message(STATUS "Found JlCxx at ${JlCxx_location}")

    get_property(dirs DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY INCLUDE_DIRECTORIES)
    foreach(dir ${dirs})
        message(STATUS "dir='${dir}'")
    endforeach()

    add_library(quantlibjl SHARED "time.cpp" "ratehelpers.cpp" "marketelements.cpp" "observer.cpp" "module.cpp" "indexes.cpp" "timeseries.cpp" "currencies.cpp" "rounding.cpp" "daycounters.cpp")
    
    # target_link_libraries(JLQuantLib ${JLCXX_TARGET} ${JLCXX_STL_TARGET} ${Julia_LIBRARY})
    target_link_libraries(quantlibjl ql_library ${QL_THREAD_LIBRARIES} ${JLCXX_TARGET} ${JLCXX_STL_TARGET} ${Julia_LIBRARY})
    
        # target_link_libraries(bsgjl bsg)
        # target_link_libraries(bsgjl JlCxx::cxxwrap_julia)
ENDIF()




#install(TARGETS
#  jlquantlib
#LIBRARY DESTINATION lib
#ARCHIVE DESTINATION lib
#RUNTIME DESTINATION lib)





