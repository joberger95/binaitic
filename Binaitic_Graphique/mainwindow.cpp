#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "qstd.h"
#include "generation.h"
#include "parameters.h"
#include "misc.h"
#include <QTextStream>
#include <QMessageBox>
#include <iostream>

using namespace qstd;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
      ui(new Ui::MainWindow)
{
    // Idee pour la courbe, en abcisse les générations et en ordonnée le Fitness
    ui->setupUi(this);

    m_process = new EvolutionProcess(0, 1);
    m_process->run();
    cout<<m_process->toString()<<endl;
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pb_Quitter_clicked()
{
    close();
}

void MainWindow::on_pb_Lancer_clicked()
{
    if(m_lancer_pushed) return;

    cout<<"generation index num : 0"<<endl;
    cout<<m_process->at(0)->toString()<<endl;

    ui->Binaitic->setToolTip("Projet Génétique");

    ui->lineEdit_Equation->setText("4x(1-x)");

    ui->label_Generation_num_res->setNum(m_process->at(0)->getGeneration_number());
    ui->label_Population_res->setNum(Parameters::individualsNb);
    ui->label_Generations_res->setNum(m_process->getGeneration_ind());
    ui->label_Mutation_res->setNum(Parameters::mutationRate);
    ui->label_Crossover_res->setNum(Parameters::crossoverRate);
    ui->label_LessFitness_res->setNum(m_process->at(0)->getFitness());
    ui->label_Alpha_res->setNum(m_process->at(0)->at(0)->getGene_num());

    ui->label_X_axis_max_res->setNum(m_process->getX_max());
    ui->label_X_axis_min_res->setNum(m_process->getX_min());
    ui->label_Y_axis_max_res->setNum(m_process->getY_max());
    ui->label_Y_axis_min_res->setNum(m_process->getY_min());
    ui->Canvas_Figure->repaint();

    m_lancer_pushed = true;
}

void MainWindow::on_pb_Precedent_clicked()
{
    if(!m_lancer_pushed) return;

    if(m_generations_index > 0) m_generations_index--;
    else return;

    cout<<"generation index num : "<<m_generations_index<<endl;
    cout<<m_process->at(m_generations_index)->toString()<<endl;

    ui->label_Generation_num_res->setNum(m_process->at(m_generations_index)->getGeneration_number());
    ui->label_Alpha_res->setNum(m_process->at(m_generations_index)->at(0)->getGene_num());
    ui->label_LessFitness_res->setNum(m_process->at(m_generations_index)->getFitness());

    ui->Canvas_Figure->setGeneration(m_process->at(m_generations_index));
    ui->Canvas_Figure->repaint();
}

void MainWindow::on_pb_Suivant_clicked()
{
    if(!m_lancer_pushed) return;

    if(m_generations_index < m_process->length() - 1) m_generations_index++;
    else return;

    cout<<"generation index num : "<<m_generations_index<<endl;
    cout<<m_process->at(m_generations_index)->toString()<<endl;

    ui->label_Generation_num_res->setNum(m_process->at(m_generations_index)->getGeneration_number());
    ui->label_Alpha_res->setNum(m_process->at(m_generations_index)->at(0)->getGene_num());
    ui->label_LessFitness_res->setNum(m_process->at(m_generations_index)->getFitness());

    ui->Canvas_Figure->setGeneration(m_process->at(m_generations_index));
    ui->Canvas_Figure->repaint();
}
