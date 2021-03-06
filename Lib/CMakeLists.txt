CMAKE_MINIMUM_REQUIRED(VERSION 3.0)

PROJECT(EyerLib
        VERSION 1.0.0.0
        )

message( STATUS "CMAKE_PROJECT_NAME    = ${CMAKE_PROJECT_NAME}" )
message( STATUS "PROJECT_VERSION_MAJOR = ${PROJECT_VERSION_MAJOR}" )
message( STATUS "PROJECT_VERSION_MINOR = ${PROJECT_VERSION_MINOR}" )
message( STATUS "PROJECT_VERSION_PATCH = ${PROJECT_VERSION_PATCH}" )
message( STATUS "PROJECT_VERSION_TWEAK = ${PROJECT_VERSION_TWEAK}" )
message( STATUS "PROJECT_HOMEPAGE_URL = ${PROJECT_HOMEPAGE_URL}")
message( STATUS "CMAKE_PROJECT_DESCRIPTION = ${CMAKE_PROJECT_DESCRIPTION}" )

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

MESSAGE(STATUS "operation system is ${CMAKE_SYSTEM}")

SET(CMAKE_INSTALL_PREFIX ${CMAKE_SOURCE_DIR}/install/)

include_directories (googletest/googletest/include)

include_directories (EyerGLAD/glad/include/)
include_directories (${CMAKE_SOURCE_DIR}/../../Lib/glfw_install/include)
include_directories (${CMAKE_SOURCE_DIR}/../../Lib/curl_install/include)
include_directories (${CMAKE_SOURCE_DIR}/../../Lib/libxml2_install/include)
include_directories (${CMAKE_SOURCE_DIR}/../../Lib/libxml2_install/include/libxml2)

link_directories(${CMAKE_SOURCE_DIR}/../../Lib/curl_install/lib)
link_directories(${CMAKE_SOURCE_DIR}/../../Lib/libxml2_install/lib)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -fPIC")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fPIC")


IF (CMAKE_SYSTEM_NAME MATCHES "Linux")
    MESSAGE(STATUS "current platform: Linux ")
ELSEIF (CMAKE_SYSTEM_NAME MATCHES "Windows")
    MESSAGE(STATUS "current platform: Windows")
    ADD_DEFINITIONS(-D EYER_PLATFORM_WINDOWS)
ELSEIF (CMAKE_SYSTEM_NAME MATCHES "Android")
    MESSAGE(STATUS "current platform: Android")
    ADD_DEFINITIONS(-D EYER_PLATFORM_ANDROID)
ELSEIF (CMAKE_SYSTEM_NAME MATCHES "Darwin")
    MESSAGE(STATUS "current platform: Darwin")
    set(CMAKE_EXE_LINKER_FLAGS
        "-framework IOKit -framework AudioToolbox -framework CoreGraphics -framework CoreMedia -framework Cocoa -framework VideoToolbox -framework AVFoundation -framework Security -framework CoreFoundation -framework CoreVideo -framework OpenGL -framework AppKit -framework CoreImage -framework VideoDecodeAcceleration"
    )
ELSE ()
    MESSAGE(STATUS "other platform: ${CMAKE_SYSTEM_NAME}")
ENDIF (CMAKE_SYSTEM_NAME MATCHES "Linux")


FUNCTION(ModuleOption moduleName moduleOption)
    IF (${moduleOption})
        ADD_SUBDIRECTORY(${moduleName})
    ENDIF(${moduleOption})
ENDFUNCTION(ModuleOption)

FUNCTION(ModuleTestOption moduleName moduleTestName moduleOption)
    IF (${moduleOption})
        ADD_SUBDIRECTORY(${moduleName})
        ADD_SUBDIRECTORY(${moduleTestName})
    ENDIF(${moduleOption})
ENDFUNCTION(ModuleTestOption)

ADD_SUBDIRECTORY(googletest)

OPTION(EyerCore         "option for EyerCore"           ON)
ModuleTestOption("EyerCore" "EyerCoreTest" EyerCore)

OPTION(EyerNet           "option for EyerNet"           ON)
ModuleTestOption("EyerNet" "EyerNetTest" EyerNet)

OPTION(EyerDASH           "option for EyerDASH"         ON)
ModuleTestOption("EyerDASH" "EyerDashTest" EyerDASH)

OPTION(EyerAV           "option for EyerAV"             ON)
ModuleOption("EyerAV" EyerAV)

OPTION(EyerCrop         "option for EyerCrop"           ON)
ModuleOption("EyerCrop" EyerCrop)

OPTION(EyerGLAD         "option for EyerGLAD"           ON)
ModuleOption("EyerGLAD" EyerGLAD)

OPTION(EyerGL           "option for EyerGL"             ON)
ModuleOption("EyerGL" EyerGL)

OPTION(EyerGLCustomComponent        "option for EyerGLCustomComponent"             ON)
ModuleOption("EyerGLCustomComponent" EyerGLCustomComponent)

OPTION(EyerGLRenderTask             "option for EyerGLRenderTask"                   ON)
ModuleOption("EyerGLRenderTask" EyerGLRenderTask)

OPTION(EyerYUV           "option for EyerYUV"           ON)
ModuleOption("EyerYUV" EyerYUV)

OPTION(EyerGLWindow      "option for EyerGLWindow"      ON)
ModuleOption("EyerGLWindow" EyerGLWindow)

OPTION(EyerType          "option for EyerType"          ON)
ModuleOption("EyerType" EyerType)

OPTION(EyerGPUDomino     "option for EyerGPUDomino"     ON)
ModuleOption("EyerGPUDomino" EyerGPUDomino)

OPTION(EyerGLShader      "option for EyerGLShader"      ON)
ModuleOption("EyerGLShader" EyerGLShader)

OPTION(EyerThread        "option for EyerThread"        ON)
ModuleOption("EyerThread" EyerThread)

OPTION(EyerImg           "option for EyerImg"           ON)
ModuleOption("EyerImg" EyerImg)

OPTION(EyerGLContext     "option for EyerGLContext"     ON)
ModuleOption("EyerGLContext" EyerGLContext)

OPTION(EyerVideoTweenAnimation           "option for EyerVideoTweenAnimation"           ON)
ModuleOption("EyerVideoTweenAnimation" EyerVideoTweenAnimation)

OPTION(EyerAVC           "option for EyerAVC"           ON)
ModuleOption("EyerAVC" EyerAVC)

OPTION(AL_TEST           "option for AL_TEST"           ON)
IF (AL_TEST)
    ADD_SUBDIRECTORY(EyerVideoTweenAnimationTest)
    ADD_SUBDIRECTORY(EyerAVTest)
    ADD_SUBDIRECTORY(EyerGLTest)
    ADD_SUBDIRECTORY(EyerRender)
    ADD_SUBDIRECTORY(EyerRenderTest)
    ADD_SUBDIRECTORY(EyerTypeTest)
    ADD_SUBDIRECTORY(EyerGPUDominoTest)
    ADD_SUBDIRECTORY(EyerThreadTest)
    ADD_SUBDIRECTORY(EyerEventQueue)
    ADD_SUBDIRECTORY(EyerImgTest)
    ADD_SUBDIRECTORY(EyerYUVTest)
    ADD_SUBDIRECTORY(EyerAVCTest)
ENDIF(AL_TEST)
