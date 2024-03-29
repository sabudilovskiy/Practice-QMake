QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    ADDStudentWindow.cpp \
    AVLTreeController.cpp \
    AVLWindow.cpp \
    ListBestController.cpp \
    ListController.cpp \
    ListWindow.cpp \
    Student.cpp \
    StudentController.cpp \
    main.cpp \
    MainWindow.cpp

HEADERS += \
    ADDStudentWindow.h \
    AVLTree.h \
    AVLTreeController.h \
    AVLWindow.h \
    List.h \
    ListBestController.h \
    ListController.h \
    ListWindow.h \
    MainWindow.h \
    Student.h \
    StudentController.h

FORMS += \
    ADDStudentWindow.ui \
    AVLWindow.ui \
    ListWindow.ui \
    MainWindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

win32:RC_ICONS += icons/graduated.ico
RESOURCES += \
    resources.qrc
