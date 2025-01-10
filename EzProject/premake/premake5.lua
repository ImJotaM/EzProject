newoption {
    trigger = "projectName",
    value = "NAME",
    description= "Sets the project name"
}

newoption {
    trigger = "libs",
    value = "LIST",
    description= "Sets project linked libs"
}

function splitString(input, delimiter)
    local result = {}
    for value in string.gmatch(input, "([^" .. delimiter .. "]+)") do
        table.insert(result, value)
    end
    return result
end

local projectName = _OPTIONS["projectname"] or "DefaultProject"

local lib_option = _OPTIONS["libs"] or ""
local libs = splitString(lib_option, ",")

workspace (projectName)
    configurations { "Debug", "Release" }
    location ("../" .. projectName)

project (projectName)
    kind "ConsoleApp"
    language "C++"
    targetdir "bin/%{cfg.buildcfg}"
    location ("../" .. projectName .. "/" .. projectName)

files { "**.hpp", "**.cpp" }

filter "configurations:Debug"
    defines { "DEBUG" }
    symbols "On"

filter "configurations:Release"
    defines { "NDEBUG" }
    optimize "On"

links (libs)
