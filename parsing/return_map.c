/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   return_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-kouc <ael-kouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 11:14:49 by ael-kouc          #+#    #+#             */
/*   Updated: 2022/12/13 14:23:45 by ael-kouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	norm_filinfo1(t_cubd *cub, t_lexer *lexer, t_g *g)
{
	if (lexer->c == 'N' && g->flag_no == 1)
	{
		g->flag_no = 0;
		cub->no = check_id(lexer, cub, "NO", g);
	}
	else if (lexer->c == 'S' && g->flag_so == 1)
	{
		g->flag_so = 0;
		cub->so = check_id(lexer, cub, "SO", g);
	}
	else if (lexer->c == 'W' && g->flag_we == 1)
	{
		g->flag_we = 0;
		cub->we = check_id(lexer, cub, "WE", g);
	}
	else
		return (1);
	return (0);
}

int	norm_filinfo2(t_cubd *cub, t_lexer *lexer, t_g *g)
{
	if (lexer->c == 'E' && g->flag_ea == 1)
	{
		g->flag_ea = 0;
		cub->ea = check_id(lexer, cub, "EA", g);
	}
	else if (lexer->c == 'F' && g->flag_f == 1)
	{
		g->flag_f = 0;
		cub->f_col = take_col(lexer, cub, "F", g);
	}
	else if (lexer->c == 'C' && g->flag_c == 1)
	{
		g->flag_c = 0;
		cub->c_col = take_col(lexer, cub, "C", g);
	}
	else if (g->take_the_map == 0)
		cub->map = swap_to_double(take_map(lexer));
	else
		return (1);
	return (0);
}

void	fill_info(t_cubd *cub, char *map)
{
	t_lexer	*lexer;
	t_g		*g;

	g = init_globals();
	lexer = init_lexer(map);
	free(map);
	while (lexer->c)
	{
		lexer_skip_space_line(lexer);
		if (norm_filinfo1(cub, lexer, g) && norm_filinfo2(cub, lexer, g))
		{
			free(g);
			err_fre_lex_cub(lexer, cub);
		}
		else
			lexer_advance(lexer);
	}
	free(lexer->src);
	free(lexer);
	free(g);
}

void	verif_name_folder(char *av, t_cubd *cub)
{
	int	lent;

	lent = (int)ft_strlen(av) - 1;
	if (!(av[lent] == 'b' && av[lent - 1] == 'u'
			&& av[lent - 2] == 'c' && av[lent - 3] == '.'))
	{
		free(cub);
		printf("error\n");
		exit(1);
	}
}

t_cubd	*return_map(char *av, t_cubd *cub)
{
	char	*map;
	int		fd;
	int		i;

	verif_name_folder(av, cub);
	fd = open(av, O_RDONLY);
	if (fd == -1)
	{
		printf("error\n");
		exit(1);
	}
	map = change_value(line_map(fd));
	fill_info(cub, map);
	i = lent_double_p(cub->map) - 1;
	if (i < 2)
		exit(1);
	check_map(cub);
	return (cub);
}
