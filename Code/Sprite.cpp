#include "Sprite.h"

Sprite::Sprite() {
  this->m_VboId = 0;
}

Sprite::~Sprite() {
  if (this->m_VboId != 0) {
    glDeleteBuffers(1, &this->m_VboId);
  }
}

void Sprite::init(float x, float y, float width, float height) {
  this->m_X = x;
  this->m_Y = y;
  this->m_Width = width;
  this->m_Height = height;

  if (this->m_VboId == 0) {
    glGenBuffers(1, &this->m_VboId);
  }

  float vertexData[12] = {
    // First triangle.
    x + width, y + width,
    x, y + height,
    x, y,

    // Second triangle.
    x, y,
    x + width, y,
    x + width, y + height
  };

  glBindBuffer(GL_ARRAY_BUFFER, this->m_VboId);

  glBufferData(GL_ARRAY_BUFFER, sizeof(vertexData), &vertexData, GL_STATIC_DRAW);

  glBindBuffer(GL_ARRAY_BUFFER, 0);
}

void Sprite::draw() {
  glBindBuffer(GL_ARRAY_BUFFER, this->m_VboId);

  glEnableVertexAttribArray(0);

  glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 0, 0);

  glDrawArrays(GL_TRIANGLES, 0, 6);

  glDisableVertexAttribArray(0);
  
  glBindBuffer(GL_ARRAY_BUFFER, 0);
}

