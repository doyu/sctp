all: sctp

sctp: sctp.c
	gcc sctp.c -o sctp -Wall

clean:
	rm -rf sctp *~

