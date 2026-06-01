#ifndef SHAWINDOW_H
#define SHAWINDOW_H

#include <QWidget>
#include "crypto/sha512.h" // Путь к твоему классу алгоритма[cite: 12]

QT_BEGIN_NAMESPACE
namespace Ui { class SHAWindow; }
QT_END_NAMESPACE

class SHAWindow : public QWidget
{
    Q_OBJECT

public:
    explicit SHAWindow(QWidget *parent = nullptr);
    ~SHAWindow();

private slots:
    void on_calcButton_clicked();

private:
    Ui::SHAWindow *ui;
};

#endif // SHAWINDOW_H