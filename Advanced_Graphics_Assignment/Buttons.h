#include "Texture.h"
#include "freetype/freetype.h"
#include "ft2build.h"
#include FT_FREETYPE_H

class Button {
public:

    Button(float x, float y, float width, float height, Texture* texture);
    void Draw();
    bool IsMouseOver(float mouseX, float mouseY);

private:
    float x, y, width, height;
    Texture* m_pTexture;
};

