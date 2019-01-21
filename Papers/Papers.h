#ifndef PAPERS_H
#define PAPERS_H

#include <QMainWindow>
#include <QFile>
#include <QFileDialog>
#include <QTextStream>
#include <QMessageBox>
#include <QPrinter>
#include <QPrintDialog>

namespace Ui {
class Papers;
}

class Papers : public QMainWindow
{   //declaring a class as a QObject - which is the default object type for QT Creator applications
    Q_OBJECT

public:
    //parent = nullptr means there is no parent of the widget
    explicit Papers(QWidget *parent = nullptr);
    ~Papers();

private slots:
    void on_actionNew_triggered();

    void on_actionOpen_triggered();

    void on_actionSave_As_triggered();

    void on_actionCopy_triggered();

    void on_actionPaste_triggered();

    void on_actionCut_triggered();

    void on_actionUndo_triggered();

    void on_actionSave_triggered();

private:
    //pointing to UI class
    Ui::Papers *ui;
    QString currentfile = "";
};

#endif // PAPERS_H

