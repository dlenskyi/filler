/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_piece.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlenskyi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 17:16:22 by dlenskyi          #+#    #+#             */
/*   Updated: 2019/01/10 17:16:23 by dlenskyi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		if_right_edge(t_fill_gen *g)
{
	int y;

	y = 0;
	if (ft_strchr(g->map.size[0], g->player.human))
		return (1);
	while (g->map.size[y])
	{
		if (g->map.size[y][g->map.x - 1] == g->player.human)
			return (1);
		y++;
	}
	return (0);
}

int		if_left_edge(t_fill_gen *g)
{
	int y;

	y = 0;
	if (ft_strchr(g->map.size[g->map.y - 1], g->player.human))
		return (1);
	while (g->map.size[y])
	{
		if (g->map.size[y][0] == g->player.human)
			return (1);
		y++;
	}
	return (0);
}

void	if_path_1(t_fill_gen *g)
{
	if (ft_strchr(g->map.size[0], g->player.human) && if_left_edge(g))
		g->fill.fill = 5;
	else if (g->pos.distance_y > g->pos.distance_x)
		g->fill.fill = (ft_strchr(g->map.size[0], g->player.human)) ? 2 : 1;
	else
		g->fill.fill = (if_left_edge(g)) ? 1 : 2;
}

void	if_path_2(t_fill_gen *g)
{
	if (ft_strchr(g->map.size[g->map.y - 1], g->player.human) &&
		if_right_edge(g))
		g->fill.fill = 6;
	else if (g->pos.distance_y > g->pos.distance_x)
		g->fill.fill = (ft_strchr(g->map.size[g->map.y - 1],
		g->player.human)) ? 3 : 4;
	else
		g->fill.fill = (if_right_edge(g)) ? 4 : 3;
}

void	validate_piece(t_fill_gen *g)
{
	if (g->pos.pos == 1)
	{
		g->pos.distance_y = top_pos(g->player.robot, g);
		g->pos.distance_y -= bot_pos(g->player.human, g);
		g->pos.distance_x = left_pos(g->player.robot, g);
		g->pos.distance_x -= right_pos(g->player.human, g);
		if_path_2(g);
	}
	else if (g->pos.pos == 2)
	{
		g->pos.distance_y = top_pos(g->player.human, g);
		g->pos.distance_y -= bot_pos(g->player.robot, g);
		g->pos.distance_x = left_pos(g->player.human, g);
		g->pos.distance_x -= right_pos(g->player.robot, g);
		if_path_1(g);
	}
}
