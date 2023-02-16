/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emlamoth <emlamoth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 15:41:54 by emlamoth          #+#    #+#             */
/*   Updated: 2023/02/16 15:20:16 by emlamoth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 256
# endif

# include "./libft/libft.h"
# include <fcntl.h>
# include <stdio.h>

typedef struct s_map
{
	int		line;
	int		col;
	int		totallen;
	int		player;
	int		exit;
	int		collect;
	int		rectangle;
	int		walled;
	
}				t_map;

t_map	*ft_parsing(int fd);
t_map	ft_map_param(char *file, t_map *map);

char	*ft_read_map(int fd);

int ft_ber(char *path)


#endif