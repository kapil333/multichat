#ifndef _server_h_
#define _server_h_

#include <iostream>

#include "mythread.h"

using namespace std;

class Server {
  public:
    MyThread *t;

  public:
    Server();
    static void * printThread(void *args);
};

#endif
