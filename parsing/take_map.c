/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   take_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-kouc <ael-kouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 01:18:18 by ael-kouc          #+#    #+#             */
/*   Updated: 2022/10/26 04:05:18 by ael-kouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

char    *take_line(t_lexer *lexer)
{
    char *str;
    char *tmp;
    char *c;

    str = ft_strdup("");
    while(lexer->c)
    {
        // printf("{%c}\n", lexer->c);
        if(lexer->c == '\n')
            break;
        tmp = str;
        c = get_c_as_str(lexer->c);
        str = ft_strjoin(str, c);
        free(tmp);
        free(c);
        lexer_advance(lexer);
    }
    return(str);
}

t_map    *take_map(t_lexer *lexer)
{
    t_map *map;

    map =NULL;
    while(lexer->c && (lexer->c == '~' || lexer->c == ' ' || lexer->c == '\n'))
        lexer_advance(lexer);
    while(lexer->src[lexer->i - 1] == ' ')
        lexer_back(lexer);
    while(lexer->c)
    {
        token_add_back(&map, take_line(lexer));
        lexer_advance(lexer);
    }
    return(map);
}