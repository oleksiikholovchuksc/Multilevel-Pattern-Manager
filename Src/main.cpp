#include "Src/UI/MainWindow.h"
#include "Src/Tests/MinimizationTest.hpp"
#include "Src/Tests/SplicingTest.hpp"
#include <QApplication>
#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    MPM::Testing::MinimizationTest mt;
    MPM::Testing::SplicingTest st;

    qDebug() << "Minimization test succeeded:" << mt.exec();
    qDebug() << "Splicing test succeeded:" << st.exec();

    MainWindow w;
    w.show();

    return a.exec();
}
