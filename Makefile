CC = gcc

CFLAGS = -c -fdiagnostics-color=always -g

INCLUDE	= ./include
SOURCE 	= ./src
OUT 	= ./out
BUILD	= ./build
BUILD_DIR= $(BUILD)/debug

defaults: debug

debug: out build_debug main linkar

out:
	@echo "CFazendo out"
	@rm -rf $(OUT)
	mkdir -p $(OUT)

build_debug:
	@echo "Fazendo build_debug"
	@rm -rf $(BUILD)
	@mkdir -p $(BUILD_DIR)

main: $(SOURCE)/main.c
	@echo "Compilando main.c"
	$(CC) -o $(OUT)/main.o -I $(INCLUDE) $(CFLAGS) $(SOURCE)/main.c

linkar: $(OUT)
	@echo "Ligando os objetos"
	$(CC) -o $(BUILD_DIR)/main $(OUT)/*