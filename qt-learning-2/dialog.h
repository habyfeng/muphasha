#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QCheckBox>
#include <QRadioButton>
#include <QPlainTextEdit>
#include <QPushButton>

class Dialog : public QDialog
{
    Q_OBJECT

private:
    QCheckBox *chkBoxUnder;
    QCheckBox *chkBoxItalic;
    QCheckBox *chkBoxBold;
    QRadioButton *rBtnBlack;
    QRadioButton *rBtnRed;
    QRadioButton *rBtnBlue;
    QPlainTextEdit *txtEdit;
    QPushButton *btnOK;
    QPushButton *btnCancel;
    QPushButton *btnClose;
    void initUI();              //UI创建与初始化
    void initSignalSlots();         //初始化信号与槽的链接

private slots:
    void on_chkBoxUnder(bool checked);
    void on_chkBoxItalic(bool checked);
    void on_chkBoxBold(bool checked);
    void setTextFontColor();


public:
    Dialog(QWidget *parent = 0);
    ~Dialog();
};

#endif // DIALOG_H
