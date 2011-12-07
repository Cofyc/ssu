project "SsuGen"
    language "C++"
    kind "ConsoleApp"

    files { "Parser.*", "Process.*", "SsuGen.cpp", "SsuLex.h" }

    currPath = path.getdirectory(_SCRIPT)

    configuration "not vs*"
        buildoptions { "-std=gnu++0x" }

    configuration { "Debug" }
        prebuildcommands { currPath .. "/../bin/debug/lemon.exe T=" .. currPath .. "/../lemon/lempar.c " .. currPath .. "/SsuLex.y" }
    configuration { "Release" }
        prebuildcommands { currPath .. "/../bin/release/lemon.exe T=" .. currPath .. "/../lemon/lempar.c " .. currPath .. "/SsuLex.y" }
