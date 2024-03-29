# Project Information and Contact Details
BU_NAME := joyedap1
GITHUB_ID := JosephOyedapo2
COURSE := 320

EXECUTABLE_NAME := predictors$(CP)
TAR_NAME := $(BU_NAME)oyedapo_project1$(CP)
TAR_IGNORES := .vscode spec

# Source File Directory - if none, use .
SOURCES_DIR := .
FILE_EXT := cpp

# Make Run Arguments
RUN_ARGS :traces/long_trace1.txt output.txt

# Compiler Flags - should be fine for most people
CXXFLAGS := -Wall -Wextra -std=c++17 -O3
LDFLAGS :=
LDLIBS :=

#################################################################################################
#                 ***You should not have to edit the makefile past this line.***                #
#################################################################################################

# Debug Flag - hides debugging by default (recommended; use make debug to debug)
DEBUG := -DNDEBUG

# Tar Flags
TAR_IGNORES := --exclude-vcs --exclude-vcs-ignores $(addprefix --exclude=, $(TAR_IGNORES))

# Source Files
SRC_FILES = $(shell find $(SOURCES_DIR)/ -type f -name '*.$(FILE_EXT)')
OBJ_FILES := $(patsubst %.$(FILE_EXT),%.o,$(SRC_FILES))
DEP_FILES := $(patsubst %.$(FILE_EXT),%.d,$(SRC_FILES))


# Makefile Rules
$(EXECUTABLE_NAME): $(OBJ_FILES)
		$(CXX) $(CXXFLAGS) $(LDFLAGS) $^ -o $@ $(LDLIBS)
# Update .gitignore to exclude the executable; ignore if .gitignore is absent
		-sed -i "1c $(EXECUTABLE_NAME)" .gitignore 2> /dev/null

-include $(DEP_FILES)

%.o: %.$(FILE_EXT)
		$(CXX) $(CXXFLAGS) $(LDFLAGS) $(DEBUG) -MMD -MP -c $< -o $@ $(LDLIBS)

all: $(EXECUTABLE_NAME)

debug:
		@$(MAKE) --no-print-directory DEBUG="" rebuild

new: clean run

run: $(EXECUTABLE_NAME)
		./$(EXECUTABLE_NAME) $(RUN_ARGS)

rebuild: clean $(EXECUTABLE_NAME)

tar: clean
		cd .. \
		&& ln -sf $(notdir $(CURDIR)) $(TAR_NAME) \
		&& tar $(TAR_IGNORES) --dereference -cvzf $(TAR_NAME).tar.gz $(TAR_NAME) \
		&& mv $(TAR_NAME).tar.gz $(notdir $(CURDIR))/$(TAR_NAME).tar.gz \
		; rm $(TAR_NAME)
		
clean:
		find . -type f -name '*.o' -delete -o -name '*.d' -delete
		rm -f $(EXECUTABLE_NAME) *.tar.gz
		

.PHONY: $(EXECUTABLE_NAME) all debug run rebuild tar clean