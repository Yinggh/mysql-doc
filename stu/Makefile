CC=gcc
AFLAGS=-Wall -g
LDFLAGS= -lmysqlclient
OBJS= add.cgi del.cgi mod.cgi sel.cgi add-c.cgi add-s.cgi sel-s.cgi del-s.cgi sel-c.cgi del1.cgi

all:$(OBJS)

$(OBJS):%.cgi:%.c
	$(CC) $(AFLAGS) $< cgic.c -o $@ $(LDFLAGS)

.PHONY:clean
clean:
	rm ./*.cgi
install:
		cp *.cgi /usr/lib/cgi-bin/sx/
		cp head.html footer.html /usr/lib/cgi-bin/sx/
		sudo cp index.html /var/www/html/
