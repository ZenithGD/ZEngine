workspace "ZEngine"
    architecture "x64"
    
    configurations {
        "Debug",
        "Release",
        "Dist"
    }
out_dir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

include_dirs = {}
include_dirs["GLFW"] = "ZEngine/vendor/GLFW/include"
include_dirs["GLAD"] = "ZEngine/vendor/GLAD/include"

include "ZEngine/vendor/GLFW"
include "ZEngine/vendor/GLAD"

project "ZEngine"
    location "ZEngine"
    kind "SharedLib"
    language "C++"

    -- Multithreaded DLL version
    staticruntime "off"

    targetdir ("bin/" .. out_dir .. "/%{prj.name}")
    objdir ("bin-int/" .. out_dir .. "/%{prj.name}")

    pchheader "zepch.h"
    pchsource "ZEngine/src/zepch.cpp"

    files {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp"
    }

    includedirs {
        "%{prj.name}/src",
        "%{prj.name}/vendor/spdlog/include",
        "%{include_dirs.GLFW}",
        "%{include_dirs.GLAD}"
    }

    -- link static libraries to ZEngine
    links {
        "GLFW",
        "GLAD",
        "opengl32.lib"
    }

    filter "system:windows"
        cppdialect "C++17"
        staticruntime "On"
        systemversion "latest"

        defines {
            "ZE_PLATFORM_WINDOWS",
            "ZE_BUILD_DLL",
            "GLFW_INCLUDE_NONE"
        }

        postbuildcommands {
            ("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. out_dir .. "/Sandbox")
        }

    filter "configurations:Debug"
        defines "ZE_DEBUG"
        buildoptions "/MDd"
        symbols "On"

    filter "configurations:Release"
        defines "ZE_RELEASE"
        buildoptions "/MD"
        optimize "On"

    filter "configurations:Dist"
        defines "ZE_DIST"
        buildoptions "/MD"
        optimize "On"

project "Sandbox"
    location "Sandbox"
    kind "ConsoleApp"
    language "C++"
    staticruntime "off"

    targetdir ("bin/" .. out_dir .. "/%{prj.name}")
    objdir ("bin-int/" .. out_dir .. "/%{prj.name}")

    files {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp"
    }

    includedirs {
        "ZEngine/src",
        "ZEngine/vendor/spdlog/include",
    }

    links {
        "ZEngine"
    }

    filter "system:windows"
        cppdialect "C++17"
        staticruntime "On"
        systemversion "latest"

        defines {
            "ZE_PLATFORM_WINDOWS"
        }

    filter "configurations:Debug"
        defines "ZE_DEBUG"
        buildoptions "/MDd"
        symbols "On"

    filter "configurations:Release"
        defines "ZE_RELEASE"
        buildoptions "/MD"
        optimize "On"

    filter "configurations:Dist"
        defines "ZE_DIST"
        buildoptions "/MD"
        optimize "On"