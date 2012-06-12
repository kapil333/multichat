#include "server.h"

using namespace std;

Server::Server() {

  serverSock = socket(AF_INET, SOCK_STREAM, 0);

  memset(&serverAddr, 0, sizeof(sockaddr_in));

  serverAddr.sin_family = AF_INET;
  serverAddr.sin_addr.s_addr = INADDR_ANY;
  serverAddr.sin_port = htons(PORT);
  
  if(bind(serverSock, (struct sockaddr *) &serverAddr, sizeof(sockaddr_in)) < 0)
    cerr << "Failed to bind";

  listen(serverSock, 5);

  socklen_t cliSize = sizeof(sockaddr_in);
  clientSock = accept(serverSock, (struct sockaddr *) &clientAddr, &cliSize);

  if(clientSock < 0)
    cerr << "Error on accept";

  memset(buff, 0, sizeof buff);

  int n;

  //n = read(clientSock, buff, sizeof buff);
 
  //cout << "read " << n << " bytes: " << buff << endl;


  MyThread *t = new MyThread();

  t->Create((void *) Server::HandleClient, &clientSock);

  //Maybe this is not necessary when the main process wont finish anyway.
  t->Join();

  while(1);
  

  close(clientSock);
  close(serverSock);
 
  /*
  char *m1 = "I'm thread 1";
  char *m2 = "I'm thread 2";

  threads[0] = new MyThread();
  threads[1] = new MyThread();

  //Create threads
  threads[0]->Create((void *) Server::PrintThread, m1);
  threads[1]->Create((void *) Server::PrintThread, m2);

  //Join threads: make process wait for threads' completion
  threads[0]->Join();
  threads[1]->Join();
  */

  //this->ListClients();

}

//Static
void *Server::PrintThread(void *args) {
  while(1) {
  	cout << "Inside function: ";
        if(args) cout << (char *) args;
        cout << endl;
        sleep(1);
  }
  return NULL;
}

//Static
void *Server::HandleClient(void *args) {

  //Get the socket descriptor
  int sock = *(int *) args;
  char buffer[256];
  int n;

  while(1) {
    memset(buffer, 0, sizeof buffer);
    n = read(sock, buffer, sizeof buffer);
    cout << "read " << n << " bytes: " << buffer << endl;
  }
  return NULL;
}

void Server::ListClients() {
  for(size_t i=0; i<clients.size(); i++) {
    cout << clients.at(i).name << endl;
  }
}

/*
void GenerateSampleClients() {
  Client *c;
  for(int i=0; i<100; i++) {
    char *n = (char *) malloc(20);
    sprintf(n, "raphael%d", i);
    c = new Client(n, 23);
    clients.push_back(*c);
    free(n);
  }
}
*/

  /* Iterator
  for(vector<Client>::iterator i = this->clients.begin;
      i < this->clients.end();
      i++) {*/
