/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emohamed <emohamed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 11:42:58 by emohamed          #+#    #+#             */
/*   Updated: 2022/11/20 18:38:11 by emohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 1

#endif

char	*get_next_line(int fd);
char    *ft_strjoin(char *s1, char *s2);
char    *new_get_exact_line(char *line);
char    *new_get_line (char *str ,int fd);
int	    ft_strlen( char *s);
int     check_str(char *buff);
char    *ft_strchr(char *string, char chrstr);
#endif