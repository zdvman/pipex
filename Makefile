# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dzuiev <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/16 12:07:25 by dzuiev            #+#    #+#              #
#    Updated: 2024/03/01 14:05:15 by dzuiev           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# **************************************************************************** #
#                                                                              #
#                             Makefile for pipex                           #
#                                                                              #
# **************************************************************************** #

# Имена исполняемых файлов для основной и бонусной частей проекта
NAME = pipex
# BONUS_NAME = pipex

# Компилятор и флаги компиляции
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g

# Директории с исходным кодом и библиотеками
LIBFT_DIR = libft
INCLUDES = includes
SRC_DIR = src
OBJ_DIR = obj
BONUS_DIR = src_bonus
OBJ_BONUS_DIR = obj_bonus

# Поиск исходных файлов и создание объектных файлов
SRCS = $(wildcard $(SRC_DIR)/*.c)
OBJS = $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)
OBJS_WITHOUT_MAIN = $(filter-out $(OBJ_DIR)/pipex.o, $(OBJS))

BONUS_SRCS = $(wildcard $(BONUS_DIR)/*.c)
BONUS_OBJS = $(BONUS_SRCS:$(BONUS_DIR)/%.c=$(OBJ_BONUS_DIR)/%.o)

# Статические библиотеки для основной и бонусной частей
LIBFT = $(LIBFT_DIR)/libft.a
LIBP = libpipex.a

# Основная цель - сборка основной части проекта
all: $(NAME)

# Сборка основной части проекта
$(NAME): $(LIBP) $(LIBFT) $(OBJ_DIR)/pipex.o
	$(CC) $(CFLAGS) -I$(INCLUDES) -o $(NAME) $(OBJ_DIR)/pipex.o -L. -lpipex -L$(LIBFT_DIR) -lft

# Сборка бонусной части проекта если имя программы
# для бонусной части отличное от основной части (не используется)
# $(BONUS_NAME): $(LIBP) $(LIBFT) $(BONUS_OBJS)
#	$(CC) $(CFLAGS) -I$(INCLUDES) -o $(BONUS_NAME) $(BONUS_OBJS) -L. -lpipex -L$(LIBFT_DIR) -lft

# Компиляция библиотеки libft
$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

# Создание статической библиотеки libpipex.a из объектных файлов
$(LIBP): $(OBJS_WITHOUT_MAIN)
	ar rcs $(LIBP) $(OBJS_WITHOUT_MAIN)

# Компиляция исходных файлов в объектные файлы
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -I$(INCLUDES) -c $< -o $@

# Компиляция исходных файлов бонусной части в объектные файлы
$(OBJ_BONUS_DIR)/%.o: $(BONUS_DIR)/%.c
	@mkdir -p $(OBJ_BONUS_DIR)
	$(CC) $(CFLAGS) -I$(INCLUDES) -c $< -o $@

# Цель для сборки бонусной части проекта
bonus: $(LIBP) $(LIBFT) $(BONUS_OBJS)
	$(CC) $(CFLAGS) -I$(INCLUDES) -o $(NAME) $(BONUS_OBJS) -L. -lpipex -L$(LIBFT_DIR) -lft

# Очистка всех созданных файлов
clean:
	$(MAKE) -C $(LIBFT_DIR) clean
	rm -rf $(OBJ_DIR) $(OBJ_BONUS_DIR) $(LIBP)

# Полная очистка проекта
fclean: clean
	$(MAKE) -C $(LIBFT_DIR) fclean
	rm -f $(NAME) 
	rm -f file2
	rm -f file
# rm -f $(BONUS_NAME)

# Пересборка проекта
re: fclean all

# Указание фиктивных целей
.PHONY: all clean fclean re bonus
