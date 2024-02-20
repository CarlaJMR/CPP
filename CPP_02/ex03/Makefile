NAME = bsp

FLAGS = -Wall -Wextra -Werror -std=c++98

SRC = main.cpp Fixed.cpp Point.cpp bsp.cpp

OBJ = $(SRC:%.cpp=%.o)

all: $(NAME)

$(NAME): $(OBJ)
	c++ $(FLAGS) $(OBJ) -o $(NAME)

clean:
	rm $(OBJ)

fclean: clean
	rm $(NAME)

re: fclean all
