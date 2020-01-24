#ifndef BLAB_FUNCTIONS
#define BLAB_FUNCTIONS

int create_socket();
struct sockaddr_in create_socket_name();
int bind_to_port(int sock_descriptor, struct sockaddr_in *sock_name);
int listen_for_connections(int sock_descriptor, int queue_length);
int accept_connections(int sock_descriptor);
int set_default_socket_options(int socket_descriptor);

#endif
