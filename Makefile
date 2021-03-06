##
## Makefile for OpenGL Shadering in /home/bonnet_v/programs/tests/shaders
## 
## Made by Bonnet Vivien
## Login   <bonnet_v@epitech.net>
## 
## Started on  Wed Apr  2 09:29:38 2014 Bonnet Vivien
## Last Update Tue Jun  9 13:19:31 2015 Aracthor
##

CXX=		g++

RM=		rm -f



BIN_DIR=	bin/
SRCS_DIR=	srcs/
INC_DIR=	inc/
OBJS_DIR=	objs/

NAME=		rm
BINARY=		$(BIN_DIR)$(NAME)

SRC=		ArgumentException.cpp	\
		BooleanOption.cpp	\
		HelpOption.cpp		\
		ListShellCommand.cpp	\
		OptionParser.cpp	\
		RM.cpp			\
		ShellCommand.cpp	\
		main.cpp

SRCS=		$(SRC:%.cpp=$(SRCS_DIR)%.cpp)

OBJS=		$(SRCS:$(SRCS_DIR)%.cpp=$(OBJS_DIR)%.o)


CXXFLAGS=	-Wall -Wextra -Werror	\
		-ansi -pedantic		\
		-I $(INC_DIR)		\
		-O2

LIBS=

LDFLAGS=	$(LIBS:%=-l%)	\
		-o $(BINARY)



$(BINARY):	$(OBJS)
		$(CXX) $(OBJS) $(LDFLAGS)

$(OBJS_DIR)%.o:	$(SRCS_DIR)%.cpp
		$(CXX) $(CXXFLAGS) -c $< -o $@

all:		$(BINARY)

clean:
		$(RM) $(OBJS)

fclean:		clean
		$(RM) $(BINARY)

re:		fclean all
