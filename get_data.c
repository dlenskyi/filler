/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define_pos.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlenskyi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/04 16:51:32 by dlenskyi          #+#    #+#             */
/*   Updated: 2019/01/04 16:51:33 by dlenskyi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	get_human_data(t_fill_gen *g)
{
	char	*line;

	if (get_next_line(0, &line) < 1)
		quit("Reading error\n", g);
	if (ft_strstr(line, "p1"))
	{
		g->player.human = 'O';
		g->player.robot = 'X';
	}
	else if (ft_strstr(line, "p2"))
	{
		g->player.human = 'X';
		g->player.robot = 'O';
	}
	free(line);
}

int		get_init_pos(t_fill_gen *g)
{
	int x;
	int y;

	y = 0;
	while (g->map.size[y])
	{
		x = 0;
		while (g->map.size[y][x])
		{
			if (g->map.size[y][x] == g->player.human)
				return (1);
			else if (g->map.size[y][x] == g->player.robot)
				return (2);
			x++;
		}
		y++;
	}
	return (0);
}

void	get_map_data(t_fill_gen *g, char *data)
{
	char	**str;
	char	*line;
	int		i;

	i = -1;
	if (!(str = ft_strsplit(data, ' ')))
		quit("Initialization error\n", g);
	g->map.y = ft_atoi(str[1]);
	g->map.x = ft_atoi(str[2]);
	if (!(g->map.size = ft_memalloc(sizeof(char*) * (g->map.y + 1))))
		quit("Initialization error\n", g);
	get_next_line(0, &line);
	free(line);
	ft_del_strsplit(str);
	while (++i < g->map.y)
	{
		if (get_next_line(0, &line) < 1)
			quit("Reading error\n", g);
		g->map.size[i] = ft_strdup(line + 4);
		free(line);
	}
	if (!g->pos.pos)
		g->pos.pos = get_init_pos(g);
}

void	get_piece_data(char *data, t_fill_gen *g)
{
	int		i;
	char	**str;

	i = -1;
	if (!(str = ft_strsplit(data, ' ')))
		quit("Initialization error\n", g);
	g->piece.y = ft_atoi(str[1]);
	g->piece.x = ft_atoi(str[2]);
	ft_del_strsplit(str);
	if (!(g->piece.size = ft_memalloc(sizeof(char*) * (g->piece.y + 1))))
		quit("Initialization error\n", g);
	while (++i < g->piece.y)
	{
		if (get_next_line(0, &g->piece.size[i]) < 1)
			quit("Reading error\n", g);
	}
}

void	get_mlx_data(t_fill_gen *g)
{
	g->mlx.width = g->map.x * 11 + 50;
	g->mlx.height = g->map.y * 11 + 50;
	g->mlx.mlx_ptr = mlx_init();
	g->mlx.win_ptr = mlx_new_window(g->mlx.mlx_ptr, g->mlx.width,
					g->mlx.height, "Filler");
	magic_start_pos(g);
}
