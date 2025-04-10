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
        GUI_OBJECT_CREATION(scls::GUI_File_Explorer, a_file_explorer_page, "notes_file_explorer_page")
        else if(object_name == "notes_hub"){a_hub_button = *parent->new_object<scls::GUI_Text>(object_name);return a_hub_button;}
        else if(object_name == "notes_navigation") {a_navigation = *parent->new_object<scls::GUI_Scroller_Choice>(object_name);return a_navigation;}
        GUI_OBJECT_CREATION(scls::GUI_Object, a_project_page, "notes_project_page")
        GUI_OBJECT_CREATION(scls::GUI_Object, a_project_note_creator_page, "notes_project_note_creator_page")

        // Home page
        GUI_OBJECT_CREATION(scls::GUI_Text, a_home_new_notes, "notes_home_new_notes")
        GUI_OBJECT_CREATION(scls::GUI_Text, a_home_open_notes, "notes_home_open_notes")

        // Input page
        GUI_OBJECT_CREATION(scls::GUI_Object, a_input_page, "notes_input_page")
        GUI_OBJECT_CREATION(scls::GUI_Text_Base<Text>, a_input_representation, "notes_input_representation")
        GUI_OBJECT_CREATION(scls::GUI_Text_Input, a_input_user, "notes_input_user")

        // Project page
        GUI_OBJECT_CREATION(scls::GUI_Text, a_project_new_note, "notes_project_new_note")
        GUI_OBJECT_CREATION(scls::GUI_Text_Input, a_project_note_creator_name, "notes_project_note_creator_name")
        GUI_OBJECT_CREATION(scls::GUI_Text, a_project_note_creator_validate, "notes_project_note_creator_validate")

        return scls::GUI_Page::__create_loaded_object_from_type(object_name, object_type, parent);
    }

    // Displays a note of the project
    void Notes_Page::display_project_note(std::shared_ptr<scls::Replica_File> file) {
        display_input_page();
        input_user()->set_text(file.get()->content_out_pattern);
        a_current_state.current_note = file;
    }

    // Loads the navigation
    void Notes_Page::load_navigation() {
        // Re-load the navigation
        navigation()->reset();
        navigation()->add_object("home", "Accueil");
        navigation()->add_object("notes_project", "Notes actuelles");

        // Loads the notes
        for(int i = 0;i<static_cast<int>(current_notes()->replica_files().size());i++) {
            navigation()->add_object("input-" + std::to_string(i), current_notes()->replica_files()[i].get()->internal_path);
        }
    }

    // Loads the notes pattern
    void Notes_Page::load_notes_pattern() {
        std::shared_ptr<scls::Pattern_Project>& pattern = a_current_state.notes_pattern;
        pattern = std::make_shared<scls::Pattern_Project>("notes_pattern", "");
    }

    // Loads the representation of the input
    std::shared_ptr<scls::Image> Notes_Page::input_load_presentation_image(std::string input) {
        scls::Text_Image_Generator tig;scls::Text_Style needed_style;
        std::shared_ptr<scls::Image> image = tig.image_shared_ptr(scls::format_string_break_line(input, std::string(" ")), needed_style);
        return image;
    }

    // Creates new notes in the input
    void Notes_Page::input_new_notes(std::string needed_path) {
        // Check the pattern
        if(notes_pattern() == 0){load_notes_pattern();}

        // Create the project
        needed_path += std::string("/notes/");
        if(!std::filesystem::exists(needed_path)){std::filesystem::create_directory(needed_path);}
        std::shared_ptr<scls::Replica_Project>& notes = a_current_state.current_notes;
        notes = std::make_shared<scls::Replica_Project>("notes", needed_path, notes_pattern_shared_ptr());

        // Load the navigation
        load_navigation();
    }

    // Opens an existing note in the project
    void Notes_Page::input_open_notes(std::string note_path) {
        // Check the pattern
        if(notes_pattern() == 0){load_notes_pattern();}

        // Create the project
        if(!scls::contains_string(note_path, ".sdr")){note_path += std::string("/maths.sdr");}
        if(std::filesystem::exists(note_path)){
            std::shared_ptr<scls::Replica_Project>& notes = a_current_state.current_notes;
            notes.reset(scls::Replica_Project::load_sda_0_2(note_path, notes_pattern_shared_ptr()));
        }

        // Load the navigation
        load_navigation();
    }

    // Creates a new note in the project
    void Notes_Page::project_create_note(std::string note_name) {
        // Create the note
        std::shared_ptr<scls::Replica_File> new_note = current_notes()->new_replica_file(note_name, 0);

        // Load the navigation
        load_navigation();
        display_project_note(new_note);
    }

    //******************
    //
    // Check the events
    //
    //******************

    // Function called after the XML loading
    void Notes_Page::after_xml_loading(){scls::GUI_Page::after_xml_loading();display_home_page();}

    // Checks the events of file explorer
    void Notes_Page::check_file_explorer() {
        if(file_explorer_page()->file_chosen()) {
            // Create notes
            std::string needed_path = file_explorer_page()->current_path();
            if(current_file_explorer_page() == PLEOS_NOTES_FILE_EXPLORER_NEW_NOTES) {input_new_notes(needed_path);}
            else if(current_file_explorer_page() == PLEOS_NOTES_FILE_EXPLORER_OPEN_NOTES) {input_open_notes(needed_path);}
        }
    }

    // Checks the events of hiding each pages
    void Notes_Page::check_hiding(){if(current_page() == PLEOS_NOTES_INPUT_PAGE){check_project_note_hiding();} }

    // Checks the events of home
    void Notes_Page::check_home() {
        if(home_new_notes()->is_clicked_during_this_frame(GLFW_MOUSE_BUTTON_LEFT)) {
            // Create new notes
            display_file_explorer_page();
            file_explorer_page()->set_current_user_document_directory();
            set_current_file_explorer_page(PLEOS_NOTES_FILE_EXPLORER_NEW_NOTES);
        }
        else if(home_open_notes()->is_clicked_during_this_frame(GLFW_MOUSE_BUTTON_LEFT)) {
            // Open new notes
            display_file_explorer_page();
            file_explorer_page()->set_current_user_document_directory();
            set_current_file_explorer_page(PLEOS_NOTES_FILE_EXPLORER_OPEN_NOTES);
        }
    }

    // Checks the events of navigation
    void Notes_Page::check_navigation(){
        // Check the selected page
        if(navigation()->selection_modified()){
            std::string page = navigation()->currently_selected_objects_during_this_frame()[0].name();

            // Home pages
            if(page == "home"){display_home_page();}
            GUI_OBJECT_SELECTION(display_input_page(), "input")
            GUI_OBJECT_SELECTION(display_project_page(), "notes_project")
            else if(page.substr(0, 5) == std::string("input")) {
                int needed_number = std::stoi(page.substr(6, page.size() - 6));
                display_project_note(current_notes()->replica_files()[needed_number]);
            }
        }
    }

    // Checks the events of project
    void Notes_Page::check_project() {
        // Create a note
        if(project_new_note()->is_clicked_during_this_frame(GLFW_MOUSE_BUTTON_LEFT)){display_project_note_creator_page();}
    }

    // Checks the events when the project is hide
    void Notes_Page::check_project_note_hiding() {
        // Save the current replica file
        if(current_note() != 0) {current_note()->content_out_pattern = input_user()->text();}
    }

    // Checks the events of project note creator
    void Notes_Page::check_project_note_creator() {
        // Validate a note
        if(project_note_creator_validate()->is_clicked_during_this_frame(GLFW_MOUSE_BUTTON_LEFT)){project_create_note(project_note_creator_name()->text());}
    }

    // Updates the events
    void Notes_Page::update_event(){
        // Basic events
        scls::GUI_Page::update_event();
        check_navigation();

        // File explorer events
        if(current_page() == PLEOS_NOTES_FILE_EXPLORER_PAGE){check_file_explorer();}

        // Home events
        if(current_page() == PLEOS_NOTES_HOME_PAGE){check_home();}

        // Project events
        if(current_page() == PLEOS_NOTES_PROJECT_PAGE){check_project();}
        if(current_page() == PLEOS_NOTES_PROJECT_NOTE_CREATOR_PAGE){check_project_note_creator();}

        if(hub_button()->is_clicked_during_this_frame(GLFW_MOUSE_BUTTON_LEFT)) {window_struct()->hide_all_pages_2d();window_struct()->display_page_2d("hub");}

        if(window_struct()->key_pressed_during_this_frame("up arrow")){window_struct()->hide_all_pages_2d();window_struct()->display_page_2d("maths");}

        if(window_struct()->key_pressed_during_this_frame("left control")){
            std::string input = scls::format_string_break_line(input_user()->plain_text(), std::string(" "));
            input_representation()->set_text(input);
        }

        // Temporary load / save
        if(current_notes() != 0 && window_struct()->key_pressed_during_this_frame("s") && (window_struct()->key_pressed("left control") || window_struct()->key_pressed("right control"))){check_project_note_hiding();current_notes()->save_sda_0_2();}
    }
}
