objects = main.o 
cflags = -O2
BIN := moonphase
DESTDIR := 
PKGNAME := moonphase
PREFIX := /usr/local
$(BIN): $(objects)
	g++ -o $(BIN) $(objects) $(cflags)

debug: $(objects)
	g++ -Ddeug -o $(BIN) $(objects) $(cflags) -g

$(objects):

test: $(BIN)
	./$(BIN)

install: $(BIN)
	install -Dm755 ${BIN} $(DESTDIR)$(PREFIX)/bin/${BIN}

.PHONY: clean check
clean:
	-rm ./$(BIN) $(objects)
