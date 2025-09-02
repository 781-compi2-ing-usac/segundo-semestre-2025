SRC     := src
BUILD   := build

CC      := gcc
BISON   := bison
FLEX    := flex
CFLAGS  := -I$(SRC) -Wall -Wextra
RM      := rm -rf $(BUILD)
MKDIR   := mkdir -p $(BUILD)

.DEFAULT_GOAL := all

# Buscar todos los .c en src (excepto parser.y y lexer.l)
SRC_FILES := $(shell find $(SRC) -name '*.c')

# Archivos generados por Bison y Flex
BISON_C := $(BUILD)/parser.tab.c
BISON_H := $(BUILD)/parser.tab.h
LEX_C   := $(BUILD)/lex.yy.c

# Objetos finales
OBJ_SRC := $(patsubst $(SRC)/%.c,$(BUILD)/%.o,$(SRC_FILES))
OBJ_GEN := $(BUILD)/parser.tab.o $(BUILD)/lex.yy.o
OBJ_ALL := $(OBJ_SRC) $(OBJ_GEN)

all: $(BUILD)/calc

$(BUILD):
	$(MKDIR)

# Generar parser
$(BISON_C) $(BISON_H) $(BUILD)/parser.output: $(SRC)/entriesTools/parser.y | $(BUILD)
	$(BISON) -d -v --locations -o $(BISON_C) $<

# Generar lexer
$(LEX_C): $(SRC)/entriesTools/lexer.l $(BISON_H) | $(BUILD)
	$(FLEX) -o $@ $<

# Compilar .c de src a .o
$(BUILD)/%.o: $(SRC)/%.c | $(BUILD)
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

# Compilar .c generados por Bison/Flex a .o
$(BUILD)/parser.tab.o: $(BISON_C) $(BISON_H)
	$(CC) $(CFLAGS) -c $(BISON_C) -o $@

$(BUILD)/lex.yy.o: $(LEX_C)
	$(CC) $(CFLAGS) -c $(LEX_C) -o $@

# Enlazar todo
$(BUILD)/calc: $(OBJ_ALL)
	$(CC) $(CFLAGS) -o $@ $^

clean:
	$(RM)

.PHONY: all clean
