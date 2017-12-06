/*
 *Autor: BOUTANT Thomas
 *
 * 27/11/2017 6 pm- 29/11/2017 3 am
 *
 *Context:
 *      Test for the vacancy "Junior Embedded Developer (C/C++)" in Kyiv
 *Company:
 *      EnvisionTEC (https://envisiontec.com/)
 *
 *
 * Rules:
 *   "  Implement a console client-server application using Qt5.3.0 library, qmake build system and g ++ compiler - 4.8.
        The client and the server must communicate via sockets and support any arbitrary set of commands and the ability to write and read the value of arbitrary parameters to the server.
        Example commands: START, STOP, SET_PARAM (key, value), GET_PARAM.
        Implement the output of the help menu for the client with the -h or --help command, which contains a list of available commands. As an IPC, use QTcpSocket.
        It will be a plus if the server can simultaneously support several clients, for example, 5.
 *   "
 *
 *Ressources:
 *      (English) http://www.bogotobogo.com/cplusplus/sockets_server_client_QT.php
 *      (French)  https://openclassrooms.com/courses/programmez-avec-le-langage-c/communiquer-en-reseau-avec-son-programme
 *      (French)  https://qt.developpez.com/tutoriels/reseau/ (very useful this one !)
*/

#include <QCoreApplication>
#include "serveurtcp.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    qDebug() << "#********************************#";
    ServeurTcp myServer;                                // we create the server ("serveur" in French, hence "ServeurTCP"...)
    myServer.Start();                                   // we launch the server

    return a.exec();
}
