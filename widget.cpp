#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    setStyleSheet("background-image: url(:/myImage/images/chessboard.png);"); //设置背景图片（棋盘）
}

Widget::~Widget()
{
    delete ui;
}
