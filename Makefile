#CFLAGS = -I ./include
#OBJ_DIR = ./obj
#SRC_DIR = ./src
#
#$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
#	$(CC) -c -o $@ $< $(CFLAGS)
#
#privateim: $(OBJ_DIR)/privateim.o $(OBJ_DIR)/helpers.o
#	$(CC) -o $@ $<

INC_DIR = ./include
OBJ_DIR = ./obj
SRC_DIR = ./src

CFLAGS = -I $(INC_DIR)

OBJS = $(OBJ_DIR)/privateim.o $(OBJ_DIR)/helpers.o

privateim: $(OBJS)
	$(CC) -o $@ $< $(CFLAGS)

$(OBJ_DIR)/privateim.o: $(SRC_DIR)/privateim.c $(INC_DIR)/privateim.h
	$(CC) -c -o $(OBJ_DIR)/privateim.o $(SRC_DIR)/privateim.c $(CFLAGS)

$(OBJ_DIR)/helpers.o: $(SRC_DIR)/helpers.c $(INC_DIR)/privateim.h
	$(CC) -c -o $(OBJ_DIR)/helpers.o $(SRC_DIR)/helpers.c $(CFLAGS)
