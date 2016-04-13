#include "sdl2canvas.h"
#include "sdl2texture.h"

#include <SDL2/SDL_image.h>

namespace ijengine {

SDL2Canvas::SDL2Canvas(SDL_Renderer *renderer)
    : m_renderer(renderer)
{
}

void
SDL2Canvas::draw(const Texture *texture, int x, int y)
{
    const SDL2Texture *text = dynamic_cast<const SDL2Texture *>(texture);

    SDL_SetRenderDrawColor(m_renderer, 255, 255, 255, 0);
    SDL_RenderClear(m_renderer);

    SDL_Rect rect { x, y, text->w(), text->h() };
    SDL_RenderCopy(m_renderer, text->texture(), nullptr, nullptr);
    SDL_RenderPresent(m_renderer);
}

void
SDL2Canvas::update()
{
    SDL_RenderPresent(m_renderer);
}

}
