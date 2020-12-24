#ifndef RESEAUTRIHISTORIQUE_H
#define RESEAUTRIHISTORIQUE_H

#include "individual.h"
#include <QString>

class Historique
{
private:
    int m_idGeneration;
    Individual m_individu;
public:
    Historique(int id, Individual *ind);
    QString toString();
    int getIdGeneration() const;
    Individual getIndividu() const;
};

#endif // RESEAUTRIHISTORIQUE_H
