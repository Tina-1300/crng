function(enable_tests target)


    add_library(unity
        external/unity/unity.c
    )

    target_include_directories(unity PUBLIC
        external/unity
    )

    file(GLOB TEST_SOURCES CONFIGURE_DEPENDS tests/*.c)

    foreach(test_file ${TEST_SOURCES})
        get_filename_component(test_name ${test_file} NAME_WE)

        add_executable(${test_name} ${test_file})

        target_link_libraries(${test_name}
            PRIVATE ${target} unity
        )

        target_include_directories(${test_name} PRIVATE
            include
        )

        add_test(NAME ${test_name} COMMAND ${test_name})
    endforeach()
endfunction()