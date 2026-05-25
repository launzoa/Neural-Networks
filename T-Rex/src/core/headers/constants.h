#pragma once
// Window constants
const int WINDOW_WIDTH = 800;
const int WINDOW_HEIGHT = 600;

// Game constants
const double SPAWN_TIME = 2.0;
const double GAME_SPEED = 400.0;
const double GAME_TIME_LIMIT = 1000;

// Ground constants
const int GROUND_Y = WINDOW_HEIGHT - 25;

// TRex constants
const double TREX_WIDTH = 48;
const double TREX_HEIGHT = 48;
const double TREX_X = 100;
const double TREX_Y = GROUND_Y - TREX_HEIGHT;
const double TREX_VEL_Y = 0;
const double TREX_GRAVITY = 1500.0;

// Small cactus constants
const int SMALL_CACTUS_WIDTH = 25;
const int SMALL_CACTUS_HEIGHT = 50;

// Big cactus constants
const int BIG_CACTUS_WIDTH = 35;
const int BIG_CACTUS_HEIGHT = 60;

// Pterodactyl constants
const int PTERODACTYL_WIDTH = 52;
const int PTERODACTYL_HEIGHT = 30;

// Actions constants
const double JUMP_IMPULSE = -600;
const double SNEAK_IMPULSE = 350;

// Perceptron constants
const int INPUT_NEURONS = 4;
const int OUTPUT_NEURONS = 1;
const double LEARNING_RATE = 0.1;
