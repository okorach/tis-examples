SHELL := /bin/bash
FONT_BOLD := `tput bold`
FONT_CYAN := `tput setaf 6`
FONT_RED := `tput setaf 1`
FONT_RESET := `tput sgr0`

.PHONY: integer-underflow build build_cov run cov tis clean all db

SHELL := /bin/bash
FONT_BOLD := `tput bold`
FONT_CYAN := `tput setaf 6`
FONT_RED := `tput setaf 1`
FONT_RESET := `tput sgr0`

CC=gcc
CFLAGS=-I. -I./integer-underflow -I./buffer-overflow -fprofile-arcs -ftest-coverage
DEPS = $(wildcard */*.h) Makefile
SRC = $(wildcard */*.c) $(wildcard *.c) 
UNDER_TEST_SRC = $(filter-out $(wildcard */test_*.c) $(wildcard */main.c) main.c,$(SRC))
ALL_OBJ = $(SRC:.c=.o)
OBJ = $(filter-out $(wildcard */main.o),$(ALL_OBJ))

.PHONY: all integer-underflow buffer-overflow link run cov tis clean all

all: integer-underflow buffer-overflow cov

integer-underflow:
	cd integer-underflow; make; cd -

buffer-overflow:
	cd buffer-overflow; make; cd -

cov: run
	@echo "UNDER_TEST_SRC = $(UNDER_TEST_SRC)"
	@echo "Running $(FONT_BOLD)gcov$(FONT_RESET) to produce file text coverage"
	@echo "$(FONT_CYAN)gcov integer-underflow/absolute.c$(FONT_RESET)"
	@gcov integer-underflow/absolute.c
	@echo "$(FONT_CYAN)gcov buffer-overflow/caesar.c$(FONT_RESET)"
	@gcov buffer-overflow/caesar.c

run: link
	@echo ""
	@echo "Running executable $(FONT_BOLD)./test$(FONT_RESET) to produce binary coverage"
	@./test

link: $(OBJ)
	@echo "$(FONT_CYAN)$(CC) -o $@ $(OBJ) $(FONT_RESET)"
	@$(CC) -o $@ $(CFLAGS) $(OBJ)

clean:
	cd integer-underflow; make clean; cd -
	cd buffer-overflow; make clean; cd -
	rm -rf test *.gcov *.gcda *.gcno *.o compile_commands.json