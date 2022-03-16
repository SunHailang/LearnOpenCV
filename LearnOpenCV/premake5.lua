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
		"src/**.h",
<<<<<<< HEAD
		"src/**.cpp",
		"src/**.hpp"
=======
		"src/**.cpp"
>>>>>>> cfeab2ae87f341025c3d79a202834fdbbb2a31c2
	}

	defines
	{
		
	}

	includedirs
	{
		"src",
		"%{IncludeDir.opencv2}",
	}

	libdirs
	{
		"%{IncludeDir.opencv2Lib}"
	}

	links
	{
<<<<<<< HEAD
		--"opencv_world455d.lib"
=======
		"opencv_world455d.lib"
>>>>>>> cfeab2ae87f341025c3d79a202834fdbbb2a31c2
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
<<<<<<< HEAD
		links
		{
			"opencv_world455d.lib"
		}
=======
>>>>>>> cfeab2ae87f341025c3d79a202834fdbbb2a31c2

	filter "configurations:Release"
		defines "OPENCV_RELEASE"
		runtime "Release"
		optimize "on"
<<<<<<< HEAD
		links
		{
			"opencv_world455.lib"
		}
=======
>>>>>>> cfeab2ae87f341025c3d79a202834fdbbb2a31c2

	filter "configurations:Dist"
		defines "OPENCV_DIST"
		runtime "Release"
		optimize "on"
<<<<<<< HEAD
		links
		{
			"opencv_world455.lib"
		}
=======
>>>>>>> cfeab2ae87f341025c3d79a202834fdbbb2a31c2
