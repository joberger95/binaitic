#ifndef GENE_H
#define GENE_H

#include <QString>

class Gene
{
private:
    double m_x;
    double m_y;
public:
    Gene(double x = -1, double y = -1);
    double getX() const;
    double getY() const;
    QString toString();
    static bool lessXThan(Gene *g1, Gene *g2);
    static bool lessYThan(Gene *g1, Gene *g2);
};

#endif // GENE_H
