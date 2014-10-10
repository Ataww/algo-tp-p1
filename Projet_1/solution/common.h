#ifndef COMMON_H
#define COMMON_H

typedef struct rectangle {
	int width;
	int height;
} rect;

typedef struct point {
	int x;
	int y;
} point;

typedef struct dalle {
	rect dim;
	bool * data;
} dalle;

#endif