/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboiteux <lboiteux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 22:58:02 by lboiteux          #+#    #+#             */
/*   Updated: 2023/11/16 22:47:39 by lboiteux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != 0)
		i++;
	return (i);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	void				*ptr;
	long long unsigned	len;
	size_t				i;

	len = nmemb * size;
	if (nmemb == 0 || size == 0)
		return (malloc(1));
	if ((int)nmemb < 0 || (int)size < 0 || len > __SIZE_MAX__)
		return (NULL);
	ptr = malloc(nmemb * size);
	if (ptr == NULL)
		return (ptr);
	i = 0;
	while (i < nmemb * size)
	{
		*(unsigned char *)(ptr + i) = 0;
		i++;
	}
	return (ptr);
}

char	*ft_strchr(char *s, int c)
{
	int		i;
	char	*cast;

	if (!s || !s[0])
		return (NULL);
	cast = (char *)s;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == (unsigned char)c)
			return (cast + i);
		else
			i++;
	}
	if (s[i] == c)
		return (cast + i);
	return (NULL);
}

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	i;
	size_t	j;
	char	*str;

	if (!s1)
	{
		s1 = (char *)malloc(1 * sizeof(char));
		s1[0] = '\0';
	}
	if (!s1 || !s2)
		return (NULL);
	str = malloc(sizeof(char) * ((ft_strlen(s1) + ft_strlen(s2)) + 1));
	if (str == NULL)
		return (NULL);
	i = -1;
	j = 0;
	if (s1)
		while (s1[++i] != '\0')
			str[i] = s1[i];
	while (s2[j] != '\0')
		str[i++] = s2[j++];
	str[ft_strlen(s1) + ft_strlen(s2)] = '\0';
	free(s1);
	return (str);
}
