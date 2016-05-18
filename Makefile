CFLAGS=-c -g
LDFLAGS=-lm

bellman: bellman.o chemin.o graphe.o
	gcc  -o $@ $^ $(LDFLAGS)

all: bellman testgraphe teststation

testgraphe: testgraphe.o graphe.o
	gcc  -o $@ $^ $(LDFLAGS)

teststation: teststation.o chemin.o graphe.o
	gcc  -o $@ $^ $(LDFLAGS)

%.o: %.c
	gcc $(CFLAGS) $<

clean:
	rm *.o bellman testgraphe teststation
