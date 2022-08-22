SHELL := /bin/bash
FONT_BOLD := `tput bold`
FONT_CYAN := `tput setaf 6`
FONT_RED := `tput setaf 1`
FONT_RESET := `tput sgr0`

.PHONY: build build_cov run cov tis clean all db

build: 
	@echo "$(FONT_CYAN)gcc -I. caesar.c main.c$(FONT_RESET)"
	@gcc -I. caesar.c main.c

build_cov:
	@echo "Building with coverage instrumentation $(FONT_BOLD)gcov$(FONT_RESET)"
	@echo "$(FONT_CYAN) gcc -I. -fprofile-arcs -ftest-coverage caesar.c main.c$(FONT_RESET)"
	@gcc -I. -fprofile-arcs -ftest-coverage caesar.c main.c

run: build
	@echo "$(FONT_CYAN)./a.out$(FONT_RESET)"
	@./a.out

cov: clean build_cov
	@echo "Running coverage with $(FONT_BOLD)gcov$(FONT_RESET)"
	@echo "$(FONT_CYAN)./a.out$(FONT_RESET)"
	@./a.out >/dev/null
	@echo "$(FONT_CYAN)gcov caesar.c$(FONT_RESET)"
	@gcov caesar.c

db:
	@echo "Building compilation database with $(FONT_BOLD)bear$(FONT_RESET)"
	@echo "$(FONT_CYAN)bear make$(FONT_RESET)"
	@bear make build

tis: db
	@echo ""
	@echo "Running $(FONT_BOLD)tis-analyzer$(FONT_RESET) in batch mode"
	@echo "$(FONT_RED)tis-analyzer -tis-config-load tis-config.json $(TIS_OPTS) caesar.c main.c$(FONT_RESET)"
	@tis-analyzer -tis-config-load tis-config.json -val caesar.c main.c

tis_gui:
	@echo ""
	@echo "Running $(FONT_BOLD)tis-analyzer$(FONT_RESET) in interactive mode"
	@echo "$(FONT_RED)tis-analyzer -tis-config-load tis-config.json $(TIS_OPTS) caesar.c main.c -gui$(FONT_RESET)"
	@tis-analyzer -tis-config-load tis-config.json -val caesar.c main.c -gui

clean:
	rm -rf a.out a.out.dSYM *.gcov *.gcda *.gcno compile_commands.json

all: run
