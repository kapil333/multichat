#include "server.h"

using namespace std;

Server::Server() {
  char *m1 = "I'm thread 1";
  char *m2 = "I'm thread 2";

  threads[0] = new MyThread();
  threads[1] = new MyThread();

  //Create threads
  threads[0]->Create((void *) Server::printThread, m1);
  threads[1]->Create((void *) Server::printThread, m2);

  //Join threads: make process wait for threads' completion
  threads[0]->Join();
  threads[1]->Join();
  
}

void *Server::printThread(void *args) {
  while(1) {
  	cout << "Inside function: ";
        if(args) cout << (char *) args;
        cout << endl;
        sleep(1);
  }
  return NULL;
}
