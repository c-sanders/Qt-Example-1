#include "MainWindowHelper.hpp"

#include <string>
#include <iostream>

using std::string;
using std::cout;
using std::endl;


MainWindowHelper::MainWindowHelper
(
 QMainWindow * mainWindow_p
)
{
    const
    string   nameMethod = "MainWindowHelper Ctor";


    cout << nameMethod << " : Enter" << endl;

    this->mainWindow_p     = mainWindow_p;

    // Create the window components.

    this->widgetCentral_p  = new QWidget();
    this->widgetButtons_p  = new QWidget();

    this->frameButtons_p   = new QFrame();

    this->label_p          = new QLabel("URL of file to download :");
    this->label_p->setStyleSheet("border: 1px solid lightgrey;");

    this->menuBar_p        = new QMenuBar(nullptr);
    this->menuFile_p       = new QMenu("File");
    this->menuHelp_p       = new QMenu("Help");

    // QLayout      * layoutMain_p;

    this->layoutVertical_p = new QVBoxLayout(this->widgetCentral_p);

    this->lineEdit_Url_p   = new QLineEdit("https://www.youtube.com/watch?v=O89_U1gZfYU");

    // this->layoutButtons_p  = new QHBoxLayout(this->widgetButtons_p);
    this->layoutButtons_p  = new QHBoxLayout(this->frameButtons_p);

    this->frameButtons_p->setStyleSheet("border: 1px solid lightgrey;");

    this->buttonDownload_p = new QPushButton("Download");
    this->buttonClear_p    = new QPushButton("Clear");
    this->buttonExit_p     = new QPushButton("Exit");

    cout << nameMethod << " : Exit" << endl;
}


MainWindowHelper::~MainWindowHelper
(
)
{
    const
    string   nameMethod = "MainWindowHelper Dtor";


    cout << nameMethod << " : Enter" << endl;

    cout << nameMethod << " : Exit" << endl;
}


int
MainWindowHelper::setup
(
)
{
    const
    string   nameMethod = "MainWindowHelper::setup";


    cout << nameMethod << " : Enter" << endl;

    // Methods local to this class.

    this->setWindowTitleAndSize();
    this->setupButtons();
    this->setupMenuBar();
    this->connectSignalsToSlots();

    this->queryMainWindowLayout();

    //

    this->buttonExit_p->setToolTip("Exit the program.");

    this->mainWindow_p->setCentralWidget(this->widgetCentral_p);

    cout << nameMethod << " : Exit" << endl;


    return 0;
}


int
MainWindowHelper::setWindowTitleAndSize
(
)
{
    const
    string   nameMethod = "MainWindowHelper::setWindowTitleAndSize";


    cout << nameMethod << " : Enter" << endl;

    this->mainWindow_p->setWindowTitle("Qt GUI frontend to yt-dlp");
    // this->mainWindow_p->resize(1000, 1000);
    this->mainWindow_p->showMaximized();

    cout << nameMethod << " : Exit" << endl;


    return 0;
}


int
MainWindowHelper::setupButtons
(
)
{
    const
    string   nameMethod = "MainWindowHelper::setupButtons";


    cout << nameMethod << " : Enter" << endl;

    cout << nameMethod << " : Exit button size w x h = " << (this->buttonExit_p->size()).width()  <<
                                                   " x " << (this->buttonExit_p->size()).height() << endl;

    this->buttonDownload_p->setFixedSize(200, 30);
    this->buttonClear_p->setFixedSize(200, 30);
    this->buttonExit_p->setFixedSize(200, 30);

    this->layoutButtons_p->addWidget(this->buttonDownload_p);
    this->layoutButtons_p->addWidget(this->buttonClear_p);
    this->layoutButtons_p->addWidget(this->buttonExit_p);

    cout << nameMethod << " : Enter" << endl;


    return 0;
}


int
MainWindowHelper::queryMainWindowLayout
(
)
{
    const
    string        nameMethod = "MainWindowHelper::queryMainWindowLayout";

    QObjectList   list;


    cout << nameMethod << " : Enter" << endl;

    this->layoutMain_p = this->mainWindow_p->layout();

    // this->layoutMain_p->addItem(this->layoutVertical_p);

    this->layoutVertical_p->addWidget(this->label_p);
    this->layoutVertical_p->addWidget(this->lineEdit_Url_p);
    this->layoutVertical_p->addWidget(this->frameButtons_p);

    /*
    cout << nameMethod << " : Layout direction = " << this->mainWindow_p->layoutDirection() << endl;

    list = this->layoutMain_p->children();

    cout << nameMethod << " : Number of child elements in layout = " << list.count() << endl;

    cout << nameMethod << " : Number of child elements in layout = " << list.count() << endl;

    cout << nameMethod << " : mainWindow_p->layout = " << this->layoutMain_p << endl;
     */

    cout << nameMethod << " : Enter" << endl;


    return 0;
}


int
MainWindowHelper::setupMenuBar
(
)
{
    const
    string   nameMethod = "MainWindowHelper::setupMenuBar";


    cout << nameMethod << " : Enter" << endl;

    // Populate the menu : File

    this->menuFile_p->addMenu("About");
    this->menuFile_p->addSeparator();
    this->menuFile_p->addMenu("Exit");

    // Populate the menu bar and add it to the main window.

    this->menuBar_p->addMenu(this->menuFile_p);
    this->menuBar_p->addMenu(this->menuHelp_p);

    this->mainWindow_p->setMenuBar(this->menuBar_p);

    cout << nameMethod << " : Exit" << endl;


    return 0;
}


int
MainWindowHelper::connectSignalsToSlots
(
)
{
    const
    string   nameMethod = "MainWindowHelper::connectSignalsToSlots";


    cout << nameMethod << " : Enter" << endl;

    // Button Clear clicked -> Clear LineEdit

    QObject::connect
    (
     this->buttonClear_p,
     & QPushButton::clicked,
     this->lineEdit_Url_p,
     & QLineEdit::clear
    );

    /*
    QObject::connect
    (
     this->buttonDownload_p,
     & QPushButton::clicked,
     this->downloadFile,
     & QLineEdit::clear
    );
     */

    QObject::connect
    (
     this->buttonExit_p,
     & QPushButton::clicked,
     this->mainWindow_p,
     & QApplication::closeAllWindows
    );

    cout << nameMethod << " : Exit" << endl;


    return 0;
}
