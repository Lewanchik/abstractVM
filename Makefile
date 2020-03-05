NAME = avm

CC = clang++

CFLAGS = -Wall -Wextra -Werror -std=c++1y

HEADERS := classes/AbstractVM.hpp \
           classes/Calculator.hpp \
           classes/Exceptions.hpp \
           classes/IOperand.hpp \
           classes/Lexer.hpp \
           classes/Number.hpp \
           classes/Operand.hpp \
           classes/OperandFactory.hpp \
           classes/Parser.hpp \
           classes/Sign.hpp \
           classes/SignOrNumber.hpp \
           classes/VMLogic.hpp

SRC_FILES = classes/main.cpp \
            classes/Calculator.cpp \
            classes/Number.cpp \
            classes/AbstractVM.cpp \
            classes/Exceptions.cpp \
            classes/Lexer.cpp \
            classes/Operand.cpp \
            classes/OperandFactory.cpp \
            classes/Parser.cpp \
            classes/Sign.cpp \
            classes/VMLogic.cpp

SRC_OBJ =  $(SRC_FILES:.cpp=.o)

all: $(NAME)

$(NAME): $(SRC_OBJ)
	$(CC) $(CFLAGS) $(SRC_OBJ) -o $(NAME)

%.o: %.cpp $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(SRC_OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all