#include "chess.h"

Chess::Chess(QWidget *parent) : QWidget(parent)
{

}
void Chess::initChess(const int num){
    if(num>=0&&num<=31){chessNum=num; ifdead=false;}
    if(num>=0&&num<=15){ifred=true;}
    if(num>=16&&num<=31){ifred=false;}
    switch(num){
    case 0:chessType=CHE;row=0;line=0;break;
    case 1:chessType=MA;row=0;line=1;break;
    case 2:chessType=XIANG;row=0;line=2;break;
    case 3:chessType=SHI;row=0;line=3;break;
    case 4:chessType=JIANG;row=0;line=4;break;
    case 5:chessType=SHI;row=0;line=5;break;
    case 6:chessType=XIANG;row=0;line=6;break;
    case 7:chessType=MA;row=0;line=7;break;
    case 8:chessType=CHE;row=0;line=8;break;
    case 9:chessType=PAO;row=2;line=1;break;
    case 10:chessType=PAO;row=2;line=7;break;
    case 11:chessType=BING;row=3;line=0;break;
    case 12:chessType=BING;row=3;line=2;break;
    case 13:chessType=BING;row=3;line=4;break;
    case 14:chessType=BING;row=3;line=6;break;
    case 15:chessType=BING;row=3;line=8;break;

    case 16:chessType=BING;row=6;line=0;break;
    case 17:chessType=BING;row=6;line=2;break;
    case 18:chessType=BING;row=6;line=4;break;
    case 19:chessType=BING;row=6;line=6;break;
    case 20:chessType=BING;row=6;line=8;break;
    case 21:chessType=PAO;row=7;line=1;break;
    case 22:chessType=PAO;row=7;line=7;break;
    case 23:chessType=CHE;row=9;line=0;break;
    case 24:chessType=MA;row=9;line=1;break;
    case 25:chessType=XIANG;row=9;line=2;break;
    case 26:chessType=SHI;row=9;line=3;break;
    case 27:chessType=JIANG;row=9;line=4;break;
    case 28:chessType=SHI;row=9;line=5;break;
    case 29:chessType=XIANG;row=9;line=6;break;
    case 30:chessType=MA;row=9;line=7;break;
    case 31:chessType=CHE;row=9;line=8;break;
    }
};
void Chess::labelChess(){
        if(chessNum==0||chessNum==8) picUrl=":/myImage/images/8.png";
        if(chessNum==1||chessNum==7) picUrl=":/myImage/images/9.png";
        if(chessNum==2||chessNum==6) picUrl=":/myImage/images/10.png";
        if(chessNum==3||chessNum==5) picUrl=":/myImage/images/11.png";
        if(chessNum==4) picUrl=":/myImage/images/12.png";
        if(chessNum==9||chessNum==10) picUrl=":/myImage/images/13.png";
        if(chessNum==11||chessNum==12||chessNum==13||chessNum==14||chessNum==15) picUrl=":/myImage/images/14.png";

        if(chessNum==16||chessNum==17||chessNum==18||chessNum==19||chessNum==20) picUrl=":/myImage/images/7.png";
        if(chessNum==21||chessNum==22) picUrl=":/myImage/images/6.png";
        if(chessNum==23||chessNum==31) picUrl=":/myImage/images/1.png";
        if(chessNum==24||chessNum==30) picUrl=":/myImage/images/2.png";
        if(chessNum==25||chessNum==29) picUrl=":/myImage/images/3.png";
        if(chessNum==26||chessNum==28) picUrl=":/myImage/images/4.png";
        if(chessNum==27) picUrl=":/myImage/images/5.png";
}
void Chess::paintChess(){
    if(ifdead==false){
    chess->resize(60,60);
    chess->setFixedSize(60,60);
    chess->setPixmap(QPixmap(picUrl));
    chess->setGeometry(10+line*60,555-row*60,50,50);
    chess->setScaledContents(true);
    }
}
void Chess::moveChess(int x, int y){
    row=x;line=y;
    paintChess();
}
void Chess::killed(){
    ifdead=true;
    chess->resize(60,60);
    chess->setFixedSize(60,60);
    chess->setPixmap(QPixmap(picUrl));
    chess->setGeometry(10000,555000,50,50);  //将该棋子的贴图画到窗口之外，达到看不见的视觉效果
    chess->setScaledContents(true);
    row=-2; line=-2; //将row,line改为不可能的值，从而不影响对局
}
