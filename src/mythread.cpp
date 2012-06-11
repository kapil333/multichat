#include "mythread.h"

MyThread::MyThread() {
  this->name = (char *) malloc(200*sizeof(int));
  sprintf(this->name, "%s", "meu nome é raphael");
  cout << this->name << endl;
}
