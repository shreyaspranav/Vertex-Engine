workspace "Vertex"
    architecture "x64"
    configurations {"Debug", "Release"}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

include "Vertex/vendor/GLFW"
include "Vertex/vendor/glad"
include "Vertex/"
include "SandboxApp/"
