multichat - a simple linux multiclient and multithreaded socket server in C++
=============================================================================

Description
-----------

multichat uses BSD sockets and libpthread to handle new connections. In the main loop, it keeps listening
for new connections, and when a new client arrives, a new thread is created, which receives messages from
this client and repasses this message to all connected clients. 

The main loop is simply:

>  while(1) {
>
>          c = new Client();
>	  t = new MyThread();
>
>	  //Blocks here;
>          c->sock = accept(serverSock, (struct sockaddr *) &clientAddr, &cliSize);
>
>	  if(clientSock < 0) {
>	    cerr << "Error on accept";
>	  }
>	  else {
>	    t->Create((void *) Server::HandleClient, c);
>	  }
>  }

This kind of behavior may be useful, because we can use the blocking nature from accept() and from each
client's recv() to keep each thread blocked and leave the scheduling of these threads to the OS.
One downside of this approach is that we must be extra careful with shared variables, since several threads
may be trying to access them 'simultaneously'. To prevent concurrency problems, a simple mutex is responsible
for granting/denying access to shared resources, as in:


>  //Acquire the lock
>  MyThread::LockMutex("'SendToAll()'");
> 
>    for(size_t i=0; i<clients.size(); i++) {
>      n = send(Server::clients[i].sock, message, strlen(message), 0);
>      cout << n << " bytes sent." << endl;
>    }
>   
>  //Release the lock  
>  MyThread::UnlockMutex("'SendToAll()'");
