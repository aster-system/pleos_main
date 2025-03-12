//******************
//
// pleos_settings.h
//
//******************
// Presentation :
//
// PLEOS, by Aster System, is a project which aims education.
// By using the power of SCLS and other Aster System's tools, we created  this.
// We want to make education easier for everyone (teachers, as students and pupils).
// The software is made in french, because the main goal is France educational system.
// For more information, see : https://aster-system.github.io/aster-system/projects/pleos.html.
//
// The "Settings" part is only usefull in the context of the software.
// Its intended to handle the software easily, from a single page of it.
//
// This file contains the page of the Settings part.
//
//******************
//
// License (GPL V3.0) :
//
// Copyright (C) 2024 by Aster System, Inc. <https://aster-system.github.io/aster-system/>
// This file is part of PLEOS.
// PLEOS is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
// PLEOS is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
// You should have received a copy of the GNU General Public License along with PLEOS. If not, see <https://www.gnu.org/licenses/>.
//

// Include PLEOS Settings
#include "../headers/pleos_settings.h"

// The namespace "pleos" is used to simplify the all.
namespace pleos {

    // Loads an object in a page from XML
    std::shared_ptr<scls::GUI_Object> Settings_Page::__create_loaded_object_from_type(std::string object_name, std::string object_type, scls::GUI_Object* parent){
        // Navigation
        if(object_name == "settings_hub"){a_hub_button = *parent->new_object<scls::GUI_Text>(object_name);return a_hub_button;}
        else if(object_name == "settings_navigation") {a_navigation = *parent->new_object<scls::GUI_Scroller_Choice>(object_name);return a_navigation;}

        // Pages
        GUI_OBJECT_CREATION(scls::GUI_Object, a_law_page, "settings_law_page")

        // Law part
        GUI_OBJECT_CREATION(scls::GUI_Text_Base<Text>, a_law_license_page, "settings_law_license_body")

        return scls::GUI_Page::__create_loaded_object_from_type(object_name, object_type, parent);
    };

    //******************
    //
    // Check the events
    //
    //******************

    // Function called after the XML loading
    void Settings_Page::after_xml_loading(){};

     // Checks the events of navigation
    void Settings_Page::check_navigation(){
        // Check the selected page
        if(a_navigation.get()->selection_modified()){
            std::string page = a_navigation.get()->currently_selected_objects_during_this_frame()[0].name();
            display_page(page);
        }

        // Check the hub button
        if(hub_button()->is_clicked_during_this_frame(GLFW_MOUSE_BUTTON_LEFT)) {window_struct()->hide_all_pages_2d();window_struct()->display_page_2d("hub");}
    };

    // Updates the events
    void Settings_Page::update_event(){
        // Basic events
        scls::GUI_Page::update_event();
        check_navigation();
    };
}
