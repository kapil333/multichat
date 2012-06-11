#include "mythread.h"

using namespace std;

MyThread::MyThread() {
/*
  int t1ret, t2ret;
 
  t1ret = pthread_create(&this->threads[1], NULL, &MyThread::printThread, NULL);
  t2ret = pthread_create(&this->threads[1], NULL, &MyThread::printThread, NULL);

  if(t1ret || t2ret) cerr << "Error while creatint threads." << endl;
  else {
    cerr << "Fine." << endl;
    //Wait until threads return
    pthread_join(threads[1], NULL);
    pthread_join(threads[0], NULL);
  }
*/
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
 
  //tret = pthread_create(&this->tid, NULL, (void *)&Callback, NULL);
  tret = pthread_create(&this->tid, NULL, (void *(*)(void *))Callback, NULL);

  if(tret) { 
    cerr << "Error while creating threads." << endl;
    return tret;
  }
  else {
    cout << "Thread succesfuly created." << endl;

    //Wait until threads return to end main process
    pthread_join(this->tid, NULL);

    return 0;
  }
}
