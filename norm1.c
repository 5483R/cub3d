/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   norm1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-kouc <ael-kouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 10:44:32 by ael-kouc          #+#    #+#             */
/*   Updated: 2022/12/10 10:47:05 by ael-kouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	calc_with(char **map)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (map[i])
	{
		if (j < (int)ft_strlen(map[i]))
			j = (int)ft_strlen(map[i]);
		i++;
	}
	return (j);
}

int	calc_hight(char **map)
{
	return (lent_double_p(map));
}

t_tood	*get_info_of2d(t_cubd *cub)
{
	t_tood	*todmap;

	todmap = malloc(sizeof(t_tood));
	todmap->hight = calc_hight(cub->map) * TILE_SIZE;
	todmap->with = calc_with(cub->map) * TILE_SIZE;
	return (todmap);
}
