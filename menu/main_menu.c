#include "main_menu.h"

//WIP
GMenu* g_main_menu(){
    //main menu
    GMenu* main_menu = g_menu_new();

    //file menu
    GMenu* file_menu = g_menu_new();

    //file menu children
    GMenuItem* open = g_menu_item_new("Open", "Open");
    GMenuItem* save = g_menu_item_new("Save", "Save");
    GMenuItem* close = g_menu_item_new("Close", "Close");

    //set attr
    g_menu_item_set_attribute(open, G_MENU_ATTRIBUTE_ACTION, "s", "app.open");
    g_menu_item_set_attribute(save, G_MENU_ATTRIBUTE_ACTION, "s", "app.save");
    g_menu_item_set_attribute(close, G_MENU_ATTRIBUTE_ACTION, "s", "app.close");
    
    g_menu_insert_item(file_menu, 0, open);
    g_menu_insert_item(file_menu, 1, save);
    g_menu_insert_item(file_menu, 2, close);
    
    //about menu
    GMenu* about_menu = g_menu_new();
    
    //about menu children
    g_menu_insert(about_menu, 0, "Version", "Version");

    g_menu_append_submenu(main_menu, "File", (GMenuModel*) file_menu);
    g_menu_append_submenu(main_menu, "About", (GMenuModel*) about_menu);

    return main_menu;
}