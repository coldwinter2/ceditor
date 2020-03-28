# set friendly platform define
 if(${CMAKE_SYSTEM_NAME} MATCHES "Windows")
     set(WINDOWS TRUE)
     set(SYSTEM_STRING "Windows Desktop")
 elseif(${CMAKE_SYSTEM_NAME} MATCHES "Android")
     set(SYSTEM_STRING "Android")
 elseif(${CMAKE_SYSTEM_NAME} MATCHES "Linux")
     if(ANDROID)
         set(SYSTEM_STRING "Android")
     else()
         set(LINUX TRUE)
         set(SYSTEM_STRING "Linux")
     endif()
 elseif(${CMAKE_SYSTEM_NAME} MATCHES "Darwin")
     if(IOS)
         set(APPLE TRUE)
         set(SYSTEM_STRING "IOS")
     else()
         set(APPLE TRUE)
         set(MACOSX TRUE)
         set(SYSTEM_STRING "Mac OSX")
     endif()
 endif()
 
function(use_compile_options target)
    if(MSVC)
        target_compile_options(${target}
            PUBLIC /MP
        )
    endif()
endfunction()