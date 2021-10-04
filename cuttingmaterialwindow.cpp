#include "cuttingmaterialwindow.h"
#include "ui_cuttingmaterialwindow.h"

CuttingMaterialWindow::CuttingMaterialWindow(QWidget* parent)
    : QMainWindow(parent)
    , ui(new Ui::CuttingMaterialWindow)
{
    ui->setupUi(this);

    ui->fragmentTableView->setModel(cuttingMaterial.getFragmentModel());
    ui->fragmentTableView->verticalHeader()->show();
}

CuttingMaterialWindow::~CuttingMaterialWindow()
{
    delete ui;
}

void CuttingMaterialWindow::on_pushButton_2_clicked()
{
    cuttingMaterial.addFragment();
}
