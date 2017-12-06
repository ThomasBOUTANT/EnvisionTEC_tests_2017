#include "clienttcp.h"

ClientTcp::ClientTcp()
{
    port=4000;                                                                  // anything greater than 1024
    QObject::connect(&socket,SIGNAL(connected()),this,SLOT(connection_OK()));   // signal sent when the server was connecting
    QObject::connect(&socket, SIGNAL(readyRead()), this, SLOT(reading()));      // signal sent when data were ready to be read
}
void ClientTcp::receive_IP(QString IP2)
{
    IP=IP2;                                                                     // the client receives an IP number...
    socket.connectToHost(IP,port);                                              // ...to be connected to the server
}
void ClientTcp::receive_text(QString t)
{
    QTextStream texte(&socket);                                                 // we link a flux with a socket
    texte << t <<endl;                                                          // we write the text found on the HCI
}
void ClientTcp::connection_OK()
{
    emit HCI_connection_OK();                                                   // we emit a signal to the HCI
}
void ClientTcp::reading()
{
    QString ligne;
    while(socket.canReadLine())                                                 // if there is something to read...
    {
        ligne = socket.readLine();                                              // ...we read it
        emit HCI_text(ligne);                                                   // and we emit it on the HCI
    }
}
