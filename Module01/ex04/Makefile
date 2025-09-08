# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eel-abed <eel-abed@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/09/08 15:57:30 by eel-abed          #+#    #+#              #
#    Updated: 2025/09/08 16:07:53 by eel-abed         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = replace

SRC = main.cpp

OBJ = $(SRC:.cpp=.o)

CXX = c++

CXXFLAGS = -Wall -Wextra -Werror -std=c++98

TEST_FILE = test.txt

all: $(NAME) $(TEST_FILE)

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)

$(TEST_FILE):
	@echo "Creating test file..."
	@echo "Hello world, this is a test world." > $(TEST_FILE)
	@echo "Bonjour je suis ton correcteur et je m'appelle xxx" >> $(TEST_FILE)
	@echo "J'aime 42" >> $(TEST_FILE)
	@echo "Final line with world at the end: world" >> $(TEST_FILE)
	@echo "Test file '$(TEST_FILE)' created successfully!"

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)
	rm -f $(TEST_FILE)
	rm -f $(TEST_FILE).replace

re: fclean all

.PHONY: all clean fclean re
