/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   norm_pars1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-kouc <ael-kouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 11:05:16 by ael-kouc          #+#    #+#             */
/*   Updated: 2022/12/10 11:08:18 by ael-kouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	skip_space_end(char *str)
{
	int	i;

	i = ft_strlen(str) - 1;
	while (i >= 0 && str[i] <= 32)
		i--;
	return (i);
}

int	skip_space_start(char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i] <= 32)
		i++;
	return (i);
}

int	check_1(char **str)
{
	int	i;
	int	a;
	int	b;

	i = 1;
	while (str[i])
	{
		a = skip_space_end(str[i]);
		b = skip_space_start(str[i]);
		if (!(str[i][a] == '1' && str[i][b] == '1'))
			return (1);
		i++;
	}
	return (0);
}

t_lexer	*init_lexer(char *src)
{
	t_lexer	*lexer;

	lexer = malloc(sizeof(t_lexer));
	lexer->src = ft_strdup(src);
	lexer->src_size = ft_strlen(src);
	lexer->i = 0;
	lexer->j = 0;
	lexer->c = lexer->src[lexer->i];
	return (lexer);
}

void	lexer_skip_space_line(t_lexer *lexer)
{
	while (lexer->src[lexer->i] == ' ' || lexer->src[lexer->i] == '\t'
		|| lexer->src[lexer->i] == '\n' || lexer->src[lexer->i] == '\r'
		|| lexer->src[lexer->i] == '~')
		lexer_advance(lexer);
}
