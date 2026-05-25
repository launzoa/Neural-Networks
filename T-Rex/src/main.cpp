#include "core/headers/GameWorld.h"
#include "core/headers/constants.h"
#include "ia/headers/Perceptron.h"
#include <raylib.h>
#include <vector>

using namespace std;

void updateDrawFrame(double deltaTime, GameWorld *game, Perceptron *perceptron,
                     int &generation, int generationTotal,
                     vector<vector<double>> &X, vector<int> &y);

int main() {
  GameWorld game;
  Perceptron perceptron(4, 0.1);

  int generation = 0;
  int generationTotal = 100;

  vector<vector<double>> X;
  vector<int> y;

  InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "Dino Run");
  Texture2D trexSprite = LoadTexture("assets/trex.png");
  Texture2D smallCactusSprite = LoadTexture("assets/smallCactus.png");
  Texture2D bigCactusSprite = LoadTexture("assets/bigCactus.png");
  Texture2D ptSprite = LoadTexture("assets/pterodatyl.png");
  SetTargetFPS(60);

  while (!WindowShouldClose()) {
    double deltaTime = GetFrameTime();
    game.timeDecrement(deltaTime);

    BeginDrawing();
    ClearBackground(RAYWHITE);

    updateDrawFrame(deltaTime, &game, &perceptron, generation, generationTotal,
                    X, y);

    DrawText(TextFormat("Generation: %i", generation), 10, 10, 20, BLACK);

    DrawRectangle(0, GROUND_Y, WINDOW_WIDTH, 5, BLACK);

    TRex trex = game.getTrex();
    Rectangle trex_source = {0, 0, (float)trexSprite.width,
                             (float)trexSprite.height};

    Rectangle trex_dest = {
        (float)(trex.getX() - (trexSprite.width - trex.getWidth()) / 2.0),
        (float)(trex.getY() + trex.getHeight() - trexSprite.height),
        (float)trexSprite.width, (float)trexSprite.height};
    DrawTexturePro(trexSprite, trex_source, trex_dest, {0, 0}, 0.0f, WHITE);

    deque<Obstacle> obstacles = game.getObstacles();

    for (Obstacle obstacle : obstacles) {
      Texture2D currentSprite;
      if (obstacle.getWidth() == SMALL_CACTUS_WIDTH) {
        currentSprite = smallCactusSprite;
      } else if (obstacle.getWidth() == BIG_CACTUS_WIDTH) {
        currentSprite = bigCactusSprite;
      } else {
        currentSprite = ptSprite;
      }

      Rectangle source_rect = {0, 0, (float)currentSprite.width,
                               (float)currentSprite.height};

      Rectangle dest_rect = {
          (float)(obstacle.getX() -
                  (currentSprite.width - obstacle.getWidth()) / 2.0),
          (float)(obstacle.getY() + obstacle.getHeight() -
                  currentSprite.height),
          (float)currentSprite.width, (float)currentSprite.height};

      DrawTexturePro(currentSprite, source_rect, dest_rect, {0, 0}, 0.0f,
                     WHITE);
    }

    EndDrawing();
  }

  UnloadTexture(trexSprite);
  UnloadTexture(smallCactusSprite);
  UnloadTexture(bigCactusSprite);
  UnloadTexture(ptSprite);
  CloseWindow();
  return 0;
}

void updateDrawFrame(double deltaTime, GameWorld *game, Perceptron *perceptron,
                     int &generation, int generationTotal,
                     vector<vector<double>> &X, vector<int> &y) {
  int SPEED_UP = (generationTotal > generation) ? 5 : 1;

  for (int i = 0; i < SPEED_UP; ++i) {
    vector<double> x = game->getInputs();
    X.push_back(x);

    int action_pred = perceptron->predict(x);

    game->update(deltaTime, action_pred);

    if (game->getGameOverState()) {
      // int action_correct = (action_pred + 2) % 3 - 1;
      int action_correct = 1;

      y.clear();
      for (int j = 0; j < X.size(); ++j) {
        y.push_back(0);
      }

      int back_frames = (y.size() > 25) ? 25 : y.size();
      for (int j = 1; j <= back_frames; ++j) {
        y[y.size() - j] = action_correct;
      }

      perceptron->train(X, y, generationTotal);

      X.clear();
      y.clear();

      game->resetGame();
      generation++;
    }
  }
}