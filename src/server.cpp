#include "server.h"

using namespace std;

static void *test(void *args) {
  while(1) {
  	cout << "Inside function: ";
        if(args) cout << (char *) args;
        cout << endl;
        sleep(1);
  }
  return NULL;
}

Server::Server() {
  this->t = new MyThread();
  this->t->Create((void *) Server::printThread, NULL);

  //this->t->Create((void *)test, NULL);

/*
  int t2ret;

  pthread_t t1;

  t2ret = pthread_create(&t1, NULL, &Server::printThread, NULL);

  pthread_join(t1, NULL);
*/

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
