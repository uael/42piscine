STD  := c++98
CXX  := clang++ -std=$(STD)
LDXX := clang++ -std=$(STD)
RM   := rm -rf

BUILD  = build
CFLAGS = -Wall -Werror -Wextra

NAME = ex00

SRC = whatever.cpp

V ?= @

all: $(NAME)

$(BUILD)/%.o: %.cpp
	@echo "  CXX     $(notdir $<)"
	@mkdir -p $(dir $@)
	$(V)$(CXX) $< -c $(CFLAGS) $(addprefix -I,$(INC)) \
		$(addprefix -D,$(DEF)) -MMD -MF $(@:.o=.d) -o $@

$(NAME): $(SRC:%.cpp=$(BUILD)/%.o)
	@echo "  LDXX    $(notdir $@)"
	$(V)$(LDXX) $^ $(LDFLAGS) $(addprefix -l,$(LDLIBS)) -o $@

clean:
	@$(RM) $(BUILD)

fclean: clean
	@$(RM) $(NAME)

re: fclean all
