/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emohamed <emohamed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 11:32:44 by emohamed          #+#    #+#             */
/*   Updated: 2022/12/11 16:02:51 by emohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
	{
		i++;
	}
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	i;
	size_t	j;
	char	*ptr;
	size_t	k;

	k = ft_strlen(s1);
	i = 0;
	j = 0;
	ptr = malloc(sizeof(char) * (k + ft_strlen(s2) + 1));
	if (!ptr)
		return (NULL);
	while (s1 && i < k)
	{
		ptr[i] = s1[i];
		i++;
	}
	while (s2 && i < ft_strlen(s2) + k)
		ptr[i++] = s2[j++];
	ptr[i] = '\0';
	free(s1);
	return (ptr);
}

char	*ft_strchr(char *string, char chrstr)
{
	int		i;
	int		j;
	char	*save;

	i = 0;
	j = 0;
	while (string[i] != chrstr)
	{
		if (string[i] == '\0')
			return (0);
		i++;
	}
	if (!string[i] || (string[i] == chrstr && string[i + 1] == '\0'))
		return (NULL);
	save = malloc(sizeof(char) * ((ft_strlen(string) - i) + 1));
	if (!save)
		return (NULL);
	i++;
	while (i < ft_strlen(string))
		save[j++] = string[i++];
	save[j] = '\0';
	return (save);
}
