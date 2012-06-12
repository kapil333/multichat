#ifndef _client_h_
#define _client_h_

#include <iostream>
#include <string>

using namespace std;

class Client {
  public:
    string name;
    int id;

    //Socket stuff
    int sock;

  public:
    Client(const char *name, int id);
};

#endif
