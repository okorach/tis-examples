SHELL := /bin/bash

FONT_BOLD := `tput bold`
FONT_CYAN := `tput setaf 6`
FONT_RED := `tput setaf 1`
FONT_RESET := `tput sgr0`

TIS_ANALYZER := tis-analyzer
TARGET := sneaky
FILES := test_driver.c increment.c
COMPILER := gcc
TIS_OPTS = -tis-config-load trustinsoft/tis.json -tis-report

.PHONY: ut clean tis tis_gui report break_build

ut:
	$(COMPILER) -Wno-unused-value -I. $(FILES) -o $(TARGET) && ./$(TARGET)

ut-debug:
	$(COMPILER) -Wno-unused-value -DDEBUG -I. $(FILES) -o $(TARGET).gcc && ./$(TARGET).gcc

ut-clang:
	clang -Wno-unused-value -DDEBUG -I. $(FILES) -o $(TARGET).clang && ./$(TARGET).clang

ut-long-name:
	$(COMPILER) -Wno-unused-value -DDEBUG -DLONG_NAME -I. $(FILES) -o $(TARGET).longname && ./$(TARGET).longname

tis:
	$(TIS_ANALYZER) $(TIS_OPTS)

tis-gui:
	@echo -e "$(FONT_CYAN)$(TIS_ANALYZER) $(TIS_OPTS) -gui$(FONT_RESET)"
	@$(TIS_ANALYZER) $(TIS_OPTS) -gui | sed '/stack:.*test_driver.c/q'

clean:
	@rm -rf sneaky.* $(TARGET) _results *.log */*.log
