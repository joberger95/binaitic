/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>
#include <moncanvas.h>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *Binaitic;
    QPushButton *pb_Quitter;
    QLabel *label_Title;
    QLabel *label_Mutation;
    QLabel *label_Equation;
    QLabel *label_Generations;
    QLabel *label_Alpha;
    QPushButton *pb_Lancer;
    MonCanvas *Canvas_Figure;
    QLineEdit *lineEdit_Equation;
    QLabel *label_LessFitness;
    QLabel *label_Population;
    QLabel *label_Population_res;
    QLabel *label_Generations_res;
    QLabel *label_Mutation_res;
    QLabel *label_LessFitness_res;
    QPushButton *pb_Precedent;
    QPushButton *pb_Suivant;
    QLabel *label_Crossover;
    QLabel *label_Crossover_res;
    QLabel *label_Generation_num;
    QLabel *label_Generation_num_res;
    QLabel *label_Alpha_res;
    QLabel *label_X_axis_max_res;
    QLabel *label_X_axis_min_res;
    QLabel *label_Y_axis_min_res;
    QLabel *label_Y_axis_max_res;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(820, 526);
        MainWindow->setStyleSheet(QString::fromUtf8("MainWindow{\n"
"	background-color : #9980FA;\n"
"}"));
        Binaitic = new QWidget(MainWindow);
        Binaitic->setObjectName(QString::fromUtf8("Binaitic"));
        pb_Quitter = new QPushButton(Binaitic);
        pb_Quitter->setObjectName(QString::fromUtf8("pb_Quitter"));
        pb_Quitter->setGeometry(QRect(690, 430, 93, 28));
        label_Title = new QLabel(Binaitic);
        label_Title->setObjectName(QString::fromUtf8("label_Title"));
        label_Title->setGeometry(QRect(330, 20, 121, 31));
        QFont font;
        font.setPointSize(20);
        font.setBold(true);
        font.setWeight(75);
        label_Title->setFont(font);
        label_Mutation = new QLabel(Binaitic);
        label_Mutation->setObjectName(QString::fromUtf8("label_Mutation"));
        label_Mutation->setGeometry(QRect(650, 200, 111, 16));
        label_Equation = new QLabel(Binaitic);
        label_Equation->setObjectName(QString::fromUtf8("label_Equation"));
        label_Equation->setGeometry(QRect(670, 70, 61, 16));
        label_Generations = new QLabel(Binaitic);
        label_Generations->setObjectName(QString::fromUtf8("label_Generations"));
        label_Generations->setGeometry(QRect(650, 170, 101, 16));
        label_Alpha = new QLabel(Binaitic);
        label_Alpha->setObjectName(QString::fromUtf8("label_Alpha"));
        label_Alpha->setGeometry(QRect(650, 260, 55, 16));
        pb_Lancer = new QPushButton(Binaitic);
        pb_Lancer->setObjectName(QString::fromUtf8("pb_Lancer"));
        pb_Lancer->setGeometry(QRect(610, 360, 171, 61));
        Canvas_Figure = new MonCanvas(Binaitic);
        Canvas_Figure->setObjectName(QString::fromUtf8("Canvas_Figure"));
        Canvas_Figure->setGeometry(QRect(109, 79, 521, 251));
        lineEdit_Equation = new QLineEdit(Binaitic);
        lineEdit_Equation->setObjectName(QString::fromUtf8("lineEdit_Equation"));
        lineEdit_Equation->setGeometry(QRect(660, 90, 113, 22));
        label_LessFitness = new QLabel(Binaitic);
        label_LessFitness->setObjectName(QString::fromUtf8("label_LessFitness"));
        label_LessFitness->setGeometry(QRect(650, 240, 91, 16));
        label_Population = new QLabel(Binaitic);
        label_Population->setObjectName(QString::fromUtf8("label_Population"));
        label_Population->setGeometry(QRect(650, 140, 101, 16));
        label_Population_res = new QLabel(Binaitic);
        label_Population_res->setObjectName(QString::fromUtf8("label_Population_res"));
        label_Population_res->setGeometry(QRect(740, 140, 55, 16));
        label_Generations_res = new QLabel(Binaitic);
        label_Generations_res->setObjectName(QString::fromUtf8("label_Generations_res"));
        label_Generations_res->setGeometry(QRect(740, 170, 55, 16));
        label_Mutation_res = new QLabel(Binaitic);
        label_Mutation_res->setObjectName(QString::fromUtf8("label_Mutation_res"));
        label_Mutation_res->setGeometry(QRect(760, 200, 55, 16));
        label_LessFitness_res = new QLabel(Binaitic);
        label_LessFitness_res->setObjectName(QString::fromUtf8("label_LessFitness_res"));
        label_LessFitness_res->setGeometry(QRect(740, 240, 55, 16));
        pb_Precedent = new QPushButton(Binaitic);
        pb_Precedent->setObjectName(QString::fromUtf8("pb_Precedent"));
        pb_Precedent->setGeometry(QRect(150, 360, 171, 61));
        pb_Suivant = new QPushButton(Binaitic);
        pb_Suivant->setObjectName(QString::fromUtf8("pb_Suivant"));
        pb_Suivant->setGeometry(QRect(360, 360, 171, 61));
        label_Crossover = new QLabel(Binaitic);
        label_Crossover->setObjectName(QString::fromUtf8("label_Crossover"));
        label_Crossover->setGeometry(QRect(650, 220, 111, 16));
        label_Crossover_res = new QLabel(Binaitic);
        label_Crossover_res->setObjectName(QString::fromUtf8("label_Crossover_res"));
        label_Crossover_res->setGeometry(QRect(760, 220, 55, 16));
        label_Generation_num = new QLabel(Binaitic);
        label_Generation_num->setObjectName(QString::fromUtf8("label_Generation_num"));
        label_Generation_num->setGeometry(QRect(110, 60, 121, 16));
        label_Generation_num_res = new QLabel(Binaitic);
        label_Generation_num_res->setObjectName(QString::fromUtf8("label_Generation_num_res"));
        label_Generation_num_res->setGeometry(QRect(220, 60, 55, 16));
        label_Alpha_res = new QLabel(Binaitic);
        label_Alpha_res->setObjectName(QString::fromUtf8("label_Alpha_res"));
        label_Alpha_res->setGeometry(QRect(700, 260, 55, 16));
        label_X_axis_max_res = new QLabel(Binaitic);
        label_X_axis_max_res->setObjectName(QString::fromUtf8("label_X_axis_max_res"));
        label_X_axis_max_res->setGeometry(QRect(620, 330, 55, 16));
        label_X_axis_min_res = new QLabel(Binaitic);
        label_X_axis_min_res->setObjectName(QString::fromUtf8("label_X_axis_min_res"));
        label_X_axis_min_res->setGeometry(QRect(110, 330, 55, 16));
        label_Y_axis_min_res = new QLabel(Binaitic);
        label_Y_axis_min_res->setObjectName(QString::fromUtf8("label_Y_axis_min_res"));
        label_Y_axis_min_res->setGeometry(QRect(70, 310, 55, 16));
        label_Y_axis_max_res = new QLabel(Binaitic);
        label_Y_axis_max_res->setObjectName(QString::fromUtf8("label_Y_axis_max_res"));
        label_Y_axis_max_res->setGeometry(QRect(60, 80, 55, 16));
        MainWindow->setCentralWidget(Binaitic);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 820, 22));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Binaitic", nullptr));
        pb_Quitter->setText(QCoreApplication::translate("MainWindow", "&Quitter", nullptr));
        label_Title->setText(QCoreApplication::translate("MainWindow", "BINAITIC", nullptr));
        label_Mutation->setText(QCoreApplication::translate("MainWindow", "Mutation rate :", nullptr));
        label_Equation->setText(QCoreApplication::translate("MainWindow", "Equation", nullptr));
        label_Generations->setText(QCoreApplication::translate("MainWindow", "G\303\251n\303\251rations :", nullptr));
        label_Alpha->setText(QCoreApplication::translate("MainWindow", "Alpha : ", nullptr));
        pb_Lancer->setText(QCoreApplication::translate("MainWindow", "&Lancer", nullptr));
        label_LessFitness->setText(QCoreApplication::translate("MainWindow", "Less fitness :", nullptr));
        label_Population->setText(QCoreApplication::translate("MainWindow", "Population :", nullptr));
        label_Population_res->setText(QString());
        label_Generations_res->setText(QString());
        label_Mutation_res->setText(QString());
        label_LessFitness_res->setText(QString());
        pb_Precedent->setText(QCoreApplication::translate("MainWindow", "&Pr\303\251c\303\251dent", nullptr));
        pb_Suivant->setText(QCoreApplication::translate("MainWindow", "&Suivant", nullptr));
        label_Crossover->setText(QCoreApplication::translate("MainWindow", "Crossover rate  :", nullptr));
        label_Crossover_res->setText(QString());
        label_Generation_num->setText(QCoreApplication::translate("MainWindow", "Generation n\302\260 :", nullptr));
        label_Generation_num_res->setText(QString());
        label_Alpha_res->setText(QString());
        label_X_axis_max_res->setText(QString());
        label_X_axis_min_res->setText(QString());
        label_Y_axis_min_res->setText(QString());
        label_Y_axis_max_res->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
