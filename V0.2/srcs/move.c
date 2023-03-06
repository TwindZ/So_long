/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emlamoth <emlamoth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 13:03:28 by emlamoth          #+#    #+#             */
/*   Updated: 2023/03/06 15:43:17 by emlamoth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_quit(t_data *data)
{
	ft_del_old_img(data);
	data->old_image = data->image;
	ft_del_old_img(data);
	mlx_close_window(data->mlx);
}

void	ft_event(int new_x, int new_y, t_data *data)
{
	if (data->map[new_y][new_x] == 'E')
	{
		if(data->collect == 0)
		{
			data->steps++;
			ft_printf("Pas : %d\n", data->steps);
			ft_printf("Carte réussite en %d pas !!!\n", data->steps);
			ft_quit(data);
		}
	}
	if (data->map[new_y][new_x] == 'A')
	{
		data->delay = 200;
		ft_printf("Mort !\n");
		ft_quit(data);
	}
}

void	ft_move(int new_x, int new_y, t_data *data, char c)
{
	data->player.direct = c;
	if (data->map[new_y][new_x] == '0' || data->map[new_y][new_x] == 'C')
	{
		if (data->map[new_y][new_x] == 'C')
		{	
			data->collect--;
			ft_printf("Âmes à collecter : %d\n", data->collect);
			data->enemydelay = 0;
		}
		data->map[new_y][new_x] = 'P';
		data->map[data->player.pos_y][data->player.pos_x] = '0';
		data->player.pos_x = new_x;
		data->player.pos_y = new_y;
		data->steps++;
		ft_printf("Pas : %d\n", data->steps);
	}
	ft_event(new_x, new_y, data);
}

void	ft_key_detect(mlx_key_data_t keydata, void *param)
{
	t_data	*data;

	data = param;
	if (keydata.action == MLX_PRESS || keydata.action == MLX_REPEAT)
	{
		if (keydata.key == MLX_KEY_W || keydata.key == MLX_KEY_UP)
			ft_move(data->player.pos_x, data->player.pos_y - 1, data, 'N');
		else if (keydata.key == MLX_KEY_S || keydata.key == MLX_KEY_DOWN)
			ft_move(data->player.pos_x, data->player.pos_y + 1, data, 'S');
		else if (keydata.key == MLX_KEY_A || keydata.key == MLX_KEY_LEFT)
			ft_move(data->player.pos_x - 1, data->player.pos_y, data, 'W');
		else if (keydata.key == MLX_KEY_D || keydata.key == MLX_KEY_RIGHT)			
			ft_move(data->player.pos_x + 1, data->player.pos_y, data, 'E');
		else if (keydata.key == MLX_KEY_ESCAPE)
		{
			ft_printf("Vous avez quitté la partie\n");
			ft_quit(data);
		}	
	}
}

