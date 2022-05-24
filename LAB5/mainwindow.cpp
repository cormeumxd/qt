#include "mainwindow.h"
#include "./ui_mainwindow.h"

std::list<elem> info;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    if (ui->CITY->text().isEmpty() || ui->NAME->text().isEmpty() || ui->NUMBER->text().isEmpty())
        return;
    elem temp;
    temp.name = ui->NAME->text(); temp.city = ui->CITY->text(); temp.number = ui->NUMBER->text();
    info.push_back(temp);
    int length = info.size();
    ui->tableWidget->setRowCount(1);
    ui->tableWidget->setItem(0,0, new QTableWidgetItem(temp.name));
    ui->tableWidget->setItem(0,1, new QTableWidgetItem(temp.city));
    ui->tableWidget->setItem(0,2, new QTableWidgetItem(temp.number));
    ui->label_5->setNum(length);

}

void MainWindow::on_pushButton_2_clicked()
{
    int i = 0;
    ui->tableWidget->setRowCount(info.size());
    for(auto it = info.begin(); it!=info.end(); it++, i++){
        ui->tableWidget->setItem(i, 0, new QTableWidgetItem(it->name));
        ui->tableWidget->setItem(i, 1, new QTableWidgetItem(it->city));
        ui->tableWidget->setItem(i, 2, new QTableWidgetItem(it->number));
        }
}


void MainWindow::on_pushButton_3_clicked()
{
    int n = ui->spinBox->text().toInt();
    if (n > info.size()) return;
    std::list<elem>::iterator it = info.begin();
    std::advance(it, n-1);
    info.erase(it);
    int length = info.size();
    ui->label_5->setNum(length);
}


void MainWindow::on_pushButton_4_clicked()
{
    ui->tableWidget->setRowCount(0);
    int k = 0;
    int a = 0;
    auto it1 = info.begin();
    auto it2 = info.end();
    auto it3 = it2;
    it3 = std::max_element(it1, it2, [](elem x, elem y) {return x.number.toInt() < y.number.toInt();});
    int n = it3->number.toInt();
    for(auto it = info.begin(); it !=info.end(); it++)
        if(it->number.toInt() == n){
           ++a;
           ui->tableWidget->setRowCount(a);
           ui->tableWidget->setItem(a-1, 0, new QTableWidgetItem(it->name));
           ui->tableWidget->setItem(a-1, 1, new QTableWidgetItem(it->city));
           ui->tableWidget->setItem(a-1, 2, new QTableWidgetItem(it->number));
        }
}


void MainWindow::on_pushButton_5_clicked()
{
    int k =0;
    auto it1 = info.begin();
    auto it2 = info.end();
    int p = ui->spinBox_2->text().toInt();
    std::for_each(it1, it2, [p, &k](elem x){if (x.number.toInt() < p) k++;});
    ui->label_6->setNum(k);
}

