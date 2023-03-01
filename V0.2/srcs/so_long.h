/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emlamoth <emlamoth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 15:41:54 by emlamoth          #+#    #+#             */
/*   Updated: 2023/03/01 18:07:06 by emlamoth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

//-------------------------------PARAMETRES----------------------------------//
# define PRGNAME "So_long"
# define BUFFER_SIZE 128
# define IMG_SIZE 64

//-------------------------------PATHS---------------------------------------//
# define WALL "./visual/LavaX64.png"
# define FLOOR "./visual/FloorX64.png"
# define PLAYERFRONT "./visual/DevFrontX64.png"
# define PLAYERBACK "./visual/DevBackX64.png"
# define PLAYERLEFT "./visual/DevLeftX64.png"
# define PLAYERRIGHT "./visual/DevRightX64.png"
# define COLLECT "./visual/SoulX64.png"
# define EXITOPEN "./visual/OpenPortX64.png"
# define EXITCLOSE "./visual/ClosePortX64.png"
# define ENEMYFRONT "./visual/AngelFrontX64.png"
# define ENEMYBACK "./visual/AngelBackX64.png"
# define ENEMYLEFT "./visual/AngelLeftX64.png"
# define ENEMYRIGHT "./visual/AngelRightX64.png"

//-------------------------------MESSAGES------------------------------------//
# define VALID "------SUCCÈS------\nCarte valide ! :)\n"
# define ERVALID "------ERREUR-------\nCarte non valide ! :(\n"
# define ERPLAYERMSS "Pas de joueur présent sur la carte.\n"
# define ERPLAYERCNT  "Carte solo, trop de joueurs présents.\n"
# define EREXITMSS "Pas de sortie présente sur la carte.\n"
# define EREXITMR "Trop de sorties sur la carte.\n"
# define ERCOLLECT "Pas d'objet sur la carte.\n"
# define ERFLOODCOL "Objet(s) inatteignable(s).\n"
# define ERFLOODEXT "Sortie inatteignable.\n"
# define ERFLOOD  "Carte non terminable.\n"
# define ERRECT  "Carte non rectangulaire.\n"
# define ERWALL  "Carte non encadrée.\n"
# define ERWRONGC "Caratère(s) invalide(s) présent(s) sur la carte.\n"
# define ERCOLMAX "Carte trop large (Max 40 colones)\n"
# define ERLINEMAX "Carte trop longue (Max 22 lignes)\n"

//------------------------------INCLUDE--------------------------------------//
# include "./libft/libft.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include "../MLX42/include/MLX42/MLX42.h"

//-------------------------------STRUCTS-------------------------------------//
typedef struct s_flood
{
	char	**map;
	int		collect;
	int		exit;
	int		done;
}				t_flood;

typedef struct s_character
{
	int		count;
	char	direct;
	int		pos_x;
	int		pos_y;
}				t_character;

typedef struct s_texture
{
	mlx_texture_t	*floor;
	mlx_texture_t	*wall;
	mlx_texture_t	*playerfront;
	mlx_texture_t	*playerback;
	mlx_texture_t	*playerleft;
	mlx_texture_t	*playerright;
	mlx_texture_t	*collect;
	mlx_texture_t	*exitclose;
	mlx_texture_t	*exitopen;
	mlx_texture_t	*enemyfront;
	mlx_texture_t	*enemyback;
	mlx_texture_t	*enemyleft;
	mlx_texture_t	*enemyright;
}				t_texture;

typedef struct s_img
{
	mlx_image_t		*floor;
	mlx_image_t		*wall;
	mlx_image_t		*playerfront;
	mlx_image_t		*playerback;
	mlx_image_t		*playerleft;
	mlx_image_t		*playerright;
	mlx_image_t		*collect;
	mlx_image_t		*exitopen;
	mlx_image_t		*exitclose;
	mlx_image_t		*enemyfront;
	mlx_image_t		*enemyback;
	mlx_image_t		*enemyleft;
	mlx_image_t		*enemyright;
}				t_img;

typedef struct s_data
{
	mlx_t			*mlx;
	int				steps;
	int				line;
	int				col;
	int				exit;
	int				collect;
	int				wrongchar;
	int				rectangle;
	int				walled;
	int				valid;
	char			**map;
	t_character		player;
	t_character		enemy;
	t_flood			flood;
	t_texture		texture;
	t_img			image;
}				t_data;

//-------------------------------PROTOTYPAGES--------------------------------//
void	ft_init_data(t_data *data);
void	ft_init_map(char *path, t_data *data);
void	ft_map_data(t_data *data);
void	ft_map_size(char *path, t_data *data);
void	ft_message(t_data *data);
void	ft_validate(t_data *data);

#endif