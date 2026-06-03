#include "core/headers/GameWorld.h"
#include "core/headers/constants.h"
#include "ia/headers/MLP.h"
#include <raylib.h>
#include <vector>

using namespace std;

void updateDrawFrame(double deltaTime, GameWorld *game, MLP *mlp,
                     int &generation, int generationTotal,
                     vector<vector<double>> &X, vector<vector<double>> &Y);

int main() {
  GameWorld game;
  MLP mlp({INPUT_NEURONS, HIDDEN_NEURONS, OUTPUT_NEURONS}, LEARNING_RATE);

  int generation = 0;
  int generationTotal = 200;

  vector<vector<double>> X;
  vector<vector<double>> Y;

  InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "Dino Run");
  Texture2D trexSprite = LoadTexture("assets/trex.png");
  Texture2D smallCactusSprite = LoadTexture("assets/smallCactus.png");
  Texture2D bigCactusSprite = LoadTexture("assets/bigCactus.png");
  Texture2D ptSprite = LoadTexture("assets/pterodatyl.png");
  Texture2D trexDuckSprite = LoadTexture("assets/trexDuck.png");
  SetTargetFPS(60);

  while (!WindowShouldClose()) {
    double deltaTime = GetFrameTime();
    game.timeDecrement(deltaTime);

    BeginDrawing();
    ClearBackground(RAYWHITE);

    updateDrawFrame(deltaTime, &game, &mlp, generation, generationTotal, X, Y);

    DrawText(TextFormat("Generation: %i", generation), 10, 10, 20, BLACK);

    if (!Y.empty()) {
      vector<double> last_pred = Y.back();
      DrawText(TextFormat("Abaixar: %.2f", last_pred[0]), 10, 40, 20, BLUE);
      DrawText(TextFormat("Correr: %.2f", last_pred[1]), 10, 70, 20, BLUE);
      DrawText(TextFormat("Pular: %.2f", last_pred[2]), 10, 100, 20, BLUE);
    }

    DrawRectangle(0, GROUND_Y, WINDOW_WIDTH, 5, BLACK);

    TRex trex = game.getTrex();

    Texture2D currentTrexSprite;

    if (trex.getHeight() < TREX_HEIGHT) {
      currentTrexSprite = trexDuckSprite;
    } else {
      currentTrexSprite = trexSprite;
    }

    Rectangle trex_source = {0, 0, (float)currentTrexSprite.width,
                             (float)currentTrexSprite.height};

    Rectangle trex_dest = {
        (float)(trex.getX() -
                (currentTrexSprite.width - trex.getWidth()) / 2.0),
        (float)(trex.getY() + trex.getHeight() - currentTrexSprite.height),
        (float)currentTrexSprite.width, (float)currentTrexSprite.height};
    DrawTexturePro(currentTrexSprite, trex_source, trex_dest, {0, 0}, 0.0f,
                   WHITE);

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
  UnloadTexture(trexDuckSprite);
  CloseWindow();
  return 0;
}

void updateDrawFrame(double deltaTime, GameWorld *game, MLP *mlp,
                     int &generation, int generationTotal,
                     vector<vector<double>> &X, vector<vector<double>> &Y) {
  int SPEED_UP = (generationTotal > generation) ? 100 : 1;

  for (int i = 0; i < SPEED_UP; ++i) {
    vector<double> x = game->getInputs();
    X.push_back(x);

    vector<double> action_pred = mlp->predict(x);
    Y.push_back(action_pred);

    int max_idx = 0;
    if (action_pred[1] > action_pred[max_idx])
      max_idx = 1;
    if (action_pred[2] > action_pred[max_idx])
      max_idx = 2;

    int action = 0;
    if (max_idx == 0)
      action = -1; // duck
    else if (max_idx == 1)
      action = 0; // run
    else
      action = 1; // jump

    game->update(deltaTime, action);

    if (game->getGameOverState()) {
      vector<double> action_correct = {0, 1, 0}; // run

      Y.clear();
      for (int j = 0; j < X.size(); ++j) {
        Y.push_back(action_correct);
      }

      if (game->getObstacles().front().getWidth() == PTERODACTYL_WIDTH) {
        action_correct = {1, 0, 0};
      } else {
        action_correct = {0, 0, 1};
      }

      int back_frames = (Y.size() > 25) ? 25 : Y.size();
      for (int j = 1; j <= back_frames; ++j) {
        Y[Y.size() - j] = action_correct;
      }

      mlp->train(X, Y, EPOCHS);

      X.clear();
      Y.clear();

      game->resetGame();
      generation++;
    }
  }
}
