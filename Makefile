CC = gcc
FONTES = $(wildcard *.c)
OBJETOS = $(FONTES:.c=.o)
EXECUTAVEL = main
LDFLAGS = -lm

all: $(EXECUTAVEL)

$(EXECUTAVEL): $(OBJETOS)
	@$(CC) -o $@ $^ $(LDFLAGS)

%.o: %.c
	@$(CC) -c $^

clean:
	rm -rf *.o
