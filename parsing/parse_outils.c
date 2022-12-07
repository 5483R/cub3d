/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_outils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-kouc <ael-kouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 02:00:38 by ael-kouc          #+#    #+#             */
/*   Updated: 2022/10/27 01:02:06 by ael-kouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"


char	*check_id(t_lexer *lexer, cub3d_t *cub, char *str)
{
	take_the_map--;
	lexer_advance(lexer);
	if(ft_strlen(str) > 1)
	{
		if(lexer->c != str[1])
			err_fre_lex_cub(lexer, cub);
		lexer_advance(lexer);
		lexer_skip_space(lexer);
		if(!(lexer->c == '.' && lexer->src[lexer->i + 1] == '/'))
			err_fre_lex_cub(lexer, cub);	
	}
	else
		lexer_skip_space(lexer);
	return(take_id(lexer, cub));
}

char	*change_value(char *str)
{
    int	i;

	i = 0;
	while(str[i])
	{
		if(str[i] == '\n')
		{
			i++;
			while(str[i] == '\n')
				str[i++] = '~';
		}
		else
			i++;
	}
	return(str);
}


int	find_path(char *str, char *search)
{
	int i;
	int j;
	int b;
	
	i = 0;
	while(str[i])
	{
		j = 0;
		if(str[i] == search[j])
		{
			b = i;
			while(str[i] && search[j] && str[i] == search[j])
			{
				j++;
				i++;
			}
			if(search[j] == '\0')
				return(1);
		}
		else
			i++;
	}
	return(0);
}

int	check_if_true(char *str)
{
	if(find_path(str, "F")
		&& find_path(str, "C")
		&& find_path(str, "NO")
		&& find_path(str, "SO")
		&& find_path(str, "WE")
		&& find_path(str, "EA"))
		return(1);
	return(0);
}

int	*take_col(t_lexer *lexer, cub3d_t *cub, char *str)
{
	char	*tmp;
	char	**spl_tmp;
	int		*color;
	int		i;

	tmp = check_id(lexer, cub, str);
	spl_tmp = find_er(lexer, cub, tmp);
	color = malloc(sizeof(int) * 3);
	i = 0;
	while(spl_tmp[i])
	{
		color[i] = ft_atoi(spl_tmp[i]);
		if(color[i] > 255)
		{
			free(color);
			free_double_p(spl_tmp);
			err_fre_lex_cub(lexer, cub);
		}
		i++;
	}
	free_double_p(spl_tmp);
	return(color);
}