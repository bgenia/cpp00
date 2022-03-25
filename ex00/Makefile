NAME := ex00

$(info $(SHELL))

SRC_DIR := .
OBJ_DIR := build/obj

SRC := $(shell find . -type f -name '*.cpp')
OBJ := $(SRC:$(SRC_DIR)/%.cpp=$(OBJ_DIR)/%.o)

CXXFLAGS := -Wall -Werror -Wextra -std=c++98

.PHONY: all
all: $(NAME)

$(NAME): $(OBJ)
	$(LINK.cpp) $^ $(LDLIBS) -o $@

$(OBJ_DIR)/%.o: %.cpp
	$(COMPILE.cpp) $< -o $@

%.o: | $(OBJ_DIR)

$(OBJ_DIR):
	mkdir -p $@

.PHONY: clean
clean:
	$(RM) $(OBJ)

.PHONY: fclean
fclean: clean
	$(RM) $(NAME)

.PHONY: re
re: fclean
	$(MAKE)
