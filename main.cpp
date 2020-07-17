#include<widget.h>
#include <QApplication>
#include<chessboard.h>
#include<chess.h>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ChessBoard CB;
    CB.show();
    return a.exec();
}
