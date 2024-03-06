/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzuiev <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 12:18:22 by dzuiev            #+#    #+#             */
/*   Updated: 2024/03/05 17:57:01 by dzuiev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin_gnl(char *s1, char const *s2)
{
	char	*str;
	size_t	s1_len;
	size_t	s2_len;

	if (!s2)
		return (NULL);
	if (s1)
		s1_len = ft_strlen(s1);
	else
		s1_len = 0;
	s2_len = ft_strlen(s2);
	str = (char *)malloc(s1_len + s2_len + 1);
	if (!str)
		return (NULL);
	if (s1)
		ft_strlcpy(str, s1, s1_len + 1);
	else
		str[0] = '\0';
	ft_memcpy(str + s1_len, s2, s2_len + 1);
	return (str);
}

static char	*read_from_fd(int fd, char *saved, char *buf)
{
	int		chars_read;
	char	*temp;

	chars_read = read(fd, buf, BUFFER_SIZE);
	while (chars_read > 0)
	{
		buf[chars_read] = '\0';
		temp = saved;
		saved = ft_strjoin_gnl(saved, buf);
		free(temp);
		if (ft_strchr(saved, '\n'))
			break ;
		chars_read = read(fd, buf, BUFFER_SIZE);
	}
	free(buf);
	if (chars_read < 0)
	{
		free(saved);
		saved = NULL;
		return (NULL);
	}
	return (saved);
}

static char	*extract_line(char **saved)
{
	char	*new_line_ptr;
	char	*line;
	char	*temp;

	new_line_ptr = ft_strchr(*saved, '\n');
	if (new_line_ptr)
	{
		line = ft_substr(*saved, 0, new_line_ptr - *saved + 1);
		temp = *saved;
		*saved = ft_strdup(new_line_ptr + 1);
		free(temp);
		return (line);
	}
	if (**saved)
	{
		line = ft_strdup(*saved);
		free(*saved);
		*saved = NULL;
		return (line);
	}
	return (NULL);
}

char	*get_next_line(int fd, char **saved)
{
	char		*line;
	char		*buf;

	if (fd < 0 || BUFFER_SIZE < 1 || fd > 4095)
		return (NULL);
	buf = malloc(BUFFER_SIZE + 1);
	if (!buf)
		return (NULL);
	*saved = read_from_fd(fd, *saved, buf);
	if (!*saved)
	{
		free(*saved);
		*saved = NULL;
		return (NULL);
	}
	line = extract_line(&*saved);
	if (line == NULL)
	{
		free(*saved);
		*saved = NULL;
	}
	return (line);
}
