function(generate_header filename file_list)
    set(file ${CMAKE_BINARY_DIR}/${filename})
    set(file_macro __ROCOS_MOD_${filename})
    string(REPLACE "." "_" file_macro ${file_macro})
    file(TOUCH ${file})
    file(WRITE ${file} "#pragma once\n")
    foreach(include_file ${file_list})
        file(APPEND ${file} "#include \"${include_file}\"\n")
    endforeach()
endfunction()

function(init_rocos_mod root_dir export_var)
    file(GLOB SKILL_HEADER_FILES
        "${root_dir}/*.h"
        "${root_dir}/*.hpp"
    )
    file(GLOB SKILL_SOURCE_FILES
        "${root_dir}/*.cpp"
    )
    generate_header(__a_skills.h "${SKILL_HEADER_FILES}")
    set(${export_var} ${${export_var}} PARENT_SCOPE)
endfunction()
