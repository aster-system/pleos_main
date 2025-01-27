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

    // Loads the bohr model simulation
    double __matter_bohr_model_simulation_start = 0;
    void Physic_Page::matter_load_bohr_model_simulation() {
        // Add the core
        int protons = 8; int neutrons = 8; int total = protons + neutrons;
        for(int i = 0;i<total;i++) {
            int random = rand()%2;
            if((random == 0 && protons > 0) || neutrons <= 0) {
                std::string needed_name = std::string("proton_") + std::to_string(protons);
                scls::Formula x = scls::Fraction(rand()%3, 5);
                scls::Formula y = scls::Fraction(rand()%3, 5);
                std::shared_ptr<Circle> current_particule = *matter_bohr_model_simulation()->add_circle(needed_name, Vector(needed_name, x, y), scls::Fraction(1, 4));
                current_particule.get()->set_border_color(scls::Color(150, 0, 0));current_particule.get()->set_border_radius(3);
                current_particule.get()->set_color(scls::Color(255, 0, 0));
                protons--;
            }
            else {
                std::string needed_name = std::string("neutron_") + std::to_string(neutrons);
                scls::Formula x = scls::Fraction(rand()%3, 5);
                scls::Formula y = scls::Fraction(rand()%3, 5);
                std::shared_ptr<Circle> current_particule = *matter_bohr_model_simulation()->add_circle(needed_name, Vector(needed_name, x, y), scls::Fraction(1, 4));
                current_particule.get()->set_border_color(scls::Color(0, 150, 0));current_particule.get()->set_border_radius(3);
                current_particule.get()->set_color(scls::Color(0, 255, 0));
                neutrons--;
            }
        }

        // Add the electrons
        int electrons = 8;
        for(int i = 0;i<static_cast<int>(electrons);i++) {
            std::string needed_name = std::string("electron_") + std::to_string(protons);
            scls::Formula x = scls::Fraction(-i, 3) - scls::Fraction(3, 4);
            scls::Formula y = 0;
            std::shared_ptr<Circle> current_particule = *matter_bohr_model_simulation()->add_circle(needed_name, Vector(needed_name, x, y), scls::Fraction(1, 7));
            current_particule.get()->set_border_color(scls::Color(0, 0, 150));current_particule.get()->set_border_radius(2);
            current_particule.get()->set_color(scls::Color(0, 0, 255));
            matter_bohr_model_simulation_electrons().push_back(current_particule);
        }

        // Update the texture
        __matter_bohr_model_simulation_start = scls::time_ns() / std::pow(10, 9);
        matter_bohr_model_simulation()->update_texture();
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

    // Updates the page
    void Physic_Page::update() {
        scls::GUI_Page::update();

        if(current_page() == PLEOS_PHYSIC_MATTER_BOHR_MODEL_SIMULATION_PAGE) {
            // Simulate the Bohr model
            for(int i = 0;i<static_cast<int>(matter_bohr_model_simulation_electrons().size());i++) {
                std::shared_ptr<Circle> current_particule = matter_bohr_model_simulation_electrons()[i];
                double* rotated = scls::__rotate_vector_3d(-0.75 - static_cast<double>(i) / 3.0, 0, 0, 0, (__matter_bohr_model_simulation_start - window_struct()->execution_time()) * 180.0, 0);
                Vector needed_vector = Vector(std::string(""), rotated[0] * 100.0, rotated[2] * 100.0); delete rotated;
                needed_vector.set_x(*needed_vector.x() / scls::Fraction(100));
                needed_vector.set_y(*needed_vector.y() / scls::Fraction(100));
                current_particule.get()->set_center(needed_vector);
            }
            matter_bohr_model_simulation()->update_texture();
        }
    }

    // Update the events
    void Physic_Page::update_event() {
        // Basic events
        scls::GUI_Page::update_event();
        check_navigation();
    }
}
