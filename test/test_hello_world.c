#include "unity/unity.h"
#include "../src/hello_world.h"

void setUp(void)
{
}

void tearDown(void)
{
}

static void test_returns_hello(void)
{
  TEST_ASSERT_EQUAL_STRING("guten tag welt!", hello_world());
}

int main(void)
{
  UnityBegin("test/test_hello_world.c");

  RUN_TEST(test_returns_hello);

  return UnityEnd();
}
