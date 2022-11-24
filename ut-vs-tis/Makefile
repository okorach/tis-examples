SHELL := /bin/bash

FONT_BOLD := `tput bold`
FONT_CYAN := `tput setaf 6`
FONT_RED := `tput setaf 1`
FONT_RESET := `tput sgr0`

TIS_ANALYZER := tis-analyzer
TARGET := increment
FILES := test_driver.c increment.c
COMPILER := gcc
TIS_OPTS = -tis-config-load trustinsoft/tis.json -tis-report

.PHONY: ut clean tis tis_gui report break_build

ut:
	$(COMPILER) -Wno-unused-value -I. $(FILES) -o $(TARGET) && ./$(TARGET)

ut-debug:
	$(COMPILER) -Wno-unused-value -DDEBUG -I. $(FILES) -o $(TARGET) && ./$(TARGET)

tis-short:
	$(TIS_ANALYZER) $(TIS_OPTS) -tis-config-select-by-name "increment short"

tis-int:
	$(TIS_ANALYZER) $(TIS_OPTS) -tis-config-select-by-name "increment int"

tis-generalized:
	@$(TIS_ANALYZER) $(TIS_OPTS) -tis-config-select-by-name "increment int generalized"

tis-array:
	@echo -e "$(FONT_CYAN)$(TIS_ANALYZER) $(TIS_OPTS)$(FONT_RESET)"
	@$(TIS_ANALYZER) $(TIS_OPTS) -tis-config-select-by-name "increment array"

tis-1-gui:
	@echo -e "$(FONT_CYAN)$(TIS_ANALYZER) $(TIS_OPTS) -gui$(FONT_RESET)"
	@$(TIS_ANALYZER) $(TIS_OPTS) -tis-config-select-by-name "increment int" -gui | sed '/stack:.*test_driver.c/q'

tis-2-gui:
	@echo -e "$(FONT_CYAN)$(TIS_ANALYZER) $(TIS_OPTS) -gui$(FONT_RESET)"
	@$(TIS_ANALYZER) $(TIS_OPTS) -tis-config-select-by-name "increment array" -gui | sed '/stack:.*test_driver.c/q'

report:
	@printf "Compiling report from past executed tests:\n"
	@rm -f _results/analysis-*.json
	@ls _results/*.json | sed 's/_results\.json//'
	@tis-report _results/
	@printf "\n\nCheck generated test report $(FONT_CYAN)tis_report.html$(FONT_RESET)\n\n"

break_build:
	@! cat _results/*_results.json|jq '{status: .alarms.status}'|grep -H '"status": "NOT OK"'

clean:
	@rm -rf a.out a.out.dSYM $(TARGET) $(TARGET).dSYM *.gcov *.gcda *.gcno _results tis_report.html tis_misra_report *.log */*.log
