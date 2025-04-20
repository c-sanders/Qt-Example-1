cmake_minimum_required(

 VERSION
     3.16
)

project(

 QtExample 
 VERSION
     1.0.0
 LANGUAGES
     CXX
)

set(

 CMAKE_CXX_STANDARD
 17
)

set(

 CMAKE_CXX_STANDARD_REQUIRED 
 ON
)

set(

 CMAKE_MODULE_PATH

)

# Find particular packages.

find_package(

 Qt6
 REQUIRED COMPONENTS
     Core
     Widgets
)

qt_standard_project_setup()

qt_add_executable(

 QtExample1
 QtExample1.cpp
 MainWindowHelper.cpp
 QtExample1.ui
)

target_link_libraries(

 QtExample1
 PRIVATE 
     Qt6::Core 
     Qt6::Widgets
)
