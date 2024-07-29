//! It is enough to use I think

shape_t* create_shape(vertex_t* vertices, int vertex_count) {
    shape_t* shape = (shape_t*)malloc(sizeof(shape_t));
    shape->vertices = (vertex_t*)malloc(sizeof(vertex_t) * vertex_count);
    memcpy(shape->vertices, vertices, sizeof(vertex_t) * vertex_count);
    shape->vertex_count = vertex_count;
    shape->next = NULL;
    return shape;
}

void add_shape(shape_t** shapes, shape_t* new_shape) {
    new_shape->next = *shapes;
    *shapes = new_shape;
}

void remove_shape(shape_t** shapes, shape_t* shape) {
    if (*shapes == shape) {
        *shapes = shape->next;
    } else {
        shape_t* prev = *shapes;
        while (prev->next && prev->next != shape) {
            prev = prev->next;
        }
        if (prev->next == shape) {
            prev->next = shape->next;
        }
    }
    free(shape->vertices);
    free(shape);
}

//TODO Edit all of particules or faces of the shape
void edit_shape(shape_t* shape, vertex_t* new_vertices, int vertex_count) {
    free(shape->vertices);
    shape->vertices = (vertex_t*)malloc(sizeof(vertex_t) * vertex_count);
    memcpy(shape->vertices, new_vertices, sizeof(vertex_t) * vertex_count);
    shape->vertex_count = vertex_count;
}
