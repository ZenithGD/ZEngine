out_dir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "GLAD"
    kind "StaticLib"
    language "C"
    staticruntime "on"
    
    targetdir ("bin/" .. out_dir .. "/%{prj.name}")
    objdir ("bin-int/" .. out_dir .. "/%{prj.name}")

    files {
        "include/glad/glad.h",
        "include/KHR/khrplatform.h",
        "src/glad.c"
    }

    includedirs "include"