CXX = g++-14
CXXFLAGS = -Wall -Wextra -Werror -std=c++98
NAME = PhoneBook
SRCS = MyAwsonePhoneBook.cpp PhoneBook.class.cpp Contact.class.cpp
OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(OBJS)
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
