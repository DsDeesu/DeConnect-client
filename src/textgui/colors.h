void initialize_colors()
{

    short textgui_RED_SELF = 200;
    short textgui_GREEN_SELF = 400;
    short textgui_BLUE_SELF = 1000;

    short textgui_RED_SERVER = 1000;
    short textgui_GREEN_SERVER = 200;
    short textgui_BLUE_SERVER = 400;

    short textgui_RED_OTHERS = 400;
    short textgui_GREEN_OTHERS = 1000;
    short textgui_BLUE_OTHERS = 200;

    short textgui_RED_DEFAULT = 1000;
    short textgui_GREEN_DEFAULT = 1000;
    short textgui_BLUE_DEFAULT = 1000;


    short textgui_RED_BACKGROUND = 165;
    short textgui_GREEN_BACKGROUND = 165;
    short textgui_BLUE_BACKGROUND = 175;


    short textgui_COLOR_SELF = 21;
    short textgui_COLOR_OTHERS = 22;
    short textgui_COLOR_SERVER = 23;
    short textgui_COLOR_DEFAULT = 24;
    short textgui_COLOR_BACKGROUND = 25;

    init_color(textgui_COLOR_SELF,       textgui_RED_SELF,       textgui_GREEN_SELF,       textgui_BLUE_SELF);
    init_color(textgui_COLOR_SERVER,     textgui_RED_SERVER,     textgui_GREEN_SERVER,     textgui_BLUE_SERVER);
    init_color(textgui_COLOR_OTHERS,     textgui_RED_OTHERS,     textgui_GREEN_OTHERS,     textgui_BLUE_OTHERS);
    init_color(textgui_COLOR_DEFAULT,    textgui_RED_DEFAULT,    textgui_GREEN_DEFAULT,    textgui_BLUE_DEFAULT);
    init_color(textgui_COLOR_BACKGROUND, textgui_RED_BACKGROUND, textgui_GREEN_BACKGROUND, textgui_BLUE_BACKGROUND);

    init_pair(textgui_PAIR_SELF,     textgui_COLOR_SELF,     textgui_COLOR_BACKGROUND);
    init_pair(textgui_PAIR_SERVER,   textgui_COLOR_SERVER,   textgui_COLOR_BACKGROUND);
    init_pair(textgui_PAIR_OTHERS,   textgui_COLOR_OTHERS,   textgui_COLOR_BACKGROUND);
    init_pair(textgui_PAIR_DEFAULT,  textgui_COLOR_DEFAULT,  textgui_COLOR_BACKGROUND);

}
