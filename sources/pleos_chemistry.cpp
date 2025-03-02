//******************
//
// pleos_chemistry.cpp
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
// The "Chemistry" part aims chemistry lessons.
// Its goal is to provide a big amount of well structured informations and animations for chemistry.
//
// This file contains the source code of pleos_chemistry.h.
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
#include "../headers/pleos_chemistry.h"

// The namespace "pleos" is used to simplify the all.
namespace pleos {

    // Loads an object in a page from XML
    std::shared_ptr<scls::GUI_Object> Chemistry_Page::__create_loaded_object_from_type(std::string object_name, std::string object_type, scls::GUI_Object* parent) {
        // Home
        if(object_name == "chemistry_home_page") {a_home_page = *parent->new_object<scls::GUI_Object>(object_name);return a_home_page;}
        else if(object_name == "chemistry_home_definitions_body") {a_home_definitions_page = *parent->new_object<scls::GUI_Text>(object_name);return a_home_definitions_page;}

        // Navigation
        else if(object_name == "chemistry_hub"){a_hub_button = *parent->new_object<scls::GUI_Text>(object_name);return a_hub_button;}
        else if(object_name == "chemistry_navigation") {a_navigation = *parent->new_object<scls::GUI_Scroller_Choice>(object_name);return a_navigation;}

        return scls::GUI_Page::__create_loaded_object_from_type(object_name, object_type, parent);
    }

    //******************
    //
    // Check the events
    //
    //******************

    // Function called after the XML loading
    void Chemistry_Page::after_xml_loading(){scls::GUI_Page::after_xml_loading();display_home_page();}

    // Checks the events of hiding each pages
    void Chemistry_Page::check_hiding(){}

    // Checks the events of navigation
    void Chemistry_Page::check_navigation(){
        // Check the selected page
        if(navigation()->selection_modified()){
            std::string page = navigation()->currently_selected_objects_during_this_frame()[0].name();

            // Home pages
            if(page == "home_definitions"){display_home_definitions_page();}
        }
    }

    // Updates the events
    void Chemistry_Page::update_event(){
        // Basic events
        scls::GUI_Page::update_event();
        check_navigation();
        if(hub_button()->is_clicked_during_this_frame(GLFW_MOUSE_BUTTON_LEFT)) {window_struct()->hide_all_pages_2d();window_struct()->display_page_2d("hub");}
    }
}
