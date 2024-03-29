/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzuiev <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 13:46:16 by dzuiev            #+#    #+#             */
/*   Updated: 2024/03/04 14:51:58 by dzuiev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libpipex.h"

/* ************************************************************************** */
/*                                                                            */
/*    Функция `ft_clean_pipes`:                                               */
/*    Освобождает память, выделенную под массив пайпов, и закрывает           */
/*    файловые дескрипторы, ассоциированные с пайпами.                        */
/*                                                                            */
/*    Параметры:                                                              */
/*    - `pipes`: указатель на массив пайпов.                                  */
/*    - `num_pipes`: количество пайпов в массиве.                             */
/*                                                                            */
/*    Работа функции:                                                         */
/*    1. Проверяет, не является ли указатель на массив пайпов NULL.           */
/*    2. Циклически проходит по всем пайпам в массиве.                        */
/*    3. Для каждого пайпа закрывает файловые дескрипторы чтения и записи,    */
/*       если они открыты, и освобождает выделенную под пайп память.          */
/*    4. Освобождает память, выделенную под массив пайпов, и устанавливает    */
/*       указатель на NULL.                                                   */
/*                                                                            */
/*    Возвращаемое значение:                                                  */
/*    - Функция не возвращает значение.                                       */
/*                                                                            */
/* ************************************************************************** */

void	ft_clean_pipes(int ***pipes, int num_pipes)
{
	int	i;

	if (!*pipes)
		return ;
	i = 0;
	while (i < num_pipes)
	{
		if ((*pipes)[i])
		{
			if ((*pipes)[i][0] >= 0)
				close((*pipes)[i][0]);
			if ((*pipes)[i][1] >= 0)
				close((*pipes)[i][1]);
			free((*pipes)[i]);
		}
		i++;
	}
	free(*pipes);
	*pipes = NULL;
}

/* ************************************************************************** */
/*                                                                            */
/*    Функция `ft_free_3d_array`:                                             */
/*    Освобождает память, выделенную под трехмерный массив строк.             */
/*                                                                            */
/*    Параметры:                                                              */
/*    - `array`: указатель на трехмерный массив строк.                        */
/*                                                                            */
/*    Работа функции:                                                         */
/*    1. Проверяет, не являются ли указатели на массив или его элементы NULL. */
/*    2. Циклически проходит по всем элементам массива.                       */
/*    3. Для каждого элемента освобождает память, выделенную под строки,      */
/*       и освобождает память, выделенную под сам элемент.                    */
/*    4. Освобождает память, выделенную под массив, и устанавливает указатель */
/*       на NULL.                                                             */
/*                                                                            */
/*    Возвращаемое значение:                                                  */
/*    - Функция не возвращает значение.                                       */
/*                                                                            */
/* ************************************************************************** */

void	ft_free_3d_array(char ****array)
{
	int	i;
	int	j;

	if (array == NULL || *array == NULL)
		return ;
	i = 0;
	while ((*array)[i])
	{
		j = 0;
		while ((*array)[i][j])
		{
			free((*array)[i][j]);
			j++;
		}
		free((*array)[i]);
		i++;
	}
	free(*array);
	*array = NULL;
}

/* ************************************************************************** */
/*                                                                            */
/*    Функция `cleanup`:                                                      */
/*    Освобождает выделенные ресурсы и завершает программу с указанным кодом  */
/*    завершения.                                                             */
/*                                                                            */
/*    Параметры:                                                              */
/*    - `pipex`: указатель на структуру данных программы.                     */
/*    - `exit_status`: код завершения программы.                              */
/*                                                                            */
/*    Работа функции:                                                         */
/*    1. Освобождает память, выделенную под команды и их аргументы.           */
/*    2. Освобождает память, выделенную под PIDы дочерних процессов.          */
/*    3. Закрывает файловые дескрипторы входного и выходного файлов.          */
/*    4. Освобождает память, выделенную под пути выполнения команд.           */
/*    5. Очищает массивы пайпов.                                              */
/*    6. Выходит из программы с переданным статусом.                          */
/*                                                                            */
/*    Возвращаемое значение:                                                  */
/*    - Функция не возвращает значение.                                       */
/*                                                                            */
/* ************************************************************************** */

void	cleanup(t_pipex *pipex, int exit_status)
{
	if (pipex->cmds)
		ft_free_array(&(pipex->cmds));
	if (pipex->my_cmd)
		ft_free_3d_array(&(pipex->my_cmd));
	if (pipex->pid)
	{
		free(pipex->pid);
		pipex->pid = NULL;
	}
	if (pipex->infile_fd >= 0)
		close(pipex->infile_fd);
	if (pipex->outfile_fd >= 0)
		close(pipex->outfile_fd);
	if (pipex->my_path)
	{
		free(pipex->my_path);
		pipex->my_path = NULL;
	}
	if (pipex->pipes)
		ft_clean_pipes(&(pipex->pipes), pipex->num_pipes);
	if (exit_status)
		exit(exit_status);
}

/* ************************************************************************** */
/*                                                                            */
/*    Функция `allocate_pid`:                                                 */
/*    Выделяет память для хранения PIDов дочерних процессов.                  */
/*                                                                            */
/*    Параметры:                                                              */
/*    - `pipex`: указатель на структуру данных программы.                     */
/*                                                                            */
/*    Работа функции:                                                         */
/*    1. Выделяет память для массива PIDов в зависимости от количества        */
/*       команд.                                                              */
/*    2. В случае ошибки выделения памяти выводит сообщение об ошибке и       */
/*       завершает программу.                                                 */
/*                                                                            */
/*    Возвращаемое значение:                                                  */
/*    - Возвращает указатель на массив PIDов.                                 */
/*                                                                            */
/* ************************************************************************** */

pid_t	*allocate_pid(t_pipex *pipex)
{
	pid_t	*pid;

	pid = (pid_t *)malloc(sizeof(pid_t) * pipex->num_cmds);
	if (pid == NULL)
	{
		ft_putstr_fd("malloc error for pid array\n", STDERR_FILENO);
		cleanup(pipex, EXIT_FAILURE);
	}
	return (pid);
}

/* ************************************************************************** */
/*                                                                            */
/*    Функция `open_file`:                                                    */
/*    Открывает файл с указанными параметрами доступа.                        */
/*                                                                            */
/*    Параметры:                                                              */
/*    - `file`: имя файла для открытия.                                       */
/*    - `flag`: флаг, определяющий режим открытия (чтение, запись, добавление)*/
/*                                                                            */
/*    Работа функции:                                                         */
/*    1. Открывает файл в соответствии с указанным флагом.                    */
/*    2. В случае ошибки открытия файла выводит информативное сообщение об    */
/*       ошибке в стандартный поток ошибок, используя описание ошибки из      */
/*       `strerror` и имя файла.                                              */
/*                                                                            */
/*    Обработка ошибок:                                                       */
/*    Если файл не удалось открыть, функция выводит описание ошибки в         */
/*    стандартный поток ошибок, добавляя имя проблемного файла для            */
/*    упрощения диагностики проблемы пользователем.                           */
/*                                                                            */
/*    Возвращаемое значение:                                                  */
/*    - Возвращает файловый дескриптор открытого файла или -1 при ошибке.     */
/*                                                                            */
/* ************************************************************************** */

int	open_file(char *file, int flag)
{
	int	fd;

	if (flag == 0)
		fd = open(file, O_RDONLY, 0644);
	else if (flag == 1)
		fd = open(file, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	else if (flag == 2)
		fd = open(file, O_WRONLY | O_CREAT | O_APPEND, 0644);
	if (fd < 0)
	{
		ft_putstr_fd(strerror(errno), STDERR_FILENO);
		ft_putstr_fd(": ", STDERR_FILENO);
		ft_putstr_fd(file, STDERR_FILENO);
		ft_putchar_fd('\n', STDERR_FILENO);
	}
	return (fd);
}
