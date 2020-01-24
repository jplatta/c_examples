#include "./blab_functions.h"
#include <string.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

int main(int argc, char *argv[])
{
  char *advice[] = {
    "\nTake smaller bites\r\n",
    "\nWatch the corners rookie\r\n",
    "\nOne word: inappropriate\r\n"
  }; 

  int listener_socket = create_socket();
  struct sockaddr_in listener_address = create_socket_name(30000);

  /* blab_functions.h */
  set_default_socket_options(listener_socket);
  bind_to_port(listener_socket, &listener_address); 
  listen_for_connections(listener_socket, 10);
  
  puts("Waiting for connections");

  while(1)
  {
    int connect_d = accept_connections(listener_socket);

    char *msg = advice[rand() % 3];

    send(connect_d, msg, strlen(msg), 0);
    close(connect_d);
  }

  return 0;
}
