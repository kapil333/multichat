#include "mythread.h"

using namespace std;

MyThread::MyThread() {
}

void * MyThread::printThread(void *args) {
  while(1) {
  	cout << "Inside function: ";
        if(args) cout << (char *) args;
        cout << endl;
        sleep(1);
  }
  return NULL;
}

int MyThread::Create(void *Callback, void *args) {
  int tret=0;
 
  //Supercreepy typecast
  tret = pthread_create(&this->tid, NULL, (void *(*)(void *))Callback, args);

  if(tret) { 
    cerr << "Error while creating threads." << endl;
    return tret;
  }
  else {
    cout << "Thread succesfuly created." << endl;

    //Wait until threads return to end main process
    //Fix - This should be called after all threads are created
    //pthread_join(this->tid, NULL);

    return 0;
  }
}

int MyThread::Join() {
  pthread_join(this->tid, NULL);
  return 0;
}
