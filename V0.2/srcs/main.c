/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emlamoth <emlamoth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 15:51:40 by emlamoth          #+#    #+#             */
/*   Updated: 2023/02/22 19:08:03 by emlamoth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void ft_map_size(char *path, t_data *data)
{
	int		i;
	char	*str;
	int		fd;
		
	i = 0;
	fd = open(path, O_RDONLY);
	while(1)
	{
		str = get_next_line(fd);
		if(str == NULL)
			break;
		free(str);
		i++;
	}
	close (fd);
	data->line = i;
}

void	ft_init_map(char *path, t_data *data)
{
	int		i;
	int		fd;
	
	
	data->map = ft_calloc((data->line + 1), (sizeof(char *)));
	i = 0;
	fd = open(path, O_RDONLY);
	while(i < data->line)
		data->map[i++] = get_next_line(fd);
	close (fd);
	data->col = ft_strlen(data->map[0]);
}

char	**ft_2dcpy(char **src)
{
	char	**new;
	int		i;
	
	i = 0;
	while(src[i])
		i++;
	new = ft_calloc((i + 1), sizeof(*src));
	i = 0;
	while(src[i])
	{
		new[i] = ft_calloc(ft_strlen(src[i]), sizeof(char));
		ft_strlcpy(new[i], src[i], ft_strlen(src[i]));
		printf("new%s", new[i]);
		i++;
	}
	return(new);
}

void	ft_map_data(t_data *data)
{
	int	y;
	int	x;
	
	y = 0;
	while(data->map[y])
	{
		x = 0;
		while(data->map[y][x])
		{
			if(data->map[y][x] == 'P')
				data->player++;
			else if(data->map[y][x] == 'E')
				data->exit++;
			else if(data->map[y][x] == 'C')
				data->collect++;
			else if(data->map[y][x] == '1' || data->map[y][x] == '0'
				|| data->map[y][x] == '\n')
				;
			else
				data->wrongChar++;
			x++;
		}
		y++;
	}
}

void	ft_init_data(t_data *data)
{
	data->line = 0;
	data->col = 0;
	data->player = 0;
	data->exit = 0;
	data->collect = 0;
	data->wrongChar = 0;
	data->rectangle = 0;
	data->walled = 0;
	data->map = NULL;
	data->floodmap = NULL;
}

int	main(int argc, char **argv)
{
	t_data		*data;

	if (argc != 2)
		return (ft_printf("Argument invalide"));
	if (ft_strncmp(&argv[1][ft_strlen(argv[1]) - 4], ".ber", 4))
		return (ft_printf("Format de carte invalide"));
	data = malloc(sizeof(*data));
	if(!data)
		return(1);
	ft_init_data(data);
	ft_map_size(argv[1], data);
	ft_init_map(argv[1], data);
	ft_map_data(data);
	data->floodmap = ft_2dcpy(data->map);
	// ft_validate(data);
	ft_printf("Nombre de lignes = %d\n", data->line);
	ft_printf("Nombre de collones = %d\n", data->col);
	ft_printf("Nombre de players = %d\n", data->player);
	ft_printf("Nombre de exit = %d\n", data->exit);
	ft_printf("Nombre de collect = %d\n", data->collect);
	ft_printf("Nombre de mauvais Char = %d\n", data->wrongChar);
	ft_printf("Map rectangulaire = %d\n", data->rectangle);
	// ft_printf("Map walled = %d\n", ft_strlen(**data->map));
	ft_printf("%s\n", data->map[5]);
	ft_freeall(data->map);
	ft_freeall(data->floodmap);
	return(0);
}
