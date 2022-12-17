/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-kouc <ael-kouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 03:02:11 by ael-kouc          #+#    #+#             */
/*   Updated: 2022/12/10 11:07:50 by ael-kouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	lexer_skip_space(t_lexer *lexer)
{
	while (lexer->src[lexer->i] == ' ' || lexer->src[lexer->i] == '\t'
		|| lexer->src[lexer->i] == '\r')
		lexer_advance(lexer);
}

void	lexer_advance(t_lexer *lexer)
{
	if (lexer->i < lexer->src_size && lexer->c != '\0')
	{
		lexer->i++;
		lexer->c = lexer->src[lexer->i];
	}
}

char	*get_c_as_str(char c)
{
	char	*str;

	str = malloc(sizeof(char) * 2);
	str[0] = c;
	str[1] = '\0';
	return (str);
}

void	lexer_back(t_lexer *lexer)
{
	lexer->i--;
	lexer->c = lexer->src[lexer->i];
}

char	*take_id(t_lexer *lexer, t_cubd *cub)
{
	char	*value;
	char	*c;
	char	*tmp;

	value = ft_strdup("");
	while (lexer->c && lexer->c != '\n' && lexer->c != ' ')
	{
		c = get_c_as_str(lexer->c);
		tmp = value;
		value = ft_strjoin(value, c);
		free(tmp);
		free(c);
		lexer_advance(lexer);
	}
	lexer_skip_space(lexer);
	if (lexer->c != '\n')
		err_fre_lex_cub(lexer, cub);
	return (value);
}
