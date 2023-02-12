#include "Buttons.h"

Button::Button(float x, float y, float width, float height, Texture* texture)
    : x(x), y(y), width(width), height(height), m_pTexture(texture) {}

void Button::Draw() {
    m_pTexture->Draw();
}

bool Button::IsMouseOver(float mouseX, float mouseY) {
    return (mouseX >= x && mouseX <= x + width) && (mouseY >= y && mouseY <= y + height);
}
