#ifndef SERVEURTCP_H
#define SERVEURTCP_H

#include <QTcpSocket>
#include <QTcpServer>
#include <QDebug>
#include "clienttcp.h"

class ServeurTcp : public QTcpServer
{
    Q_OBJECT
    public :
        ServeurTcp();
        void Start();
        void textManager(QString);              //to manage the different inputs coming from the clients
        void disconnect();

    private slots :
        void connectionAsked();
        void reading();

    signals :
        void HCI_connection();
        void HCI_text(QString);

    private :
        QTcpSocket *clientConnection;
};


#endif // SERVEURTCP_H
