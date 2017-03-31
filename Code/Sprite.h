#pragma once

#include <glad/glad.h>

class Sprite {
 public:
  Sprite();
  ~Sprite();

  void init(float x, float y, float width, float height);

  void draw();

 private:
  float m_X;
  float m_Y;
  float m_Width;
  float m_Height;
  GLuint m_VboId;
};

