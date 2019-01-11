/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_peace.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlenskyi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/11 15:56:57 by dlenskyi          #+#    #+#             */
/*   Updated: 2019/01/11 15:56:58 by dlenskyi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		is_safe(int x, int y, t_fill_gen *g)
{
	int k;
	int i;
	int j;

	i = -1;
	k = 0;
	while (g->piece.size[++i])
	{
		j = -1;
		while (g->piece.size[i][++j])
		{
			if (g->piece.size[i][j] == '*' &&
				((((y + i >= g->map.y || x + j >= g->map.x) ||
				(y + i < 0 || x + j < 0))) ||
				(g->map.size[y + i][x + j] == g->player.robot ||
				g->map.size[y + i][x + j] == g->player.robot + 32)))
				return (0);
			if (g->piece.size[i][j] == '*' && (g->map.size[y + i][x + j] ==
				g->player.human))
				k++;
		}
	}
	return (k == 1 ? 1 : 0);
}

void	print_left(t_fill_gen *g)
{
	int x;
	int y;

	x = 0;
	while (x <= g->map.x)
	{
		y = 0;
		while (y <= g->map.y)
		{
			if (is_safe(x, y, g))
			{
				g->fill.x = x;
				g->fill.y = y;
				return ;
			}
			y++;
		}
		x++;
	}
}

void	print_right(t_fill_gen *g)
{
	int x;
	int y;

	x = g->map.x;
	while (x > 0)
	{
		y = g->map.y;
		while (y > 0)
		{
			if (is_safe(x, y, g))
			{
				g->fill.x = x;
				g->fill.y = y;
				return ;
			}
			y--;
		}
		x--;
	}
}

void	fill_piece(t_fill_gen *g)
{
	validate_piece(g);
	if (g->fill.fill == 1)
		put_top_pos(g);
	else if (g->fill.fill == 4)
		put_bot_pos(g);
	else if (g->fill.fill == 2)
		put_left_pos(g);
	else if (g->fill.fill == 3)
		put_right_pos(g);
	else if (g->fill.fill == 5)
		print_left(g);
	else if (g->fill.fill == 6)
		print_right(g);
	ft_printf("%d %d\n", g->fill.y, g->fill.x);
}

void	if_the_best(t_fill_gen *g)
{
	char	*line;

	if (get_next_line(0, &line) < 1)
		return ;
	if (g->map.size)
		ft_del_strsplit(g->map.size);
	get_map_data(g, line);
	free(line);
	if (get_next_line(0, &line) < 1)
		quit("Reading error\n", g);
	if (g->piece.size)
		ft_del_strsplit(g->piece.size);
	get_piece_data(line, g);
	fill_piece(g);
}
