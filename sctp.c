#include <stdio.h>
#include <stdint.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <linux/sctp.h>
#include <errno.h>
#include <arpa/inet.h>

int main(int argc, char *argv[])
{
	int sock;
	int err;
	struct sockaddr_in6 addr = { .sin6_family = AF_INET6, };

	sock = socket(AF_INET6, SOCK_STREAM, IPPROTO_SCTP);
	inet_pton(AF_INET6, "1200:0000:0000:0000:0000:0000:0000:0001", &addr.sin6_addr);
	err = bind(sock, (struct sockaddr *)&addr, sizeof(addr));
	// #define	EADDRNOTAVAIL	99	/* Cannot assign requested address */
	printf("err=%d errno=%d\n", err, errno);
	return 0;
}

