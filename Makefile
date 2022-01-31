objects = main.o 
cflags = -O2
debugflags = -g
BIN := moonphase
SRCS := *.cpp
DESTDIR := 
PKGNAME := moonphase
PREFIX := /usr/local

all: $(BIN)

$(BIN): $(objects)
	g++ -o $(BIN) $(objects) $(cflags)

debug: $(objects)
	g++ -Ddeug -o $(BIN) $(objects) $(cflags) $(debugflags)

$(objects): $(SRCS)

test: $(BIN)
	./$(BIN)

install: $(BIN)
	install -Dm755 ${BIN} $(DESTDIR)$(PREFIX)/bin/${BIN}

.PHONY: clean check tags
clean:
	-rm ./$(BIN) $(objects) .tags
