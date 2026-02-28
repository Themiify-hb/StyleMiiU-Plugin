#pragma once
#include <content_redirection/redirection.h>
#include "WUPSConfigItemThemeBool.h"
#include <string>
#include <vector>

#define VERSION                                "v0.4.5"
#define THEME_MANAGER_ENABLED_STRING           "themeManagerEnabled"
#define SHUFFLE_THEMES_STRING                  "suffleThemes"
#define MASHUP_THEMES_STRING                   "mashupThemes"

#define DEFAULT_THEME_MANAGER_ENABLED          true
#define DEFAULT_SHUFFLE_THEMES                 false
#define DEFAULT_MASHUP_THEMES                  false

extern bool gThemeManagerEnabled;
extern bool gShuffleThemes;
extern bool gMashupThemes;
extern const char* theme_directory_path;
extern std::string gCurrentTheme;

extern ConfigItemThemeBool* gCurrentThemeItem;

extern CRLayerHandle gContentLayerHandle;

extern bool shuffleEnabled;

extern std::vector<std::string> enabledThemes;