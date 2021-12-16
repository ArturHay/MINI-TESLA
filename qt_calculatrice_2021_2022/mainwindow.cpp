#include <QDebug>
#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_2_clicked()
{
    // Lecteur des données de l'interface
    QString N1_str=ui->lineEdit->text();
    QString N2_str=ui->lineEdit_2->text();

    // Conversion en entier non signé 8 bits
    unsigned char N1=N1_str.toInt();
    unsigned char N2=N2_str.toInt();

    // Opération addition
    unsigned char R=N1+N2;

    // Conversion du résultat en chaîne
    QString R_str;
    R_str.setNum(R);

    //Affichage dans l'interface
    ui->lineEdit_3->setText(R_str);

    // Affichage en héxadécimal
    QString RHex_str=R_str.setNum(R,16);
    ui->lineEdit_22->setText(RHex_str);
}


void MainWindow::on_pushButton_3_clicked()
{
    // Lecteur des données de l'interface
    QString N1_str=ui->lineEdit_4->text();
    QString N2_str=ui->lineEdit_10->text();

    // Conversion en entier non signé 8 bits
    char N1=N1_str.toInt();
    char N2=N2_str.toInt();

    // Opération addition
    char R=N1+N2;

    // Conversion du résultat en chaîne
    QString R_str;
    R_str.setNum(R);

    //Affichage dans l'interface
    ui->lineEdit_16->setText(R_str);

    // Affichage en héxadécimal
    QString RHex_str=R_str.setNum(R,16);
    ui->lineEdit_23->setText(RHex_str);
}

void MainWindow::on_pushButton_4_clicked()
{
    // Lecteur des données de l'interface
    QString N1_str=ui->lineEdit_5->text();
    QString N2_str=ui->lineEdit_11->text();

    // Conversion en entier non signé 8 bits
    unsigned short N1=N1_str.toInt();
    unsigned short N2=N2_str.toInt();

    // Opération addition
    unsigned short R=N1+N2;

    // Conversion du résultat en chaîne
    QString R_str;
    R_str.setNum(R);

    //Affichage dans l'interface
    ui->lineEdit_17->setText(R_str);

    // Affichage en héxadécimal
    QString RHex_str=R_str.setNum(R,16);
    ui->lineEdit_24->setText(RHex_str);
}

void MainWindow::on_pushButton_5_clicked()
{
    // Lecteur des données de l'interface
    QString N1_str=ui->lineEdit_6->text();
    QString N2_str=ui->lineEdit_12->text();

    // Conversion en entier non signé 8 bits
    short N1=N1_str.toInt();
    short N2=N2_str.toInt();

    // Opération addition
    short R=N1+N2;

    // Conversion du résultat en chaîne
    QString R_str;
    R_str.setNum(R);

    //Affichage dans l'interface
    ui->lineEdit_18->setText(R_str);

    // Affichage en héxadécimal
    QString RHex_str=R_str.setNum(R,16);
    ui->lineEdit_25->setText(RHex_str);
}

void MainWindow::on_pushButton_6_clicked()
{
    // Lecteur des données de l'interface
    QString N1_str=ui->lineEdit_9->text();
    QString N2_str=ui->lineEdit_13->text();

    // Conversion en entier non signé 8 bits
    unsigned int N1=N1_str.toInt();
    unsigned int N2=N2_str.toInt();

    // Opération addition
    unsigned int R=N1+N2;

    // Conversion du résultat en chaîne
    QString R_str;
    R_str.setNum(R);

    //Affichage dans l'interface
    ui->lineEdit_19->setText(R_str);

    // Affichage en héxadécimal
    QString RHex_str=R_str.setNum(R,16);
    ui->lineEdit_26->setText(RHex_str);
}

void MainWindow::on_pushButton_7_clicked()
{
    // Lecteur des données de l'interface
    QString N1_str=ui->lineEdit_7->text();
    QString N2_str=ui->lineEdit_14->text();

    // Conversion en entier non signé 8 bits
    int N1=N1_str.toInt();
    int N2=N2_str.toInt();

    // Opération addition
    int R=N1+N2;

    // Conversion du résultat en chaîne
    QString R_str;
    R_str.setNum(R);

    //Affichage dans l'interface
    ui->lineEdit_20->setText(R_str);

    // Affichage en héxadécimal
    QString RHex_str=R_str.setNum(R,16);
    ui->lineEdit_27->setText(RHex_str);
}

void MainWindow::on_pushButton_8_clicked()
{
    // Lecteur des données de l'interface
    QString N1_str=ui->lineEdit_8->text();
    QString N2_str=ui->lineEdit_15->text();

    // Conversion en entier non signé 8 bits
    unsigned int N1=N1_str.toInt();
    unsigned int N2=N2_str.toInt();

    // Opération modulo
    unsigned int R=N1%N2;

    // Conversion du résultat en chaîne
    QString R_str;
    R_str.setNum(R);

    //Affichage dans l'interface
    ui->lineEdit_21->setText(R_str);

    // Affichage en héxadécimal
    QString RHex_str=R_str.setNum(R,16);
    ui->lineEdit_28->setText(RHex_str);
}

void MainWindow::on_pushButton_9_clicked()
{
    foreach(QLineEdit *widget, this->findChildren<QLineEdit*>())
    {
        widget->clear();
    }
}

void MainWindow::on_pushButton_clicked()
{
    MainWindow::close();
}

void MainWindow::on_pushButton_10_clicked()
{
    // Récupération des chaînes de caractères
    QString N1_str=ui->lineEdit_29->text();
    qDebug()<<"N1_str="<<N1_str;
    QString N2_str=ui->lineEdit_30->text();
    qDebug()<<"N2_str="<<N2_str;
    // Conversion en entier base 10 : decimal
    unsigned int N1 = N1_str.toInt(nullptr,10);
    unsigned int N2 = N2_str.toInt(nullptr,10);
    // Opération OU
    unsigned int R=N1||N2;
    qDebug()<<"R="<<R;
    // Conversion réprésentation décimal en binaire
    QString R_str(QString::number(R,2));
    // Affichage dans l'interface utilisateur
    qDebug()<<"R="<<R;
    ui->lineEdit_31->setText(R_str);
}

void MainWindow::on_pushButton_11_clicked()
{
    // Récupération des chaînes de caractères
    QString N1_str=ui->lineEdit_32->text();
    qDebug()<<"N1_str="<<N1_str;
    QString N2_str=ui->lineEdit_33->text();
    qDebug()<<"N2_str="<<N2_str;
    // Conversion en entier base 10 : decimal
    unsigned int N1 = N1_str.toInt(nullptr,10);
    unsigned int N2 = N2_str.toInt(nullptr,10);
    // Opération ET
    unsigned int R=N1&&N2;
    qDebug()<<"R="<<R;
    // Conversion réprésentation décimal en binaire
    QString R_str(QString::number(R,2));
    // Affichage dans l'interface utilisateur
    qDebug()<<"R="<<R;
    ui->lineEdit_34->setText(R_str);
}

void MainWindow::on_pushButton_12_clicked()
{
    // Récupération des chaînes de caractères
    QString N1_str=ui->lineEdit_35->text();
    qDebug()<<"N1_str="<<N1_str;
    // Conversion en entier base 10 : decimal
    unsigned int N1 = N1_str.toInt(nullptr,10);
    // Opération NON
    unsigned int R=!N1;
    qDebug()<<"R="<<R;
    // Conversion réprésentation décimal en binaire
    QString R_str(QString::number(R,2));
    // Affichage dans l'interface utilisateur
    qDebug()<<"R="<<R;
    ui->lineEdit_36->setText(R_str);
}

void MainWindow::on_pushButton_13_clicked()
{
    // Récupération des chaînes de caractères
    QString N1_str=ui->lineEdit_38->text();
    qDebug()<<"N1_str="<<N1_str;
    QString N2_str=ui->lineEdit_37->text();
    qDebug()<<"N2_str="<<N2_str;
    // Conversion en entier base 2 : binaire
    unsigned int N1 = N1_str.toInt(nullptr,2);
    unsigned int N2 = N2_str.toInt(nullptr,2);
    // Opération OU Bit à Bit
    unsigned int R=N1|N2;
    qDebug()<<"R="<<R;
    // Conversion réprésentation décimal en binaire
    QString R_str(QString::number(R,2));
    // Affichage dans l'interface utilisateur
    qDebug()<<"R="<<R;
    ui->lineEdit_39->setText(R_str);
}

void MainWindow::on_pushButton_14_clicked()
{
    // Récupération des chaînes de caractères
    QString N1_str=ui->lineEdit_40->text();
    qDebug()<<"N1_str="<<N1_str;
    QString N2_str=ui->lineEdit_41->text();
    qDebug()<<"N2_str="<<N2_str;
    // Conversion en entier base 2 : binaire
    unsigned int N1 = N1_str.toInt(nullptr,2);
    unsigned int N2 = N2_str.toInt(nullptr,2);
    // Opération OU Ex Bit à bit
    unsigned int R=N1^N2;
    qDebug()<<"R="<<R;
    // Conversion réprésentation décimal en binaire
    QString R_str(QString::number(R,2));
    // Affichage dans l'interface utilisateur
    qDebug()<<"R="<<R;
    ui->lineEdit_42->setText(R_str);
}

void MainWindow::on_pushButton_15_clicked()
{
    // Récupération des chaînes de caractères
    QString N1_str=ui->lineEdit_43->text();
    qDebug()<<"N1_str="<<N1_str;
    QString N2_str=ui->lineEdit_44->text();
    qDebug()<<"N2_str="<<N2_str;
    // Conversion en entier base 2 : binaire
    unsigned int N1 = N1_str.toInt(nullptr,2);
    unsigned int N2 = N2_str.toInt(nullptr,2);
    // Opération ET Bit à bit
    unsigned int R=N1&N2;
    qDebug()<<"R="<<R;
    // Conversion réprésentation décimal en binaire
    QString R_str(QString::number(R,2));
    // Affichage dans l'interface utilisateur
    qDebug()<<"R="<<R;
    ui->lineEdit_45->setText(R_str);
}

void MainWindow::on_pushButton_16_clicked()
{
    // Récupération des chaînes de caractères
    QString N1_str=ui->lineEdit_46->text();
    qDebug()<<"N1_str="<<N1_str;
    // Conversion en entier base 10 : decimal
    unsigned int N1 = N1_str.toInt(nullptr,10);
    // Opération NON Bit à bit
    unsigned int R=~N1;
    qDebug()<<"R="<<R;
    // Conversion réprésentation décimal en binaire
    QString R_str(QString::number(R,2));
    // Affichage dans l'interface utilisateur
    qDebug()<<"R="<<R;
    ui->lineEdit_47->setText(R_str);
}

void MainWindow::on_pushButton_17_clicked()
{
    // Lecteur des données de l'interface
    QString N1_str=ui->lineEdit_48->text();
    QString N2_str=ui->lineEdit_49->text();

    // Conversion en entier non signé 8 bits
    float N1=N1_str.toFloat();
    float N2=N2_str.toFloat();

    // Opération addition
    float R=N1+N2;

    // Conversion du résultat en chaîne
    QString R_str;
    R_str.setNum(R);

    //Affichage dans l'interface
    ui->lineEdit_50->setText(R_str);
    ui->lineEdit_51->setText(this->convertToIEEE32(R));

    // Affichage en héxadécimal
//    QString RHex_str=R_str.setNum(R,16);
//    ui->lineEdit_51->setText(RHex_str);
}

void MainWindow::on_pushButton_18_clicked()
{
    // Lecteur des données de l'interface
    QString N1_str=ui->lineEdit_52->text();
    QString N2_str=ui->lineEdit_53->text();

    // Conversion en entier non signé 8 bits
    float N1=N1_str.toFloat();
    float N2=N2_str.toFloat();

    // Opération addition
    float R=N1-N2;

    // Conversion du résultat en chaîne
    QString R_str;
    R_str.setNum(R);

    //Affichage dans l'interface
    ui->lineEdit_54->setText(R_str);
    ui->lineEdit_55->setText(this->convertToIEEE32(R));

    // Affichage en héxadécimal
//    QString RHex_str=R_str.setNum(R,16);
//    ui->lineEdit_55->setText(RHex_str);
}

void MainWindow::on_pushButton_19_clicked()
{
    // Lecteur des données de l'interface
    QString N1_str=ui->lineEdit_56->text();
    QString N2_str=ui->lineEdit_57->text();

    // Conversion en entier non signé 8 bits
    float N1=N1_str.toFloat();
    float N2=N2_str.toFloat();

    // Opération addition
    float R=N1*N2;

    // Conversion du résultat en chaîne
    QString R_str;
    R_str.setNum(R);

    //Affichage dans l'interface
    ui->lineEdit_58->setText(R_str);
    ui->lineEdit_59->setText(this->convertToIEEE32(R));

    // Affichage en héxadécimal
//    QString RHex_str=R_str.setNum(R,16);
//    ui->lineEdit_59->setText(RHex_str);
}

void MainWindow::on_pushButton_20_clicked()
{
    // Lecteur des données de l'interface
    QString N1_str=ui->lineEdit_60->text();
    QString N2_str=ui->lineEdit_61->text();

    // Conversion en entier non signé 8 bits
    float N1=N1_str.toFloat();
    float N2=N2_str.toFloat();
    // Opération addition
    float R=N1/N2;

    // Conversion du résultat en chaîne
    QString R_str;
    R_str.setNum(R);

    //Affichage dans l'interface
    ui->lineEdit_62->setText(R_str);
    ui->lineEdit_63->setText(this->convertToIEEE32(R));

    // Affichage en héxadécimal
//    QString RHex_str=R_str.setNum(R,16);
//    ui->lineEdit_63->setText(RHex_str);
}

QString MainWindow::convertToIEEE32(float &p_R)
{
    unsigned char *p = (unsigned char *)&p_R;
    QString oct1;
    QString oct2;
    QString oct3;
    QString oct4;
    oct1.setNum(*p,16);
    oct2.setNum(*(p + 1), 16);
    oct3.setNum(*(p + 2), 16);
    oct4.setNum(*(p + 3), 16);
    QString stringResult = oct1 + " " + oct2 + " " + oct3 + " " + oct4;
    return(stringResult);
}

QString MainWindow::convertToIEEE64(double &p_R)
{
    unsigned char *p = (unsigned char *)&p_R;
    QString oct1;
    QString oct2;
    QString oct3;
    QString oct4;
    QString oct5;
    QString oct6;
    QString oct7;
    QString oct8;
    oct1.setNum(*p,16);
    oct2.setNum(*(p + 1), 16);
    oct3.setNum(*(p + 2), 16);
    oct4.setNum(*(p + 3), 16);
    oct5.setNum(*(p + 4), 16);
    oct6.setNum(*(p + 5), 16);
    oct7.setNum(*(p + 6), 16);
    oct8.setNum(*(p + 7), 16);
    QString stringResult = oct1 + " " + oct2 + " " + oct3 + " " + oct4 + " " + oct5 + " " + oct6 + " " + oct7 + " " + oct8;
    return(stringResult);
}
void MainWindow::on_pushButton_21_clicked()
{
    QString R_Str=ui->lineEdit_64->text();
    float R = R_Str.toFloat();
    ui->lineEdit_65->setText(this->convertToIEEE32(R));
}

void MainWindow::on_pushButton_22_clicked()
{
    QString R_Str=ui->lineEdit_64->text();
    double R = R_Str.toDouble();
    ui->lineEdit_66->setText(this->convertToIEEE64(R));
}

void MainWindow::on_lineEdit_67_textChanged(const QString &arg1)
{
    if(ui->lineEdit_67->isModified())
    {
        int R=arg1.toInt(nullptr,10);
        ui->lineEdit_68->setText("0x"+QString::number(R,16));
        ui->lineEdit_69->setText("%"+QString::number(R,2));
    }
}

void MainWindow::on_lineEdit_68_textChanged(const QString &arg1)
{
    if(ui->lineEdit_68->isModified())
    {
        int R=arg1.toInt(nullptr,16);
        ui->lineEdit_67->setText(QString::number(R,10));
        ui->lineEdit_69->setText("%"+QString::number(R,2));
    }
}

void MainWindow::on_lineEdit_69_textChanged(const QString &arg1)
{
    if(ui->lineEdit_69->isModified())
    {
        int R=arg1.toInt(nullptr,2);
        ui->lineEdit_67->setText(QString::number(R,10));
        ui->lineEdit_68->setText("0x"+QString::number(R,16));
    }
}

void MainWindow::on_lineEdit_70_textChanged(const QString &arg1)
{
    if(ui->lineEdit_70->isModified())
    {
        ui->lineEdit_71->setText(arg1.toLatin1().toHex());
        ui->lineEdit_72->setText(arg1.toUtf8().toHex());
    }
}
void MainWindow::on_lineEdit_71_textChanged(const QString &arg1)
{
    // Saisie du nombre selon le code ASCII Latin
    QRegExp rx("^[0-9A-F]{2}$");
    qDebug()<<rx;
    QValidator *validator = new QRegExpValidator(rx, this);
    ui->lineEdit_71->setValidator(validator);
    int R;
    if(ui->lineEdit_71->isModified())
    {
        R=arg1.toInt(nullptr, 16);
        QChar carac(R);
        qDebug()<<carac;
        ui->lineEdit_70->setText(carac);
    }
}
void MainWindow::on_pushButton_23_clicked()
{
    QLabel *label = new QLabel();
    // Définir l'icon
    QIcon *icon=new QIcon(QPixmap("icons/calc.ico"));
    label->setWindowIcon(*icon);
    label->setPixmap(QPixmap("images/latin1.png"));
    label->show();
}


void MainWindow::on_lineEdit_72_textChanged(const QString &arg1)
{
    // Saisie du nombre selon le code Utf-8
    QRegExp rx("^[0-9A-F]{4}$");
    qDebug()<<rx;
    QValidator *validator = new QRegExpValidator(rx, this);
    ui->lineEdit_72->setValidator(validator);
    int R;
    if(ui->lineEdit_72->isModified())
    {
        R=arg1.toInt(nullptr, 16);
        QChar carac(R);
        qDebug()<<carac;
        ui->lineEdit_70->setText(carac);
    }
}

void MainWindow::on_lineEdit_73_textChanged(const QString &arg1)
{
    // Saisie du nombre 2 octets
    QRegExp rx("^[0-9A-F]{4}$");
    QValidator *validator = new QRegExpValidator(rx, this);
    ui->lineEdit_73->setValidator(validator);
    int R;
    if(ui->lineEdit_73->isModified())
    {
        R = arg1.toUShort(nullptr, 16);
        QChar carac(R);
        ui->lineEdit_70->setText(carac);
    }
}
