#include "minirt.h"

vec vec_add(vec v1, vec v2)
{
     v1.x += v2.x;
     v1.y += v2.y;
     v1.z += v2.z;
     return v1;
}

vec vec_sub(vec v1, vec v2)
{
     v1.x -= v2.x;
     v1.y -= v2.y;
     v1.z -= v2.z;
     return v1;
}

int vec_dot(vec v1, vec v2)
{
    return (v1.x * v2.x) + (v1.y * v2.y) + (v1.z * v2.z);
}

vec vec_cross(vec v1, vec v2)
{
    v1.x = (v1.y * v2.z) - (v1.z * v2.y);
    v1.y = (v1.z * v2.x) - (v1.x * v2.z);
    v1.z = (v1.x * v2.y) - (v1.y * v2.x);
    return v1;
}

vec vec_scalar(vec v, int n)
{
    v.x *= n;
    v.y *= n;
    v.z *= n;
    return v;
}

int vec_len(vec v)
{
    return sqrt(vec_dot(v, v));
}
