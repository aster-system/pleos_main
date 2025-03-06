//******************
//
// pleos_it.h
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
// The "IT" part aims IT lessons.
// Its goal is to teach everyone about IT, easily, and with cool informations and animations.
//
// This file contains the source code of "pleos_it.h".
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
#include "../headers/pleos_it.h"

// The namespace "pleos" is used to simplify the all.
namespace pleos {
    // Loads an object in a page from XML
    std::shared_ptr<scls::GUI_Object> IT_Page::__create_loaded_object_from_type(std::string object_name, std::string object_type, scls::GUI_Object* parent) {
        // Trees simulation
        if(object_name == "it_data_structures_tree_simulation"){a_data_structures_tree_simulation = *parent->new_object<scls::GUI_Object>(object_name);return a_data_structures_tree_simulation;}

        // Pages
        else if(object_name == "it_algorithms_page") {a_algorithms_page = *parent->new_object<scls::GUI_Object>(object_name);return a_algorithms_page;}
        else if(object_name == "it_algorithms_sort_body") {a_algorithms_sort_page = *parent->new_object<scls::GUI_Text_Base<Text>>(object_name);return a_algorithms_sort_page;}
        else if(object_name == "it_data_structures_page") {a_data_structures_page = *parent->new_object<scls::GUI_Object>(object_name);return a_data_structures_page;}
        else if(object_name == "it_data_structures_tree_body"){a_data_structures_tree_page = *parent->new_object<scls::GUI_Text_Base<Text>>(object_name);return a_data_structures_tree_page;}
        else if(object_name == "it_data_structures_tree_simulation_body"){a_data_structures_tree_simulation_page = *parent->new_object<scls::GUI_Text>(object_name);return a_data_structures_tree_simulation_page;}

        // Navigation
        else if(object_name == "it_hub"){a_hub_button = *parent->new_object<scls::GUI_Text>(object_name);return a_hub_button;}
        else if(object_name == "it_navigation") {a_navigation = *parent->new_object<scls::GUI_Scroller_Choice>(object_name);return a_navigation;}

        return scls::GUI_Page::__create_loaded_object_from_type(object_name, object_type, parent);
    }

    // Check the events of navigation
    void IT_Page::check_navigation() {
        // Check the selected page
        if(a_navigation.get()->selection_modified()){
            std::string page = a_navigation.get()->currently_selected_objects_during_this_frame()[0].name();

            // IT pages
            if(page == "algorithms"){display_algorithms_page();}
            else if(page == "algorithms_sort"){display_algorithms_sort_page();}
            else if(page == "data_structures_trees"){display_data_structures_trees_page();}
            else if(page == "data_structures_trees_graphic"){
                display_data_structures_trees_simulation_page();

                std::string content = "<tree><node name=\"Ville 1\" x=0 y=0></node><node name=\"Ville 2\" x=0 y=-1><link id=0></node><node name=\"Ville 3\" x=3/2 y=1/2><link id=1></node><node name=\"Ville 4\" x=-1 y=1/2><link id=2><link id=0></node><node name=\"Ville 5\" x=1/2 y=-1/2><link id=3></node></tree>";
                std::shared_ptr<Tree<std::string>> tree = tree_from_xml(content, window_struct()->balises_shared_ptr());
                data_structures_tree_simulation()->texture()->set_image(tree.get()->to_image());
            }
        }

        // Check the hub button
        if(hub_button()->is_clicked_during_this_frame(GLFW_MOUSE_BUTTON_LEFT)) {window_struct()->hide_all_pages_2d();window_struct()->display_page_2d("hub");}
    }

    // Update the events
    void IT_Page::update_event() {
        // Basic events
        scls::GUI_Page::update_event();
        check_navigation();
    }
}
