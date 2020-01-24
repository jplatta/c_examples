#include "unity/unity.h"
#include "../src/blab_functions.h"
#include <sys/socket.h>
#include <arpa/inet.h>

void setUp(void){}

void tearDown(void){}

static void test_create_socket_without_error(void)
{
  int result = create_socket();
  TEST_ASSERT_GREATER_THAN( -1, result);
}

static void test_create_socket_name_without_error(void)
{
  struct sockaddr_in expected;
  expected.sin_family = PF_INET;
  expected.sin_port = (in_port_t)htons(1234);
  expected.sin_addr.s_addr = htonl(INADDR_ANY);

  struct sockaddr_in actual = create_socket_name(1234);

  TEST_ASSERT_EQUAL(expected.sin_family, actual.sin_family);
  TEST_ASSERT_EQUAL(expected.sin_port, actual.sin_port);
  TEST_ASSERT_EQUAL(expected.sin_addr.s_addr, actual.sin_addr.s_addr);
}

static void test_bind_to_port_without_error(void)
{
  struct sockaddr_in sock_name;
  sock_name.sin_family = PF_INET;
  sock_name.sin_port = (in_port_t)htons(1234);
  sock_name.sin_addr.s_addr = htonl(INADDR_ANY);

  int sock_desc = socket(PF_INET, SOCK_STREAM, 0);

  int result = bind_to_port(sock_desc, &sock_name);

  TEST_ASSERT_GREATER_THAN(-1, result);
}

static void test_listen_without_error(void)
{
  int queue_length = 10;
  int sock_desc = socket(PF_INET, SOCK_STREAM, 0);

  int result = listen_for_connections(sock_desc, queue_length);

  TEST_ASSERT_GREATER_THAN(-1, result);
}

static void test_accepts_connections_without_error(void)
{
  TEST_IGNORE();

  /* Creat Socket Descriptor */
  int sock_desc = socket(PF_INET, SOCK_STREAM, 0);

  /* Bind Socket to Port */
  struct sockaddr_in name;
  name.sin_family = PF_INET;
  name.sin_port = (in_port_t)htons(30000);
  name.sin_addr.s_addr = htonl(INADDR_ANY);
  int c = bind(sock_desc, (struct sockaddr *) &name, sizeof(name));

  /* Listen for Connections */
  listen(sock_desc, 10);
  
  int result = accept_connections(sock_desc);

  TEST_ASSERT_GREATER_THAN(-1, result);
}

int main(void)
{
  UnityBegin("test/test_blab_functions.c");

  RUN_TEST(test_create_socket_without_error);
  RUN_TEST(test_create_socket_name_without_error);
  RUN_TEST(test_bind_to_port_without_error);
  RUN_TEST(test_listen_without_error);
  RUN_TEST(test_accepts_connections_without_error);

  return UnityEnd();
}

