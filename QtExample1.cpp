#include <string>
#include <iostream>

#include <Qt>
#include <QApplication>
#include <QMainWindow>

#include "MainWindowHelper.hpp"


using std::string;
using std::cout;
using std::endl;



int
main
(
 int    argc,
 char ** argv
)
{
    const
    string             nameMethod = "main";

    // According to the Qt documentation, the QApplication object should be created as early as
    // possible.

    QApplication       app(argc, argv);

    QMainWindow        mainWindow(nullptr);

    MainWindowHelper * mainWindowHelper_p;


    cout << nameMethod << " : Enter" << endl;

    mainWindowHelper_p = new MainWindowHelper(& mainWindow);

    mainWindowHelper_p->setup();

    mainWindow.show();

    cout << nameMethod << " : Exit" << endl;


    return app.exec();
}

