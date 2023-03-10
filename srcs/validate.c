/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emlamoth <emlamoth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 14:08:41 by emlamoth          #+#    #+#             */
/*   Updated: 2023/03/07 17:40:13 by emlamoth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_flood_cpy(t_data *data)
{
	int	i;

	i = 0;
	data->flood.map = ft_calloc((data->line + 1), sizeof(char *));
	if (!data->flood.map)
		exit(1);
	while (data->map[i])
	{
		data->flood.map[i] = ft_calloc((data->col + 1), sizeof(char));
		if (!data->flood.map[i])
		{
			ft_freeall(data->flood.map);
			exit(1);
		}
		ft_memcpy(data->flood.map[i], data->map[i], data->col + 1);
		i++;
	}
}

void	ft_floodfill(int x, int y, t_data *data)
{
	if (x < 0 || y < 0 || x > data->col - 1 || y > data->line - 1)
		return ;
	if (data->flood.map[y][x] == 'X' || data->flood.map[y][x] == '1')
		return ;
	if (data->flood.map[y][x] == 'C')
		data->flood.collect += 1;
	if (data->flood.map[y][x] == 'E')
		data->flood.exit += 1;
	data->flood.map[y][x] = 'X';
	ft_floodfill(x + 1, y, data);
	ft_floodfill(x - 1, y, data);
	ft_floodfill(x, y + 1, data);
	ft_floodfill(x, y - 1, data);
}

void	ft_validate(t_data *data)
{
	if (data->exit != 1 || data->playercount != 1 || data->collect < 1
		|| data->rectangle != 0 || data->wrongchar != 0 || data->walled != 0
		|| data->enemycount > 1 || data->col > 40 || data->line > 19
		|| data->col < 7)
		data->valid = 1;
	if (data->valid == 0)
	{
		ft_flood_cpy(data);
		ft_floodfill(data->player.pos_x, data->player.pos_y, data);
		data->flood.done = 0;
		if (data->collect != data->flood.collect
			|| data->exit != data->flood.exit)
			data->valid = 1;
		ft_freeall(data->flood.map);
	}
}
