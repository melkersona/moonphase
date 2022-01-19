objects = main.o 
cflags = -pthread
output = output
$(output): $(objects)
	g++ -o $(output) $(objects) $(cflags)

debug: $(objects)
	g++ -Ddeug -o $(output) $(objects) $(cflags) -g

$(objects):

test: $(output)
	./$(output)

.PHONY: clean
clean:
	-rm ./$(output) $(objects)
