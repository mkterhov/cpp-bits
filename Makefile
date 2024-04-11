SRC_DIR := src
BIN_DIR := bin
CXX := g++
CXXFLAGS := -Wall -O2

$(shell mkdir -p $(BIN_DIR))

all: compile

compile:
	@$(eval EXEC=$(shell find $(SRC_DIR) -name '*.cpp' | fzf --height 40% --reverse))
	@$(MAKE) $(BIN_DIR)/$(notdir $(EXEC:%.cpp=%))

# Pattern rule for compiling
$(BIN_DIR)/%: $(SRC_DIR)/%.cpp
	@echo "Compiling $<..."
	@$(CXX) $(CXXFLAGS) -o $@ $<

# Clean up binaries
clean:
	@echo "Cleaning up..."
	@rm -rf $(BIN_DIR)/*

run:
	@$(eval EXEC=$(shell find $(BIN_DIR) -type f | fzf --height 40% --reverse))
	@echo "Running $(EXEC)..."
	@./$(EXEC)
