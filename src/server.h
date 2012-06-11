#ifndef _server_h_
#define _server_h_

#include <iostream>

#include "mythread.h"

using namespace std;

class Server {
  public:
    MyThread *threads[2];

  public:
    Server();
    static void * printThread(void *args);
};

#endif
