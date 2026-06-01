#include "vigenerewindow.h"
#include "ui_vigenerewindow.h"

VigenereWindow::VigenereWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::VigenereWindow)
{
    ui->setupUi(this);
}

VigenereWindow::~VigenereWindow()
{
    delete ui;
}

void VigenereWindow::on_encryptButton_clicked()
{
    std::string text = ui->textEdit->text().toStdString();
    std::string key = ui->keyEdit->text().toStdString();

    if (text.empty() || key.empty()) {
        ui->resultEdit->setText("Ошибка: Текст и ключ не должны быть пустыми!");
        return;
    }

    std::string encrypted = VigenereCipher::encrypt(text, key);
    ui->resultEdit->setText(QString::fromStdString(encrypted));
}

void VigenereWindow::on_decryptButton_clicked()
{
    std::string text = ui->textEdit->text().toStdString();
    std::string key = ui->keyEdit->text().toStdString();

    if (text.empty() || key.empty()) {
        ui->resultEdit->setText("Ошибка: Текст и ключ не должны быть пустыми!");
        return;
    }

    std::string decrypted = VigenereCipher::decrypt(text, key);
    ui->resultEdit->setText(QString::fromStdString(decrypted));
}