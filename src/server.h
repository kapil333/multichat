#ifndef _server_h_
#define _server_h_

#include <iostream>
#include <vector>

#include <cstdio>
#include <cstdlib>
#include <cstring>

#include <sys/socket.h>
#include <netinet/in.h>

#include "mythread.h"
#include "client.h"

#define PORT 30666

using namespace std;

class Server {
  public:
    MyThread *threads[2];
    vector<Client> clients;

    /* Socket stuff */
    int serverSock, clientSock;
    struct sockaddr_in serverAddr, clientAddr;
    char buff[256];

  public:
    Server();
    static void * PrintThread(void *args);
    static void * HandleClient(void *args);
    void ListClients();
};

#endif
