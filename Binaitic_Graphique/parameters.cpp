#include "parameters.h"
#include "qstd.h"
using namespace qstd;

int Parameters::individualsNb = 20;
int Parameters::generationsMaxNb = 10;
int Parameters::initialGenesNb = 20;
int Parameters::minFitness = 0;

double Parameters::mutationRate = 0.1;
double Parameters::mutationAddRate = 0.2;
double Parameters::mutationDeleteRate = 0.1;
double Parameters::crossoverRate = 0.6;
// ******************************************************
// TODO : modifier la graine :
// - 0 : non aléatoire pour debug
// - rien : aléatoire
// ******************************************************
MyRandom *Parameters::randomGenerator=new MyRandom();

int Parameters::debug = 1;

void Parameters::print(QString txt, int d)
{
    if(d<debug)
        cout<<txt<<endl;
}
