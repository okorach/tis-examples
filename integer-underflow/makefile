SHELL := /bin/bash
FONT_BOLD := `tput bold`
FONT_CYAN := `tput setaf 6`
FONT_RED := `tput setaf 1`
FONT_RESET := `tput sgr0`

CC=gcc
CFLAGS=-I. -fprofile-arcs -ftest-coverage
DEPS = $(wildcard *.h) Makefile
SRC = $(wildcard *.c) 
OBJ = $(SRC:.c=.o)
TARGET = absolute

%.o: %.c $(DEPS)
	@echo "Compiling $(FONT_BOLD)$<$(FONT_RESET)"
	@echo "$(FONT_CYAN)$(CC) -c $< $(CFLAGS)$(FONT_RESET)"
	@$(CC) -c $< $(CFLAGS)

.PHONY: build run cov tis clean all db

cov: run
	@echo ""
	@echo "Running $(FONT_BOLD)gcov$(FONT_RESET) to produce file text coverage"
	@echo "$(FONT_CYAN)gcov $(TARGET).c$(FONT_RESET)"
	@gcov $(TARGET).c

run: $(TARGET)
	@echo ""
	@echo "Running executable $(FONT_BOLD)./$(TARGET)$(FONT_RESET) to produce binary coverage"
	@./$(TARGET)

$(TARGET): $(OBJ)
	@echo ""
	@echo "Linking executable $(FONT_BOLD)./$(TARGET)$(FONT_RESET)"
	@echo "$(FONT_CYAN)$(CC) -o $@ $(OBJ) $(FONT_RESET)"
	@$(CC) -o $@ $(CFLAGS) $(OBJ)

tis: db
	@echo ""
	@echo "Running $(FONT_BOLD)tis-analyzer$(FONT_RESET) in batch mode"
	@echo "$(FONT_RED)tis-analyzer -tis-config-load tis-config.json $(TIS_OPTS) absolute.c main.c$(FONT_RESET)"
	@tis-analyzer -tis-config-load tis-config.json -val absolute.c main.c

tis_gui:
	@echo ""
	@echo "Running $(FONT_BOLD)tis-analyzer$(FONT_RESET) in interactive mode"
	@echo "$(FONT_RED)tis-analyzer -tis-config-load tis-config.json $(TIS_OPTS) absolute.c main.c -gui$(FONT_RESET)"
	@tis-analyzer -tis-config-load tis-config.json -val absolute.c main.c -gui

clean:
	rm -rf $(TARGET) *.gcov *.gcda *.gcno *.o compile_commands.json

# db: $(SRC) compile_commands.json
# 	@rm $(OBJ)
# 	@echo "Building compilation database with $(FONT_BOLD)bear$(FONT_RESET)"
# 	@echo "$(FONT_CYAN)bear make test$(FONT_RESET)"
# 	@bear make test
# 	@rm -rf a.out a.out.dSYM *.gcov *.gcda *.gcno *.o compile_commands.json
