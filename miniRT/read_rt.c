#include "minirt.h"
#include "support/get_next_line.h"

void	skip_space(char **str)
{
	while(**str == ' ')
		(*str)++;
}

void	set_res(char *str, scene *scene)
{
	scene->res_height = 0;
	scene->res_width = 0;
	skip_space(&str);
	while(*str >= '0' && *str <= '9')
	{
		scene->res_width *= 10;
		scene->res_width += *str - '0';
		str++;
	}
	skip_space(&str);
	while(*str >= '0' && *str <= '9')
	{
		scene->res_height *= 10;
		scene->res_height += *str - '0';
		str++;
	}
}

int		get_color(char *str)
{
	int b;
	int r;
	int g;

	r = 0;
	g = 0;
	b = 0;
	while(*str >= '0' && *str <= '9')
	{
		i *= 10;
		i += *str - '0';
		str++;
	}
	if(*str == ',')
		str++;

}

void	set_ambient(char *str, amb_light *ambient)
{
	int i;

	ambient->intensity = 0.0;
	ambient->color = 0;
	skip_space(&str);
	i = 10;
	if(*str >= '0' && *str <= '9')
	{
		ambient->intensity *= 10;
		ambient->intensity += *str - '0';
		str += 2;
	}
	while(*str >= '0' && *str <= '9')
	{
		str++;
		ambient->intensity += (*str - '0')/i;
		i *= 10;
		str++;
	}
	skip_space(&str);
}

void	*read_rt(char *name)
{
	int		fd;
	int		i;
	char	*str;
	void	*obj_list;
	scene	scene;

	i = 1;
	fd = open(name, O_RDONLY);
	while(i)
	{
		i = get_next_line(fd, &str);
		if(i == -1)
			exit(1);
		if(*str == 'R')
			set_res((str + 1), &scene);
		if(*str == 'A')
			set_ambient((str + 1), &scene.ambient);
		free(str);
	}
}
