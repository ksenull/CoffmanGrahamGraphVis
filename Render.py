import pygame


DISPLAY_WIDTH = 800
DISPLAY_HEIGHT = 600
CAPTION = "Coffman-Graham graph layering algorithm visualization"

WHITE = (255, 255, 255)
BLACK = (0, 0, 0)


def inputLayering():
    graph = []
    layers = []
    with open("input.txt", "r") as f:
        n = int(f.readline())  # number of vertices
        for _ in range(n):
            tokens = [*map(int, f.readline().split())]
            graph.append(tokens)
        m = int(f.readline())  # number of layers
        for _ in range(m):
            tokens = [*map(int, f.readline().split())]
            layers.append(tokens)

    print(graph)
    print(layers)
    return graph, layers


def renderLabel(label, font_size, center, screen, color):
    if pygame.font:
        font = pygame.font.Font(None, font_size)
    text = font.render(label, 1, color)
    textpos = text.get_rect(center=center)
    screen.blit(text, textpos)

def renderHeader(label, screen, color):
    if pygame.font:
        font = pygame.font.Font(None, 40)
    text = font.render(label, 1, color)
    textpos = text.get_rect(left=10)
    screen.blit(text, textpos)


def drawGraphByLayers(graph, layers, screen, color=BLACK):
    if len(graph) == 0:
        return

    assert len(layers) > 0

    layering_width = max(map(len, layers))
    renderHeader("Layering with width={}:".format(layering_width), screen, color)

    layer_height = DISPLAY_HEIGHT // (len(layers) + 1)
    vertex_y = DISPLAY_HEIGHT - layer_height
    layer_width = DISPLAY_WIDTH // 3 // (layering_width - 1)
    vertex_start_x = DISPLAY_WIDTH // 3
    vertex_x = vertex_start_x
    vertex_radius = layer_height // 3

    vertex2pos = {}
    for layer in reversed(layers):
        for v in layer:
            pos = (vertex_x, vertex_y)
            vertex2pos[v] = pos
            pygame.draw.circle(screen, color, pos, vertex_radius)
            vertex_x += layer_width
        vertex_y -= layer_height
        vertex_x = vertex_start_x

    for v, edges in enumerate(graph):
        for e in edges:
            pygame.draw.line(screen, color, vertex2pos[v], vertex2pos[e], 5)

    for v in range(len(graph)):
        renderLabel(str(v), vertex_radius - 5, center=vertex2pos[v], screen=screen, color=WHITE)


def Render(graph, layers):
    pygame.init()
    screen = pygame.display.set_mode((DISPLAY_WIDTH, DISPLAY_HEIGHT))
    pygame.display.set_caption(CAPTION)

    clock = pygame.time.Clock()

    pressed_exit = False
    while not pressed_exit:
        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                pressed_exit = True
            if event.type == pygame.KEYDOWN and event.key == pygame.K_RETURN:
                pygame.image.save(screen, "images/Layering_2.png")

        screen.fill(WHITE)
        drawGraphByLayers(graph, layers, screen)
        # print(event)

        pygame.display.update()
        clock.tick(60)

    pygame.quit()


if __name__ == '__main__':
    graph, layers = inputLayering()
    Render(graph, layers)