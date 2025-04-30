workspace "testWorkspace"
    configurations { "release" }

    project "test"
        kind "ConsoleApp"
        language "C++"
        system "macosx"
        files { "test.cpp" }
