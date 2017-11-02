#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include "QTextStream"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setCentralWidget(ui->textEdit);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionCopy_triggered()
{
    ui->textEdit->copy();
}

void MainWindow::on_actionCut_triggered()
{
    ui->textEdit->cut();
}

void MainWindow::on_actionPaste_triggered()
{
    ui->textEdit->paste();
}

void MainWindow::on_actionUndo_triggered()
{
    ui->textEdit->undo();
}

void MainWindow::on_actionRedo_triggered()
{
    ui->textEdit->redo();
}

void MainWindow::on_actionNew_triggered()
{
    nFileName="";
    ui->textEdit->setPlainText("");
}

void MainWindow::on_actionOpen_triggered()
{
    QString file = QFileDialog::getOpenFileName(this,tr("Open file test"),nFileName,"Text File (*.txt);;All File (*.)");
    if(!file.isEmpty()){
        QFile sFile (file);
        if(sFile.open(QFile::ReadOnly | QFile:: Text)) {
            nFileName = file;
            QTextStream in (&sFile);
            QString text = in.readAll();
            sFile.close();
            ui->textEdit->setPlainText(text);
        }
    }
}

void MainWindow::on_actionSave_triggered()
{
    QFile sFile (nFileName);
    if (sFile.open((QFile::WriteOnly | QFile::Text))) {
        QTextStream out(&sFile);
        out << ui-> textEdit->toPlainText();
        sFile.flush();
        sFile.close();
    } else {
        on_actionSave_as_triggered();


    }

}

void MainWindow::on_actionSave_as_triggered()
{
    QString file = QFileDialog::getSaveFileName(this,tr("Save File"),nFileName,"Text File (*.txt);;All File (*.)");
    if (!file.isEmpty()) {
        nFileName = file;
        on_actionSave_triggered();

    }
}

void MainWindow::on_actionExit_triggered()
{
    exit(0);
    //this->close();
}

void MainWindow::on_actionFind_triggered()
{
    //ui->textEdit->find();
}

void MainWindow::on_actionCenter_triggered()
{
    //ui->QTextEdit::setAlignment(Qt::AlignCenter);
}
