project "imgui"
        kind "StaticLib"
        language "C++"
        staticruntime "off"
        location "imgui"

        targetdir ("%{wks.location}/bin/%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}/%{prj.name}")
        objdir ("%{wks.location}/bin-int/%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}/%{prj.name}")


        files
        {
                "imgui/imconfig.h",
        	"imgui/imgui.h",
        	"imgui/imgui.cpp",
        	"imgui/imgui_draw.cpp",
        	"imgui/imgui_internal.h",
        	"imgui/imgui_tables.cpp",
        	"imgui/imgui_widgets.cpp",
        	"imgui/imstb_rectpack.h",
        	"imgui/imstb_textedit.h",
        	"imgui/imstb_truetype.h",
        	"imgui/imgui_demo.cpp",
        }

        filter "system:windows"
		systemversion "latest"
		cppdialect "C++latest"

	filter "system:linux"
		pic "On"
		systemversion "latest"
		cppdialect "C++latest"

	filter "configurations:Debug"
		runtime "Debug"
		symbols "on"

	filter "configurations:Release"
		runtime "Release"
		optimize "on"

        filter "configurations:Dist"
		runtime "Release"
		optimize "on"
                symbols "off"