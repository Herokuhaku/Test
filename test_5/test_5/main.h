#pragma once

struct vec2
{
	int x;
	int y;
	vec2 operator+(int i)
	{
		x += i;
		y += i;
		return {x,y};
	}
};


vec2 _off;
int _size;
vec2 point[2];
vec2 mag = {1,1};
bool _magbool = false;			// false‚ª+ true‚ª-
int _intercept = 0;
bool _interceptbool = false;	// false‚ª+ true‚ª-