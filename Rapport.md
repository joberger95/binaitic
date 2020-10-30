BERGER Jordan

LUCAS Adam

MAPET Yorick

https://github.com/joberger95/binaitic

# Projet Binaitic

Dans une optique d'amélioration des compétences de chacun des étudiants dans les domaines de la génétique et du développement C++, le projet sera basé sur:

- base de suivi: http://www.alliot.fr/fgenetic.html.fr
- logiciel de développement: QTCreator
- GitHub
- VsCode pour la rédaction du rapport MarkDown.

## Objectif

Un alogrithme génétique a pour but d'effectuer des optimisations dans un espace défini de données, résoudre un problème aux solutions inconnues dans un temps acceptables. 

Ici, l'étude d'une fonction aléatoire représentée par une courbe et composée d'une "population" basée sur la notion de sélection naturelle.

# Composition d'une génération et de ses individus

## Le gène

Un gène est formé d'une coordonnée en **x** ainsi que dd'une coordonnée en **y**.

## Un individu

Chacun des individus est identifié par son gène et une valeur de fitness (ici, sa coordonnée **y**).

## Une génération

Une génération est composée d'un nombre défini d'individus.

```C++
    int Parameters::generationsMaxNb = 10;
```

# Processus de sélection et de mutation

## L'alpha et son fitness

L'individu désigné comme étant l'Alpha est celui dont le fitness est le plus bas.

```C++
bool Generation::lessFitnessThan(Generation *g1, Generation *g2)
{
    return g1->getFitness() < g2->getFitness();
}
```
## Le cross-fit

Valeur aléatoire permettant de scinder en deux parties le gène de deux individus. Ces dernières deviennent donc miscibles afin de former un nouveau gène. C'est la **sélection naturelle et aléatoire**. Ce processus est appliqué à toute la génération pour former la génération suivante.

```C++
for(int i = 0; i < Parameters::initialGenesNb; i++) {
        x = Parameters::randomGenerator->getFloat();
        if(x < m_x_min || x > m_x_max) {
            i--;
            continue;
        }
```
## La sélection des individus

L'Alpha est sélectionné par son fitness et rejoint automatiquement la génération n+1. Les individus, issus de la génération n-1, se voient donc un à un mélanger avec l'Alpha. L'individu générer, à l'aide du cross-fit, rejoint ensuite la génération n+1.

## La mutation aléatoire

La mutation est dite aléatoire car mélange le gène de deux individus (cf: cross-fit).

## La nouvelle génération

La nouvelle génération est la résultante des mélanges effectués sur la génération n-1. Elle se verra elle aussi désigné son Alpha et subira les mêmes effets afin de créer la génération n+1.

# Lecture graphique

# Problèmes rencontrés

# Retour d'expérience
