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

// Include PLEOS Maths and PLEOS physic
#include "pleos_maths.h"
#include "../../pleos_libs/pleos_physic.h"

// Possible pages
#define PLEOS_PHYSIC_HOME_PAGE 0
// Matter pages
#define PLEOS_PHYSIC_MATTER_SCALE_PAGE 101
#define PLEOS_PHYSIC_MATTER_BOHR_MODEL_PAGE 110
#define PLEOS_PHYSIC_MATTER_BOHR_MODEL_SIMULATION_PAGE 115
#define PLEOS_PHYSIC_MATTER_QUANTUM_MECHANIC_PAGE 120
#define PLEOS_PHYSIC_MATTER_BOSONS_PAGE 150
// Mechanic pages
#define PLEOS_PHYSIC_MECHANIC_SHOCKS_PAGE 120

// The namespace "pleos" is used to simplify the all.
namespace pleos {

    class Physic_Page : public scls::GUI_Page {
        // Class representating the "Physic" page for PLEOS
    public:

        // Physic_Page constructor
        Physic_Page(scls::_Window_Advanced_Struct* window_struct, std::string name):scls::GUI_Page(window_struct, name){};
        // Loads an object in a page from XML
        virtual std::shared_ptr<scls::GUI_Object> __create_loaded_object_from_type(std::string object_name, std::string object_type, scls::GUI_Object* parent);

        // Function called after the XML loading
        virtual void after_xml_loading(){display_home_definition_body();};

        //******************
        //
        // Matter page
        //
        //******************

        // Loads the bohr model simulation
        void matter_load_bohr_model_simulation();

        // Getters and setters
        inline Bohr_Model& matter_bohr_model() {return a_current_state.matter_bohr_model;};
        inline std::vector<std::shared_ptr<Bohr_Model::Electron>>& matter_bohr_model_simulation_electrons() {return a_current_state.matter_bohr_model_simulation_electrons;};
        inline std::vector<std::shared_ptr<Bohr_Model::Photon>>& matter_bohr_model_simulation_photons() {return a_current_state.matter_bohr_model_simulation_photons;};
        inline int& matter_bohr_model_simulation_photons_number() {return a_current_state.matter_bohr_model_simulation_photons_number;};

        //******************
        //
        // Check the events
        //
        //******************

        // Checks the events of navigation
        void check_navigation();
        // Updates the page
        virtual void update();
        // Updates the Bohr model simulation
        void update_bohr_model_simulation();
        // Updates the events
        virtual void update_event();

        //******************
        //
        // Handle pages
        //
        //******************

        // Displays the matter pages
        void display_matter_bohr_model_page(){set_current_page(PLEOS_PHYSIC_MATTER_BOHR_MODEL_PAGE);display_matter_page();matter_bohr_model_page()->set_visible(true);};
        void display_matter_bohr_model_simulation_page(){set_current_page(PLEOS_PHYSIC_MATTER_BOHR_MODEL_SIMULATION_PAGE);display_matter_page();matter_bohr_model_simulation_page()->set_visible(true);matter_load_bohr_model_simulation();};
        void display_matter_bosons_page(){set_current_page(PLEOS_PHYSIC_MATTER_BOSONS_PAGE);display_matter_page();matter_bosons_body_page()->set_visible(true);};
        void display_matter_page(){hide_all();matter_page()->set_visible(true);};
        void display_matter_scale_page(){set_current_page(PLEOS_PHYSIC_MATTER_SCALE_PAGE);display_matter_page();matter_scale_page()->set_visible(true);}

        // Displays the mechanic pages
        void display_mechanic_dynamic_page(){display_mechanic_page();mechanic_dynamic_page()->set_visible(true);}
        void display_mechanic_kinematic_page(){display_mechanic_page();mechanic_kinematic_page()->set_visible(true);}
        void display_mechanic_page(){hide_all();mechanic_page()->set_visible(true);};

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

        // Navigation
        inline scls::GUI_Text* hub_button() const {return a_hub_button.get();};

        // Returns pages
        GUI_PAGE(scls::GUI_Object, a_home_body, PLEOS_PHYSIC_HOME_PAGE, home_body, display_home_body, hide_all);
        inline scls::GUI_Text* matter_bohr_model_page() const {return a_physic_matter_bohr_model_body.get();};
        inline scls::GUI_Object* matter_bohr_model_simulation_page() const {return a_physic_matter_bohr_model_simulation_body.get();};
        inline scls::GUI_Text* matter_bosons_body_page() const {return a_physic_matter_bosons_body.get();};
        inline scls::GUI_Object* matter_page() const {return a_physic_matter_page.get();};
        inline scls::GUI_Text* matter_scale_page() const {return a_physic_matter_scale_body.get();};
        inline scls::GUI_Object* mechanic_page() const {return a_physic_mechanic_page.get();};

        // Home
        GUI_PAGE(scls::GUI_Text_Base<Text>, a_home_definition_body, PLEOS_PHYSIC_HOME_PAGE, home_definition_body, display_home_definition_body, display_home_body);

        // Matter
        inline Graphic_Object* matter_bohr_model_simulation() const {return a_physic_matter_bohr_model_simulation.get();};
        GUI_PAGE(scls::GUI_Text_Base<Text>, a_physic_matter_quantum_mechanic_page, PLEOS_PHYSIC_MATTER_QUANTUM_MECHANIC_PAGE, matter_quantum_mechanic_page, display_matter_quantum_mechanic_page, display_matter_page);

        // Mechanic
        GUI_PAGE(scls::GUI_Text_Base<Text>, a_physic_mechanic_shocks_body, PLEOS_PHYSIC_MECHANIC_SHOCKS_PAGE, mechanic_shocks_body, display_mechanic_shocks_body, display_mechanic_page);
        inline scls::GUI_Text* mechanic_dynamic_page() const {return a_physic_mechanic_dynamic_body.get();};
        inline scls::GUI_Text* mechanic_kinematic_page() const {return a_physic_mechanic_kinematic_body.get();};

   private:

        // Current state of the page
        struct {
            // Matter
            // Current bohr model
            Bohr_Model matter_bohr_model;
            // Electrons in the Bohr model simulation
            std::vector<std::shared_ptr<Bohr_Model::Electron>> matter_bohr_model_simulation_electrons;
            // Photons in the Bohr model simulation
            std::vector<std::shared_ptr<Bohr_Model::Photon>> matter_bohr_model_simulation_photons;
            int matter_bohr_model_simulation_photons_number = 0;

            // Current page
            unsigned short current_page = PLEOS_MATHS_HOME_PAGE;
        } a_current_state;

        //******************
        // GUI handling
        //******************

        // Matter
        std::shared_ptr<scls::GUI_Text> a_physic_matter_bohr_model_body;
        std::shared_ptr<scls::GUI_Object> a_physic_matter_bohr_model_simulation_body;
        std::shared_ptr<scls::GUI_Text> a_physic_matter_bosons_body;
        std::shared_ptr<Graphic_Object> a_physic_matter_bohr_model_simulation;
        std::shared_ptr<scls::GUI_Text> a_physic_matter_scale_body;

        // Mechanic
        std::shared_ptr<scls::GUI_Text> a_physic_mechanic_dynamic_body;
        std::shared_ptr<scls::GUI_Text> a_physic_mechanic_kinematic_body;

        // Pages
        std::shared_ptr<scls::GUI_Object> a_physic_matter_page;
        std::shared_ptr<scls::GUI_Object> a_physic_mechanic_page;

        // Navigation
        std::shared_ptr<scls::GUI_Text> a_hub_button;
        std::shared_ptr<scls::GUI_Scroller_Choice> a_navigation;
    };
}

#endif // PLEOS_PHYSIC_PAGE
