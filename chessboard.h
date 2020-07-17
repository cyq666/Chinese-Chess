#ifndef CHESSBOARD_H
#define CHESSBOARD_H
#include <QWidget>
#include<QLabel>
#include<chess.h>
#include<widget.h>
#include<QMouseEvent>
#include<QDebug>
#include<QToolTip>
#include<QPainter>
#include<QPushButton>
#include<QFont>

class ChessBoard : public QWidget
{
    Q_OBJECT
public:
    explicit ChessBoard(QWidget *parent = nullptr);
public:
   QLabel *huiqi;
   QWidget win;
   QLabel *who_win;
   static int who_go;
   QLabel *who_go_tip1;
   QLabel *who_go_tip2;
   QLabel *last_move;
   QLabel *last_move_tip;
    static int Turn_num;
    bool canchessmove;
    bool canMoveSHI(int num, int x, int y); //士走棋规则
    bool canMoveBING(int num, int x, int y); //兵走棋规则
    bool canMoveMA(int num, int x, int y); //马走棋规则
    bool canMoveXIANG(int num,  int x, int y); //象走棋规则
    bool canMoveCHE(int num, int x, int y); //车走棋规则
    bool canMovePAO(int num,  int x, int y); //炮走棋规则
    bool canMoveJIANG(int num,  int x, int y); //将走棋规则
    bool beChess(int x, int y); // 输入行列坐标判断该坐标上有没有棋子
    int Num_of_Chess(int num, int x, int y); // 计算即将行走的棋子与某一坐标之间有几颗棋子
    bool same_color(int num,int x,int y);
    Chess mychess[32];  //定义32颗棋子
    void paintEvent(QPaintEvent *event); //绘制棋盘、棋子
    bool canmove(int num,int x,int y);
    void show_last_move(int num);
protected:
    void mousePressEvent(QMouseEvent *event); //实现鼠标点击走棋
    void mouseMoveEvent(QMouseEvent *e); //显示当前鼠标位置，方便调试

};

#endif // CHESSBOARD_H
