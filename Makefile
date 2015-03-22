ifeq ($(.CURDIR),)
	.CURDIR = .
endif

INC_DIR = $(.CURDIR)/include
OBJ_DIR = $(.CURDIR)/obj
SRC_DIR = $(.CURDIR)/src

CFLAGS = -I $(INC_DIR)

OBJS = $(OBJ_DIR)/privateim.o $(OBJ_DIR)/helpers.o

$(.CURDIR)/privateim: $(OBJS)
	$(CC) -o $(.CURDIR)/privateim $(OBJS) $(CFLAGS)

$(OBJ_DIR)/privateim.o: $(SRC_DIR)/privateim.c $(INC_DIR)/privateim.h
	$(CC) -c -o $(OBJ_DIR)/privateim.o $(SRC_DIR)/privateim.c $(CFLAGS)

$(OBJ_DIR)/helpers.o: $(SRC_DIR)/helpers.c $(INC_DIR)/helpers.h
	$(CC) -c -o $(OBJ_DIR)/helpers.o $(SRC_DIR)/helpers.c $(CFLAGS)

clean:
	rm -f $(OBJ_DIR)/*.o $(.CURDIR)/privateim
