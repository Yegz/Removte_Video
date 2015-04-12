TEMPLATE = app
DEPENDPATH  += . source include
INCLUDEPATH += . include

QT          += sql

SOURCES = main.cpp                 \
          source/login.cpp         \
          source/staffdatabase.cpp \
          source/system_init.cpp   \
          source/c_socket.cpp      \
          source/video.cpp         \


HEADERS = include/login.h           \
          include/staffdatabase.h   \
          include/system_init.h     \
          include/c_socket.h        \
          include/video.h           \
          include/debug.h           \

FORMS = ui/login.ui            \
        ui/Video_Play.ui       \

RESOURCES += login.qrc          \


