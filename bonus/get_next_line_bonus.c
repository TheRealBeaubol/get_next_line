/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboiteux <lboiteux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 22:57:47 by lboiteux          #+#    #+#             */
/*   Updated: 2023/12/19 16:51:17 by lboiteux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_split_line(char *sline)
{
	int		i;
	char	*str;

	i = 0;
	if (!sline[i])
		return (NULL);
	while (sline[i] && sline[i] != '\n')
		i++;
	if (sline[i] == '\n')
		i++;
	str = ft_calloc((i + 2), sizeof(char));
	if (!str)
		return (NULL);
	i = 0;
	while (sline[i] && sline[i] != '\n')
	{
		str[i] = sline[i];
		i++;
	}
	if (sline[i] == '\n')
		str[i] = sline[i];
	str[++i] = 0;
	return (str);
}

char	*ft_get_line(int fd, char *line)
{
	char	*buffer;
	int		sizeread;

	buffer = ft_calloc((BUFFER_SIZE + 1), sizeof(char));
	if (!buffer)
		return (NULL);
	sizeread = 1;
	while (!ft_strchr(buffer, '\n') && sizeread != 0)
	{
		sizeread = read(fd, buffer, BUFFER_SIZE);
		if (sizeread == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[sizeread] = '\0';
		line = ft_strjoin(line, buffer);
	}
	free(buffer);
	return (line);
}

char	*ft_new_sstring(char *sline)
{
	int		i;
	char	*str;

	i = 0;
	while (sline[i] && sline[i] != '\n')
		i++;
	if (!sline[i])
	{
		free(sline);
		return (NULL);
	}
	str = ft_new_sstring_implementation(sline, i);
	return (str);
}

char	*ft_new_sstring_implementation(char *sline, int i)
{
	char	*str;
	int		j;

	str = ft_calloc((ft_strlen(sline) - i + 1), sizeof(char));
	if (!str)
		return (NULL);
	j = 0;
	while (sline[++i] != 0)
		str[j++] = sline[i];
	str[j] = 0;
	free(sline);
	if (!*str)
	{
		free(str);
		return (NULL);
	}
	return (str);
}

char	*get_next_line(int fd)
{
	char		*temp_line;
	static char	*sline[1024];

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	sline[fd] = ft_get_line(fd, sline[fd]);
	if (!sline[fd] || sline[fd][0] == 0)
	{
		free(sline[fd]);
		sline[fd] = NULL;
		return (NULL);
	}
	temp_line = ft_split_line(sline[fd]);
	sline[fd] = ft_new_sstring(sline[fd]);
	return (temp_line);
}

#include <stdio.h>

int	main(void)
{
	char	*str;
	
	str = get_next_line(0);
	printf("%s", str);
}