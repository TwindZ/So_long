/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_data.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emlamoth <emlamoth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 14:13:49 by emlamoth          #+#    #+#             */
/*   Updated: 2023/02/27 16:59:26 by emlamoth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_init_map(char *path, t_data *data)
{
	int		fd;
	int		i;
	
	data->map = ft_calloc((data->line + 1), (sizeof(char *)));
	i = 0;
	fd = open(path, O_RDONLY);
	while(1)
	{
		data->map[i] = get_next_line(fd);
		if(!data->map[i])
			break;
		if(data->map[i][0] == '\n')
			data->rectangle = 1;
		if(data->map[i][ft_strlen(data->map[i]) - 1] == '\n')
			data->map[i][ft_strlen(data->map[i]) - 1] = '\0';
		if(!data->map[i])
			break;
		
		i++;
	}
	close (fd);
	data->col = ft_strlen(data->map[0]);
}

void	ft_map_data_util(int x, int y, t_data *data)
{
	if(data->map[y][x] == 'P')
	{
		data->player.count++;
		data->player.pos_x = x;
		data->player.pos_y = y;
	}
	else if(data->map[y][x] == 'E')
		data->exit++;
	else if(data->map[y][x] == 'C')
		data->collect++;
	else if(data->map[y][x] == '1' || data->map[y][x] == '0')
		;
	else
		data->wrongChar++;
	if(data->map[0][x] != '1' || data->map[y][0] != '1' ||
		data->map[data->line - 1][x] != '1' ||
		data->map[y][data->col - 1] != '1')
		data->walled = 1;
}

void	ft_is_rec(t_data *data)
{ 
	int	x;
	int	y;
	
	y = 0;
	while(data->map[y])
	{
		x = 0;
		while(data->map[y][x])
			x++;
		if(x != data->col)
			data->rectangle = 1;
		y++;
	}
}

void	ft_map_data(t_data *data)
{
	int	y;
	int	x;
	
	y = 0;
	while(data->map[y])
	{
		x = 0;
		while(data->map[y][x])
		{
			ft_map_data_util(x, y, data);
			x++;
		}
		y++;
	}
	ft_is_rec(data);
}