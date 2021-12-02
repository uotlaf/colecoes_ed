CC = gcc

CFLAGS = -c -fdiagnostics-color=always -g

INCLUDE	= ./include
SOURCE 	= ./src
OUT 	= ./out
BUILD	= ./build
BUILD_DIR= $(BUILD)/debug

defaults: debug

debug: out build_debug colecao compara main linkar

out:
	@rm -rf $(OUT)
	mkdir -p $(OUT)

build_debug:
	@rm -rf $(BUILD)
	@mkdir -p $(BUILD_DIR)

colecao: $(SOURCE)/colecao.c $(INCLUDE)/colecao.h
	$(CC) -o $(OUT)/colecao.o -I $(INCLUDE) $(CFLAGS) $(SOURCE)/colecao.c

compara: $(SOURCE)/compara.c $(INCLUDE)/compara.h
	$(CC) -o $(OUT)/compara.o -I $(INCLUDE) $(CFLAGS) $(SOURCE)/compara.c

main: $(SOURCE)/main.c
	$(CC) -o $(OUT)/main.o -I $(INCLUDE) $(CFLAGS) $(SOURCE)/main.c

linkar: $(OUT)
	$(CC) -o $(BUILD_DIR)/main $(OUT)/*