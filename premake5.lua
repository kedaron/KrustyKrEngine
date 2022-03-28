workspace "KrustyKrEngine"
	architecture "x64"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "KrustyKrEngine"
	location "KrustyKrEngine"
	kind "SharedLib"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"%{prj.name}/vendor/spdlog/include"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"KK_PLATFORM_WINDOWS",
			"KK_BUILD_DLL"
		}

		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
		}

	filter "configurations:Debug"
		defines "KK_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "KK_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "KK_DIST"
		optimize "On"

project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"KrustyKrEngine/vendor/spdlog/include",
		"KrustyKrEngine/src"
	}

	links
	{
		"KrustyKrEngine"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"KK_PLATFORM_WINDOWS"
		}

	filter "configurations:Debug"
		defines "KK_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "KK_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "KK_DIST"
		optimize "On"