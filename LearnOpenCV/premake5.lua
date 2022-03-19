project "LearnOpenCV"
	kind "ConsoleApp"
	language "C++"
	cppdialect "C++17"
	staticruntime "on"

	targetdir ("%{wks.location}/bin/" .. outputdir .. "/%{prj.name}")
	objdir ("%{wks.location}/bin-int/" .. outputdir .. "/%{prj.name}")

	-- pchheader "hzpch.h"
	-- pchsource "src/hzpch.cpp"

	files
	{
		"include/**.h",
		"src/**.cpp"
	}

	defines
	{
		
	}

	includedirs
	{
		"include",
		"%{IncludeDir.opencv2}",
	}

	libdirs
	{
		"%{IncludeDir.opencv2Lib}"
	}

	links
	{
		--"opencv_world455d.lib"
	}

	--filter "files:vendor/ImGuizmo/**.cpp"
	--flags { "NoPCH" }

	filter "system:windows"
		systemversion "latest"

		defines
		{
		}

	filter "configurations:Debug"
		defines "OPENCV_DEBUG"
		runtime "Debug"
		symbols "on"
		links
		{
			"opencv_world455d.lib"
		}

	filter "configurations:Release"
		defines "OPENCV_RELEASE"
		runtime "Release"
		optimize "on"
		links
		{
			"opencv_world455.lib"
		}

	filter "configurations:Dist"
		defines "OPENCV_DIST"
		runtime "Release"
		optimize "on"
		links
		{
			"opencv_world455.lib"
		}
