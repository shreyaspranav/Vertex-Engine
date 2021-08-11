workspace "Vertex"
    architecture "x64"
    configurations {"Debug", "Release"}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"


include "Vertex/vendor/GLFW"
include "Vertex/vendor/GLAD"
include "Vertex/"
include "SandboxApp/"
include "vendor/lua"