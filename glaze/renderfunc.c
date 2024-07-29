//! It is enough to use I think

void device_init(device_t* device, int width, int height, void* fb) {
    device->framebuffer = (IUINT32*)fb;
    device->width = width;
    device->height = height;
    memset(fb, 0, width * height * 4);
}

void device_pixel(device_t* device, int x, int y, IUINT32 color) {
    if (x >= 0 && x < device->width && y >= 0 && y < device->height) {
        device->framebuffer[y * device->width + x] = color;
    }
}

void draw_shape(device_t* device, const transform_t* transform, const shape_t* shape) {
    for (int i = 0; i < shape->vertex_count; i++) {
        vector_t screen_pos;
        transform_apply(transform, &screen_pos, &shape->vertices[i].pos);
        int x = (int)((screen_pos.x + 1.0f) * 0.5f * device->width);
        int y = (int)((1.0f - screen_pos.y) * 0.5f * device->height);
        device_pixel(device, x, y, 0xFFFFFF);
    }
}

void render(device_t* device, const transform_t* transform, const shape_t* shapes) {
    shape_t* shape = (shape_t*)shapes;
    while (shape) {
        draw_shape(device, transform, shape);
        shape = shape->next;
    }
}
