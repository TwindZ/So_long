/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emlamoth <emlamoth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 12:45:59 by emlamoth          #+#    #+#             */
/*   Updated: 2023/03/02 15:50:54 by emlamoth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_free_texture(t_data *data)
{
	mlx_delete_texture(data->texture.collect);
	mlx_delete_texture(data->texture.floor);
	mlx_delete_texture(data->texture.wall);
	mlx_delete_texture(data->texture.playerfront);
	mlx_delete_texture(data->texture.playerback);
	mlx_delete_texture(data->texture.playerleft);
	mlx_delete_texture(data->texture.playerright);
	mlx_delete_texture(data->texture.exitopen);
	mlx_delete_texture(data->texture.exitclose);
	mlx_delete_texture(data->texture.enemyfront);
	mlx_delete_texture(data->texture.enemyback);
	mlx_delete_texture(data->texture.enemyleft);
	mlx_delete_texture(data->texture.enemyright);
}

void	ft_load_texture(t_data *data)
{
	data->texture.collect = mlx_load_png(COLLECT);
	data->texture.floor = mlx_load_png(FLOOR);
	data->texture.wall = mlx_load_png(WALL);
	data->texture.playerfront = mlx_load_png(PLAYERFRONT);
	data->texture.playerback = mlx_load_png(PLAYERBACK);
	data->texture.playerleft = mlx_load_png(PLAYERLEFT);
	data->texture.playerright = mlx_load_png(PLAYERRIGHT);
	data->texture.exitopen = mlx_load_png(EXITOPEN);
	data->texture.exitclose = mlx_load_png(EXITCLOSE);
	data->texture.enemyfront = mlx_load_png(ENEMYFRONT);
	data->texture.enemyback = mlx_load_png(ENEMYBACK);
	data->texture.enemyleft = mlx_load_png(ENEMYLEFT);
	data->texture.enemyright = mlx_load_png(ENEMYRIGHT);
}

void	ft_text_img(t_data *data)
{
	data->image.collect = mlx_texture_to_image(data->mlx,
			data->texture.collect);
	data->image.exitopen = mlx_texture_to_image(data->mlx,
			data->texture.exitopen);
	data->image.exitclose = mlx_texture_to_image(data->mlx,
			data->texture.exitclose);
	data->image.playerfront = mlx_texture_to_image(data->mlx, data->texture.playerfront);
	data->image.playerback = mlx_texture_to_image(data->mlx, data->texture.playerback);
	data->image.playerleft = mlx_texture_to_image(data->mlx, data->texture.playerleft);
	data->image.playerright = mlx_texture_to_image(data->mlx, data->texture.playerright);
	data->image.floor = mlx_texture_to_image(data->mlx, data->texture.floor);
	data->image.wall = mlx_texture_to_image(data->mlx, data->texture.wall);
	data->image.enemyfront = mlx_texture_to_image(data->mlx, data->texture.enemyfront);
	data->image.enemyback = mlx_texture_to_image(data->mlx, data->texture.enemyback);
	data->image.enemyleft = mlx_texture_to_image(data->mlx, data->texture.enemyleft);
	data->image.enemyright = mlx_texture_to_image(data->mlx, data->texture.enemyright);
}

void	ft_del_old_img(t_data *data)
{
	mlx_delete_image(data->mlx, data->old_image.collect);
	mlx_delete_image(data->mlx, data->old_image.exitopen);
	mlx_delete_image(data->mlx, data->old_image.wall);
	mlx_delete_image(data->mlx, data->old_image.playerfront);
	mlx_delete_image(data->mlx, data->old_image.playerback);
	mlx_delete_image(data->mlx, data->old_image.playerleft);
	mlx_delete_image(data->mlx, data->old_image.playerright);
	mlx_delete_image(data->mlx, data->old_image.floor);
	mlx_delete_image(data->mlx, data->old_image.exitclose);
	mlx_delete_image(data->mlx, data->old_image.enemyfront);
	mlx_delete_image(data->mlx, data->old_image.enemyback);
	mlx_delete_image(data->mlx, data->old_image.enemyleft);
	mlx_delete_image(data->mlx, data->old_image.enemyright);

}