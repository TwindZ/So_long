/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_render.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emlamoth <emlamoth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 16:32:17 by emlamoth          #+#    #+#             */
/*   Updated: 2023/02/21 17:35:43 by emlamoth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"



mlx_t	*ft_mlx_init(t_map *map)
{
	mlx_t *mlx;
	
	mlx = mlx_init(map->col * IMG_SIZE, map->line * IMG_SIZE, "So_long", 0);
	return (mlx);
}

t_texture	ft_texture_init(mlx_t *mlx)
{
	t_texture texture;
	
	texture.wall = mlx_texture_to_image(mlx, mlx_load_png(WALL));
	texture.floor = mlx_texture_to_image(mlx, mlx_load_png(FLOOR));
	texture.player = mlx_texture_to_image(mlx, mlx_load_png(PLAYER));
	texture.collect = mlx_texture_to_image(mlx, mlx_load_png(COLLECT));
	texture.exit = mlx_texture_to_image(mlx, mlx_load_png(EXIT));
	return(texture);
}

int ft_render(t_map *map, mlx_t *mlx, t_texture texture)
{
	
	int x;
	int y;
	
	y = 0;
	while(y < map->line)
	{
		x = 0;
		while(x < map->col)
		{
			if(map->map_a[y][x] == '1')
				mlx_image_to_window(mlx, texture.wall, x * IMG_SIZE, y * IMG_SIZE);
			if(map->map_a[y][x] == '0')
				mlx_image_to_window(mlx, texture.floor, x * IMG_SIZE, y * IMG_SIZE);
			if(map->map_a[y][x] == 'E')
				mlx_image_to_window(mlx, texture.exit, x * IMG_SIZE, y * IMG_SIZE);
			if(map->map_a[y][x] == 'P')
				mlx_image_to_window(mlx, texture.player, x * IMG_SIZE, y * IMG_SIZE);
			if(map->map_a[y][x] == 'C')
				mlx_image_to_window(mlx, texture.collect, x * IMG_SIZE, y * IMG_SIZE);
			x++;
		}
		y++;
	}
	return(0);
}