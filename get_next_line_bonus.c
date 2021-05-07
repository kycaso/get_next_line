/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbelda-h <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 13:30:26 by fbelda-h          #+#    #+#             */
/*   Updated: 2021/03/30 17:30:12 by fbelda-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	s_f(char *s, char **line, char **thres)
{
	char	*aux;
	char	*aux2;
	int		l;

	aux = ft_strdup(*line);
	if (*line)
	{
		free (*line);
		*line = NULL;
	}
	if (ft_strchr(s, '\n') == NULL)
		*line = ft_strjoin(aux, s);
	else
	{
		free(*thres);
		*thres = ft_strdup(ft_strchr(s, '\n'));
		l = ft_strlen(s) - ft_strlen(*thres) - 1;
		aux2 = ft_substr(s, 0, l);
		*line = ft_strjoin(aux, aux2);
		free (aux2);
	}
	free (aux);
	free (s);
	return (1);
}

int	great_loop(int fd, char **line, char **thres, int f)
{
	int	r;

	if (*thres)
	{
		f = 1;
		free (*thres);
		*thres = NULL;
	}
	*thres = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!*thres)
		return (-1);
	r = read(fd, *thres, BUFFER_SIZE);
	if (r <= 0)
	{
		free(*thres);
		if (r == 0 && !f)
			*line = ft_strdup("");
		*thres = NULL;
		return (r);
	}
	thres[0][r] = '\0';
	if (!ft_strchr(*thres, '\n') && s_f(ft_strdup(*thres), line, thres))
		return (great_loop(fd, line, thres, 0));
	s_f(ft_strdup(*thres), line, thres);
	return (1);
}

int	get_next_line(int fd, char **line)
{
	static char	*thres[4096];

	if (fd <= -1 || line == NULL || BUFFER_SIZE <= 0)
		return (-1);
	*line = NULL;
	if (thres[fd] == 0)
		return (great_loop(fd, line, &thres[fd], 0));
	if (ft_strchr(thres[fd], '\n') == NULL)
	{
		s_f(ft_strdup(thres[fd]), line, &thres[fd]);
		return (great_loop(fd, line, &thres[fd], 0));
	}
	else
		s_f(ft_strdup(thres[fd]), line, &thres[fd]);
	return (1);
}
