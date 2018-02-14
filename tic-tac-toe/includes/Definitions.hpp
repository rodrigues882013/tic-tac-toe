#pragma once

#include <string>

namespace game
{
    class Constants
    {
    public:
        static const unsigned int WINDOW_WIDTH = 500;
        static const unsigned int WINDOW_HEIGHT = 600;

        static const int X_PIECE = 8;
        static const int O_PIECE = 0;
        static const int EMPTY_PIECE = -1;
        static const int PLAYER_PIECE = X_PIECE;
        static const int AI_PIECE = O_PIECE;
		static const int TIME_BEFORE_SHOWING_GAME_OVER = O_PIECE;

        static constexpr float SPLASH_STATE_SHOW_TIME = 0.5f;

        //Assets
        static constexpr const char* SPLASH_SCENE_BACKGROUND_FILEPATH = "resources/res/splash_background.png";
        static constexpr const char* MAIN_MENU_BACKGROUND_FILEPATH = "resources/res/main_menu_background.png";
        static constexpr const char* MAIN_MENU_TITLE_FILEPATH = "resources/res/game_title.png";

        static constexpr const char* GAME_BACKGROUND_FILEPATH = MAIN_MENU_BACKGROUND_FILEPATH;
        static constexpr const char* PAUSE_BACKGROUND_FILEPATH = MAIN_MENU_BACKGROUND_FILEPATH;

        static constexpr const char* MAIN_MENU_PLAY_BUTTON = "resources/res/play_button.png";
        static constexpr const char* MAIN_MENU_PLAY_BUTTON_OUTER = "resources/res/play_button_outer.png";
        static constexpr const char* PAUSE_BUTTON = "resources/res/pause_button.png";
        static constexpr const char* RESUME_BUTTON = "resources/res/resume_button.png";
        static constexpr const char* HOME_BUTTON = "resources/res/home_button.png";
        static constexpr const char* RETRY_BUTTON = "resources/res/retry_button.png";


        static constexpr const char* X_PIECE_FILEPATH = "resources/res/x.png";
        static constexpr const char* O_PIECE_FILEPATH = "resources/res/o.png";
        static constexpr const char* X_WINING_PIECE_FILEPATH = "resources/res/x_win.png";
        static constexpr const char* O_WINING_PIECE_FILEPATH = "resources/res/o_win.png";


        //States
        static const unsigned int STATE_PLAYING = 98;
        static const unsigned int STATE_PAUSED = 97;
        static const unsigned int STATE_WON = 96;
        static const unsigned int STATE_LOSE = 95;
        static const unsigned int STATE_PLACE_PIECE = 94;
        static const unsigned int STATE_AI_PLAYING = 93;
        static const unsigned int STATE_DRAW = 93;

        static constexpr const char* GRID_SPRITE_FILE_PATH = "resources/res/grid.png";

    };

}