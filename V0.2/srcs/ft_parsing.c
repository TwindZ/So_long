/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emlamoth <emlamoth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 14:40:13 by emlamoth          #+#    #+#             */
/*   Updated: 2023/02/22 15:16:23 by emlamoth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// static int	ft_is_walled(char *file)
// {
// 	int	i;

// 	i = 0;
// 	while (file[i] != '\n')
// 	{
// 		if (file[i] != '1')
// 			return (1);
// 		i++;
// 	}
// 	while (file[i])
// 	{
// 		if (file[i] == '\n')
// 		{
// 			if (file[i + 1] != '1' || file[i - 1] != '1')
// 				return (1);
// 		}
// 		i++;
// 	}
// 	while (file[--i] != '\n')
// 	{
// 		if (file[i] != '1')
// 			return (1);
// 	}
// 	return (0);
// }

// static int	ft_is_rec(char *file, t_map *map)
// {
// 	int	i;
// 	int	j;

// 	i = 0;
// 	while (file[i])
// 	{
// 		j = 0;
// 		while (file[i] && file[i] != '\n')
// 		{
// 			i++;
// 			j++;
// 		}
// 		if (file[i] == '\n' && map->col == j)
// 			i++;
// 		else if (file[i] == '\0' && map->col == j)
// 			return (0);
// 		else
// 			return (1);
// 	}
// 	return (1);
// }

// static int	ft_valid_map(char *file, t_map *map)
// {
// 	map->walled = ft_is_walled(file);
// 	map->rectangle = ft_is_rec(file, map);
// 	if (map->collect < 1)
// 		return (ft_printf("Aucun objet collectible\n"));
// 	if (map->exit != 1)
// 		return (ft_printf("Mauvais nombre de sortie\n"));
// 	if (map->player < 1)
// 		return (ft_printf("Pas de joueur sur la carte\n"));
// 	if (map->rectangle != 0)
// 		return (ft_printf("Carte non rectangulaire\n"));
// 	if (map->walled != 0)
// 		return (ft_printf("Carte non entièrement murrée\n"));
// 	return (0);
// }


t_data	*ft_parsing(int fd)
{
	t_data	*data;
	
	data = malloc(sizeof(data));
	data->line = ft_countline(fd);
	
	return(data);

	



}
