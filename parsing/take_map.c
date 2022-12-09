/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   take_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-kouc <ael-kouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 01:18:18 by ael-kouc          #+#    #+#             */
/*   Updated: 2022/12/09 16:38:13 by ael-kouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

char	*take_line(t_lexer *lexer)
{
	char	*str;
	char	*tmp;
	char	*c;

	str = ft_strdup("");
	while (lexer->c)
	{
		if (lexer->c == '\n')
			break ;
		tmp = str;
		c = get_c_as_str(lexer->c);
		str = ft_strjoin(str, c);
		free(tmp);
		free(c);
		lexer_advance(lexer);
	}
	return (str);
}

t_map	*take_map(t_lexer *lexer)
{
	t_map	*map;

	map = NULL;
	while (lexer->c && (lexer->c == '~' || lexer->c == ' ' || lexer->c == '\n'))
		lexer_advance(lexer);
	while (lexer->src[lexer->i - 1] == ' ')
		lexer_back(lexer);
	while (lexer->c)
	{
		token_add_back(&map, take_line(lexer));
		lexer_advance(lexer);
	}
	return (map);
}

void	norm_oneplayer(t_cubd *cub, char **str, int i, int j)
{
	cub->x_player = (double )j;
	cub->y_player = (double )i;
	if (str[i][j] == 'N')
		cub->ang = 1.5 * M_PI;
	else if (str[i][j] == 'E')
		cub->ang = 0;
	else if (str[i][j] == 'W')
		cub->ang = M_PI;
	else
		cub->ang = M_PI_2;
	str[i][j] = '0';
}

void	norm_take_colore(int *color, char **spl_tmp,
	t_cubd *cub, t_lexer *lexer)
{
	free(color);
	free_double_p(spl_tmp);
	err_fre_lex_cub(lexer, cub);
}
