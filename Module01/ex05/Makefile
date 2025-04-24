# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eel-abed <eel-abed@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/22 18:38:09 by eel-abed          #+#    #+#              #
#    Updated: 2025/04/24 16:46:40 by eel-abed         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = harl

SRC = main.cpp Harl.cpp

OBJ = $(SRC:.cpp=.o)

CXX = c++

CXXFLAGS = -Wall -Wextra -Werror -std=c++98

all: $(NAME)

$(NAME): $(OBJ)
    $(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)

clean:
    rm -f $(OBJ)

fclean: clean
    rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
