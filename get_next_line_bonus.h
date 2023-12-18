/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmoura-p <cmoura-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 15:42:49 by cmoura-p          #+#    #+#             */
/*   Updated: 2023/12/10 20:07:42 by cmoura-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif
# ifndef FD_MAX
#  define FD_MAX FOPEN_MAX
# endif

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>

char	*get_next_line(int fd);
char	*ft_extract(char *str);
char	*ft_getchr(const char *s, int c);
size_t	ft_getlen(const char *str);
char	*ft_getjoin(char *s1, char *s2);
void	ft_getcpy(char *str);
void	*ft_calloc(size_t nmemb, size_t size);

#endif
