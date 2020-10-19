-- ---------------------------------
-- Toni Barella, Gustavo Aranda
-- Inteligencia Artificial 3VGP
-- ESAT 2016-2020
-- Genie Project Configuration.
-- ---------------------------------

solution ("3IA_Solution" .. _ACTION)
  configurations { "Debug", "Release" }
  platforms { "x32", "x64" }
  location ("build")
  --language "C"
  --kind "ConsoleApp"

	language "C++"
	kind "ConsoleApp"

	projects = { "PR0_Base", "PR1_AStar" }

	for i, prj in ipairs(projects) do
		project (prj)
		targetname (prj)

		prj_path = "./build/" .. prj

		location (prj_path .. "/" .. _ACTION)

		includedirs {
			"./include/",
			"./deps/include",
		}

		files {
			"./deps/include/*.h",
		}

	    defines { "_CRT_SECURE_NO_WARNINGS" }
	    flags { "ExtraWarnings" }

		configuration "vs2015"
		  windowstargetplatformversion "8.1"

		configuration "vs2017"
		--windowstargetplatformversion "10.0.15063.0"
		  windowstargetplatformversion "10.0.16299.0"
		--windowstargetplatformversion "10.0.17134.0"
		--windowstargetplatformversion "10.0.17134.471"


    configuration "Debug"
        defines { "DEBUG" }
		links { "./deps/lib/esat/ESAT_d", "opengl32",
		"user32","shell32","gdi32","./deps/lib/sfmllib/sfml-graphics-d",
    "./deps/lib/sfmllib/sfml-window-d","./deps/lib/sfmllib/sfml-system-d"}
        targetdir ("bin/Debug")
        targetsuffix "_d"
        objdir ("build/" .. "Debug")
        flags { "Symbols" }

    configuration "Release"
		links { "./deps/lib/esat/ESAT_d", "opengl32",
		"user32","shell32","gdi32"}
        targetdir ("bin/Release")
        objdir ("build/" .. "Release")
        flags { "Optimize" }

	end

	project "PR0_Base"
		files {
      "./src/*.cc",
      "./include/*.h",
    }



	project "PR1_AStar"
		files {}
