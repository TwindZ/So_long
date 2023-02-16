/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emlamoth <emlamoth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 14:40:13 by emlamoth          #+#    #+#             */
/*   Updated: 2023/02/16 15:01:25 by emlamoth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	ft_is_walled(char *file)
{
	int i;

	i = 0;
	while(file[i] != '\n')
	{
		if(file[i] != '1')
			return (0);
		i++;
	}
	while(file[i])
	{
		if(file[i] == '\n')
		{
			if(file[i + 1] != '1' || file[i - 1] != '1')
				return (0);
		}
		i++;
	}
	while(file[--i] != '\n')
	{
		if(file[i] != '1')
			return (0);
	}
	return (1);
}

static int	ft_is_rec(char *file, t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (file[i])
	{
		j = 0;
		while (file[i] && file[i] != '\n')
		{
			i++;
			j++;
		}
		if (file[i] == '\n' && map->col == j)
			i++;
		else if (file[i] == '\0' && map->col == j)
			return (1);
		else
			return (0);	
	}
	return (0);
}

static int ft_valid_map(char *file, t_map *map)
{
	map->walled = ft_is_walled(file);
	map->rectangle = ft_is_rec(file, map);
	if(map->collect > 0 && map->exit == 1 && map->line > 2 &&
		map->player == 1 && map->rectangle == 1 && map->walled == 1 &&
		map->col > 2)
		return (1);
	return (0);
}

t_map	*ft_parsing(int fd)
{
	t_map	*map;
	char	*file;
	
	map = (t_map *)malloc(sizeof(*map));
	file = ft_read_map(fd);
	ft_map_param(file, map);
	if(ft_valid_map(file, map))
		ft_printf("Map valide !! :)\n");
	else
		ft_printf("Map invalide !! :(\n");
	free(file);
	return(map);
}
