/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emlamoth <emlamoth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 14:40:28 by emlamoth          #+#    #+#             */
/*   Updated: 2023/03/06 17:15:57 by emlamoth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_go_and_back(t_data *data)
{
	if (data->wallindexdir == 0)
		data->wallindex++;
	if (data->wallindexdir == 1)
		data->wallindex--;
	if (data->wallindex == 8)
		data->wallindexdir = 1;
	if (data->wallindex == 0)
		data->wallindexdir = 0;
}

void	ft_animation(t_data *data)
{
	if (data->collectindex == 7)
		data->collectindex = 0;
	data->image.collect = mlx_texture_to_image(data->mlx,
			data->texture.collect[data->collectindex]);
	if (data->rendercount % 5 == 0)
		data->collectindex++;
	if (data->rendercount == 30)
	{
		ft_go_and_back(data);
		data->rendercount = 0;
	}
	data->image.wall = mlx_texture_to_image(data->mlx,
			data->texture.wall[data->wallindex]);
	data->rendercount++;
}
