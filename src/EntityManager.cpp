#if INTERFACE

#include "Entity.hpp"
#include <map>
#include <memory>
#include <string>
#include <vector>
typedef std::vector<std::shared_ptr<Entity>> EntityVec;
typedef std::map<std::string, EntityVec> EntityMap;

class EntityManager {
  EntityVec m_entities;
  EntityVec m_toAdd;
  EntityMap m_entityMap;
  size_t m_totalEntities;

public:
  EntityManager() {}

  void update() {
    for (auto e : m_toAdd) {
      m_entities.push_back(e);
      m_entityMap[e->tag()].push_back(e);
    }
    // to add removal
    m_toAdd.clear();
  };

  std::shared_ptr<Entity> addEntity(const std::string &tag) {
    auto e = std::make_shared<Entity>(m_totalEntities++, tag);
    m_toAdd.push_back(e);
    return e;
  }
};

#endif
