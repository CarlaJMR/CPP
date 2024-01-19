NAME = phonebook

FLAGS = -Wall -Wextra -Werror -std=c++98

SRC = main.cpp PhoneBook.cpp

OBJ = $(SRC:%.cpp=%.o)

all: $(NAME)

$(NAME): $(OBJ)
	c++ $(FLAGS) $(OBJ) -o $(NAME)

fclean: clean
	rm $(NAME)

re: fclean all