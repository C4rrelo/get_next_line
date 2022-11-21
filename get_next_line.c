/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmiguel- <tmiguel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 09:50:45 by tmiguel-          #+#    #+#             */
/*   Updated: 2022/11/21 14:49:18 by tmiguel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*protect(char *get_line)
{
	char	*hold;
	size_t	i;

	i = 0;
	while (get_line[i] != '\0' && get_line[i] != '\n')
		i++;
	if (get_line[i] == '\0')
		return (NULL);
	hold = ft_substr(get_line, i + 1, ft_strlen(get_line) - i);
	if (*hold == '\0')
	{
		free(hold);
		hold = NULL;
		return (NULL);
	}
	get_line[i + 1] = '\0';
	return (hold);
}

char	*read_line(int fd, char *buffer, char *hold)
{
	int		i;
	char	*temp;

	i = 1;
	while (i != '\0')
	{
		i = read(fd, buffer, BUFFER_SIZE);
		if (i == -1)
			return (NULL);
		else if (i == 0)
			break ;
		buffer[i] = '\0';
		if (!hold)
			hold = ft_strdup("");
		temp = hold;
		hold = ft_strjoin(temp, buffer);
		free(temp);
		temp = NULL;
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	return (hold);
}

char	*get_next_line(int fd)
{
	static char	*hold;
	char		*buffer;
	char		*get_line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	get_line = read_line(fd, buffer, hold);
	free(buffer);
	buffer = NULL;
	if (!get_line)
	{
		free(hold);
		hold = NULL;
		return (NULL);
	}
	hold = protect(get_line);
	return (get_line);
}
