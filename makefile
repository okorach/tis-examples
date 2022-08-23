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
SUBDIRS := `ls -d -- */`

TARGET = "a.out"
CC = gcc
CFLAGS=-I. -I./integer-underflow -I./buffer-overflow -fprofile-arcs -ftest-coverage
DEPS = $(wildcard */*.h) makefile

SRC = $(wildcard */*.c) $(wildcard *.c) 
UNDER_TEST_SRC = $(filter-out $(wildcard */test_*.c) $(wildcard */main.c) main.c,$(SRC))
GCOV_FILES = $(UNDER_TEST_SRC:.c=.c.gcov)
ALL_OBJ = $(SRC:.c=.o)
OBJ = $(filter-out $(wildcard */main.o),$(ALL_OBJ))

.PHONY: all $(SUBDIRS) link run cov tis clean all

all: $(SUBDIRS) cov

integer-underflow:
	cd integer-underflow; make; cd -

buffer-overflow:
	cd buffer-overflow; make; cd -

#---------------------------- Standard directives -----------------------------

cov: run
	@echo ""
	@echo "$(FONT_RED)Running $(FONT_BOLD)gcov$(FONT_RESET) to produce file text coverage$(FONT_RESET)"

run: $(TARGET)
	@echo ""
	@echo "$(FONT_RED)Running executable $(FONT_BOLD)./$(TARGET)$(FONT_RESET) to produce binary coverage$(FONT_RESET)"
	@./$(TARGET)

clean:
	cd integer-underflow; make clean; cd -
	cd buffer-overflow; make clean; cd -
	rm -rf $(TARGET) *.gcov *.gcda *.gcno *.o compile_commands.json

$(TARGET): $(OBJ)
	@echo "$(FONT_CYAN)$(CC) -o $@ $(OBJ) $(FONT_RESET)"
	@$(CC) -o $@ $(CFLAGS) $(OBJ)

# %.o: %.c $(DEPS)
# 	@echo "Compiling $(FONT_BOLD)$<$(FONT_RESET)"
# 	@echo "$(FONT_CYAN)$(CC) -c $< $(CFLAGS)$(FONT_RESET)"
# 	@$(CC) -c $< $(CFLAGS)

%.c.gcov: %.c
	@echo "$(FONT_CYAN)gcov $<$(FONT_RESET)"
	@gcov $<
