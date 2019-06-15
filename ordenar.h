#ifndef ORDENAR_H
#define ORDENAR_H

#include <QVector>
#include "equipe.h"
#include <algorithm>
#include <QObject>
#include <QFile>
#include "mediana.h"
#include<QDebug>
#include <QFileDialog>
#include <QTextStream>


class Ordenar
{
private:
     QVector<Equipe> grupo;

public:
     void OrdenarPorNome();
     void OrdenarPorTitulos();
     void OrdenarPorPontos();
     void ColocarTime(Equipe x);
     Equipe operator[](int a);
     int size();
     void TimeComMaisTitulosEmenosTitulos();
     void TimeComMaisPontosEmenosPontos ();
     bool TestarNome(Equipe x, QString y);
     bool TestarQtdEstaduais(Equipe x, float y);
     bool TestarQtdCopaBr(Equipe x, float y);
     bool TestarQtdBrasileiro(Equipe x, float y);
     bool TestarQtdLibertadores(Equipe x, float y);
     bool TestarQtdMundial(Equipe x, float y);
     float getMediaGeralDePontosFinal();
     float getMediaGeralDeTitulosTotais();
     bool Dados(QString dados);
     bool CarregarGrupo(QString dados);
     bool InvalidarNumeros(QString x);
     bool InvalidarChar(int i);
     bool ValidarTitulos(Equipe a);


     Ordenar();
};


bool CompararPorNome (Equipe x, Equipe y);
bool CompararPorTitulos (Equipe z , Equipe t);
bool CompararPorPontos (Equipe i, Equipe j);




#endif // ORDENAR_H
