#include "qt_main.h"

int main(int argc, char* argv[])
{
    QApplication a(argc, argv);
    Qt_main window;
    window.setWindowTitle("Search engine");
    window.setFixedSize(600, 400 );
    window.show();
    return QApplication::exec();
}


