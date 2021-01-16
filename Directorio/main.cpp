#include <QCoreApplication>
#include <QDir>
#include <QtDebug>
#include <string>
#include<iostream>
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    qDebug()<<" BIENVENIDO ";
    qDebug()<<"Ingrese un Path";
    std::string path;
    std::cin>>path;
    QString qpath = QString::fromStdString(path);
    // Creando un directorio a partir de un path
    QDir directorio(qpath);
    // Obteniendo informacion del directorio home
    qDebug() << "\nObteniendo información de" << directorio.absolutePath() << ":";
    QFileInfoList contenido= directorio.entryInfoList();
    foreach (const QFileInfo &info, contenido) {
        qDebug() << "--------------------------------------------";
        qDebug() << "|" "Nombre:" "                   "  "|" << info.fileName();
        qDebug() << "|" "Es directorio:" "            "  "|" << info.isDir();
        qDebug() << "|" "Tamanio: " "                 "  "|" << info.size();
        qDebug() << "|" "Se puede leer:" "            "  "|" << info.isReadable();
        qDebug() << "|" "Es un archivo ejecutable:"" "  "|"<< info.isExecutable();
        qDebug() << "|" "Duenio del elemento" "       "  "|"<<info.owner();


    }
    return 0;
}
