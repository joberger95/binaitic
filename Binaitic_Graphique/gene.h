#ifndef GENE_H
#define GENE_H

#include <QString>

class Gene
{
private:
    double m_x = -1;
    double m_y = -1;
    int m_gene_num;
public:
    Gene(double x = -1, double y = -1);
    double getX() const;
    double getY() const;
    void setX(double x);
    void setY(double y);
    QString toString();
    static bool lessXThan(Gene *g1, Gene *g2);
    static bool lessYThan(Gene *g1, Gene *g2);
    int getGene_num() const;
    void setGene_num(int gene_num);
};

#endif // GENE_H
