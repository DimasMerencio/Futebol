#include "equipe.h"


    float Equipe::getQuantestadual() const
    {
        return quantestadual;
    }

    void Equipe::setQuantestadual(float value)
    {

         quantestadual = value;

    }

    float Equipe::getQuantcopabr() const
    {
        return quantcopabr;
    }
    
    void Equipe::setQuantcopabr(float value)
    {

            quantcopabr = value;

    }
    
    float Equipe::getPontcopabr() const
    {
        return pontcopabr;
    }
    
    void Equipe::setPontcopabr(float value)
    {
        value = 10;
        pontcopabr = value*quantcopabr;
    }
    
    float Equipe::getTitulos() const
    {
        return titulos;
    }

    void Equipe::setTitulos(float value)
    {
        value = quantcopabr+quantmundial+quantestadual+quantbrasileiro+quantlibertadores;
        titulos =  value;
    }

    QString Equipe::getTime() const
    {
        return nome;
    }
    
    void Equipe::setTime(const QString &value)
    {

            nome = value;

    }

    Equipe::Equipe()
    {
       quantmundial = 0;
       quantbrasileiro = 0;
       quantlibertadores = 0;
       quantestadual = 0;
       quantcopabr = 0;
       nome = "time";
    }

    float Equipe::getQuantlibertadores() const
    {
        return quantlibertadores;
    }

    void Equipe::setQuantlibertadores(float value)
    {

            quantlibertadores = value;


    }

    float Equipe::getQuantbrasileiro() const
    {
        return quantbrasileiro;
    }

    void Equipe::setQuantbrasileiro(float value)
    {

            quantbrasileiro = value;

    }

    float Equipe::getQuantmundial() const
    {
        return quantmundial;
    }

    void Equipe::setQuantmundial(float value)
    {

            quantmundial = value;

    }

    float Equipe::getPontlibertadores() const
    {
        return pontlibertadores;
    }

    void Equipe::setPontlibertadores(float value)
    {
        value = 25;
        pontlibertadores = value * quantlibertadores;
    }

    float Equipe::getPontbrasileiro() const
    {
        return pontbrasileiro;
    }

    void Equipe::setPontbrasileiro(float value)
    {
        value = 20;
        pontbrasileiro = value * quantbrasileiro;
    }

    float Equipe::getPontmundial() const
    {
        return pontmundial;
    }

    void Equipe::setPontmundial(float value)
    {
        value = 50;
        pontmundial = value * quantmundial;
    }

    float Equipe::getPontfinal() const
    {
        return pontfinal;
    }

    void Equipe::setPontfinal(float value)
    {
        value = pontmundial+pontestadual+pontbrasileiro+pontlibertadores+pontcopabr;
        pontfinal = value;
    }

    float Equipe::getPontestadual() const
    {
        return pontestadual;
    }

    void Equipe::setPontestadual(float value)
    {
     value = 5;
     pontestadual = quantestadual*value;
    }

