/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emlamoth <emlamoth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 15:51:40 by emlamoth          #+#    #+#             */
/*   Updated: 2023/03/01 17:52:23 by emlamoth         ###   ########.fr       */
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

void	ft_del_img(t_data *data)
{
	mlx_delete_image(data->mlx, data->image.collect);
	mlx_delete_image(data->mlx, data->image.exitopen);
	mlx_delete_image(data->mlx, data->image.wall);
	mlx_delete_image(data->mlx, data->image.playerfront);
	mlx_delete_image(data->mlx, data->image.playerback);
	mlx_delete_image(data->mlx, data->image.playerleft);
	mlx_delete_image(data->mlx, data->image.playerright);
	mlx_delete_image(data->mlx, data->image.floor);
	mlx_delete_image(data->mlx, data->image.exitclose);
	mlx_delete_image(data->mlx, data->image.enemyfront);
	mlx_delete_image(data->mlx, data->image.enemyback);
	mlx_delete_image(data->mlx, data->image.enemyleft);
	mlx_delete_image(data->mlx, data->image.enemyright);
}

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

void	ft_quit(t_data *data)
{
	ft_del_img(data);
	mlx_close_window(data->mlx);
	ft_printf("Fin de partie !\n");
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
		}
		data->map[new_y][new_x] = 'P';
		data->map[data->player.pos_y][data->player.pos_x] = '0';
		data->player.pos_x = new_x;
		data->player.pos_y = new_y;
		data->steps++;
		ft_printf("Pas : %d\n", data->steps);
	}
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
}

void	ft_img_to_win(void *param)
{
	int			x;
	int			y;
	mlx_image_t	*img;
	t_data		*data;

	data = param;
	y = 0;
	ft_del_img(data);
	ft_text_img(data);
	while (y < data->line)
	{
		x = 0;
		while (x < data->col)
		{
			img = ft_set_img(data->map[y][x], data);
			mlx_image_to_window(data->mlx, img, x * IMG_SIZE, y * IMG_SIZE);
			x++;
		}
		y++;
	}
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
			ft_quit(data);
	}
	ft_img_to_win(data);
}

void	ft_render(t_data *data)
{
	data->mlx = mlx_init(data->col * IMG_SIZE,
			data->line * IMG_SIZE, PRGNAME, false);
	ft_load_texture(data);
	ft_img_to_win(data);
	mlx_key_hook(data->mlx, &ft_key_detect, data);
	//mlx_loop_hook(data->mlx, &ft_img_to_win, data);
	mlx_loop(data->mlx);
	ft_free_texture(data);
}

int	main(int argc, char **argv)
{
	t_data		*data;

	if (argc != 2)
		return (ft_printf("Argument invalide !"));
	if (ft_strncmp(&argv[1][ft_strlen(argv[1]) - 4], ".ber", 4))
		return (ft_printf("Format de carte invalide !"));
	data = malloc(sizeof(*data));
	if (!data)
		return (ft_printf("Problème de création de struct data !"));
	ft_init_data(data);
	ft_map_size(argv[1], data);
	ft_init_map(argv[1], data);
	ft_map_data(data);
	ft_validate(data);
	ft_message(data);
	
	//-------------------TESTING AREA----------------------------------------//
	ft_printf("Nombre de lignes = %d\n", data->line);
	ft_printf("Nombre de collones = %d\n", data->col);
	ft_printf("Nombre de players = %d\n", data->player);
	ft_printf("Nombre de enemies = %d\n", data->enemy.count);
	ft_printf("Nombre de exit = %d\n", data->exit);
	ft_printf("Nombre de collect = %d\n", data->collect);
	ft_printf("Nombre de mauvais Char = %d\n", data->wrongchar);
	ft_printf("Map rectangulaire = %d\n", data->rectangle);
	ft_printf("Map valide = %d\n", data->valid);
	ft_printf("Map walled = %d\n", data->walled);
	ft_printf("Map flood exit = %d\n", data->flood.exit);
	ft_printf("Map flood collect = %d\n", data->flood.collect);
	//-------------------TESTING AREA----------------------------------------//
	if(data->valid == 0)
	{
		ft_render(data);
		mlx_terminate(data->mlx);
	}
	ft_freeall(data->map);
	free(data);
	return (0);
}
