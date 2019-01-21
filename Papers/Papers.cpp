#include "papers.h"
#include "ui_Papers.h"

Papers::Papers(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Papers)
{
    //this line sets up the user interface for us - initialises it
    ui->setupUi(this);
    this->setCentralWidget(ui->plainTextEdit);
}

//destructor that DELETES user interface ui
Papers::~Papers()
{
    delete ui;
}

void Papers::on_actionNew_triggered()
{
    //new function to create a new file and clear the current one
    currentfile.clear();
    ui->plainTextEdit->setPlainText(QString());
}

void Papers::on_actionOpen_triggered()
{
    QString fileName = QFileDialog::getOpenFileName(this, "Open the file");
    QFile file(fileName);
    currentfile = fileName;

    if(!file.open(QIODevice::ReadOnly | QFile::Text)){
        QMessageBox::warning(this, "Warning", "Cannot open file: " + file.errorString());
        return;
    }

    setWindowTitle(fileName);
    QTextStream in(&file);
    QString text = in.readAll();
    ui->plainTextEdit->setPlainText(text);
    file.close();
}

void Papers::on_actionSave_As_triggered()
{
    QString fileName = QFileDialog::getSaveFileName(this, "Save as");
    QFile file(fileName);

    if(!file.open(QFile::WriteOnly | QFile::Text)){
        QMessageBox::warning(this, "Warning", "Cannot save file: " +file.errorString());
        return;
    }
    currentfile = fileName;
    setWindowTitle(fileName);
    QTextStream out(&file);
    QString text = ui->plainTextEdit->toPlainText();
    out << text;
    file.close();
}


void Papers::on_actionCopy_triggered()
{
    ui->plainTextEdit->copy();
}


void Papers::on_actionPaste_triggered()
{
    ui->plainTextEdit->paste();

}


void Papers::on_actionCut_triggered()
{
    ui->plainTextEdit->cut();
}


void Papers::on_actionUndo_triggered()
{
    ui->plainTextEdit->undo();
}

void Papers::on_actionSave_triggered()
{
    QString fileName = QFileDialog::getSaveFileName(this, "Save");
        QFile file(fileName);
        if (!file.open(QFile::WriteOnly | QFile::Text)) {
            QMessageBox::warning(this, "Warning", "Cannot save file: " + file.errorString());
            return;
        }
        currentfile = fileName;
        setWindowTitle(fileName);
        QTextStream out(&file);
        QString text = ui->plainTextEdit->toPlainText();
        out << text;
        file.close();
}
