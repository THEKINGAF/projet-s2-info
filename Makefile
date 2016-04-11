CFLAGS=-c -g
LDFLAGS=-lm

testgraphe: testgraphe.o graphe.o
	gcc  -o $@ $^ $(LDFLAGS)

testchemin: testchemin.o chemin.o graphe.o
	gcc  -o $@ $^ $(LDFLAGS)

%.o: %.c
	gcc $(CFLAGS) $<
