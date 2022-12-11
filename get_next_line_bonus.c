/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emohamed <emohamed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 11:32:48 by emohamed          #+#    #+#             */
/*   Updated: 2022/12/11 16:03:00 by emohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	check_str(char *buff)
{
	int	i;

	i = 0;
	while (buff[i])
	{
		if (buff[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char	*new_get_line(char *str, int fd)
{
	int		r;
	char	*buff;

	buff = malloc(BUFFER_SIZE + 1);
	while (1)
	{
		r = read(fd, buff, BUFFER_SIZE);
		if (r == 0)
			break ;
		if (r == -1)
		{
			free(str);
			free(buff);
			return (NULL);
		}
		buff[r] = '\0';
		str = ft_strjoin(str, buff);
		if (check_str(str) == 1)
			break ;
	}
	free(buff);
	return (str);
}

char	*new_get_exact_line(char *line)
{
	char	*extline;
	int		i;

	if (!line)
		return (NULL);
	i = 0;
	while (line[i] != '\n' && line[i] != '\0')
		i++;
	extline = malloc(i + 2);
	if (!extline)
		return (NULL);
	i = 0;
	while (line[i] != '\n' && line[i] != '\0')
	{
		extline[i] = line[i];
		i++;
	}
	if (line[i] == '\n')
	{
		extline[i] = '\n';
		i++;
	}
	extline[i] = '\0';
	return (extline);
}

char	*get_next_line(int fd)
{
	static char	*save[OPEN_MAX];
	char		*line;
	char		*p;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (fd == 2)
		return (NULL);
	save[fd] = new_get_line(save[fd], fd);
	p = save[fd];
	line = new_get_exact_line(save[fd]);
	if (!line)
		return (NULL);
	save[fd] = ft_strchr(save[fd], '\n');
	free(p);
	return (line);
}

// [OPEN_MAX] = max of file that the progam can run one the same time :
// we give OPEN_MAX AS A save parameter for handling the multipls fd
//&&the case of fd pointed to another fd