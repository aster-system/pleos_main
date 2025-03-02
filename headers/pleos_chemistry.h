//******************
//
// pleos_chemistry.h
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
// This file contains the page of the Chemistry plugin.
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

#ifndef PLEOS_CHEMISTRY
#define PLEOS_CHEMISTRY

// Include PLEOS Libs
#include "../../pleos_libs/pleos_mathematics.h"

// Possible pages
#define PLEOS_CHEMISTRY_HOME_PAGE 0

// The namespace "pleos" is used to simplify the all.
namespace pleos {

    class Chemistry_Page : public scls::GUI_Page {
        // Class representating the "Chemistry" page for PLEOS
    public:

        // Chemistry_Page constructor
        Chemistry_Page(scls::_Window_Advanced_Struct* window_struct, std::string name):scls::GUI_Page(window_struct, name){};
        // Loads an object in a page from XML
        virtual std::shared_ptr<scls::GUI_Object> __create_loaded_object_from_type(std::string object_name, std::string object_type, scls::GUI_Object* parent);

        //******************
        //
        // Check the events
        //
        //******************

        // Function called after the XML loading
        virtual void after_xml_loading();
        // Checks the events of hiding each pages
        void check_hiding();
        // Checks the events of navigation
        void check_navigation();
        // Updates the events
        virtual void update_event();

        //******************
        //
        // Handle the pages
        //
        //******************

        // Displays the home page
        void display_home_page(){hide_all();home_page()->set_visible(true);};
        void display_home_definitions_page(){display_home_page();home_definitions_page()->set_visible(true);};

        // Hides all the pages
        inline void hide_all(){hide_sub_pages(true);check_hiding();};

        // Returns / resets the current page
        inline unsigned short current_page() const {return a_current_state.current_page;};
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
        inline scls::GUI_Object* home_page() const {return a_home_page.get();};

        // Home page
        inline scls::GUI_Text* home_definitions_page() const {return a_home_definitions_page.get();};

    private:

        // Current state of the page
        struct {
            // Current page
            unsigned short current_page = PLEOS_CHEMISTRY_HOME_PAGE;
        } a_current_state;

        // Global navigation
        std::shared_ptr<scls::GUI_Text> a_hub_button;
        std::shared_ptr<scls::GUI_Scroller_Choice> a_navigation;

        // Pages
        std::shared_ptr<scls::GUI_Object> a_home_page;

        // Home page
        std::shared_ptr<scls::GUI_Text> a_home_definitions_page;
    };
}

#endif // PLEOS_CHEMISTRY
