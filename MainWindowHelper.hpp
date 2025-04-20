#ifndef MAINWINDOWHELPER_HPP
#define MAINWINDOWHELPER_HPP


#include <string>

#include <QApplication>
#include <QMainWindow>
#include <QMenuBar>
// #include <QPopupMenu>
#include <QToolBar>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>


class
MainWindowHelper
{
public :

    MainWindowHelper
    (
     QMainWindow * mainWindow_p
    );

    ~MainWindowHelper
    (
    );


public :

    int
    setup
    (
    );


private :

    int
    setWindowTitleAndSize
    (
    );

    int
    queryMainWindowLayout
    (
    );

    int
    setupMenuBar
    (
    );

    int
    setupButtons
    (
    );

    int
    connectSignalsToSlots
    (
    );

    int
    downloadFile
    (
    );


private :

    QMainWindow  * mainWindow_p;

    QMenuBar     * menuBar_p;

    QMenu        * menuFile_p,
                 * menuHelp_p;

    QLayout      * layoutMain_p;

    QWidget      * widgetCentral_p,
                 * widgetButtons_p;

    QFrame       * frameButtons_p;

    QVBoxLayout  * layoutVertical_p,
                 * layoutLineEdit_p;

    QHBoxLayout  * layoutButtons_p;

    QLabel       * label_p;

    QLineEdit    * lineEdit_Url_p;

    QPushButton  * buttonDownload_p,
                 * buttonClear_p,
                 * buttonExit_p;
};


#endif
