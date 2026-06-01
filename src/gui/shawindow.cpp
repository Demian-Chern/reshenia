#include "shawindow.h"
#include "ui_shawindow.h"

SHAWindow::SHAWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SHAWindow)
{
    ui->setupUi(this);
}

SHAWindow::~SHAWindow()
{
    delete ui;
}

void SHAWindow::on_calcButton_clicked()
{
    QString input = ui->inputEdit->text();
    if (input.isEmpty()) return;

    // Вызываем твой алгоритм SHA-512[cite: 11]
    std::string result = SHA512::hash(input.toStdString());

    // Выводим результат в поле вывода
    ui->resultEdit->setText(QString::fromStdString(result));
}