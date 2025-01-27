//******************
//
// pleos_hub.h
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
// This file contains the source code of the hub and the main software.
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

#ifndef PLEOS_HUB
#define PLEOS_HUB

// Include PLEOS plugins
#include "pleos_it.h"
#include "pleos_maths.h"
#include "pleos_physic.h"

// The namespace "pleos" is used to simplify the all.
namespace pleos {

    class Hub_Page : public scls::GUI_Page {
        // Class representating the "Hub" page for PLEOS
    public:

        // Hub_Page constructor
        Hub_Page(scls::_Window_Advanced_Struct* window_struct, std::string name):scls::GUI_Page(window_struct, name){};
        // Loads an object in a page from XML
        virtual std::shared_ptr<scls::GUI_Object> __create_loaded_object_from_type(std::string object_name, std::string object_type, scls::GUI_Object* parent);

        // Returns / resets the current page
        inline unsigned short current_page() const {return a_current_state.current_page;};
        inline void set_current_page(unsigned short new_page) {a_current_state.current_page = new_page;};

        //******************
        //
        // Check the events
        //
        //******************

        // Checks the events of navigation
        void check_navigation();
        // Updates the events
        virtual void update_event();

   private:

        // Current state of the page
        struct {
            // Current page
            unsigned short current_page = PLEOS_MATHS_HOME_PAGE;
        } a_current_state;

        //******************
        // GUI handling
        //******************

        // Navigation
        std::shared_ptr<scls::GUI_Text> a_navigation_it_button;
        std::shared_ptr<scls::GUI_Text> a_navigation_maths_button;
        std::shared_ptr<scls::GUI_Text> a_navigation_physic_button;
    };

    class Pleos_Window : public scls::Window {
        // Window in PLEOS
    public :
        // Pleos_Window constructor
        Pleos_Window(unsigned int w, unsigned int h, std::string path) : scls::Window(w, h, path) { set_window_title(std::string("PLEOS - Hub")); }

        // Create an object in the window
        std::shared_ptr<scls::Object> __create_loaded_object_from_type(std::string object_name, std::string object_type) {
            if(object_name == "hub") {std::shared_ptr<Hub_Page> hub = *new_page_2d<Hub_Page>(object_name);return hub;}
            else if(object_name == "it") {std::shared_ptr<IT_Page> hub = *new_page_2d<IT_Page>(object_name);return hub;}
            else if(object_name == "maths") {std::shared_ptr<Maths_Page> hub = *new_page_2d<Maths_Page>(object_name);return hub;}
            else if(object_name == "physic") {std::shared_ptr<Physic_Page> hub = *new_page_2d<Physic_Page>(object_name);return hub;}
            return scls::Window::__create_loaded_object_from_type(object_name, object_type);
        }
    };
}

#endif // PLEOS_HUB
