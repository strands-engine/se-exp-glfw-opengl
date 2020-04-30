workspace "oglexp"
  architecture "x64"

  configurations
  {
    "Debug",
    "Release",
    "Dist"
  }

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "oglexp"
  location "oglexp"
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
      "OXP_PLATFORM_WIN",
      "OXP_BUILD_DLL"
    }

    postbuildcommands
    {
      ("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/sandbox")
    }

  filter "configurations:Debug"
    defines "OXP_DEBUG"
    symbols "On"

  filter "configurations:Release"
    defines "OXP_RELEASE"
    optimize "On"

  filter "configurations:Dist"
    defines "OXP_DIST"
    optimize "On"

  filter { "system:windows", "configurations:Release" }
    buildoptions "/MT"


project "sandbox"
  location "sandbox"
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
    "oglexp/vendor/spdlog/include",
    "oglexp/src"
  }

  links
  {
    "oglexp"
  }

  filter "system:windows"
    cppdialect "C++17"
    staticruntime "On"
    systemversion "latest"

    defines
    {
      "OXP_PLATFORM_WIN",
    }

  filter "configurations:Debug"
    defines "OXP_DEBUG"
    symbols "On"

  filter "configurations:Release"
    defines "OXP_RELEASE"
    optimize "On"

  filter "configurations:Dist"
    defines "OXP_DIST"
    optimize "On"

  filter { "system:windows", "configurations:Release" }
    buildoptions "/MT"

