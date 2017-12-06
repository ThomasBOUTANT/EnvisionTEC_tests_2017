#include "serveurtcp.h"

ServeurTcp :: ServeurTcp ()
{
}

void ServeurTcp :: Start ()
{
    qDebug() << "#********* Start Server *********#";
    listen(QHostAddress::Any,4000);                                                     // the server is now listening
    QObject::connect(this, SIGNAL(newConnection()),this, SLOT(connectionAsked()));
    qDebug() << "#********************************#\n";
    qDebug() << "Port = 4000";
    qDebug() << "To be connected : open a terminal, then write";
    qDebug() << "     > telnet";
    qDebug() << "     > open localhost 4000\n";
    qDebug() << "#********************************#\n";
}

void ServeurTcp :: connectionAsked()
 {
    qDebug() << "   *** Someone asks for a connection ***";
    emit HCI_connection();                                                              // we send a signal to the HCI
    clientConnection = nextPendingConnection();                                         // we create a new socket for this client
    QObject:: connect(clientConnection, SIGNAL(readyRead()),this, SLOT(reading()));     // if we receive data, reading() slot is called
}
void ServeurTcp ::reading()
{
    QString ligne;
    while(clientConnection->canReadLine())                                              // if we can read the socket
    {
        ligne = clientConnection->readLine();                                           // we read the line
        emit HCI_text(ligne);                                                           // and we send it to the HCI
    }
    textManager(ligne);                                                                 // we manage the answer given to the client
}

void ServeurTcp::disconnect()
{
    qDebug() << "Disconnected...\n";
}

void ServeurTcp::textManager(QString mylign)
{
    QTextStream texte(clientConnection);                                                // we create a flux to write on the socket

    if (mylign == "START\r\n")
    {
        qDebug() << "     START demand\n\n\n";
        Start();
    }
    else if (mylign == "STOP\r\n")
    {
        qDebug() << "     STOP demand\n";
        texte << "  Goodbye..." << endl;
        clientConnection->disconnect();
    }
    else if (mylign == "HELLO\r\n")
    {
        qDebug() << "     HELLO !!!";
        texte << "  Hello ! Have a good day " << clientConnection << " !!\n" << endl;
    }
    else if (mylign == "IDEAS\r\n")
    {
        qDebug() << "     The same : I don't have ideas...";
        texte << "-- I don't know which commands I can implemente... And you ?--\n" << endl;
    }

    else if (mylign == "--h\r\n" || mylign == "-h\r\n")
    {
        qDebug() << "     HELP request\n";
        texte << "#****************************************************#" << endl;
        texte << "#******* HELP GLOSSARY ******************************#" << endl;
        texte << "#****************************************************#" << endl;
        texte << "#* START - reset the client parameters **************#" << endl;
        texte << "#* STOP - disconnect the client *********************#" << endl;
        texte << "#* HELLO - to say 'Hello' and to be happy !**********#" << endl;
        texte << "#* IDEAS - ask help to find ideas for this glossary *#" << endl;
        texte << "#****************************************************#\n" << endl;
    }
    else if (mylign == "\r\n")
    {
        //nothing
    }
    else
    {
        texte << "--  Message received! --" << endl;
        texte << "-- You can write '-h' or '--h' for help. --\n" << endl;
    }
}
