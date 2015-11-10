TEMPLATE = app
CONFIG += console
CONFIG -= qt
TARGET = hton-helper
SOURCES += \
    hton-helper.c

OTHER_FILES = \
    README.md 

INSTALLS    += target
unix:target.path  = /usr/bin

compiler_clean.commands = -$(DEL_FILE) $(TARGET)


