#ifndef CUTTINGMATERIALWINDOW_H
#define CUTTINGMATERIALWINDOW_H

#include "cuttingmaterial.h"

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class CuttingMaterialWindow;
}
QT_END_NAMESPACE

class CuttingMaterialWindow : public QMainWindow {
    Q_OBJECT

public:
    CuttingMaterialWindow(QWidget* parent = nullptr);
    ~CuttingMaterialWindow();

private slots:
    void on_pushButton_2_clicked();

private:
    CuttingMaterial cuttingMaterial;
    Ui::CuttingMaterialWindow* ui;
};
#endif // CUTTINGMATERIALWINDOW_H
