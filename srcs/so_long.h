/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emlamoth <emlamoth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 15:41:54 by emlamoth          #+#    #+#             */
/*   Updated: 2023/02/21 17:36:17 by emlamoth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define BUFFER_SIZE 128
# define IMG_SIZE 64

# define WALL "./visual/Lavax64.png"
# define FLOOR "./visual/rock2x64.png"
# define PLAYER "./visual/rock2wdemonx64.png"
# define COLLECT "./visual/rock2soulx64.png"
# define EXIT "./visual/rock2x64blackhole.png"


# include "./libft/libft.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include "../MLX42/include/MLX42/MLX42.h"


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
	char	**map_a;

}				t_map;

typedef struct	s_texture
{
	mlx_image_t	*wall;
	mlx_image_t	*floor;
	mlx_image_t	*player;
	mlx_image_t	*exit;
	mlx_image_t	*collect;
}				t_texture;

t_map		*ft_parsing(int fd);
t_map		*ft_map_param(char *file, t_map *map);
t_map		*ft_map_init(t_map *map);

char		*ft_read_map(int fd);

int			ft_ber(char *path);
int ft_render(t_map *map, mlx_t *mlx, t_texture texture);

t_texture	ft_texture_init(mlx_t *mlx);

mlx_t		*ft_mlx_init(t_map *map);
mlx_image_t	*ft_parse_texture(t_texture *texture, t_map *map, int y, int x);

#endif