/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-kouc <ael-kouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 02:04:58 by ael-kouc          #+#    #+#             */
/*   Updated: 2022/12/11 10:55:16 by ael-kouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	sur_by_walls(char **map)
{
	int	j;
	int	a;

	a = 0;
	j = lent_double_p(map) - 1;
	while (map[0][a])
	{
		if (!(map[0][a] <= 32 || map[0][a] == '1'))
			return (1);
		a++;
	}
	a = 0;
	while (map[j][a])
	{
		if (!(map[j][a] <= 32 || map[j][a] == '1'))
			return (1);
		a++;
	}
	return (0);
}

int	all_element(char **map)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	while (map[0][j])
	{
		if (!(map[0][j] == '~' || map[0][j] == '1' || map[0][j] <= 32))
			return (1);
		j++;
	}
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (!(map[i][j] == '1' || map[i][j] == '0'
				|| map[i][j] == 'N' || map[i][j] == 'S' || map[i][j] == 'E'
				|| map[i][j] == 'W' || map[i][j] <= 32))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

void	free_cub(t_cubd *cub)
{
	free(cub->no);
	free(cub->so);
	free(cub->ea);
	free(cub->we);
	free(cub->f_col);
	free(cub->c_col);
	free_double_p(cub->map);
}

void	check_txs(t_cubd *cub)
{
	int	fd[4];
	int	f;
	int	i;

	i = 0;
	f = 0;
	fd[0] = open(cub->no, O_RDONLY);
	if (fd[0] == -1)
		f += 1;
	fd[1] = open(cub->so, O_RDONLY);
	if (fd[1] == -1)
		f += 1;
	fd[2] = open(cub->we, O_RDONLY);
	if (fd[2] == -1)
		f += 1;
	fd[3] = open(cub->ea, O_RDONLY);
	if (fd[3] == -1)
		f += 1;
	if (f != 0)
	{
		free(cub);
		exit_mssg("ERROR\n");
	}
	while (i < 4)
		close(fd[i++]);
}

void	check_map(t_cubd *cub)
{
	check_txs(cub);
	if (all_element(cub->map) || sur_by_walls(cub->map)
		|| check_1(cub->map) || check_spaces(cub->map)
		|| one_player(cub->map, cub))
	{
		free_cub(cub);
		exit_mssg("ERROR");
	}
}
