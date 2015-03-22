CFLAGS = -I ./include
OBJ_DIR = ./obj
SRC_DIR = ./src

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) -c -o $@ $< $(CFLAGS)

privateim: $(OBJ_DIR)/privateim.o $(OBJ_DIR)/helpers.o
	$(CC) -o $@ $<