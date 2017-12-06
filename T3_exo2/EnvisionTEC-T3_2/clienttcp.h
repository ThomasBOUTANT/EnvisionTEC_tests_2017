#ifndef CLIENTTCP_H
#define CLIENTTCP_H

#include <QTcpSocket>
#include <QDebug>

class ClientTcp : public QObject
{
    Q_OBJECT
    public :
        ClientTcp();

    public slots :
        void receive_IP(QString IP2);       // for the client to have an ID
        void receive_text(QString t);       // to write on the socket

    private slots :
        void connection_OK();               // check if client is connected
        void reading();                     // to read the socket
                                            //("HCI" for "Human-computer interface". In French, it's "IHM" for "Interface homme-machine"...)

    signals :
        void HCI_connection_OK();
        void HCI_text(QString);

    private :
        QString IP;
        int port;
        QTcpSocket socket;
};

#endif // CLIENTTCP_H
