include_directories (../)
include_directories (./)

add_library(
        EyerAVC
        EyerAnnexB.cpp
        EyerAnnexB.hpp
        EyerNALU.cpp
        EyerNALU.hpp
        EyerSlice.cpp
        EyerSlice.hpp
        EyerSPS.cpp
        EyerSPS.hpp
        EyerAVCCommon.cpp
        EyerAVCCommon.hpp
        EyerAVC_VLC.cpp
        EyerAVC_VLC.hpp
        EyerBitStream.cpp
        EyerBitStream.hpp
        EyerSyntaxElement.cpp
        EyerSyntaxElement.hpp
)

target_link_libraries (
        EyerAVC
        EyerCore
)

set(head_files
        EyerAVC.hpp
        )

INSTALL(FILES ${head_files} DESTINATION include/EyerAVC)
INSTALL(
        TARGETS EyerAVC
        RUNTIME DESTINATION bin
        LIBRARY DESTINATION lib
        ARCHIVE DESTINATION lib
)

