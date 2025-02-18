/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbakour <zbakour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 17:13:17 by zbakour           #+#    #+#             */
/*   Updated: 2025/02/18 17:58:04 by zbakour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_enemy(t_game *game, t_enemy *enemy)
{
	int	new_x;
	int	new_y;

	new_x = enemy->x + enemy->direction;
	new_y = enemy->y;
	if (game->map->ptr[new_y][new_x] == '1'
			|| game->map->ptr[new_y][new_x] == 'X'
			|| game->map->ptr[new_y][new_x] == 'G'
			|| game->map->ptr[new_y][new_x] == 'C'
			|| game->map->ptr[new_y][new_x] == 'E')
		enemy->direction *= -1;
	else
	{
		game->map->ptr[enemy->y][enemy->x] = '0';
		render_image(game, "textures/bg_64n.xpm", enemy->x * TILE_SIZE, enemy->y
			* TILE_SIZE);
		enemy->x = new_x;
		game->map->ptr[enemy->y][enemy->x] = 'T';
		render_image(game, "textures/env/enemy.xpm", new_x * TILE_SIZE, enemy->y
			* TILE_SIZE);
	}
}
