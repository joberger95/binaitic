#ifndef RESEAUTRIHISTORIQUES_H
#define RESEAUTRIHISTORIQUES_H

#include <QList>
#include "historique.h"

class Historiques : public QList<Historique *>
{
private:
    int m_generationFinale;
public:
    Historiques();
    int getGenerationFinale() const;
    void setGenerationFinale(int generationFinale);
};

#endif // RESEAUTRIHISTORIQUES_H
