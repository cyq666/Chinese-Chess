#ifndef CHESS_H
#define CHESS_H
#include <QWidget>
#include<QLabel>
#include<QString>
#include<qdebug.h>
#include<QMouseEvent>

class Chess : public QWidget
{
    Q_OBJECT
public:
    explicit Chess(QWidget *parent = nullptr);
public:
    enum type{BING,PAO,CHE,MA,XIANG,SHI,JIANG}; //枚举棋子类型

public:    //每个棋子的属性
    int row;  //所在行
    int line;  //所在列
    int chessNum; //棋子序号
    bool ifdead; //是否死亡（被吃）
    bool ifred; //是否为红色
    type chessType;
    QString picUrl;
    QLabel *chess;
   public:
     void initChess(const int num); //初始化棋子
     void labelChess();  //初始化棋子贴图
     void paintChess(); //绘制棋子（显示图片）
     void moveChess(int x,int y); //走棋
     void killed(); //棋子被吃
     };

#endif // CHESS_H
