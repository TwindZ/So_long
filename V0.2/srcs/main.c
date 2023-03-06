/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emlamoth <emlamoth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 15:51:40 by emlamoth          #+#    #+#             */
/*   Updated: 2023/03/06 17:14:58 by emlamoth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_game(t_data *data)
{
	data->mlx = mlx_init(data->col * IMG_SIZE,
			data->line * IMG_SIZE + 50, PRGNAME, false);
	ft_load_texture(data);
	mlx_key_hook(data->mlx, &ft_key_detect, data);
	mlx_loop_hook(data->mlx, &ft_render, data);
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
	data->dificulty = (unsigned)ft_atoi(argv[2]);
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
	ft_printf("Nombre de enemies = %d\n", data->enemycount);
	ft_printf("Nombre de exit = %d\n", data->exit);
	ft_printf("Nombre de collect = %d\n", data->collect);
	ft_printf("Nombre de mauvais Char = %d\n", data->wrongchar);
	ft_printf("Map rectangulaire = %d\n", data->rectangle);
	ft_printf("Map valide = %d\n", data->valid);
	ft_printf("Map walled = %d\n", data->walled);
	ft_printf("Map flood exit = %d\n", data->flood.exit);
	ft_printf("Map flood collect = %d\n", data->flood.collect);
	//-------------------TESTING AREA----------------------------------------//
	if (data->valid == 0)
	{
		ft_game(data);
		mlx_terminate(data->mlx);
	}
	ft_freeall(data->map);
	free(data);
}
