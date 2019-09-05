#include "dialog.h"
#include <QHBoxLayout>

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
{
    initUI();
    initSignalSlots();
    setWindowTitle("Form created mannually");
}

Dialog::~Dialog()
{

}


void Dialog::initUI()
{
    //创建3个checkbox, 并水平布局
    chkBoxUnder = new QCheckBox(tr("Underline"));
    chkBoxItalic = new QCheckBox(tr("Italic"));
    chkBoxBold = new QCheckBox(tr("Bold"));

    QHBoxLayout *HLay1 = new QHBoxLayout();
    HLay1->addWidget(chkBoxUnder);
    HLay1->addWidget(chkBoxItalic);
    HLay1->addWidget(chkBoxBold);

    //创建3个radiobutton, 并水平布局
    rBtnBlue = new QRadioButton(tr("blue"));
    rBtnRed =  new QRadioButton(tr("red"));
    rBtnBlack =  new QRadioButton(tr("black"));
    rBtnBlack->setChecked(true);


    QHBoxLayout *HLay2 = new QHBoxLayout();
    HLay2->addWidget(rBtnBlue);
    HLay2->addWidget(rBtnRed);
    HLay2->addWidget(rBtnBlack);

    //创建3个pushbutton, 并水平布局
    btnOK = new QPushButton("确定");
    btnCancel = new QPushButton("取消");
    btnClose = new QPushButton("关闭");

    QHBoxLayout *HLay3 = new QHBoxLayout();
    HLay3->addStretch();
    HLay3->addWidget(btnOK);
    HLay3->addWidget(btnCancel);
    HLay3->addStretch();
    HLay3->addWidget(btnClose);

    //创建文本框, 并设置初始字体
    txtEdit = new QPlainTextEdit();
    txtEdit->setPlainText("Hello world\n\n");
    QFont font = txtEdit->font();
    font.setPointSize(20);
    txtEdit->setFont(font);

    //创建垂直布局, 并设置为主布局
    QVBoxLayout *VLay = new QVBoxLayout;
    VLay->addLayout(HLay1);
    VLay->addLayout(HLay2);
    VLay->addWidget(txtEdit);
    VLay->addLayout(HLay3);
    setLayout(VLay);    //设置为窗体的主布局

}

void Dialog::initSignalSlots()
{
    //3个QRadioButton的clicked()信号与setTextFontColor()槽函数相关联
    connect(rBtnBlue, SIGNAL(clicked()), this, SLOT(setTextFontColor()));
    connect(rBtnRed, SIGNAL(clicked()), this, SLOT(setTextFontColor()));
    connect(rBtnBlack, SIGNAL(clicked()), this, SLOT(setTextFontColor()));

    connect(chkBoxUnder, SIGNAL(clicked(bool)), this, SLOT(on_chkBoxUnder(bool)));
    connect(chkBoxItalic, SIGNAL(clicked(bool)), this, SLOT(on_chkBoxItalic(bool)));
    connect(chkBoxBold, SIGNAL(clicked(bool)), this, SLOT(on_chkBoxBold(bool)));
    //三个按钮的信号与窗体的槽函数关联
    connect(btnOK, SIGNAL(clicked()), this, SLOT(accept()));
    connect(btnCancel, SIGNAL(clicked()), this, SLOT(reject()));
    connect(btnClose, SIGNAL(clicked()), this, SLOT(close()));


}

void Dialog::on_chkBoxUnder(bool checked)
{
    QFont font = txtEdit->font();
    font.setUnderline(checked);
    txtEdit->setFont(font);
}

void Dialog::on_chkBoxItalic(bool checked)
{
    QFont font = txtEdit->font();
    font.setItalic(checked);
    txtEdit->setFont(font);
}

void Dialog::on_chkBoxBold(bool checked)
{
    QFont font = txtEdit->font();
    font.setBold(checked);
    txtEdit->setFont(font);
}

void Dialog::setTextFontColor()
{
    QPalette plet = txtEdit->palette();
    if(rBtnBlue->isChecked())
        plet.setColor(QPalette::Text, Qt::blue);
    else if(rBtnRed->isChecked())
        plet.setColor(QPalette::Text, Qt::red);
    else if(rBtnBlack->isChecked())
        plet.setColor(QPalette::Text, Qt::black);
    else {
      plet.setColor(QPalette::Text, Qt::blue);
    }

    txtEdit->setPalette(plet);
}


