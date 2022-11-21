/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmiguel- <tmiguel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 11:11:23 by tmiguel-          #+#    #+#             */
/*   Updated: 2022/11/21 11:11:24 by tmiguel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(char const *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	j;
	char	*str;

	str = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!str)
		return (NULL);
	i = 0;
	while (s1[i] != '\0')
	{
		str[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j] != '\0')
	{
		str[i + j] = s2[j];
		j++;
	}
	str[i + j] = '\0';
	return (str);
}

char	*ft_strdup(char const *src)
{
	size_t	i;
	char	*str;

	i = 0;
	str = (char *)malloc(ft_strlen(src) + 1);
	if (!str)
		return (NULL);
	while (src[i] != '\0')
	{
		str[i] = src[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_strchr(const char *s, int i)
{
	while (*s != '\0' && (unsigned char)i != *s)
		s++;
	if ((unsigned char)i == *s)
		return ((char *)s);
	return (0);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*home_s;
	size_t			x;

	x = 0;
	if (start >= ft_strlen(s))
	{
		home_s = (char *)malloc(sizeof(char));
		*home_s = 0;
		return (home_s);
	}
	if (len >= ft_strlen(s))
		len = ft_strlen(s) - start;
	home_s = (char *)malloc(sizeof(*home_s) * (len + 1));
	if (!home_s)
		return (NULL);
	while (start < ft_strlen(s) && x < len)
		home_s[x++] = s[start++];
	home_s[x] = '\0';
	return (home_s);
}
