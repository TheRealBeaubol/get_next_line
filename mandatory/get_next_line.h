/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboiteux <lboiteux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 22:57:20 by lboiteux          #+#    #+#             */
/*   Updated: 2023/11/16 22:35:59 by lboiteux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

size_t	ft_strlen(const char *s);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strchr(char *s, int c);
void	*ft_calloc(size_t nmemb, size_t size);
char	*ft_split_line(char *sline);
char	*ft_get_line(int fd, char *line);
char	*ft_new_sstring(char *sline);
char	*ft_new_sstring_implementation(char *sline, int i);
char	*get_next_line(int fd);

#endif
