#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include<QObject>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->actionSalvar,SIGNAL(triggered()),this,SLOT(SalvarDados()));
    connect(ui->actionCarregar,SIGNAL(triggered()),this,SLOT(CarregarDados()));
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::AtualizarTabela(){
     ui->TabelaDados->clearContents();
     for (int i = 0; i < grupo.size(); i++) {
     InserirEquipe(grupo[i],i);


     }
}

void MainWindow:: InserirDados(){
    float mediageraldepontos = grupo.getMediaGeralDePontosFinal();
    float mediageraldetitulos = grupo.getMediaGeralDeTitulosTotais();


    ui->label_17->setText(QString::number(mediageraldetitulos));
    ui->label_18->setText(QString::number(mediageraldepontos));



}

void MainWindow::InserirEquipe(Equipe a, int b)
{
    qDebug()<< a.getTime();
    ui->TabelaDados->setItem(b,0,new QTableWidgetItem(a.getTime()));
    ui->TabelaDados->setItem(b,1,new QTableWidgetItem(QString::number(a.getQuantestadual())));
    ui->TabelaDados->setItem(b,2,new QTableWidgetItem(QString::number(a.getPontestadual())));
    ui->TabelaDados->setItem(b,3,new QTableWidgetItem(QString::number(a.getQuantcopabr())));
    ui->TabelaDados->setItem(b,4,new QTableWidgetItem(QString::number(a.getPontcopabr())));
    ui->TabelaDados->setItem(b,5,new QTableWidgetItem(QString::number(a.getQuantbrasileiro())));
    ui->TabelaDados->setItem(b,6,new QTableWidgetItem(QString::number(a.getPontbrasileiro())));
    ui->TabelaDados->setItem(b,7,new QTableWidgetItem(QString::number(a.getQuantlibertadores())));
    ui->TabelaDados->setItem(b,8,new QTableWidgetItem(QString::number(a.getPontlibertadores())));
    ui->TabelaDados->setItem(b,9,new QTableWidgetItem(QString::number(a.getQuantmundial())));
    ui->TabelaDados->setItem(b,10,new QTableWidgetItem(QString::number(a.getPontmundial())));
    ui->TabelaDados->setItem(b,11,new QTableWidgetItem(QString::number(a.getTitulos())));
    ui->TabelaDados->setItem(b,12,new QTableWidgetItem(QString::number(a.getPontfinal())));



}


void MainWindow::on_pushButton_clicked()// vai adicionar os objetos na tabela.
{
    Equipe time;

        time.setTime(ui->Nome->text());
        time.setQuantbrasileiro(ui->Brasileiros->text().toInt());
        time.setQuantestadual(ui->Estaduais->text().toInt());
        time.setQuantmundial(ui->Mundiais->text().toInt());
        time.setQuantlibertadores(ui->Libertadores->text().toInt());
        time.setQuantcopabr(ui->Copas->text().toInt());
        time.setPontcopabr(0);
        time.setPontestadual(0);
        time.setPontbrasileiro(0);
        time.setPontlibertadores(0);
        time.setPontmundial(0);
        time.setTitulos(0);
        time.setPontfinal(0);
        QMessageBox frase;
        ui->Nome->clear();
        ui->Brasileiros->clear();
        ui->Libertadores->clear();
        ui->Brasileiros->clear();
        ui->Estaduais->clear();
        ui->Mundiais->clear();
        ui->Copas->clear();

      if((grupo.TestarNome(time,time.getTime())) and (grupo.TestarQtdEstaduais(time,time.getQuantestadual())) and (grupo.TestarQtdCopaBr(time,time.getQuantcopabr())) and (grupo.TestarQtdBrasileiro(time,time.getQuantbrasileiro())) and (grupo.TestarQtdLibertadores(time,time.getQuantlibertadores())) and (grupo.TestarQtdMundial(time,time.getQuantmundial()))and (grupo.InvalidarNumeros(time.getTime())) and (grupo.InvalidarChar(time.getQuantestadual())) and (grupo.InvalidarChar(time.getQuantcopabr())) and (grupo.InvalidarChar(time.getQuantbrasileiro())) and (grupo.InvalidarChar(time.getQuantlibertadores())) and (grupo.InvalidarChar(time.getQuantmundial())) and (grupo.ValidarTitulos(time))){

        int b = ui->TabelaDados->rowCount();
        ui->TabelaDados->insertRow(b);
        grupo.ColocarTime(time);
        InserirEquipe(time,b);
        InserirDados();
        grupo.TimeComMaisTitulosEmenosTitulos();
        ui->label_7->setText(grupo[0].getTime());
        ui->label_14->setText(grupo[grupo.size()-1].getTime());
        grupo.TimeComMaisPontosEmenosPontos();
        ui->label_15->setText(grupo[0].getTime());
        ui->label_16->setText(grupo[grupo.size()-1].getTime());


      }else {
         frase.setText("Dados inválidos");
         frase.exec();
      }

}


void MainWindow::on_pushButton_2_clicked()//vai ordenar por nome os itens da tabela.
{

   grupo.OrdenarPorNome();
   AtualizarTabela();


}

void MainWindow::on_pushButton_3_clicked()//vai ordenar por títulos is itens da tabela.
{
    grupo.OrdenarPorTitulos();
    AtualizarTabela();
}

void MainWindow::on_pushButton_4_clicked()//vai ordenar por pontos.
{
    grupo.OrdenarPorPontos();
    AtualizarTabela();
}



void MainWindow::on_actionSalvar_triggered()//salva dados de equipe.
{
    QMessageBox msg;
    QString tipos = "CSV(*.csv);; Arquivos de texto (*.txt) ";
    QString x = QFileDialog::getSaveFileName(this,"Escrever arquivos","",tipos);
    QFile teste(x);
    if(!teste.open(QFile::WriteOnly)){
        msg.setText("Não foi possível salvar o arquivo");
        msg.exec();
    }else {

        grupo.Dados(x);
        teste.close();
 }
}

void MainWindow::on_actionCarregar_triggered()//carregar dados de equipe.
{
    QMessageBox msg;
    QString tipos= "CSV(*.csv)";
    QString carregar = QFileDialog:: getOpenFileName(this,"Carregar Arquivos","",tipos);
    QFile teste(carregar);
    if(!teste.open(QFile::ReadOnly)){
        msg.setText("Não foi possível carregar o arquivo");
        msg.exec();
    }
        grupo.CarregarGrupo(carregar);
           for(int j = 0; j < grupo.size() ;++j){
               ui->TabelaDados->insertRow(j);
               InserirEquipe(grupo[j],j);
               teste.close();
           }
}



void MainWindow::on_TabelaDados_cellDoubleClicked(int row, int column)
{
    Equipe s;
    if(column == 0){
        QMessageBox::StandardButton resposta = QMessageBox::question(this,"Editar times", "Deseja editar esse item?");
        if(resposta == QMessageBox::Yes){
            bool sim;
            QString txt = QInputDialog::getText(this, "Alterar time", "Time", QLineEdit::Normal,"",&sim);
            if(sim and !txt.isEmpty()){
                s.setTime(txt+"");
                s.setQuantestadual(grupo[row].getQuantestadual());
                s.setQuantcopabr(grupo[row].getQuantcopabr());
                s.setQuantbrasileiro(grupo[row].getQuantbrasileiro());
                s.setQuantlibertadores(grupo[row].getQuantlibertadores());
                s.setQuantmundial(grupo[row].getQuantmundial());

                grupo.ColocarTime(s);
                ui->TabelaDados->setItem(row,0,new QTableWidgetItem(s.getTime()));

            }
        }

    }
    if(column == 1){
        QMessageBox::StandardButton resposta = QMessageBox::question(this,"Editar times", "Deseja editar a Qtd.Estaduais?");
        if(resposta == QMessageBox::Yes){
            bool sim;
            QString txt = QInputDialog::getText(this, "Alterar Estaduais", "Estaduais", QLineEdit::Normal,"",&sim);
            if(sim and !txt.isEmpty()){
                s.setTime(grupo[row].getTime());
                s.setQuantestadual(txt.toInt());
                s.setQuantcopabr(grupo[row].getQuantcopabr());
                s.setQuantbrasileiro(grupo[row].getQuantbrasileiro());
                s.setQuantlibertadores(grupo[row].getQuantlibertadores());
                s.setQuantmundial(grupo[row].getQuantmundial());

                grupo.ColocarTime(s);
                ui->TabelaDados->setItem(row,1,new QTableWidgetItem(QString::number(s.getQuantestadual())));

            }
        }

    }
    if(column == 3){
        QMessageBox::StandardButton resposta = QMessageBox::question(this,"Editar times", "Deseja editar a Qtd.Copa do Brasil?");
        if(resposta == QMessageBox::Yes){
            bool sim;
            QString txt = QInputDialog::getText(this, "Alterar Copa", "Copa do Brasil", QLineEdit::Normal,"",&sim);
            if(sim and !txt.isEmpty()){
                s.setTime(grupo[row].getTime());
                s.setQuantestadual(grupo[row].getQuantestadual());
                s.setQuantcopabr(txt.toInt());
                s.setQuantbrasileiro(grupo[row].getQuantbrasileiro());
                s.setQuantlibertadores(grupo[row].getQuantlibertadores());
                s.setQuantmundial(grupo[row].getQuantmundial());

                grupo.ColocarTime(s);
                ui->TabelaDados->setItem(row,3,new QTableWidgetItem(QString::number(s.getQuantcopabr())));

            }
        }

    }
    if(column == 5){
        QMessageBox::StandardButton resposta = QMessageBox::question(this,"Editar times", "Deseja editar a Qtd.Brasileiros?");
        if(resposta == QMessageBox::Yes){
            bool sim;
            QString txt = QInputDialog::getText(this, "Alterar brasileiros", "Brasileiro", QLineEdit::Normal,"",&sim);
            if(sim and !txt.isEmpty()){
                s.setTime(grupo[row].getTime());
                s.setQuantestadual(grupo[row].getQuantestadual());
                s.setQuantcopabr(grupo[row].getQuantcopabr());
                s.setQuantbrasileiro(txt.toInt());
                s.setQuantlibertadores(grupo[row].getQuantlibertadores());
                s.setQuantmundial(grupo[row].getQuantmundial());

                grupo.ColocarTime(s);
                ui->TabelaDados->setItem(row,5,new QTableWidgetItem(QString::number(s.getQuantbrasileiro())));

            }
        }

    }
    if(column == 7){
        QMessageBox::StandardButton resposta = QMessageBox::question(this,"Editar times", "Deseja editar a Qtd.Libertadores?");
        if(resposta == QMessageBox::Yes){
            bool sim;
            QString txt = QInputDialog::getText(this, "Alterar Libertadores", "Libertadores", QLineEdit::Normal,"",&sim);
            if(sim and !txt.isEmpty()){
                s.setTime(grupo[row].getTime());
                s.setQuantestadual(grupo[row].getQuantestadual());
                s.setQuantcopabr(grupo[row].getQuantcopabr());
                s.setQuantbrasileiro(grupo[row].getQuantbrasileiro());
                s.setQuantlibertadores(txt.toInt());
                s.setQuantmundial(grupo[row].getQuantmundial());

                grupo.ColocarTime(s);
                ui->TabelaDados->setItem(row,7,new QTableWidgetItem(QString::number(s.getQuantlibertadores())));

            }
        }

    }
    if(column == 9){
        QMessageBox::StandardButton resposta = QMessageBox::question(this,"Editar times", "Deseja editar a Qtd.Mundial?");
        if(resposta == QMessageBox::Yes){
            bool sim;
            QString txt = QInputDialog::getText(this, "Alterar Estaduais", "Mundial", QLineEdit::Normal,"",&sim);
            if(sim and !txt.isEmpty()){
                s.setTime(grupo[row].getTime());
                s.setQuantestadual(grupo[row].getQuantestadual());
                s.setQuantcopabr(grupo[row].getQuantcopabr());
                s.setQuantbrasileiro(grupo[row].getQuantbrasileiro());
                s.setQuantlibertadores(grupo[row].getQuantlibertadores());
                s.setQuantmundial(txt.toInt());

                grupo.ColocarTime(s);
                ui->TabelaDados->setItem(row,9,new QTableWidgetItem(QString::number(s.getQuantmundial())));

            }
        }

    }
}
