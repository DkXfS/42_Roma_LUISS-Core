#include "mlx.h"
#include "minirt.h"

int make_color(uchar a, uchar r, uchar g, uchar b)
{
	return ((a<<24) + (r<<16) + (g<<8) + b);
}

void	img_pixel(t_img *img, int x, int y, int color)
{
	char *addr;

	addr = img->addr + img->linesize * y + (img->bpp/8) * x;
	*(int*)addr = color;
}

int main()
{
	int i, j = 719;
    uchar r, g, b, gc = 0;
	void *mlx_ptr, *window;
	t_img img;

	mlx_ptr = mlx_init();
	window = mlx_new_window(mlx_ptr, 1280, 720, "TR14L");
	img.img = mlx_new_image(mlx_ptr, 1280, 720);
	img.addr = mlx_get_data_addr(img.img, &img.bpp, &img.linesize, &img.endian);
	while(j)
	{
		r = 0;
		g = 0;
        b = 255;
		i = 1279;
		while(i)
		{
            if(r < 255 && gc > 0)
            {
                r++;
                g--;
            }
            if(g < 255 && gc == 0)
                g++;
            if(g == 255)
                gc = 1;
			if(b > 0)
                b--;
			img_pixel(&img, i, j, make_color(0, r, g, b));
			i--;
		}
		j--;
	}
	mlx_put_image_to_window(mlx_ptr, window, img.img, 0, 0);
	mlx_string_put(mlx_ptr, window, 620, 360, make_color(0, 255, 100, 0), "T35T");
	mlx_loop(mlx_ptr);
}
