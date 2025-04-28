CXX = g++-14
CXXFLAGS = -Wall -Wextra -Werror -std=c++98
NAME = Zombie
SRCS = main.cpp zombieHord.cpp Zombie.cpp
OBJS = $(SRCS:.cpp=.o)
GREEN = \033[0;32m
RESET = \033[0m

all: $(NAME)

$(NAME): $(OBJS)
	@echo "$(GREEN)[Compiling project...]$(RESET)"
	@$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJS)

%.o: %.cpp
	@$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	@rm -f $(OBJS)

fclean: clean
	@rm -f $(OBJS)
	@rm -f $(NAME)

re: fclean all

run: all
	@./$(NAME)

.PHONY: all clean fclean re