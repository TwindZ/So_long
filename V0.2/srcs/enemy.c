/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emlamoth <emlamoth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 13:15:34 by emlamoth          #+#    #+#             */
/*   Updated: 2023/03/06 17:17:09 by emlamoth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_enemy_move(int new_x, int new_y, char direct, t_data *data)
{
	if (data->map[new_y][new_x] == '0')
	{
		data->map[data->enemy.pos_y][data->enemy.pos_x] = '0';
		data->map[new_y][new_x] = 'A';
		data->enemy.pos_x = new_x;
		data->enemy.pos_y = new_y;
		data->enemy.direct = direct;
	}
	else if (data->map[new_y][new_x] == 'P')
		ft_quit(data);
	// else if(data->map[new_y][new_x] == '1')
	// {
	// ft_enemy_rand(data);
	// }
}

void	ft_enemy_rand(t_data *data)
{
	int	ramdom;

	data->dificulty = (data->collect * 5) + 1;
	if (data->enemydelay == data->dificulty)
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
