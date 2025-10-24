#CXX = g++-14 
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98
NAME = Bureaucrat
SRCS = main.cpp Bureaucrat.cpp AForm.cpp ShrubberyCreationForm.cpp RobotomyRequestForm.cpp
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
	@rm -f *_shrubbery

re: fclean all

run: all
	@./$(NAME)

leaks: all
#	@echo "$(GREEN)[Checking for memory leaks...]$(RESET)"
#	@leaks --atExit -- ./$(NAME) | grep "leaked"

	@echo "$(GREEN)[Checking for memory leaks with Valgrind...]$(RESET)"
	@valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./$(NAME)

.PHONY: all clean fclean re