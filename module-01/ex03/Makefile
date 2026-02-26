NAME		=	./exe

CXX			=	g++
CXXFLAGS	=	-std=c++98 -Wall -Wextra -Werror #-g3

SRCS		=	./main.cpp\
				./HumanA.cpp\
				./HumanB.cpp\
				./Weapon.cpp

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