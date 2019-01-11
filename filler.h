/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlenskyi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/04 16:23:47 by dlenskyi          #+#    #+#             */
/*   Updated: 2019/01/04 16:23:49 by dlenskyi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include "libft/includes/libft.h"
# include "mlx.h"

typedef struct		s_fill_player
{
	char			robot;
	char			human;
}					t_fill_player;

typedef struct		s_fill_piece
{
	char			**size;
	int				x;
	int				y;
}					t_fill_piece;

typedef struct		s_fill_map
{
	char			**size;
	int				x;
	int				y;
}					t_fill_map;

typedef struct		s_fill_pos
{
	int				pos;
	int				distance_x;
	int				distance_y;
}					t_fill_pos;

typedef struct		s_fill
{
	int				fill;
	int				x;
	int				y;
}					t_fill;

typedef struct		s_fill_mlx
{
	void			*mlx_ptr;
	void			*win_ptr;
	int				width;
	int				height;
}					t_fill_mlx;

typedef struct		s_fill_gen
{
	t_fill_mlx		mlx;
	t_fill_player	player;
	t_fill_piece	piece;
	t_fill_map		map;
	t_fill_pos		pos;
	t_fill			fill;
}					t_fill_gen;

/*
**					getting all data
*/

void				get_human_data(t_fill_gen *g);
int					get_init_pos(t_fill_gen *g);
void				get_map_data(t_fill_gen *g, char *data);
void				get_piece_data(char *data, t_fill_gen *g);
void				get_mlx_data(t_fill_gen *g);

/*
**					getting piece coordinates
*/

int					top_pos(char c, t_fill_gen *g);
int					bot_pos(char c, t_fill_gen *g);
int					left_pos(char c, t_fill_gen *g);
int					right_pos(char c, t_fill_gen *g);

/*
**					validating piece position
*/

int					if_right_edge(t_fill_gen *g);
int					if_left_edge(t_fill_gen *g);
void				if_path_1(t_fill_gen *g);
void				if_path_2(t_fill_gen *g);
void				validate_piece(t_fill_gen *g);

/*
**					collecting all piece coords
*/

void				put_top_pos(t_fill_gen *g);
void				put_bot_pos(t_fill_gen *g);
void				put_left_pos(t_fill_gen *g);
void				put_right_pos(t_fill_gen *g);

/*
**					fill it! (if its safe and best choice, of course)
*/

int					is_safe(int x, int y, t_fill_gen *g);
void				print_left(t_fill_gen *g);
void				print_right(t_fill_gen *g);
void				if_the_best(t_fill_gen *g);
void				fill_piece(t_fill_gen *g);

/*
**					drawing pieces
*/

void				magic_border(t_fill_gen *g, int color, int x, int y);
void				magic_start_pos(t_fill_gen *g);
void				magic_piece(t_fill_gen *g);

/*
**					mlx loop and kb util
*/

int					ft_loop(t_fill_gen *g);
int					finish(int keycode);

/*
**					quitting the project
*/

void				quit(char *s, t_fill_gen *g);

#endif
