#include "pidgin/libpurple/protocols/jabber/auth_digest_md5.h"
#include "pidgin/libpurple/protocols/jabber/jabber.h"

int main(){
  char *h1, *h2, *l, *r1, *r2;
  JabberID *jid;
  char *passwd, *nonce, *cnonce, *a2, *realm;

  r1 = generate_response_value(jid, passwd, nonce, cnonce, a2, realm);
  r2 = generate_response_value(jid, passwd, nonce, cnonce, a2, realm);

  for(int i = 0; i < 16; ++i)
    __CPROVER_assert(r1[i] == r2[i], "ERROR: Information Leak");

  return 0;
}
