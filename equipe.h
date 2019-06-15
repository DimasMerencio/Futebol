#ifndef EQUIPE_H
#define EQUIPE_H

#include <QObject>


class Equipe
{
    QString nome;// time de futebol adicionado.
        float quantlibertadores;// quantidade de copa libertadores que o time adicionado tem.
        float quantbrasileiro;// quantidade de campeonatos brasileiros que um time tem.
        float quantmundial;// quantidade de campeonatos mundiais que o time tem.
        float pontlibertadores;// quantidade de pontos que o time tem de acordo com a quantidade de libertadores.
        float pontbrasileiro;// quantidade de pontos que o time tem de acordo com a quantidade de brasileiros.
        float pontmundial;// quantidade de pontos que o time tem de acordo com a quantidade de mundiais.
        float pontfinal;// quantidade de pontos final de um time, que vai ser dado por uma média ponderada entre a quantidade de pontos da libertadores, brasileiro e mundial.
        float pontestadual; // quantidade de pontos de um time, de acordo com a quantidade de campeonatos estaduais.
        float quantestadual;// quantidade de campeonatos estaduais de um time.
        float quantcopabr;// quantidade de copas do brasil.
        float pontcopabr;// pontuação da copa do brasil.
        float titulos;// titulos totais de um time de futebol.
    public:

        QString getTime() const;
        void setTime(const QString &value);
        float getQuantlibertadores() const;
        void setQuantlibertadores(float value);
        float getQuantbrasileiro() const;
        void setQuantbrasileiro(float value);
        float getQuantmundial() const;
        void setQuantmundial(float value);
        float getPontlibertadores() const;
        void setPontlibertadores(float value);
        float getPontbrasileiro() const;
        void setPontbrasileiro(float value);
        float getPontmundial() const;
        void setPontmundial(float value);
        float getPontfinal() const;
        void setPontfinal(float value);
        float getPontestadual() const;
        void setPontestadual(float value);
        float getQuantestadual() const;
        void setQuantestadual(float value);
        float getQuantcopabr() const;
        void setQuantcopabr(float value);
        float getPontcopabr() const;
        void setPontcopabr(float value);
        float getTitulos() const;
        void setTitulos(float value);
        Equipe ();
};

#endif // EQUIPE_H
