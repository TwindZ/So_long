/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emlamoth <emlamoth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 13:01:03 by emlamoth          #+#    #+#             */
/*   Updated: 2023/02/16 15:16:27 by emlamoth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int ft_ber(char *path)
{
	
}

char	*ft_read_map(int fd)
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

static int ft_col(char *file)
{
	int	i;

	i = 0;
	while(file[i] != '\n')
		i++;
	return (i);
}

t_map	ft_map_param(char *file, t_map *map)
{
	int	i;

	i = 0;	
	while (file[i])
	{
		if (file[i] == 'P')
			map->player++;
		else if (file[i] == 'E')
			map->exit++;
		else if (file[i] == 'C')
			map->collect++;
		else if (file[i] == '\n')
			map->line++;
		i++;
	}
	map->line += 1;
	map->col = ft_col(file);
	map->totallen = i;
	return (*map);
}