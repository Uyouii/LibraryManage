#include "library.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Library S;
	QFont font = a.font();
	font.setPointSize(11); //设置整体字体大小
	a.setFont(font);
    return a.exec();
}
