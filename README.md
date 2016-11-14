# investigating-information-leakage

to investigate any security information leakage in Pidgin (libpurple).

CBMC Command:
cbmc -I ./s2n -I ./s2n/api -I ./s2n/libcrypto-build/openssl/include ./harness.c ./s2n/tls/s2n_send.c ./s2n/crypto/s2n_hash.c ./s2n/stuffer/s2n_stuffer.c --unwind 1 > result.txt 2>&1

