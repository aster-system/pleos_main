//******************
//
// pleos_physic.h
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
// This file contains the main "Physic" page.
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

#ifndef PLEOS_PHYSIC_PAGE
#define PLEOS_PHYSIC_PAGE

// Include PLEOS Maths
#include "pleos_maths.h"

// The namespace "pleos" is used to simplify the all.
namespace pleos {

    class Physic_Page : public scls::GUI_Page {
        // Class representating the "Physic" page for PLEOS
    public:

        // Physic_Page constructor
        Physic_Page(scls::_Window_Advanced_Struct* window_struct, std::string name):scls::GUI_Page(window_struct, name){};
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
        std::shared_ptr<scls::GUI_Scroller_Choice> a_navigation;
    };
}

#endif // PLEOS_PHYSIC_PAGE
