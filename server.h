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
#include <vector>

class Server
{

public:
    Server(Config conf, struct sockaddr_in &saun);

    ~Server();

    int InitServer(struct sockaddr_in &saun);

    void WaitingForAccept();

private:
    int CreateWorkers();
    void ReadData(int addressConnnected);

    void Response(int addressConnnected, HTTPRequest message);

    int _socket;
    std::vector<int> sockets;
    Config _conf;
    int countOfThreadsAlive = 0;
};