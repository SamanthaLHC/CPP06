NAME = cast

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -Wconversion -g3 -std=c++98

SRC = ./main.cpp

OBJ = $(SRC:%.cpp=%.o)

all: $(NAME)

${NAME}: ${OBJ}
	${CXX} ${CXXFLAGS} ${OBJ} -o ${NAME}

clean:
	rm -rf ${OBJ}

fclean: clean
	rm -rf ${NAME}

re : fclean
	make all

grind: ${NAME}
		valgrind ./$(NAME)

.PHONY: clean fclean re grind test