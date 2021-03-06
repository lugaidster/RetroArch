/*  RetroArch - A frontend for libretro.
 *  Copyright (C) 2011-2015 - Daniel De Matteis
 *
 *  RetroArch is free software: you can redistribute it and/or modify it under the terms
 *  of the GNU General Public License as published by the Free Software Found-
 *  ation, either version 3 of the License, or (at your option) any later version.
 *
 *  RetroArch is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY;
 *  without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
 *  PURPOSE.  See the GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License along with RetroArch.
 *  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef _MENU_DISPLAYLIST_H
#define _MENU_DISPLAYLIST_H

#include <stdint.h>

#include <boolean.h>
#include <retro_miscellaneous.h>
#include <file/file_list.h>

#include "menu_setting.h"

#ifdef __cplusplus
extern "C" {
#endif

#ifndef COLLECTION_SIZE
#define COLLECTION_SIZE 99999
#endif

enum 
{
   PARSE_NONE           = (1 << 0),
   PARSE_GROUP          = (1 << 1),
   PARSE_ACTION         = (1 << 2),
   PARSE_ONLY_UINT      = (1 << 3),
   PARSE_ONLY_BOOL      = (1 << 4),
   PARSE_ONLY_FLOAT     = (1 << 5),
   PARSE_ONLY_BIND      = (1 << 6),
   PARSE_ONLY_GROUP     = (1 << 7),
   PARSE_ONLY_SUB_GROUP = (1 << 8),
   PARSE_SUB_GROUP      = (1 << 9)
};

enum
{
   DISPLAYLIST_NONE = 0,
   DISPLAYLIST_INFO,
   DISPLAYLIST_HELP,
   DISPLAYLIST_HELP_SCREEN_LIST,
   DISPLAYLIST_MAIN_MENU,
   DISPLAYLIST_GENERIC,
   DISPLAYLIST_SETTINGS,
   DISPLAYLIST_SETTINGS_ALL,
   DISPLAYLIST_HORIZONTAL,
   DISPLAYLIST_HORIZONTAL_CONTENT_ACTIONS,
   DISPLAYLIST_HISTORY,
   DISPLAYLIST_PLAYLIST_COLLECTION,
   DISPLAYLIST_DEFAULT,
   DISPLAYLIST_CORES,
   DISPLAYLIST_CORES_SUPPORTED,
   DISPLAYLIST_CORES_COLLECTION_SUPPORTED,
   DISPLAYLIST_CORES_UPDATER,
   DISPLAYLIST_CORES_DETECTED,
   DISPLAYLIST_CORE_OPTIONS,
   DISPLAYLIST_CORE_INFO,
   DISPLAYLIST_PERFCOUNTERS_CORE,
   DISPLAYLIST_PERFCOUNTERS_FRONTEND,
   DISPLAYLIST_SHADER_PASS,
   DISPLAYLIST_SHADER_PRESET,
   DISPLAYLIST_DATABASES,
   DISPLAYLIST_DATABASE_CURSORS,
   DISPLAYLIST_DATABASE_PLAYLISTS,
   DISPLAYLIST_DATABASE_PLAYLISTS_HORIZONTAL,
   DISPLAYLIST_DATABASE_QUERY,
   DISPLAYLIST_DATABASE_ENTRY,
   DISPLAYLIST_AUDIO_FILTERS,
   DISPLAYLIST_VIDEO_FILTERS,
   DISPLAYLIST_CHEAT_FILES,
   DISPLAYLIST_REMAP_FILES,
   DISPLAYLIST_RECORD_CONFIG_FILES,
   DISPLAYLIST_CONFIG_FILES,
   DISPLAYLIST_CONTENT_HISTORY,
   DISPLAYLIST_IMAGES,
   DISPLAYLIST_FONTS,
   DISPLAYLIST_OVERLAYS,
   DISPLAYLIST_SHADER_PARAMETERS,
   DISPLAYLIST_SHADER_PARAMETERS_PRESET,
   DISPLAYLIST_SYSTEM_INFO,
   DISPLAYLIST_DEBUG_INFO,
   DISPLAYLIST_USER_BINDS_LIST,
   DISPLAYLIST_ACCOUNTS_LIST,
   DISPLAYLIST_INPUT_SETTINGS_LIST,
   DISPLAYLIST_INPUT_HOTKEY_BINDS_LIST,
   DISPLAYLIST_PLAYLIST_SETTINGS_LIST,
   DISPLAYLIST_ACCOUNTS_CHEEVOS_LIST,
   DISPLAYLIST_LOAD_CONTENT_LIST,
   DISPLAYLIST_INFORMATION_LIST,
   DISPLAYLIST_CONTENT_SETTINGS,
   DISPLAYLIST_OPTIONS,
   DISPLAYLIST_OPTIONS_CHEATS,
   DISPLAYLIST_OPTIONS_REMAPPINGS,
   DISPLAYLIST_OPTIONS_MANAGEMENT,
   DISPLAYLIST_OPTIONS_DISK,
   DISPLAYLIST_OPTIONS_SHADERS,
   DISPLAYLIST_ADD_CONTENT_LIST,
   DISPLAYLIST_SCAN_DIRECTORY_LIST,
   DISPLAYLIST_ARCHIVE_ACTION,
   DISPLAYLIST_ARCHIVE_ACTION_DETECT_CORE,
   DISPLAYLIST_CORE_CONTENT
};

typedef struct menu_displaylist_info
{
   bool need_sort;
   bool need_refresh;
   bool need_push;
   file_list_t *list;
   file_list_t *menu_list;
   char path[PATH_MAX_LENGTH];
   char path_b[PATH_MAX_LENGTH];
   char path_c[PATH_MAX_LENGTH];
   char label[PATH_MAX_LENGTH];
   char exts[PATH_MAX_LENGTH];
   unsigned type;
   unsigned type_default;
   size_t directory_ptr;
   unsigned flags;
   rarch_setting_t *setting;
} menu_displaylist_info_t;

int menu_displaylist_push_list(menu_displaylist_info_t *info, unsigned type);

void menu_displaylist_push_list_process(menu_displaylist_info_t *info);

int menu_displaylist_push(file_list_t *list, file_list_t *menu_list);

int menu_displaylist_parse_settings(void *data, menu_displaylist_info_t *info, 
      const char *info_label, unsigned parse_type, bool add_empty_entry);

#ifdef __cplusplus
}
#endif

#endif
