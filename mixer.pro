include($$PWD/../../plugins.pri)

TARGET = $$PLUGINS_PREFIX/Effect/mixer

HEADERS += mixerplugin.h \
           effectmixerfactory.h \
           settingsdialog.h

SOURCES += mixerplugin.cpp \
           effectmixerfactory.cpp \
           settingsdialog.cpp

FORMS += settingsdialog.ui

unix{
    target.path = $$PLUGIN_DIR/Effect
    INSTALLS += target
}
