NAME = materia

CXX = c++

CXXFLAGS = -Wall -Wextra -Werror -std=c++98

SRC = AMateria.cpp Cure.cpp Ice.cpp main.cpp MateriaSource.cpp Character.cpp 

OBJ = $(SRC:%.cpp=%.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)

clean:
	rm $(OBJ)

fclean: clean
	rm $(NAME)

re: fclean all
