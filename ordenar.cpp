#include "ordenar.h"


void Ordenar::ColocarTime(Equipe x)
{
    grupo.push_back(x);
}
Equipe Ordenar::operator[](int a)
{
    return grupo[a];
}

void Ordenar::OrdenarPorNome()
{
 std::sort(grupo.begin(),grupo.end(),CompararPorNome);
}

void Ordenar::OrdenarPorTitulos()
{
 std::sort(grupo.begin(),grupo.end(),CompararPorTitulos);
}

void Ordenar::OrdenarPorPontos()
{
 std::sort(grupo.begin(),grupo.end(),CompararPorPontos);
}


int Ordenar::size()
{
    return grupo.size();
}

void Ordenar::TimeComMaisTitulosEmenosTitulos()
{
    std::sort(grupo.begin(),grupo.end(),CompararPorTitulos);
    }


void Ordenar::TimeComMaisPontosEmenosPontos()
{
    std::sort(grupo.begin(),grupo.end(),CompararPorTitulos);
}

Ordenar::Ordenar()
{

}


bool CompararPorNome(Equipe w, Equipe y)
{
    return w.getTime().toLower()< y.getTime().toLower();
}

bool CompararPorTitulos(Equipe z, Equipe t)
{

    return z.getTitulos()>t.getTitulos();

}


bool CompararPorPontos(Equipe i, Equipe j)
{
    return i.getPontfinal()> j.getPontfinal();
}


bool Ordenar:: TestarQtdEstaduais(Equipe x, float y)
{
    if(y >= 0){
        return 1;
    }else {
        return 0;
    }

}

bool Ordenar:: TestarQtdCopaBr(Equipe x, float y)
{
    if(y >= 0){
        return 1;
    }else {
        return 0;
    }

}

bool Ordenar:: TestarQtdBrasileiro(Equipe x, float y)
{
    if(y >= 0){
        return 1;
    }else {
        return 0;
    }

}

bool Ordenar:: TestarQtdLibertadores(Equipe x, float y)
{
    if(y >= 0){
        return 1;
    }else {
        return 0;
    }

}

bool Ordenar:: TestarQtdMundial(Equipe x, float y)
{
    if(y >= 0){
        return 1;
    }else {
        return 0;
    }

}


float Ordenar::getMediaGeralDePontosFinal()
{
    float mediapontos;
    mediapontos = 0;
    for(Equipe x : grupo){
        mediapontos += x.getPontfinal();
    }
    return mediapontos/grupo.size();
}

float Ordenar::getMediaGeralDeTitulosTotais()
{
    float mediatitulos;
    mediatitulos = 0;
    for (Equipe y:grupo) {
        mediatitulos+=y.getTitulos();
    }
    return mediatitulos/grupo.size();
}

bool Ordenar::Dados(QString dados)
{
    QFile salvar(dados);
    QString arquivo;
        if(!salvar.open(QIODevice::WriteOnly))
            return false;

        for(Equipe y : grupo){
            arquivo = y.getTime() + ',' + QString::number(y.getQuantestadual())+ ',' + QString::number(y.getPontestadual())+ ',' +  QString::number(y.getQuantcopabr()) + ',' + QString::number(y.getPontcopabr()) + ',' + QString::number(y.getQuantbrasileiro()) + ',' + QString::number(y.getPontbrasileiro()) +',' +  QString::number(y.getQuantlibertadores())+',' + QString::number(y.getPontlibertadores()) + ',' + QString::number(y.getQuantmundial()) + ',' + QString::number(y.getPontmundial())+','+  QString::number(y.getTitulos())+',' + QString::number(y.getPontfinal())+ '\n';
            salvar.write(arquivo.toLocal8Bit());
        }
        return true;
}

bool Ordenar::CarregarGrupo(QString arquivo)
{
    QFile carregar(arquivo);
        if(!carregar.open(QIODevice::ReadOnly))
            return 0;

        QString y;
        Equipe x;
        while(!carregar.atEnd()){
            y = carregar.readLine();
            QStringList lista = y.split(",");
            x.setTime(lista[0]);
            x.setQuantestadual(lista[1].toDouble());
            x.setPontestadual(lista[2].toDouble());
            x.setQuantcopabr(lista[3].toDouble());
            x.setPontcopabr(lista[4].toDouble());
            x.setQuantbrasileiro(lista[5].toDouble());
            x.setPontbrasileiro(lista[6].toDouble());
            x.setQuantlibertadores(lista[7].toDouble());
            x.setPontlibertadores(lista[8].toDouble());
            x.setQuantmundial(lista[9].toDouble());
            x.setPontmundial(lista[10].toDouble());
            x.setTitulos(lista[11].toDouble());
            x.setPontfinal(lista[12].toDouble());
            ColocarTime(x);
        }
        return 1;
}

bool Ordenar::InvalidarNumeros(QString x)
{
    QString valores = "0123456789";
    for(int h = 0 ;h <x.size();h ++){
        for(int i =0;i < valores.size();i++){
            if(x[h] == valores[i]){
                return 0;
            }
        }
    }
    return  1;
}

bool Ordenar::InvalidarChar(int i)
{
    QString proibir = QString::number(i);
    QString carater;
}



bool Ordenar::ValidarTitulos(Equipe a)
{
    if((a.getQuantestadual()==0) and (a.getQuantcopabr()==0) and (a.getQuantbrasileiro()==0) and (a.getQuantlibertadores()==0) and (a.getQuantmundial()==0) ){
        return 0;
    }
    return 1;
}


bool Ordenar:: TestarNome(Equipe x, QString y)
{
    if((y.size() > 2) and y != "0" ){
        return 1;
    }else {
        return 0;
    }
}

