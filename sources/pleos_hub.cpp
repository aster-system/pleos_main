//******************
//
// pleos_hub.cpp
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
// The "Hub" part provides a hub between every part of the software.
//
// This file contains the source code of "pleos_hub.h".
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

// Include PLEOS Libs
#include "../headers/pleos_hub.h"

// The namespace "pleos" is used to simplify the all.
namespace pleos {
    // Loads an object in a page from XML
    std::shared_ptr<scls::GUI_Object> Hub_Page::__create_loaded_object_from_type(std::string object_name, std::string object_type, scls::GUI_Object* parent) {
        // Navigation
        if(object_name == "hub_navigation_chemistry_button"){a_navigation_chemistry_button = *parent->new_object<scls::GUI_Text>(object_name);return a_navigation_chemistry_button;}
        else if(object_name == "hub_navigation_it_button"){a_navigation_it_button = *parent->new_object<scls::GUI_Text>(object_name);return a_navigation_it_button;}
        else if(object_name == "hub_navigation_maths_button") {a_navigation_maths_button = *parent->new_object<scls::GUI_Text>(object_name);return a_navigation_maths_button;}
        else if(object_name == "hub_navigation_physic_button"){a_navigation_physic_button = *parent->new_object<scls::GUI_Text>(object_name);return a_navigation_physic_button;}

        return scls::GUI_Page::__create_loaded_object_from_type(object_name, object_type, parent);
    }

    // Checks the events of navigation
    void Hub_Page::check_navigation() {
        if(a_navigation_chemistry_button.get()->is_clicked_during_this_frame(GLFW_MOUSE_BUTTON_LEFT)) {window_struct()->hide_all_pages_2d();window_struct()->display_page_2d("chemistry");}
        if(a_navigation_it_button.get()->is_clicked_during_this_frame(GLFW_MOUSE_BUTTON_LEFT)) {window_struct()->hide_all_pages_2d();window_struct()->display_page_2d("it");}
        if(a_navigation_maths_button.get()->is_clicked_during_this_frame(GLFW_MOUSE_BUTTON_LEFT)) {window_struct()->hide_all_pages_2d();window_struct()->display_page_2d("maths");}
        if(a_navigation_physic_button.get()->is_clicked_during_this_frame(GLFW_MOUSE_BUTTON_LEFT)) {window_struct()->hide_all_pages_2d();window_struct()->display_page_2d("physic");}
    }

    // Updates the events
    void Hub_Page::update_event() {GUI_Page::update_event();check_navigation();}
}
