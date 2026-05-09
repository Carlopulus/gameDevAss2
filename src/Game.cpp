#include "Entity.hpp"
#include "EntityManager.hpp"

#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Window/Cursor.hpp>
#include <memory>
#include <random>
#include <string>

struct PlayerConfig {
  int SR, CR, FR, FG, FB, OR, OG, OB, OT, V;
  float S;
};

struct EnemyConfig {
  int SR, CR, OR, OG, OB, OT, VMIN, VMAX, L, SI;
  float SMIN, SMAX;
};

struct BulletConfig {
  int SR, CR, FR, FG, FB, OR, OG, OB, OT, V, L;
  float S;
};

class Game {
  sf::RenderWindow m_window;
  EntityManager m_entities;
  sf::Font m_font;
  sf::Text m_text;
  PlayerConfig m_playerConfig;
  EnemyConfig m_enemyConfig;
  BulletConfig m_bulletConfig;
  int m_score = 0;
  int m_currentframe = 0;
  int m_lastEnemySpawnTime = 0;
  bool m_paused = false;
  bool m_running = true;

  std::shared_ptr<Entity> m_player;

  void init(const std::string &config) // init game and config
  {

  };
  void setPaused(bool paused) {

  };

  void sMovement();     // System: Entity position / movement update
  void sUserInput();    // System: User Input
  void sLifespan();     // System: Lifespan
  void sRender();       // System: Render / Drawing
  void sEnemySpawner(); // System: Spawns Enemies
  void sCollision();    // System: Collisions

  void spawnPlayer();
  void spawnEnemy();
  void spawnSmallEnemies(std::shared_ptr<Entity> entity);
  void spawnBullet(std::shared_ptr<Entity> entity, const Vec2 &mousePos);
  void spawnSpecialWeapon(std::shared_ptr<Entity> entity);

public:
  Game(const std::string &conf) : m_text(m_font) { init(conf); }

  void run() {}
};
