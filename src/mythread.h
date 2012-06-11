#ifndef _mythread_h_
#define _mythread_h_

#include <iostream>
#include <string>
#include <pthread.h>
#include <unistd.h>

using namespace std;

class MyThread {
  public:
    pthread_t tid;

  private:

  public:
    MyThread();
    int Create(void *Callback, void *args);
    int Join();

  private:
    static void *printThread(void *args);
};

#endif
