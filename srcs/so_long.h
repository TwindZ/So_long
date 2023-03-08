/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emlamoth <emlamoth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 15:41:54 by emlamoth          #+#    #+#             */
/*   Updated: 2023/03/08 11:43:24 by emlamoth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

//-------------------------------PARAMETRES----------------------------------//
# define PRGNAME "Soul Long Keeper"
# define BUFFER_SIZE 128
# define IMG_SIZE 64

//-------------------------------PATHS---------------------------------------//
# define WALL1 "./visual/wall/LavaX64_1.png"
# define WALL2 "./visual/wall/LavaX64_2.png"
# define WALL3 "./visual/wall/LavaX64_3.png"
# define WALL4 "./visual/wall/LavaX64_4.png"
# define WALL5 "./visual/wall/LavaX64_5.png"
# define WALL6 "./visual/wall/LavaX64_6.png"
# define WALL7 "./visual/wall/LavaX64_7.png"
# define WALL8 "./visual/wall/LavaX64_8.png"
# define WALL9 "./visual/wall/LavaX64_9.png"
# define FLOOR "./visual/FloorX64.png"
# define PLAYERFRONT "./visual/devil/DevFrontX64.png"
# define PLAYERBACK "./visual/devil/DevBackX64.png"
# define PLAYERLEFT "./visual/devil/DevLeftX64.png"
# define PLAYERRIGHT "./visual/devil/DevRightX64.png"
# define COLLECT1 "./visual/soul/SoulX64_1.png"
# define COLLECT2 "./visual/soul/SoulX64_2.png"
# define COLLECT3 "./visual/soul/SoulX64_3.png"
# define COLLECT4 "./visual/soul/SoulX64_4.png"
# define COLLECT5 "./visual/soul/SoulX64_5.png"
# define COLLECT6 "./visual/soul/SoulX64_6.png"
# define COLLECT7 "./visual/soul/SoulX64_7.png"
# define EXITOPEN "./visual/OpenPortX64.png"
# define EXITCLOSE "./visual/ClosePortX64.png"
# define ENEMYFRONT "./visual/angel/AngelFrontX64.png"
# define ENEMYBACK "./visual/angel/AngelBackX64.png"
# define ENEMYLEFT "./visual/angel/AngelLeftX64.png"
# define ENEMYRIGHT "./visual/angel/AngelRightX64.png"

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
# define ERLINEMAX "Carte trop longue (Max 19 lignes)\n"
# define ERCOLMIN "Carte trop petite pour afficher les compteurs\n"

//------------------------------INCLUDE--------------------------------------//
# include "../MLX42/include/MLX42/MLX42.h"
# include "./libft/libft.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
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
	char	direct;
	int		pos_x;
	int		pos_y;
}				t_character;

typedef struct s_texture
{
	mlx_texture_t	*floor;
	mlx_texture_t	*wall[10];
	mlx_texture_t	*collect[8];
	mlx_texture_t	*playerfront;
	mlx_texture_t	*playerback;
	mlx_texture_t	*playerleft;
	mlx_texture_t	*playerright;
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
	mlx_image_t		*screenstr1;
	mlx_image_t		*screenstr2;
	mlx_image_t		*screenstr3;
	mlx_image_t		*screenstr4;
	mlx_image_t		*screenstr5;
}				t_img;

typedef struct s_data
{
	int				col;
	int				collect;
	int				collectindex;
	int				delay;
	int				dificulty;
	int				enemycount;
	int				enemydelay;
	int				exit;
	int				line;
	int				playercount;
	int				ramdom;
	int				rectangle;
	int				rendercount;
	int				steps;
	int				valid;
	int				wallindexdir;
	int				wallindex;
	int				walled;
	int				wrongchar;
	char			**map;
	mlx_t			*mlx;
	t_character		player;
	t_character		enemy;
	t_flood			flood;
	t_texture		texture;
	t_img			image;
	t_img			old_image;
}				t_data;

//-------------------------------PROTOTYPAGES--------------------------------//
mlx_image_t	*ft_e_direct(t_data *data);

void		ft_animation(t_data *data);
void		ft_death(t_data *data);
void		ft_del_old_img(t_data *data);
void		ft_enemy_rand(t_data *data);
void		ft_free_texture(t_data *data);
void		ft_go_and_back(t_data *data);
void		ft_init_data(t_data *data);
void		ft_init_map(char *path, t_data *data);
void		ft_img_to_win(t_data *data);
void		ft_key_detect(mlx_key_data_t keydata, void *param);
void		ft_load_texture(t_data *data);
void		ft_map_data(t_data *data);
void		ft_map_size(char *path, t_data *data);
void		ft_message(t_data *data);
void		ft_quit(t_data *data);
void		ft_render(void *param);
void		ft_screen_steps(t_data *data);
void		ft_screen_info(t_data *data);
void		ft_text_img(t_data *data);
void		ft_validate(t_data *data);

#endif