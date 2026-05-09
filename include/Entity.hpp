#ifndef ENTITY_HPP
#define ENTITY_HPP

#include "Components.hpp"
#include <memory>
#include <string>

class Entity {
  const size_t m_id = 0;
  const std::string m_tag = "default";
  bool m_alive = true;

public:
  // Punteros a componentes (Smart Pointers)
  std::shared_ptr<CTransform> cTransform;
  std::shared_ptr<CShape> cShape;
  std::shared_ptr<CCollision> cCollision;
  std::shared_ptr<CInput> cInput;
  std::shared_ptr<CScore> cScore;
  std::shared_ptr<CLifespan> cLifespan;

  // Constructor Público
  Entity(const size_t id, const std::string &tag);

  bool isActive();
  const std::string &tag();
  size_t id();
};

#endif
