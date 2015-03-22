CFLAGS = -I ./include

./obj/%.o: ./src/%.c
	$(CC) -c -o $@ $< $(CFLAGS)

privateim: ./obj/privateim.o ./obj/helpers.o
	$(CC) -o privateim ./obj/privateim.o ./obj/helpers.o