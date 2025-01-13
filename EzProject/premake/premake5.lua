newoption {
    trigger = "projectName",
    value = "NAME",
    description = "Sets the project name"
}

newoption{
    trigger = "projectDir",
    value = "PATH",
    description = "Sets the project directory"
}

local projectName = _OPTIONS["projectName"] or "DefaultProject"
local projectDir = _OPTIONS["projectDir"] or "../"

workspace (projectName)
    configurations { "Debug", "Release" }
    location (projectDir .. "/" .. projectName)

project (projectName)
    kind "ConsoleApp"
    language "C++"
    targetdir "bin/%{cfg.buildcfg}"
    location (projectDir .. projectName .. "/" .. projectName)

files { "**.hpp", "**.cpp" }

filter "configurations:Debug"
    defines { "DEBUG" }
    symbols "On"

filter "configurations:Release"
    defines { "NDEBUG" }
    optimize "On"
