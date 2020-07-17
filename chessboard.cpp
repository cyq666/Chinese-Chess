#include "chessboard.h"

ChessBoard::ChessBoard(QWidget *parent) : QWidget(parent)
{
    setWindowTitle("中国象棋");
    resize(760,628);
    setFixedSize(760,628);
    for(int i=0;i<32;i++)
    {
        mychess[i].chess=new QLabel(this);
        mychess[i].initChess(i);
        mychess[i].labelChess();
        mychess[i].paintChess();
        update();
    }
QFont font;
font.setPixelSize(30);
who_go_tip1=new QLabel(this);
who_go_tip1->setFont(font);
who_go_tip1->setText("红方动子");
who_go_tip1->setStyleSheet("color:red;");
who_go_tip1->move(600,100);
who_go_tip2=new QLabel(this);
who_go_tip2->setFont(font);
who_go_tip2->setText("黑方动子");
who_go_tip2->move(9999,9999);
last_move=new QLabel(this);
last_move->resize(200,200);
last_move->move(9999,9999);
QFont font2;
font2.setPixelSize(25);
last_move_tip=new QLabel(this);
last_move_tip->setFont(font2);
last_move_tip->setText("前次落子:");
last_move_tip->move(580,220);
}

int ChessBoard::who_go=1;

void ChessBoard::paintEvent(QPaintEvent *event){
    QPainter painter(this);
    painter.drawPixmap(0,0,560,628,QPixmap(":/myImage/images/chessboard.png"));
};

bool ChessBoard::beChess(int x, int y){
    for(int i=0;i<32;i++)
    {if(mychess[i].row==x&&mychess[i].line==y)
        return true;}

    return false;
}

int ChessBoard::Num_of_Chess(int num, int x, int y){
    int sum=0;
    if(x>mychess[num].row&&y==mychess[num].line)
    {
        for(int i=mychess[num].row+1;i<x;i++)
            for(int j=0;j<32;j++)
                if(mychess[j].row==i&&mychess[j].line==y)
                    sum++;
    }
    else if(x<mychess[num].row&&y==mychess[num].line)
    {
        for(int i=x+1;i<mychess[num].row;i++)
            for(int j=0;j<32;j++)
                if(mychess[j].row==i&&mychess[j].line==y)
                    sum++;
    }
    else if(y>mychess[num].line&&x==mychess[num].row)
    {
        for(int i=mychess[num].line+1;i<y;i++)
            for(int j=0;j<32;j++)
                if(mychess[j].line==i&&mychess[j].row==x)
                    sum++;
    }
    else if(y<mychess[num].line&&x==mychess[num].row)
    {
        for(int i=y+1;i<mychess[num].line;i++)
            for(int j=0;j<32;j++)
                if(mychess[j].line==i&&mychess[j].row==x)
                    sum++;
    }
    return sum;
}





bool ChessBoard::canMoveBING(int num, int x, int y){
    if(num>=11&&num<=15){
        if(mychess[num].row<5&&x==mychess[num].row+1&&y==mychess[num].line) return true;
        else if(mychess[num].row>=5&&x==mychess[num].row+1&&y==mychess[num].line) return true;
       else if(mychess[num].row>=5&&x==mychess[num].row&&y==mychess[num].line-1) return true;
        else if(mychess[num].row>=5&&x==mychess[num].row&&y==mychess[num].line+1) return true;
         return false;
    }
    if(num>=16&&num<=20){
        if(mychess[num].row>4&&x==mychess[num].row-1&&y==mychess[num].line) return true;
        else if(mychess[num].row<=4&&x==mychess[num].row-1&&y==mychess[num].line) return true;
        else if(mychess[num].row<=4&&x==mychess[num].row&&y==mychess[num].line-1) return true;
        else if(mychess[num].row<=4&&x==mychess[num].row&&y==mychess[num].line+1) return true;
         return false;
    }
}

bool ChessBoard::canMoveSHI(int num,  int x, int y){
    if(num==3||num==5)
       { if(x>=0&&x<=2&&y>=3&&y<=5)
        {
            if(x==mychess[num].row+1&&y==mychess[num].line+1) return true;
            else if(x==mychess[num].row-1&&y==mychess[num].line-1) return true;
            else if(x==mychess[num].row+1&&y==mychess[num].line-1) return true;
            else if(x==mychess[num].row-1&&y==mychess[num].line+1) return true;
            return false;
        }
         return false;}
     if(num==26||num==28)
        { if(x>=7&&x<=9&&y>=3&&y<=5)
     {
             if(x==mychess[num].row+1&&y==mychess[num].line+1) return true;
             else if(x==mychess[num].row-1&&y==mychess[num].line-1) return true;
             else if(x==mychess[num].row+1&&y==mychess[num].line-1) return true;
             else if(x==mychess[num].row-1&&y==mychess[num].line+1) return true;
             return false;
     }
     return false;}
}

bool ChessBoard::canMoveXIANG(int num, int x, int y){
    if(num==2||num==6)
    {if(x<5)
        {
            if(x==mychess[num].row+2&&y==mychess[num].line-2&&beChess(x-1,y+1)==false) return true;
            else if(x==mychess[num].row+2&&y==mychess[num].line+2&&beChess(x-1,y-1)==false) return true;
            else if(x==mychess[num].row-2&&y==mychess[num].line-2&&beChess(x+1,y+1)==false) return true;
            else if(x==mychess[num].row-2&&y==mychess[num].line+2&&beChess(x+1,y-1)==false) return true;
            return false;
        }
        return false;
    }
    if(num==25||num==29)
       { if(x>4)
        {
            if(x==mychess[num].row+2&&y==mychess[num].line-2&&beChess(x-1,y+1)==false) return true;
            else if(x==mychess[num].row+2&&y==mychess[num].line+2&&beChess(x-1,y-1)==false) return true;
            else if(x==mychess[num].row-2&&y==mychess[num].line-2&&beChess(x+1,y+1)==false) return true;
            else if(x==mychess[num].row-2&&y==mychess[num].line+2&&beChess(x+1,y-1)==false) return true;
            return false;
        }
        return false;
    }
}

bool ChessBoard::canMoveMA(int num, int x, int y){
    if(num==1||num==7||num==24||num==30)
       { if(x==mychess[num].row+2&&y==mychess[num].line+1&&beChess(x-1,y-1)==false) return true;
        else if(x==mychess[num].row+1&&y==mychess[num].line+2&&beChess(x-1,y-1)==false) return true;
        else if(x==mychess[num].row-1&&y==mychess[num].line+2&&beChess(x+1,y-1)==false) return true;
        else if(x==mychess[num].row-2&&y==mychess[num].line+1&&beChess(x+1,y-1)==false) return true;
        else if(x==mychess[num].row-2&&y==mychess[num].line-1&&beChess(x+1,y+1)==false) return true;
        else if(x==mychess[num].row-1&&y==mychess[num].line-2&&beChess(x+1,y+1)==false) return true;
        else if(x==mychess[num].row+1&&y==mychess[num].line-2&&beChess(x-1,y+1)==false) return true;
        else if(x==mychess[num].row+2&&y==mychess[num].line-1&&beChess(x-1,y+1)==false) return true;
    }
    return false;
}

bool ChessBoard::canMoveCHE(int num, int x, int y){
    if(num==0||num==8||num==23||num==31)
    {
       if(x>mychess[num].row&&y==mychess[num].line)
          {for(int i=mychess[num].row+1;i<x;i++)
             if(beChess(i,y)) return false;
       return true;}

       else if(x<mychess[num].row&&y==mychess[num].line)
            {for(int i=x+1;i<mychess[num].row;i++)
                if(beChess(i,y)) return false;
       return true;}

       else if(y>mychess[num].line&&x==mychess[num].row)
       {for(int i=mychess[num].line+1;i<y;i++)
               if(beChess(x,i)) return false;
       return true;}
       else if(y<mychess[num].line&&x==mychess[num].row)
       {for(int i=y+1;i<mychess[num].line;i++)
               if(beChess(x,i)) return false;
       return true;}

return false;
    }
}

bool ChessBoard::canMovePAO(int num,  int x, int y){
    if(num==9||num==10||num==21||num==22)
    {
        if(x>mychess[num].row&&y==mychess[num].line)
           { if(Num_of_Chess(num,x,y)==0&&!beChess(x,y)) return true;
            else if(Num_of_Chess(num,x,y)==1) return true;
        return false;}

        else if(x<mychess[num].row&&y==mychess[num].line)
             {
            if(Num_of_Chess(num,x,y)==0&&!beChess(x,y)) return true;
                        else if(Num_of_Chess(num,x,y)==1) return true;
        return false;}

        else if(y>mychess[num].line&&x==mychess[num].row)
        {if(Num_of_Chess(num,x,y)==0&&!beChess(x,y)) return true;
            else if(Num_of_Chess(num,x,y)==1) return true;
        return false;}
        else if(y<mychess[num].line&&x==mychess[num].row)
        {if(Num_of_Chess(num,x,y)==0&&!beChess(x,y)) return true;
            else if(Num_of_Chess(num,x,y)==1) return true;
        return false;}

return false;
    }
}

bool ChessBoard::canMoveJIANG(int num, int x, int y){
    if(num==4){
        if(x>=0&&x<=2&&y>=3&&y<=5)
           { if(x==mychess[num].row+1&&y==mychess[num].line) return true;
            else if(x==mychess[num].row-1&&y==mychess[num].line) return true;
            else if(x==mychess[num].row&&y==mychess[num].line+1) return true;
            else if(x==mychess[num].row&&y==mychess[num].line-1) return true;
    }
        return false;
}
    if(num==27)
       { if(x>=7&&x<=9&&y>=3&&y<=5)
        {
            if(x==mychess[num].row+1&&y==mychess[num].line) return true;
            else if(x==mychess[num].row-1&&y==mychess[num].line) return true;
            else if(x==mychess[num].row&&y==mychess[num].line+1) return true;
            else if(x==mychess[num].row&&y==mychess[num].line-1) return true;
        }
        return false;
    }
}

bool ChessBoard::same_color(int num, int x, int y){
    if(num>=0&&num<=15)
       { for(int i=0;i<32;i++)
            if(mychess[i].row==x&&mychess[i].line==y&&mychess[i].ifred==true) return true;
}
    else if(num>=16&&num<=31)
       { for(int i=0;i<32;i++)
            if(mychess[i].row==x&&mychess[i].line==y&&mychess[i].ifred==false) return true;
    }
   else return false;
}

void ChessBoard::show_last_move(int num){
    QString picUrl;
    if(num==0||num==8) picUrl=":/myImage/images/8.png";
    if(num==1||num==7) picUrl=":/myImage/images/9.png";
    if(num==2||num==6) picUrl=":/myImage/images/10.png";
    if(num==3||num==5) picUrl=":/myImage/images/11.png";
    if(num==4) picUrl=":/myImage/images/12.png";
    if(num==9||num==10) picUrl=":/myImage/images/13.png";
    if(num==11||num==12||num==13||num==14||num==15) picUrl=":/myImage/images/14.png";

    if(num==16||num==17||num==18||num==19||num==20) picUrl=":/myImage/images/7.png";
    if(num==21||num==22) picUrl=":/myImage/images/6.png";
    if(num==23||num==31) picUrl=":/myImage/images/1.png";
    if(num==24||num==30) picUrl=":/myImage/images/2.png";
    if(num==25||num==29) picUrl=":/myImage/images/3.png";
    if(num==26||num==28) picUrl=":/myImage/images/4.png";
    if(num==27) picUrl=":/myImage/images/5.png";
    last_move->setPixmap(QPixmap(picUrl));

    last_move->setGeometry(650,250,80,80);
    last_move->setScaledContents(true);
}

bool ChessBoard::canmove(int num, int x, int y){
    if(num>=0&&num<=15&&who_go%2==0) return false;
    if(num>=16&&num<=31&&who_go%2==1) return false;


    if(num>=11&&num<=20){
        if(canMoveBING(num,x,y)) return true;
        else return false;
    }
    else if(num==3||num==5||num==26||num==28)
                 if(canMoveSHI(num,x,y)) return true;
                 else return false;
    else if(num==2||num==6||num==25||num==29)
                  if(canMoveXIANG(num,x,y)) return true;
                  else return false;
    else if(num==1||num==7||num==24||num==30)
                   if(canMoveMA(num,x,y)) return true;
                   else return false;
    else if(num==0||num==8||num==23||num==31)
                   if(canMoveCHE(num,x,y)) return true;
                   else return false;
    else if(num==9||num==10||num==21||num==22)
                   if(canMovePAO(num,x,y)) return true;
                   else return false;
    else if(num==4||num==27)
                   if(canMoveJIANG(num,x,y)) return true;
                   else return false;
    else return true;
}







void ChessBoard::mouseMoveEvent(QMouseEvent *e){
    QToolTip::showText(e->globalPos(),QString("(%1,%2)").arg(e->x()).arg(e->y()));
    update();
}

void ChessBoard::mousePressEvent(QMouseEvent *event){

    static  int move_time=0;
   static int num;
         int judge_row=-1; int judge_line=-1;

       for(int i=0;i<=8;i++)
       {if(event->x()>(40+60*i-25)&&event->x()<(40+60*i+25)) judge_line=i;}
       for(int i=0;i<=9;i++)
          { if(event->y()>(46+60*i-25)&&event->y()<(46+60*i+25)) judge_row=9-i; }


if(move_time==0){
           for(int i=0;i<=31;i++)
           {if(mychess[i].row==judge_row&&mychess[i].line==judge_line)
                   num=i;
               else continue;}}
       if(judge_line!=-1&&judge_row!=-1)
       {
           switch(move_time){
                  case 0: move_time++; break;
                  case 1: move_time++; break;
                  }
       }

if(move_time==2&&canmove(num,judge_row,judge_line)){
    for(int i=0;i<=31;i++)
    {if(mychess[i].row==judge_row&&mychess[i].line==judge_line)
            mychess[i].killed();}}
       if(move_time==2&&canmove(num,judge_row,judge_line)==true){
           mychess[num].moveChess(judge_row,judge_line);
           update();
           move_time=0;
           who_go++;
           show_last_move(num);
       }
       if(move_time==2&&canmove(num,judge_row,judge_line)==false)
           move_time=0;

      if(mychess[27].ifdead)
      {
          win.resize(200,100);
          who_win=new QLabel(&win);
          who_win->setText(" 红方胜！");
          who_win->move(70,40);
          win.show();
      }
      if(mychess[4].ifdead)
      {
          win.resize(200,100);
          who_win=new QLabel(&win);
          who_win->setText(" 黑方胜！");
          who_win->move(70,40);
          win.show();
      }
      if(who_go%2==1)
      {
          who_go_tip1->move(600,100);
          who_go_tip2->move(9999,9999);
      }
      if(who_go%2==0)
      {
          who_go_tip1->move(9999,9999);
          who_go_tip2->move(600,100);
      }
}
