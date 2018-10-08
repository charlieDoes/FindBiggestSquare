# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anjansse <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/09/03 10:13:31 by anjansse          #+#    #+#              #
#    Updated: 2018/09/12 21:12:09 by anjansse         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = bsq

all : $(NAME)

$(NAME) :
	gcc -Wall -Wextra -Werror -c srcs/*.c -I includes/*.h
	gcc *.o -o $(NAME)

clean : 
	/bin/rm -f *.o

fclean : clean
	/bin/rm -f $(NAME)

re : fclean all 
