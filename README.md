multichat - a simple linux multiclient and multithreaded socket server in C++
=============================================================================

Description
-----------

multichat uses BSD TCP sockets and libpthread to handle new connections. In the main loop, it keeps listening
for new connections, and when a new client arrives, a new thread is created, which receives messages from
this client and repasses this message to all connected clients. 

The main loop is simply:

```
  while(1) {

    c = new Client();
    t = new MyThread();

    //Blocks here;
    c->sock = accept(serverSock, (struct sockaddr *) &clientAddr, &cliSize);

    if(c->sock < 0) {
      cerr << "Error on accept";
    }
    else {
      t->Create((void *) Server::HandleClient, c);
    }
  }
```

This kind of behavior may be useful, because we can use the blocking nature from accept() and from each
client's recv() to keep each thread blocked and leave the scheduling of these threads to the OS.
One downside of this approach is that we must be extra careful with shared variables, since several threads
may be trying to access them 'simultaneously'. To prevent concurrency problems, a simple mutex is responsible
for granting/denying access to shared resources, as in Server::SendToAll() function:

```
  //Acquire the lock - Blocks here until the lock is acquired
  MyThread::LockMutex("'SendToAll()'");

    for(size_t i=0; i<clients.size(); i++) {
      n = send(Server::clients[i].sock, message, strlen(message), 0);
      cout << n << " bytes sent." << endl;
    }
   
  //Release the lock
  MyThread::UnlockMutex("'SendToAll()'");
```

Usage
-----

### Compile and run

```
> $ make
g++ -Wall -g  -c src/main.cpp -o obj/main.o
g++ -Wall -g  -c src/mythread.cpp -o obj/mythread.o
g++ -Wall -g  -c src/server.cpp -o obj/server.o
g++ -Wall -g  -c src/client.cpp -o obj/client.o
g++ -Wall -g -lpthread -o ./bin/chat ./obj/main.o ./obj/mythread.o ./obj/server.o ./obj/client.o

> $ ./bin/chat 
Running!
Mutex initialized.
```

### Connecting clients. For example, using telnet and using netcat:

* telnet:

```
> $ telnet 127.0.0.1 30666
Trying 127.0.0.1...
Connected to 127.0.0.1.
Escape character is '^]'.
Hello from telnet!
<Client n.0>: Hello from telnet!
<Client n.1>: Hello from netcat!
```

* netcat:

```
> $ netcat 127.0.0.1 30666
<Client n.0>: Hello from telnet!
Hello from netcat!
<Client n.1>: Hello from netcat!
```

License
-------

This software is released with no warranties and is under public domain.
