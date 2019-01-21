#include "papers.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Papers w;
    w.show();
    //puts application into a loop to show updates and refresh screen
    return a.exec();
}

