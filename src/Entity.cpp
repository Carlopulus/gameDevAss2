#if INTERFACE

#include "Components.hpp"
#include <memory>
#include <string>
class Entity {
  const size_t m_id = 0;
  const std::string m_tag = "default";
  bool m_alive = true;

public:
  std::shared_ptr<CTransform> cTransform;
  std::shared_ptr<CShape> cShape;
  std::shared_ptr<CCollision> cCollision;
  std::shared_ptr<CInput> cInput;
  std::shared_ptr<CScore> cScore;
  std::shared_ptr<CLifespan> cLifespan;

  bool isActive() { return m_alive; }

  const std::string &tag() { return m_tag; }

  size_t id() { return m_id; }

  Entity(const size_t id, const std::string &tag) : m_id(id), m_tag(tag) {};
};

#endif
