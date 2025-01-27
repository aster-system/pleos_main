//******************
//
// pleos_physic.cpp
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
// The "Physic" part provides some datas about physic.
//
// This file contains the source code of "pleos_physic.h".
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
#include "../headers/pleos_physic.h"

// The namespace "pleos" is used to simplify the all.
namespace pleos {
    // Loads an object in a page from XML
    std::shared_ptr<scls::GUI_Object> Physic_Page::__create_loaded_object_from_type(std::string object_name, std::string object_type, scls::GUI_Object* parent) {
        // Matter
        if(object_name == "physic_matter_bohr_model_simulation") {a_physic_matter_bohr_model_simulation = *parent->new_object<Graphic>(object_name);return a_physic_matter_bohr_model_simulation;}
        else if(object_name == "physic_matter_bohr_model_simulation_body"){a_physic_matter_bohr_model_simulation_body = *parent->new_object<scls::GUI_Object>(object_name);return a_physic_matter_bohr_model_simulation_body;}
        else if(object_name == "physic_matter_scale_body"){a_physic_matter_scale_body = *parent->new_object<scls::GUI_Text>(object_name);return a_physic_matter_scale_body;}

        // Pages
        else if(object_name == "physic_matter_page"){a_physic_matter_page = *parent->new_object<scls::GUI_Object>(object_name);return a_physic_matter_page;}

        // Navigation
        else if(object_name == "physic_navigation") {a_navigation = *parent->new_object<scls::GUI_Scroller_Choice>(object_name);return a_navigation;}

        return scls::GUI_Page::__create_loaded_object_from_type(object_name, object_type, parent);
    }

    // Check the events of navigation
    void Physic_Page::check_navigation() {
        // Check the selected page
        if(a_navigation.get()->selection_modified()){
            std::string page = a_navigation.get()->currently_selected_objects_during_this_frame()[0].name();

            // Arithmetic pages
            if(page == "matter_bohr_model_simulation"){display_matter_bohr_model_simulation_page();}
            else if(page == "matter_scale"){display_matter_scale_page();}
        }
    }

    // Update the events
    void Physic_Page::update_event() {
        // Basic events
        scls::GUI_Page::update_event();
        check_navigation();
    }
}
