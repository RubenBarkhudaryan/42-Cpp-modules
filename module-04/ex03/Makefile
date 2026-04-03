NAME		=	animal

CXX			=	c++
CXXFLAGS	=	-std=c++98 -Wall -Wextra -Werror #-g3

SRCS		=	./main.cpp\
				./AMatreia.cpp\
				./Ice.cpp\
				./Cure.cpp\
				./Character.cpp\

OBJS		=	$(SRCS:%.cpp=%.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

%.o : %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re