
// Needed libs
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

typedef unsigned int IUINT32;

// vector and matrices definitions
typedef struct { float x, y, z, w; } vector_t;
typedef struct { float m[4][4]; } matrix_t;

// Color and texture coordinates
typedef struct { float r, g, b; } color_t;
typedef struct { float u, v; } texcoord_t;

// Vertex struct
typedef struct {
    vector_t pos;
    color_t color;
    texcoord_t texcoord;
    float rhw;
} vertex_t;

// Transform struct
typedef struct {
    matrix_t world;
    matrix_t view;
    matrix_t projection;
    matrix_t transform;
    float w, h;
} transform_t;

// Device struct
typedef struct {
    IUINT32* framebuffer;
    int width;
    int height;
} device_t;

// Shape definition
typedef struct shape_t {
    vertex_t* vertices;
    int vertex_count;
    struct shape_t* next;
} shape_t;
