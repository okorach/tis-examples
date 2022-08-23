SHELL := /bin/bash
FONT_BOLD := `tput bold`
FONT_CYAN := `tput setaf 6`
FONT_RED := `tput setaf 1`
FONT_RESET := `tput sgr0`

.PHONY: absolute build build_cov run cov tis clean all db

absolute:
	cd absolute; make clean test; cd -
SHELL := /bin/bash
FONT_BOLD := `tput bold`
FONT_CYAN := `tput setaf 6`
FONT_RED := `tput setaf 1`
FONT_RESET := `tput sgr0`

CC=gcc
CFLAGS=-I. -I./integer-underflow -fprofile-arcs -ftest-coverage
DEPS = $(wildcard */*.h) Makefile
SRC = $(wildcard */*.c) $(wildcard *.c) 
ALL_OBJ = $(SRC:.c=.o)
OBJ = $(filter-out $(wildcard */main.o),$(ALL_OBJ))

.PHONY: all absolute run cov tis clean all db

all: absolute cov

absolute:
	cd integer-underflow; make; cd -

cov: run
	@echo ""
	@echo "Running $(FONT_BOLD)gcov$(FONT_RESET) to produce file text coverage"
	@echo "$(FONT_CYAN)gcov integer-underflow/absolute.c$(FONT_RESET)"
	@gcov integer-underflow/absolute.c

run: test
	@echo ""
	@echo "Running executable $(FONT_BOLD)./test$(FONT_RESET) to produce binary coverage"
	@./test

test: $(OBJ)
	@echo "$(FONT_CYAN)$(CC) -o $@ $(OBJ) $(FONT_RESET)"
	@$(CC) -o $@ $(CFLAGS) $(OBJ)

clean:
	cd integer-underflow; make clean; cd -
	rm -rf test *.gcov *.gcda *.gcno *.o compile_commands.json