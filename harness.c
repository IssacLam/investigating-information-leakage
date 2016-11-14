#include <s2n.h>
#include "tls/s2n_connection.h"

int main() {
  struct s2n_connection c_1, c_2;
  ssize_t size;
  char *buf;
  s2n_blocked_status *blocked_1, *blocked_2;

  // assume the connection with an empty buffer and is not closed.
  __CPROVER_assume(c_1.out.blob.data[0] == 0);
  __CPROVER_assume(c_1.closed != 0);

  // assume the connections of two runs are the same state
  __CPROVER_assume(c_1 == c_2);
  __CPROVER_assume(*blocked_1 == *blocked_2);

  // the trivial observable is that two run should send the same size of msg.
  size_t o_1, o_2;
  o_1 = s2n_send(&c_1, buf, size, blocked_1);
  o_2 = s2n_send(&c_2, buf, size, blocked_2);

  assert(o_1 == o_2);

  // check whether the buffer is sanitised after the msg is sent.
  int i;
  //if(i >= 0 && i < c_1.writefd)
	assert((c_1.out.blob.data)[0] == 0);

  return 0;
};
