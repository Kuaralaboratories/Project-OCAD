int main() {
    const int width = 800;  //TODO Needed to fetched from users resizing events
    const int height = 600; //TODO Needed to fetched from users resizing events
    device_t device;
    void* framebuffer = malloc(width * height * 4);
    device_init(&device, width, height, framebuffer);

    // Handle shapes
    //TODO get shapes from memory and manager, it needs to be a 3D renderer of shapes that chosen by user
    vertex_t vertices[] = {
        {{-0.5f, -0.5f, 0.0f, 1.0f}, {1.0f, 0.0f, 0.0f}, {0.0f, 0.0f}},
        {{ 0.5f, -0.5f, 0.0f, 1.0f}, {0.0f, 1.0f, 0.0f}, {1.0f, 0.0f}},
        {{ 0.0f,  0.5f, 0.0f, 1.0f}, {0.0f, 0.0f, 1.0f}, {0.5f, 1.0f}}
    };
    shape_t* shapes = NULL;
    shape_t* triangle = create_shape(vertices, 3);
    add_shape(&shapes, triangle);

    // Complete transformations
    transform_t transform;
    transform_update(&transform);

    // Render loop
    render(&device, &transform, shapes);

    // Clear cache
    remove_shape(&shapes, triangle);
    free(framebuffer);
    return 0;
}
