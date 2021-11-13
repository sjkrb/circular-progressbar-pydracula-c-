#ifndef DIALOG_H
#define DIALOG_H

#include <QWidget>
#include <QFormLayout>
#include <QMainWindow>
class CircularProgressBar;
class Dialog : public QMainWindow
{
    Q_OBJECT
public:
    explicit Dialog(QMainWindow *parent = nullptr);

    QVBoxLayout *layout;
signals:
    void textChanged(QString str);

private:
    int val;
    CircularProgressBar *progressbar;
};

#endif // DIALOG_H
