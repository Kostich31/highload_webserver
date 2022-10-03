#pragma once

#include <string>
#include "constants.h"
#include <sys/socket.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/un.h>
#include <string>
#include <netinet/in.h>
#include <arpa/inet.h>

class Server
{

public:
    Server(Config conf);

    ~Server();

    int InitServer(struct sockaddr_in &saun);

    void WaitingForAccept();

private:
    void ReadData(int addressConnnected);

    void Response(int addressConnnected, HTTPRequest message);

    int _socket;
    Config _conf;
};