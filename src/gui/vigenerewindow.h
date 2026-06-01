#ifndef VIGENEREWINDOW_H
#define VIGENEREWINDOW_H

#include <QWidget>
#include "crypto/vigenere_cipher.h" // Путь к твоему классу шифрования

QT_BEGIN_NAMESPACE
namespace Ui { class VigenereWindow; }
QT_END_NAMESPACE

class VigenereWindow : public QWidget
{
    Q_OBJECT

public:
    explicit VigenereWindow(QWidget *parent = nullptr);
    ~VigenereWindow();

private slots:
    void on_encryptButton_clicked();
    void on_decryptButton_clicked();

private:
    Ui::VigenereWindow *ui;
};

#endif // VIGENEREWINDOW_H