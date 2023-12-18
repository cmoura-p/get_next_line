/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmoura-p <cmoura-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 19:28:21 by cmoura-p          #+#    #+#             */
/*   Updated: 2023/12/18 15:11:49 by cmoura-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_extract(char *str)
{
	int		i;
	char	*s;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\n')
		i++;
	s = (char *)ft_calloc((i + 1), sizeof(char));
	s[i] = 0;
	while (i-- > 0)
		s[i] = str[i];
	return (s);
}

char	*get_next_line(int fd)
{
	static char	segment[FD_MAX][BUFFER_SIZE + 1];

	auto char *piece = NULL;
	auto char *line = NULL;
	auto int size = 1;
	if (fd < 0 || fd >= FD_MAX || BUFFER_SIZE <= 0)
		return (NULL);
	if (!segment[fd][0])
		size = read(fd, segment[fd], BUFFER_SIZE);
	while (size > 0)
	{
		piece = ft_extract(segment[fd]);
		line = ft_getjoin(line, piece);
		ft_getcpy(segment[fd]);
		if (ft_getchr(line, '\n'))
			return (line);
		size = read(fd, segment[fd], BUFFER_SIZE);
	}
	if (size < 0)
	{
		if (line)
			free(line);
		line = NULL;
	}
	return (line);
}
/*
// Esse eh o teste do Joao Ribeiro com arquivos de teste da Fran
int	main(void)
{
	char	*line;
	int		i;
	int		fd;
	int		fd2;
	int		fd3;
	i = 0;
	fd = open("41_with_nl", O_RDONLY);
	fd2 = open("multiple_nlx5", O_RDONLY);
	fd3 = open("alternate_line_nl_with_nl", O_RDONLY);
	line = "Existencia";
	while (i++ < 4)
	{
		line = get_next_line(fd);
		printf("[%02d] -> %s", i, line);
		line = get_next_line(fd2);
		printf("[%02d] -> %s", i, line);
		line = get_next_line(fd3);
		printf("[%02d] -> %s", i, line);
	}
	free(line);
	close(fd);
	return (0);
}

// Esse eh meu proprio main com arquivos de teste da Fran
int	main(void)
{
	int		fd;
	int		fd1;
	int		fd2;
	int		fd3;
	int		fd4;
	int		flag;
	char	*line;
	flag = 1;
	fd = open("41_with_nl", O_RDONLY);
	fd1 = open("multiple_nlx5", O_RDONLY);
	fd2 = open("empty", O_RDONLY);
	fd3 = open("alternate_line_nl_with_nl", O_RDONLY);
	fd4 = open("43_with_nl", O_RDONLY);
	while (flag)
	{
		line = get_next_line(fd4);
		if (line)
		{
			printf("%s", line);
			free(line);
		}
		else
			flag = 0;
	}
	close(fd4);
	flag = 1;
	while (flag)
	{
		line = get_next_line(fd3);
		if (line)
		{
			printf("%s", line);
			free(line);
		}
		else
			flag = 0;
	}
	close(fd3);
	while (flag)
	{
		line = get_next_line(fd1);
		if (line)
		{
			printf("%s", line);
			free(line);
		}
		else
			flag = 0;
	}
	close(fd1);
	flag = 1;
	while (flag)
	{
		line = get_next_line(fd2);
		if (line)
		{
			printf("%s", line);
			free(line);
		}
		else
			flag = 0;
	}
	close(fd2);
	flag = 1;
	while (flag)
	{
		line = get_next_line(fd);
		if (line)
		{
			printf("%s", line);
			free(line);
		}
		else
			flag = 0;
	}
	close(fd);
	return (0);
}
 */