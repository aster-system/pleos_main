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

#ifndef PLEOS_SETTINGS
#define PLEOS_SETTINGS

// Include PLEOS Libs
#include "../../pleos_libs/pleos_mathematics.h"
#include "../../pleos_libs/pleos_text.h"

// Pages
#define PLEOS_SETTINGS_HOME_PAGE 0
#define PLEOS_SETTINGS_ABOUT_PAGE 1
#define PLEOS_SETTINGS_ABOUT_PRESENTATION_PAGE 2
// Law pages
#define PLEOS_SETTINGS_LAW_PAGE 100
#define PLEOS_SETTINGS_LAW_LICENSE_PAGE 110

// The namespace "pleos" is used to simplify the all.
namespace pleos {

    class Settings_Page : public scls::GUI_Page {
        // Class representating the "Maths" page for PLEOS
    public:

        // Settings_Page constructor
        Settings_Page(scls::_Window_Advanced_Struct* window_struct, std::string name):scls::GUI_Page(window_struct, name){};
        // Loads an object in a page from XML
        virtual std::shared_ptr<scls::GUI_Object> __create_loaded_object_from_type(std::string object_name, std::string object_type, scls::GUI_Object* parent);

        // About part
        GUI_PAGE(scls::GUI_Object, a_about_page, PLEOS_SETTINGS_ABOUT_PAGE, about_page, display_about_page, hide_all);
        GUI_PAGE(scls::GUI_Text_Base<Text>, a_about_presentation_page, PLEOS_SETTINGS_ABOUT_PRESENTATION_PAGE, about_presentation_page, display_about_presentation_page, display_about_page);

        // Law part
        GUI_PAGE(scls::GUI_Object, a_law_page, PLEOS_SETTINGS_LAW_PAGE, law_page, display_law_page, hide_all);
        GUI_PAGE(scls::GUI_Text_Base<Text>, a_law_license_page, PLEOS_SETTINGS_LAW_LICENSE_PAGE, law_license_page, display_law_license_page, display_law_page);

        //******************
        //
        // Check the events
        //
        //******************

        // Function called after the XML loading
        virtual void after_xml_loading();
         // Checks the events of navigation
        void check_navigation();
        // Updates the events
        virtual void update_event();

        //******************
        //
        // Handle the pages
        //
        //******************

        // Display a page by its name
        inline void display_page(std::string needed_page){if(needed_page == std::string("about_presentation")){display_about_presentation_page();}else if(needed_page == std::string("law_license")){display_law_license_page();}};

        // Hides all the pages
        void hide_all(){hide_sub_pages(true);};

        // Returns / resets the current page
        inline unsigned short current_page() const {return a_current_state.current_page;};
        inline void set_current_page(unsigned short new_page) {a_current_state.current_page = new_page;};

        //******************
        //
        // GUI handling
        //
        //******************

        // Returns navigation
        inline scls::GUI_Text* hub_button() const {return a_hub_button.get();};
        inline scls::GUI_Scroller_Choice* navigation() const {return a_navigation.get();};

    private:

        // Current state of the page
        struct {
            // Current page
            unsigned short current_page = PLEOS_SETTINGS_HOME_PAGE;
        } a_current_state;

        // Global navigation
        std::shared_ptr<scls::GUI_Text> a_hub_button;
        std::shared_ptr<scls::GUI_Scroller_Choice> a_navigation;
    };
}

#endif // PLEOS_SETTINGS
