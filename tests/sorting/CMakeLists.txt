set(sources
    bubblesort_test.cpp
    insertionsort_test.cpp
    selectionsort_test.cpp
    shakersort_test.cpp
    shellsort_test.cpp
    quicksort_test.cpp
    quicksort_subfile_optimization_test.cpp
)
foreach(src ${sources})
    get_filename_component(src_name ${src} NAME_WE)
    add_executable(${src_name} ${src})
    target_include_directories(${src_name} PUBLIC ${headers})
    target_link_libraries(${src_name} gtest_main)
    add_test(NAME ${src_name} COMMAND ${src_name})
endforeach()