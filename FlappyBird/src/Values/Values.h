#pragma once

#include <vector>
#include <string>

// Window
constexpr int FRAMERATE = 60;
constexpr int WIDTH = 1280;
constexpr int HEIGHT = 720;

// Icon
constexpr auto ICON_PATH = "assets/icon/icon.png";

// Font
constexpr auto FONT_PATH = "assets/fonts/Polytype.ttf";

// Menu
constexpr auto PLAY_BUTTON_PATH = "assets/sprites/buttons/play.png";
constexpr auto EXIT_BUTTON_PATH = "assets/sprites/buttons/exit.png";
constexpr auto LEFT_ARROW_BUTTON_PATH = "assets/sprites/buttons/arrowLeft.png";
constexpr auto RIGHT_ARROW_BUTTON_PATH = "assets/sprites/buttons/arrowRight.png";

// Sounds
constexpr auto HIT_SOUND_PATH = "assets/sounds/hit.ogg";
constexpr auto FLAP_SOUND_PATH = "assets/sounds/flap.ogg";
constexpr auto SCORE_SOUND_PATH = "assets/sounds/score.ogg";
constexpr auto CLICK_SOUND_PATH = "assets/sounds/click.ogg";
constexpr auto THEME_SOUND_PATH = "assets/sounds/theme.ogg";

// Pipe
constexpr int  PIPE_NUM = 5;
constexpr auto PIPE_PATH = "assets/sprites/pipe/pipe.png";

// Bird
constexpr int  BIRD_NUM = 14;
constexpr auto BIRD_LIGHT_PATH = "assets/sprites/bird/light.png";
const std::vector<std::string> BIRD_PATHS = {
	"assets/sprites/bird/bird1.png",
	"assets/sprites/bird/bird2.png",
	"assets/sprites/bird/bird3.png",
	"assets/sprites/bird/bird4.png",
	"assets/sprites/bird/bird5.png",
	"assets/sprites/bird/bird6.png",
	"assets/sprites/bird/bird7.png",
	"assets/sprites/bird/bird8.png",
	"assets/sprites/bird/bird9.png",
	"assets/sprites/bird/bird10.png",
	"assets/sprites/bird/bird11.png",
	"assets/sprites/bird/bird12.png",
	"assets/sprites/bird/bird13.png",
	"assets/sprites/bird/bird14.png"
};

// Backgrounds
constexpr int  BACKGROUNDS_NUM = 4;

// Forest
const std::vector<std::string> FOREST_LAYER_PATHS = {
	"assets/sprites/bg/forest/layer7.png",
	"assets/sprites/bg/forest/layer6.png",
	"assets/sprites/bg/forest/layer5.png",
	"assets/sprites/bg/forest/layer4.png",
	"assets/sprites/bg/forest/layer3.png",
	"assets/sprites/bg/forest/layer2.png",
	"assets/sprites/bg/forest/layer1.png"
};

// Desert
const std::vector<std::string> DESERT_LAYER_PATHS = {
	"assets/sprites/bg/desert/layer9.png",
	"assets/sprites/bg/desert/layer8.png",
	"assets/sprites/bg/desert/layer7.png",
	"assets/sprites/bg/desert/layer6.png",
	"assets/sprites/bg/desert/layer5.png",
	"assets/sprites/bg/desert/layer4.png",
	"assets/sprites/bg/desert/layer3.png",
	"assets/sprites/bg/desert/layer2.png",
	"assets/sprites/bg/desert/layer1.png"
};

// Lake
const std::vector<std::string> LAKE_LAYER_PATHS = {
	"assets/sprites/bg/lake/layer7.png",
	"assets/sprites/bg/lake/layer6.png",
	"assets/sprites/bg/lake/layer5.png",
	"assets/sprites/bg/lake/layer4.png",
	"assets/sprites/bg/lake/layer3.png",
	"assets/sprites/bg/lake/layer2.png",
	"assets/sprites/bg/lake/layer1.png"
};

// Waterfall
const std::vector<std::string> WATERFALL_LAYER_PATHS = {
	"assets/sprites/bg/waterfall/layer5.png",
	"assets/sprites/bg/waterfall/layer4.png",
	"assets/sprites/bg/waterfall/layer3.png",
	"assets/sprites/bg/waterfall/layer2.png",
	"assets/sprites/bg/waterfall/layer1.png"
};