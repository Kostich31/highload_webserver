#include <iostream>
#include <string>
#include <vector>
#include <thread>
#include "server.h"
#include "utils.h"
#include <unistd.h>

int main(void)
{
    struct sockaddr_in addr;

    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = htonl(INADDR_ANY);
    addr.sin_port = htons(4000);

    Server server(parseConfig(configPath), addr);

    server.InitServer(addr);
    // pid_t pid = fork();
    // fork();
    server.WaitingForAccept();

    return 0;
}
