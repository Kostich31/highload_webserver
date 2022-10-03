#include <iostream>
#include <string>
#include "server.h"
#include "utils.h"


int main(void)
{
    struct sockaddr_in addr;

	addr.sin_family = AF_INET; 
    addr.sin_addr.s_addr = htonl(INADDR_ANY);
    addr.sin_port = htons(4000);

    Server server(parseConfig(configPath));

    if (server.InitServer(addr) < 0) {
        std::cerr << "[ERROR] Error while init server" << std::endl;
        exit(-1);
    };
    server.WaitingForAccept();
    

    return 0;
}