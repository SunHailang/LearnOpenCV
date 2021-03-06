-- premake5.lua
include "./vendor/premake/premake_customization/solution_items.lua"

workspace "LearnOpenCV"
	architecture "x86_64"
	architecture "x64"
	startproject "LearnOpenCV"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

	solution_items
	{
		".editorconfig"
	}

	flags
	{
		"MultiProcessorCompile"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

-- Include directories relative to root folder (solution directory)
IncludeDir = {}
IncludeDir["opencv2"] = "%{wks.location}/Library/opencv/build/include"
IncludeDir["opencv2Lib"] = "%{wks.location}/Library/opencv/build/x64/vc14/lib"

group "Dependencies"
	-- include "vendor/premake"

group ""

include "LearnOpenCV"
-- include "LearnOpenCV-Editor"