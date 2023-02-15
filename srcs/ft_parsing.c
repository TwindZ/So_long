/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emlamoth <emlamoth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 14:40:13 by emlamoth          #+#    #+#             */
/*   Updated: 2023/02/15 18:03:08 by emlamoth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 256
#endif

static int	ft_is_rec(char *file)
{
	int	i;
	int	j;
	int	ref;

	i = 0;
	ref = 0;
	if (!file)
		return(0);
	while (file[i] != '\n')
		i++;
	ref = i;
	i++;
	while (file[i])
	{
		j = 0;
		while (file[i] && file[i] != '\n')
		{
			i++;
			j++;
		}
		if (file[i] == '\n' && ref == j)
			i++;
		else if (file[i] == '\0' && ref == j)
			return (1);
		else
			return (0);	
	}
	return (0);
}

static char	*ft_read_map(int fd)
{
	char	*buf;
	int		ret;
	char	*file;

	file = malloc(1 * 1);
	buf = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!file || !buf)
		return (NULL);
	file[0] = '\0';
	ret = 1;
	while (ret != 0)
	{
		ret = read(fd, buf, BUFFER_SIZE);
		if (ret == -1)
		{
			free(buf);
			free(file);
			return (NULL);
		}
		buf[ret] = '\0';
		file = ft_strjoin(file, buf, 1);
	}
	free(buf);
	return (file);
}

t_map	*ft_parsing(int fd)
{
	t_map	*map;
	int		i;
	char	*file;

	i = 0;
	map = (t_map *)malloc(sizeof(t_map));
	file = ft_read_map(fd);
	map->rectangle = ft_is_rec(file);
	while (file[i])
	{
		if (file[i] == 'P')
			map->player += 1;
		else if (file[i] == 'E')
			map->exit += 1;
		else if (file[i] == 'C')
			map->collect += 1;
		else if (file[i] == '\n')
			map->line += 1;
		i++;
	}
	map->line += 1;
	free(file);
	return(map);
}

