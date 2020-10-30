#include "qstd.h"
using namespace qstd;

#include "gene.h"
#include "generation.h"
#include "evolutionprocess.h"
#include "parameters.h"

void test_1(void);
void test_2(void);
void test_3(void);

int main(void)
{
    test_3();
}

void test_1(void) {

    Generation my_generation(0, 11);

    my_generation.GeneAppend(0, 1);
    my_generation.GeneAppend(1, 10);
    my_generation.GeneAppend(7, 5);
    my_generation.GeneAppend(8, 52);
    my_generation.GeneAppend(10, 87);

    cout<<my_generation.toString()<<endl;
}

void test_2(void) {
    EvolutionProcess process(0, 1);
    process.GenerationAppend();
    cout<<process.at(0)->toString()<<endl;
}

void test_3(void) {
    EvolutionProcess process(0, 1);
    cout<<"Instanciation process oK"<<endl;
    process.init();
    cout<<process.toString()<<endl;
}

