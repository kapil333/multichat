#include <iostream>
#include "mythread.h"
#include "server.h"

using namespace std;

int main() {
  cout << "Running!" << endl;

  //MyThread mt;

  Server *s;
  s = new Server();

  //mt = new MyThread();

  return 0;
}
