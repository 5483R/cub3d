#ifndef PARS_H
#define PARS_H

#include "../cub3d.h"

int flag_no;
int flag_so;
int flag_ea;
int flag_we;
int flag_f;
int flag_c;
int take_the_map;

typedef struct t_map
{
    char *str;
    struct t_map *next;
}   t_map;

typedef struct s_tood{
	int with;
	int hight;
}	t_tood;

typedef struct s_rays
{
    double  rayangle;
    double  wallHitx;
    double  wallHity;
    double  distance;
    double  projectionplan;
    double  projectiowalls;
    double  wallsheight;
    double		walltoppixel;
	double     wallbottompixel;
}   t_rays;

typedef struct s_cast
{
    double x_intercept;
    double y_intercept;
    double x_step;
    double y_step;
    double next_horz_x;
    double xtocheck;
    double ytocheck;
    double next_horz_y;
    double x_horz_w_hit;
    double y_horz_w_hit;
}   t_cast;

typedef struct texture_t
{
    void	*img;
    char    *add;
    int     bp;
    int     end;
    int     len;
}   texture_t;

typedef struct cub3d_t
{
    void	*mlx;
	void	*win;
    double     x_player;
    double     y_player;
    double      ang;
    char    direction;
    int     *f_col;
    int     *c_col;
    char    **map;
    double *distances;
    char    *info;
    t_rays  **rays;
    char    *NO;
    char    *SO;
    char    *EA;
    char    *WE;
    int     b;
    int     l;
    int     e;
    void    *img;
    int     *add;
    t_tood *todmap;
    texture_t *texture;
}   cub3d_t;


typedef struct lexer
{
	char	c;
	int		src_size;
	int		j;
	char	*src;
	int		i;
}	t_lexer;

char	*line_map(int fd);
char	**split_map(char *c);
cub3d_t	*return_map(char *av, cub3d_t *cub);
char	*change_value(char *str);
int     find_path(char *str, char *search);
int     check_if_true(char *str);
t_lexer	*init_lexer(char *src);
void	lexer_skip_space(t_lexer *lexer);
void	lexer_advance(t_lexer *lexer);
void	err_fre_lex_cub(t_lexer *lexer, cub3d_t *cub);
char	*get_c_as_str(char c);
void	lexer_skip_space_line(t_lexer *lexer);
char	*take_id(t_lexer *lexer, cub3d_t *cub);
void	lexer_back(t_lexer *lexer);
char	*check_id(t_lexer *lexer, cub3d_t *cub, char *str);
int     *take_col(t_lexer *lexer, cub3d_t *cub, char *str);
void    free_double_p(char **str);
int     lent_double_p(char **str);
int     check_numbers(char **str);
char    **find_er(t_lexer *lexer, cub3d_t *cub, char *str);
char    *take_line(t_lexer *lexer);
t_map    *take_map(t_lexer *lexer);
t_map   *init_map(char *str);
void	token_add_back(t_map **map, char *value);
char    **swap_to_double(t_map *map);
int     lst_size(t_map *map);
void	exit_mssg(char *str);
void    check_map(cub3d_t *cub);
void    free_cub(cub3d_t *cub);
int     all_element(char **map);
int     sur_by_walls(char **map);
int     check_1(char **str);
int     skip_space_start(char *str);
int     skip_space_end(char *str);
int     find_wall(char **str, int i, int j);
int     check_spaces(char **str);
int     check_first_line(char **str);
int     check_last_line(char **str);
int     check_zeros(char **str, int i, int j);
int     one_player(char **str, cub3d_t *cub);
unsigned int pixelget(cub3d_t *cub, int x,int y, int i);
int check_nums(char **str);
void get_add_xml(cub3d_t *cub);
#endif