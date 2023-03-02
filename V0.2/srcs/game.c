/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emlamoth <emlamoth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 12:41:03 by emlamoth          #+#    #+#             */
/*   Updated: 2023/03/02 17:56:26 by emlamoth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

mlx_image_t	*ft_e_direct(t_data *data)
{
	if(data->enemy.direct == 'N')
		return (data->image.enemyback);
	else if(data->enemy.direct == 'W')
		return (data->image.enemyleft);
	else if(data->enemy.direct == 'E')
		return (data->image.enemyright);
	else
		return (data->image.enemyfront);
}

mlx_image_t	*ft_p_direct(t_data *data)
{
	if(data->player.direct == 'N')
		return (data->image.playerback);
	else if(data->player.direct == 'W')
		return (data->image.playerleft);
	else if(data->player.direct == 'E')
		return (data->image.playerright);
	else
		return (data->image.playerfront);
}

mlx_image_t	*ft_set_img(char c, t_data *data)
{
	if (c == '1')
		return (data->image.wall);
	if (c == '0')
		return (data->image.floor);
	if (c == 'P')
		return (ft_p_direct(data));
	if (c == 'C')
		return (data->image.collect);
	if (c == 'A')
		return (ft_e_direct(data));
	if (c == 'E')
	{
		if(data->collect == 0)
			return (data->image.exitopen);
		return (data->image.exitclose);
	}
	else
		return (0);
}

void	ft_img_to_win(t_data *data)
{
	int			x;
	int			y;
	y = 0;		
	// if(data->r_count == 0)
	// {		
		data->rendercount = 0;
		ft_del_old_img(data);
		data->old_image = data->image;
		ft_text_img(data);
		while (y < data->line)
		{
			x = 0;
			while (x < data->col)
			{
				mlx_image_to_window(data->mlx,
				ft_set_img(data->map[y][x], data), x * IMG_SIZE, y * IMG_SIZE);
				x++;
			}
			y++;
		}
	//}
	//data->r_count++;
}

void	ft_screen_info(t_data *data)
{
	char	str1[40] = "Nombre de pas : ";
	char	str2[40] = "Ame a ramasser : ";
	char	*number;
	
	number = ft_itoa(data->steps);
	ft_strlcat(str1, number, ft_strlen(str1) + ft_strlen(number) + 1);
	mlx_put_string(data->mlx, str1, (data->col / 2 * IMG_SIZE) - 80, 24);
	free(number);
	number = ft_itoa(data->collect);
	if(data->collect == 0)
	{
		mlx_put_string(data->mlx, "Vite le portail est OUVERT !",
		(data->col / 2 * IMG_SIZE) - 110,
			(data->line * IMG_SIZE) - 40 );
	}
	else
	{
		ft_strlcat(str2, number, ft_strlen(str2) + ft_strlen(number) + 1);
		mlx_put_string(data->mlx, str2, (data->col / 2 * IMG_SIZE) - 85,
			(data->line * IMG_SIZE) - 40 );
	}
	free(number);
}

void	ft_enemy_move(int new_x, int new_y, char direct, t_data *data)
{
	if(data->map[new_y][new_x] == '0')
	{
		data->map[data->enemy.pos_y][data->enemy.pos_x] = '0';
		data->map[new_y][new_x] = 'A';
		data->enemy.pos_x = new_x;
		data->enemy.pos_y = new_y;
		data->enemy.direct = direct;
	}
	else if (data->map[new_y][new_x] == 'P')
		ft_quit(data);
}

void	ft_enemy_rand(t_data *data)
{
	int	ramdom;
	
	if(data->enemydelay == data->dificulty)
	{
		data->enemydelay = 0;
		ramdom = rand() % 4; 
		if (ramdom == 0)
			ft_enemy_move(data->enemy.pos_x, data->enemy.pos_y - 1, 'N', data);
		else if (ramdom == 1)
			ft_enemy_move(data->enemy.pos_x, data->enemy.pos_y + 1, 'S', data);	
		else if (ramdom == 2)
			ft_enemy_move(data->enemy.pos_x + 1, data->enemy.pos_y, 'E', data);
		else if (ramdom == 3)
			ft_enemy_move(data->enemy.pos_x - 1, data->enemy.pos_y, 'W', data);
	}
	data->enemydelay++;
}

void	ft_render(void *param)
{
	
	t_data		*data;

	data = param;
	ft_img_to_win(data);
	ft_screen_info(data);
	if(data->enemycount == 1)
		ft_enemy_rand(data);
}