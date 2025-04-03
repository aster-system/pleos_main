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
// This file contains the page of the "Notes" part.
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

#ifndef PLEOS_NOTES
#define PLEOS_NOTES

// Include PLEOS Libs
#include "../../pleos_libs/pleos_text.h"

// Possible pages
#define PLEOS_NOTES_HOME_PAGE 0
#define PLEOS_NOTES_INPUT_PAGE 100
#define PLEOS_NOTES_PROJECT_PAGE 200
#define PLEOS_NOTES_PROJECT_NOTE_CREATOR_PAGE 210
// File explorer
#define PLEOS_NOTES_FILE_EXPLORER_PAGE 10000
#define PLEOS_NOTES_FILE_EXPLORER_NEW_NOTES 10001
#define PLEOS_NOTES_FILE_EXPLORER_OPEN_NOTES 10002

// Include SCLS documentalist Agatha if needed
#include "../../../scls-documentalist-agatha/scls_documentalist.h"

// The namespace "pleos" is used to simplify the all.
namespace pleos {

    class Notes_Page : public scls::GUI_Page {
        // Class representating the "Notes" page for PLEOS
    public:

        // Notes_Page constructor
        Notes_Page(scls::_Window_Advanced_Struct* window_struct, std::string name):scls::GUI_Page(window_struct, name){};
        // Loads an object in a page from XML
        virtual std::shared_ptr<scls::GUI_Object> __create_loaded_object_from_type(std::string object_name, std::string object_type, scls::GUI_Object* parent);

        // Displays a note of the project
        void display_project_note(std::shared_ptr<scls::Replica_File> file);

        // Loads the navigation
        void load_navigation();
        // Loads the notes pattern
        void load_notes_pattern();
        // Loads the representation of the input
        std::shared_ptr<scls::Image> input_load_presentation_image(std::string input);
        // Creates new notes in the input
        void input_new_notes(std::string needed_path);
        // Opens an existing note in the project
        void input_open_notes(std::string note_name);

        // Creates a new note in the project
        void project_create_note(std::string note_name);

        // Getters and setters
        inline scls::Replica_File* current_note() const {return a_current_state.current_note.get();};
        inline scls::Replica_Project* current_notes() const {return a_current_state.current_notes.get();};
        inline scls::Pattern_Project* notes_pattern() const {return a_current_state.notes_pattern.get();};
        inline std::shared_ptr<scls::Pattern_Project> notes_pattern_shared_ptr() const {return a_current_state.notes_pattern;};

        //******************
        //
        // Check the events
        //
        //******************

        // Function called after the XML loading
        virtual void after_xml_loading();
        // Checks the events of file explorer
        void check_file_explorer();
        // Checks the events of hiding each pages
        void check_hiding();
        // Checks the events of input
        void check_home();
        // Checks the events of navigation
        void check_navigation();
        // Checks the events of project
        void check_project();
        void check_project_note_creator();
        void check_project_note_hiding();
        // Updates the events
        virtual void update_event();

        //******************
        //
        // Handle the pages
        //
        //******************

        // Hides all the pages
        inline void hide_all(){hide_sub_pages(true);check_hiding();};

        // Returns / resets the current page
        inline unsigned short current_file_explorer_page() const {return a_current_state.current_file_explorer_page;};
        inline unsigned short current_page() const {return a_current_state.current_page;};
        inline void set_current_file_explorer_page(unsigned short new_page) {a_current_state.current_file_explorer_page = new_page;};
        inline void set_current_page(unsigned short new_page) {a_current_state.current_page = new_page;};

        //******************
        //
        // GUI handling
        //
        //******************

        // Returns hub and navigation
        inline scls::GUI_Text* hub_button() const {return a_hub_button.get();};
        inline scls::GUI_Scroller_Choice* navigation() const {return a_navigation.get();};

        // Returns pages
        GUI_PAGE(scls::GUI_File_Explorer, a_file_explorer_page, PLEOS_NOTES_FILE_EXPLORER_PAGE, file_explorer_page, display_file_explorer_page, hide_all);
        GUI_PAGE(scls::GUI_Object, a_home_page, PLEOS_NOTES_HOME_PAGE, home_page, display_home_page, hide_all);
        GUI_PAGE(scls::GUI_Object, a_input_page, PLEOS_NOTES_INPUT_PAGE, input_page, display_input_page, hide_all);
        GUI_PAGE(scls::GUI_Object, a_project_page, PLEOS_NOTES_PROJECT_PAGE, project_page, display_project_page, hide_all);
        GUI_PAGE(scls::GUI_Object, a_project_note_creator_page, PLEOS_NOTES_PROJECT_NOTE_CREATOR_PAGE, project_note_creator_page, display_project_note_creator_page, hide_all);

        // Home handling
        GUI_OBJECT(scls::GUI_Text, a_home_new_notes, home_new_notes);
        GUI_OBJECT(scls::GUI_Text, a_home_open_notes, home_open_notes);

        // Input handling
        GUI_OBJECT(scls::GUI_Text_Base<Text>, a_input_representation, input_representation);
        GUI_OBJECT(scls::GUI_Text_Input, a_input_user, input_user);

        // Project handling
        GUI_OBJECT(scls::GUI_Text, a_project_new_note, project_new_note);
        GUI_OBJECT(scls::GUI_Text_Input, a_project_note_creator_name, project_note_creator_name);
        GUI_OBJECT(scls::GUI_Text, a_project_note_creator_validate, project_note_creator_validate);

    private:

        // Current state of the page
        struct {
            // Current notes
            std::shared_ptr<scls::Replica_File> current_note;
            std::shared_ptr<scls::Replica_Project> current_notes;
            // Pattern needed for notes
            std::shared_ptr<scls::Pattern_Project> notes_pattern;

            // Current file explorer page
            unsigned short current_file_explorer_page = PLEOS_NOTES_FILE_EXPLORER_NEW_NOTES;
            // Current page
            unsigned short current_page = PLEOS_NOTES_HOME_PAGE;
        } a_current_state;

        // Global navigation
        std::shared_ptr<scls::GUI_Text> a_hub_button;
        std::shared_ptr<scls::GUI_Scroller_Choice> a_navigation;
    };
}

#endif // PLEOS_NOTES
