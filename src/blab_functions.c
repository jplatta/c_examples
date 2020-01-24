#include <sys/socket.h>
#include <arpa/inet.h>
#include <stdio.h>

int create_socket()
{
  int listener_d = socket(PF_INET, SOCK_STREAM, 0);
  return listener_d;
}

struct sockaddr_in create_socket_name(int port_num)
{
  struct sockaddr_in sock_name;
  sock_name.sin_family = PF_INET;
  sock_name.sin_port = (in_port_t)htons(port_num);
  sock_name.sin_addr.s_addr = htonl(INADDR_ANY);
  return sock_name;
}

int bind_to_port(int sock_descriptor, struct sockaddr_in *sock_name)
{
  struct sockaddr_in sname = *sock_name;

  int connection = bind(sock_descriptor, (struct sockaddr *) &sname, sizeof(sname));

  return connection;
}

int listen_for_connections(int sock_descriptor, int queue_length)
{
  return listen(sock_descriptor, queue_length);
}

int accept_connections(int sock_descriptor)
{
  struct sockaddr_storage client_addr;
  unsigned int address_size = sizeof(client_addr);
  int connect_desc = accept(sock_descriptor, (struct sockaddr *) &client_addr, &address_size);

  return connect_desc;
}

int set_default_socket_options(int socket_descriptor)
{
  int reuse = 1;
  return setsockopt(socket_descriptor, SOL_SOCKET, SO_REUSEADDR, (char *) &reuse, sizeof(int));
}
