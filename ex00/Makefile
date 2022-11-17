# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hyunkyle <hyunkyle@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/06 10:50:54 by hyunkyle          #+#    #+#              #
#    Updated: 2022/11/15 20:45:54 by hyunkyle         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	= $(wildcard *.cpp)
HEADER = $(wildcard *.hpp)

OBJS=${SRCS:.cpp=.o}

COMFILE_FLAGS = c++ -Wall -Wextra -Werror -std=c++98
LINLING_FLAG = c++ -Wall -Wextra -Werror -std=c++98

NAME = megaphone

$(NAME)	: $(OBJS)
	$(COMFILE_FLAGS) -o $(NAME) $(OBJS)

.cpp.o:
	$(LINLING_FLAG) -c $< -o $@ -I $(HEADER)
	
all	: $(NAME)


clean	:
		rm -f $(OBJS)

fclean	:
		make clean
		rm -f $(NAME)

re	:	
	make fclean 
	make all


.PHONY	:	all clean re
