//******************
//
// pleos_notes.h
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
// The "Notes" part is made for students.
// It allows to take notes directly in PLEOS.
//
// This file contains the source code of "pleos_notes.h".
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
#include "../headers/pleos_notes.h"

// The namespace "pleos" is used to simplify the all.
namespace pleos {

    // Loads an object in a page from XML
    std::shared_ptr<scls::GUI_Object> Notes_Page::__create_loaded_object_from_type(std::string object_name, std::string object_type, scls::GUI_Object* parent) {
        // Home
        if(object_name == "notes_home_page") {a_home_page = *parent->new_object<scls::GUI_Object>(object_name);return a_home_page;}

        // Navigation
        else if(object_name == "notes_hub"){a_hub_button = *parent->new_object<scls::GUI_Text>(object_name);return a_hub_button;}
        else if(object_name == "notes_navigation") {a_navigation = *parent->new_object<scls::GUI_Scroller_Choice>(object_name);return a_navigation;}

        // Input page
        GUI_OBJECT_CREATION(scls::GUI_Object, a_input_page, "notes_input_page")
        GUI_OBJECT_CREATION(scls::GUI_Text_Base<Text>, a_input_representation, "notes_input_representation")
        GUI_OBJECT_CREATION(scls::GUI_Text_Input, a_input_user, "notes_input_user")

        return scls::GUI_Page::__create_loaded_object_from_type(object_name, object_type, parent);
    }

    // Loads the representation of the input
    std::shared_ptr<scls::Image> Notes_Page::input_load_presentation_image(std::string input) {
        scls::Text_Image_Generator tig;scls::Text_Style needed_style;
        std::shared_ptr<scls::Image> image = tig.image_shared_ptr(input, needed_style);
        return image;
    }

    //******************
    //
    // Check the events
    //
    //******************

    // Function called after the XML loading
    void Notes_Page::after_xml_loading(){scls::GUI_Page::after_xml_loading();display_home_page();}

    // Checks the events of hiding each pages
    void Notes_Page::check_hiding(){}

    // Checks the events of navigation
    void Notes_Page::check_navigation(){
        // Check the selected page
        if(navigation()->selection_modified()){
            std::string page = navigation()->currently_selected_objects_during_this_frame()[0].name();

            // Home pages
            if(page == "home"){display_home_page();}
            GUI_OBJECT_SELECTION(display_input_page(), "input")
        }
    }

    // Updates the events
    void Notes_Page::update_event(){
        // Basic events
        scls::GUI_Page::update_event();
        check_navigation();
        if(hub_button()->is_clicked_during_this_frame(GLFW_MOUSE_BUTTON_LEFT)) {window_struct()->hide_all_pages_2d();window_struct()->display_page_2d("hub");}

        if(window_struct()->key_pressed_during_this_frame("up arrow")){window_struct()->hide_all_pages_2d();window_struct()->display_page_2d("maths");}

        if(window_struct()->key_pressed_during_this_frame("left control")){input_representation()->set_text(scls::format_string_as_plain_text(input_user()->text()));}

        // Temporary load / save
        if(window_struct()->key_pressed_during_this_frame("s") && (window_struct()->key_pressed("left control") || window_struct()->key_pressed("right control"))){scls::write_in_file("tests/lesson.txt", input_user()->text());}
        if(window_struct()->key_pressed_during_this_frame("$") && window_struct()->key_pressed_during_this_frame("left shift")){input_user()->set_text(scls::read_file("tests/lesson.txt"));}
    }
}
