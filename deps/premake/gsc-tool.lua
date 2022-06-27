gsc_tool = {
    source = path.join(dependencies.basePath, "gsc-tool/src")
}

function gsc_tool.import()
    links {"xsk-gsc-h1", "xsk-gsc-utils"}
    gsc_tool.includes()
end

function gsc_tool.includes()
    includedirs {
        path.join(gsc_tool.source, "utils"), 
        path.join(gsc_tool.source, "h1"),
        path.join(dependencies.basePath, "extra/gsc-tool") -- https://github.com/GEEKiDoS/open-teknomw3/blob/master/deps/extra/gsc-tool
    }
end

-- https://github.com/xensik/gsc-tool/blob/dev/premake5.lua#L95
function gsc_tool.project()
    project "xsk-gsc-utils"
    kind "StaticLib"
    language "C++"

    pchheader "stdafx.hpp"
    pchsource(path.join(gsc_tool.source, "utils/stdafx.cpp"))

    files {
        path.join(gsc_tool.source, "utils/**.h"), 
        path.join(gsc_tool.source, "utils/**.hpp"),
        path.join(gsc_tool.source, "utils/**.cpp")
    }

    includedirs {
        path.join(gsc_tool.source, "utils"), 
        gsc_tool.source
    }

    zlib.includes()

    project "xsk-gsc-h1"
    kind "StaticLib"
    language "C++"

    pchheader "stdafx.hpp"
    pchsource(path.join(gsc_tool.source, "h1/stdafx.cpp"))

    files {
        path.join(gsc_tool.source, "h1/**.h"), 
        path.join(gsc_tool.source, "h1/**.hpp"),
        path.join(gsc_tool.source, "h1/**.cpp"), 
        path.join(dependencies.basePath, "extra/gsc-tool/interface.cpp")
    }

    includedirs {
        path.join(gsc_tool.source, "h1"), 
        gsc_tool.source, 
        path.join(dependencies.basePath, "extra/gsc-tool")
    }
end

table.insert(dependencies, gsc_tool)
