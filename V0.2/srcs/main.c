/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emlamoth <emlamoth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 15:51:40 by emlamoth          #+#    #+#             */
/*   Updated: 2023/02/28 09:48:31 by emlamoth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


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
	//ft_render();
	//-------------------TESTING AREA----------------------------------------//
	// ft_printf("Nombre de lignes = %d\n", data->line);
	// ft_printf("Nombre de collones avec \\n = %d\n", data->col);
	// ft_printf("Nombre de players = %d\n", data->player);
	// ft_printf("Nombre de exit = %d\n", data->exit);
	// ft_printf("Nombre de collect = %d\n", data->collect);
	// ft_printf("Nombre de mauvais Char = %d\n", data->wrongChar);
	// ft_printf("Map rectangulaire = %d\n", data->rectangle);
	// ft_printf("Map valide = %d\n", data->valid);
	// ft_printf("Map walled = %d\n", data->walled);
	// ft_printf("Map flood exit = %d\n", data->flood.exit);
	// ft_printf("Map flood collect = %d\n", data->flood.collect);
	//-------------------TESTING AREA----------------------------------------//
	ft_freeall(data->map);
	free(data);
	return (0);
}
