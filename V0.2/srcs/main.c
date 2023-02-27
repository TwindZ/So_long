/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emlamoth <emlamoth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 15:51:40 by emlamoth          #+#    #+#             */
/*   Updated: 2023/02/27 17:09:13 by emlamoth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_init_data(t_data *data)
{
	data->line = 0;
	data->col = 0;
	data->exit = 0;
	data->collect = 0;
	data->wrongChar = 0;
	data->rectangle = 0;
	data->walled = 0;
	data->valid = 0;
	data->map = NULL;
	data->player.count = 0;
	data->player.pos_x = 0;
	data->player.pos_y = 0;
	data->flood.map = NULL;
	data->flood.collect = 0;
	data->flood.exit = 0;
	data->flood.done = 1;
}

void ft_map_size(char *path, t_data *data)
{
	char	*str;
	int		fd;
	int		i;
		
	i = 0;
	fd = open(path, O_RDONLY);
	while(1)
	{
		str = get_next_line(fd);
		if(!str)
			break;
		free(str);
		i++;
	}
	free(str);
	close (fd);
	data->line = i;
}
void	ft_message(t_data *data)
{
	if(data->valid == 1)
		ft_printf(ERVALID);
	if(data->valid == 0)
		ft_printf(VALID);
	if(data->collect < 1)
		ft_printf(ERCOLLECT);
	if(data->exit > 1)
		ft_printf(EREXITMR);
	if(data->exit < 1)
		ft_printf(EREXITMSS);
	if(data->player.count > 1)
		ft_printf(ERPLAYERCNT);
	if(data->player.count < 1)
		ft_printf(ERPLAYERMSS);
	if(data->rectangle > 0)
		ft_printf(ERRECT);
	if(data->walled > 0)
		ft_printf(ERWALL);
	if(data->flood.exit != data->exit && data->flood.done == 0)
		ft_printf(ERFLOODEXT);
	if(data->flood.collect != data->collect && data->flood.done == 0)
		ft_printf(ERFLOODCOL);		
}

int	main(int argc, char **argv)
{
	t_data		*data;

	if (argc != 2)
		return (ft_printf("Argument invalide !"));
	if (ft_strncmp(&argv[1][ft_strlen(argv[1]) - 4], ".ber", 4))
		return (ft_printf("Format de carte invalide !"));
	data = malloc(sizeof(*data));
	if(!data)
		return(ft_printf("Problème de création de struct data !"));
	ft_init_data(data);
	ft_map_size(argv[1], data);
	ft_init_map(argv[1], data);
	ft_map_data(data);
	ft_validate(data);
	ft_message(data);
	//-------------------TESTING AREA----------------------------------------//
	ft_printf("Nombre de lignes = %d\n", data->line);
	ft_printf("Nombre de collones avec \\n = %d\n", data->col);
	ft_printf("Nombre de players = %d\n", data->player);
	ft_printf("Nombre de exit = %d\n", data->exit);
	ft_printf("Nombre de collect = %d\n", data->collect);
	ft_printf("Nombre de mauvais Char = %d\n", data->wrongChar);
	ft_printf("Map rectangulaire = %d\n", data->rectangle);
	ft_printf("Map valide = %d\n", data->valid);
	ft_printf("Map walled = %d\n", data->walled);
	ft_printf("Map flood exit = %d\n", data->flood.exit);
	ft_printf("Map flood collect = %d\n", data->flood.collect);
	//-------------------TESTING AREA----------------------------------------//
	ft_freeall(data->map);
	//ft_freeall(data->flood.map);
	free(data);
	return(0);
}
