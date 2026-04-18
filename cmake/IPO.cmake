include(CheckIPOSupported)

function(enable_lto_if_supported target)
    check_ipo_supported(RESULT ipo_supported)

    if(ipo_supported)
        set_property(TARGET ${target} PROPERTY INTERPROCEDURAL_OPTIMIZATION_RELEASE TRUE)
    endif()
endfunction()