set(sources
    bubblesort_test.cpp
)
foreach(src ${sources})
    get_filename_component(src_name ${src} NAME_WE)
    add_executable(${src_name} ${src})
    target_include_directories(${src_name} PUBLIC ${headers})
    target_link_libraries(${src_name} gtest_main)
    add_test(NAME ${src_name} COMMAND ${src_name})
endforeach()