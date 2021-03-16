# QxOrm 的通用配置，包含了 Qt 和 boost 库依赖
include($$PWD/../../QxOrm/QxOrm.pri)

CONFIG += console
DEFINES += _BUILDING_USER

# 预编译头文件
!contains(DEFINES, _QX_NO_PRECOMPILED_HEADER) {
    PRECOMPILED_HEADER = precompiled.h
}

# QxOrm 库相关配置
INCLUDEPATH += $$PWD/../../QxOrm/include
LIBS += -L$$PWD/../../QxOrm/lib

# 设置生成的目标名称、添加依赖库
CONFIG(debug, debug|release) {
    TARGET = Userd
    LIBS += -lQxOrmd
} else {
    TARGET = User
    LIBS += -lQxOrm
}

# 文件列表
HEADERS += \
    precompiled.h \
    export.h \
    user.h

SOURCES += \
    main.cpp \
    user.cpp
