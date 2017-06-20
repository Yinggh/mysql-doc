CC=gcc
AFLAGS=-Wall -g
LDFLAGS= -lmysqlclient
OBJS= add.cgi del.cgi mod.cgi sel.cgi

all:$(OBJS)

$(OBJS):%.cgi:%.c
	$(CC) $(AFLAGS) $< cgic.c -o $@ $(LDFLAGS)

.PHONY:clean
clean:
	rm ./*.cgi
install:
		cp *.cgi /usr/lib/cgi-bin/sx


		sudo mkdir /usr/lib/cgi-bin/sx
		sudo chmod 777 /usr/lib/cgi-bin/sx
