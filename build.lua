IncludeDir = {}
IncludeDir["GLFW"] = "vendor/glfw/include"
IncludeDir["spdlog"] = "vendor/spdlog/include"
IncludeDir["Glad"] = "vendor/Glad/include"

include "vendor/glfw"
include "vendor/Glad"

project "AtlasLib"
        kind "StaticLib"
        language "C++"
        
	targetdir ("bin/%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}/%{prj.name}")
	objdir ("bin-int/%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}/%{prj.name}")

        files
        {
                "source/**.h",
                "source/**.hpp",
                "source/**.cpp"
        }

        includedirs
        {
                "source",
                "%{IncludeDir.GLFW}",
                "%{IncludeDir.spdlog}",
                "%{IncludeDir.Glad}",
        }

        links
        {
                "GLFW",
                "Glad",
                "opengl32.lib",
                "dwmapi.lib",
        }

        filter "system:windows"
                cppdialect "C++latest"  -- C++26 for (std::format, print, println, etc)
                staticruntime "off"
                systemversion "latest"

                defines
                {
                        "AT_PLATFORM_WINDOWS", 
                }

        filter "configurations:Debug"
                defines "AT_DEBUG"
                symbols "on"

        filter "configurations:Release"
                defines "AT_RELEASE"
                optimize "on"
