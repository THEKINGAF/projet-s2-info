CFLAGS=-c -g
LDFLAGS=-lm

testgraphe: testgraphe.o graphe.o
	gcc  -o $@ $^ $(LDFLAGS)

%.o: %.c
	gcc $(CFLAGS) $<
