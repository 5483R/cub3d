/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_outils1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schoukou <schoukou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 00:27:22 by ael-kouc          #+#    #+#             */
/*   Updated: 2022/11/28 22:31:37 by schoukou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void    free_double_p(char **str)
{
    int i;

    i = 0;
    while(str[i])
        free(str[i++]);
    free(str);
}

int lent_double_p(char **str)
{
    int i;
    
    i = 0;
    if(!str)
        return(0);
    while(str[i])
        i++;
    return(i);
}


int check_numbers(char **str)
{
    int i;
    int j;

    i = 0;
    while(str[i])
    {
        j = 0;
        while(str[i][j])
        {
            if(!(str[i][j] >= '0' && str[i][j] <= '9'))
                return(1);
            j++;
        }
        i++;
    }
    return(0);
}

char    **find_er(t_lexer *lexer, cub3d_t *cub, char *str)
{
    char    **spl_tmp;
    
    spl_tmp = ft_split(str, ',');
    free(str);
    if((lent_double_p(spl_tmp) < 3 
        || lent_double_p(spl_tmp) > 3) || check_numbers(spl_tmp))
    {
        free_double_p(spl_tmp);
        err_fre_lex_cub(lexer, cub);
    }
    return(spl_tmp);
}

int one_player(char **str, cub3d_t *cub)
{
    int i;
    int j;
    int calc;
    
    i = 0;
    j = 0;
    calc = 0;
    while(str[i])
    {
        j = 0;
        while(str[i][j])
        {
            if(str[i][j] == 'N' || str[i][j] == 'S'
                || str[i][j] == 'E' || str[i][j] == 'W')
            {
                cub->x_player = (double )j;
                cub->y_player = (double )i;
                if(str[i][j] == 'N')
                    cub->ang = 1.5 * M_PI;
                else if(str[i][j] == 'E')
                    cub->ang = 0;
                else if(str[i][j] == 'W')
                    cub->ang = M_PI;
                else
                    cub->ang = M_PI_2;
                str[i][j] = '0';
                calc++;
            }
            j++;
        }
        i++;
    }
    if(calc != 1)
        return(1);
    return(0);
}