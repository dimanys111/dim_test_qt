#include "cuttingmaterialwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    CuttingMaterialWindow w;
    w.show();
    return a.exec();
}
