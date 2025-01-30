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
        if(object_name == "physic_matter_bohr_model_body"){a_physic_matter_bohr_model_body = *parent->new_object<scls::GUI_Text>(object_name);return a_physic_matter_bohr_model_body;}
        else if(object_name == "physic_matter_bohr_model_simulation") {a_physic_matter_bohr_model_simulation = *parent->new_object<Graphic>(object_name);return a_physic_matter_bohr_model_simulation;}
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
        // Loads the datas
        int protons = 17; int neutrons = 18;
        int electrons = 17;

        // Add the core
        int total = protons + neutrons;
        for(int i = 0;i<total;i++) {
            // Get the datas about the particule
            scls::Formula x = scls::Fraction(rand()%3, 5) - scls::Fraction(3, 10);
            scls::Formula y = scls::Fraction(rand()%3, 5) - scls::Fraction(3, 10);

            // Draw a proton or neutron
            int random = rand()%2;
            if((random == 0 && protons > 0) || neutrons <= 0) {
                std::string needed_name = std::string("proton_") + std::to_string(protons);
                std::shared_ptr<Circle> current_particule = *matter_bohr_model_simulation()->add_circle(needed_name, Vector(needed_name, x, y), scls::Fraction(1, 4));
                current_particule.get()->set_border_color(scls::Color(150, 0, 0));current_particule.get()->set_border_radius(3);
                current_particule.get()->set_color(scls::Color(255, 0, 0));
                protons--;
            }
            else {
                std::string needed_name = std::string("neutron_") + std::to_string(neutrons);
                std::shared_ptr<Circle> current_particule = *matter_bohr_model_simulation()->add_circle(needed_name, Vector(needed_name, x, y), scls::Fraction(1, 4));
                current_particule.get()->set_border_color(scls::Color(0, 150, 0));current_particule.get()->set_border_radius(3);
                current_particule.get()->set_color(scls::Color(0, 255, 0));
                neutrons--;
            }
        }

        // Add the electrons
        matter_bohr_model() = Bohr_Model(electrons);
        for(int i = 0;i<static_cast<int>(electrons);i++) {
            std::string needed_name = std::string("electron_") + std::to_string(protons);
            std::shared_ptr<Bohr_Model::Electron> current_electron = matter_bohr_model().electron_datas(i);
            scls::Formula x = current_electron.get()->distance * -1 - scls::Fraction(3, 4);
            // Create the particule
            std::shared_ptr<Circle>& current_particule = current_electron.get()->circle;
            current_particule = *matter_bohr_model_simulation()->add_circle(needed_name, Vector(needed_name, x, 0), scls::Fraction(1, 7));
            current_particule.get()->set_border_color(scls::Color(0, 0, 150));current_particule.get()->set_border_radius(2);
            current_particule.get()->set_color(scls::Color(0, 0, 255));
            // Add the electron
            matter_bohr_model_simulation_electrons().push_back(current_electron);
        }

        // Update the texture
        __matter_bohr_model_simulation_start = scls::time_ns() / std::pow(10, 9);
        matter_bohr_model_simulation()->set_draw_base(false);matter_bohr_model_simulation()->set_draw_sub_bases(false);
        matter_bohr_model_simulation()->update_texture();
    }

    // Check the events of navigation
    void Physic_Page::check_navigation() {
        // Check the selected page
        if(a_navigation.get()->selection_modified()){
            std::string page = a_navigation.get()->currently_selected_objects_during_this_frame()[0].name();

            // Arithmetic pages
            if(page == "matter_bohr_model"){display_matter_bohr_model_page();}
            else if(page == "matter_bohr_model_simulation"){display_matter_bohr_model_simulation_page();}
            else if(page == "matter_scale"){display_matter_scale_page();}
        }
    }

    // Updates the page
    void Physic_Page::update() {
        scls::GUI_Page::update();

        if(current_page() == PLEOS_PHYSIC_MATTER_BOHR_MODEL_SIMULATION_PAGE) {update_bohr_model_simulation();}
    }

    // Updates the Bohr model simulation
    void Physic_Page::update_bohr_model_simulation() {
        // Simulate the Bohr model
        // Simulate the electrons
        for(int i = 0;i<static_cast<int>(matter_bohr_model_simulation_electrons().size());i++) {
            std::shared_ptr<Bohr_Model::Electron> current_electron = matter_bohr_model_simulation_electrons()[i];
            std::shared_ptr<Circle> current_particule = current_electron.get()->circle;
            scls::Fraction needed_distance = current_electron.get()->distance + (scls::Fraction(1, 2) * current_electron.get()->energy);
            double* rotated = scls::__rotate_vector_3d(-0.75 - needed_distance.to_double(), 0, 0, 0, current_electron.get()->angle.to_double() + (__matter_bohr_model_simulation_start - window_struct()->execution_time()) * 180.0, 0);
            Vector needed_vector = Vector(std::string(""), rotated[0] * 100.0, rotated[2] * 100.0); delete rotated;
            needed_vector.set_x(*needed_vector.x() / scls::Fraction(100));
            needed_vector.set_y(*needed_vector.y() / scls::Fraction(100));
            current_particule.get()->set_center(needed_vector);
        }
        // Simulate the photons
        for(int i = 0;i<static_cast<int>(matter_bohr_model_simulation_photons().size());i++) {
            std::shared_ptr<Bohr_Model::Photon> current_photon = matter_bohr_model_simulation_photons()[i];
            std::shared_ptr<Circle> current_particule = current_photon.get()->circle;
            scls::Fraction duration = scls::Fraction(static_cast<double>(scls::time_ns() - current_photon.get()->creation_time) / std::pow(10, 6), 1000);
            if(duration < 1) {
                // Move the photon
                Vector new_position = (current_photon.get()->end_position - current_photon.get()->start_position);
                new_position *= duration;
                current_particule.get()->set_center(current_photon.get()->start_position + new_position);
            }
            else if(current_photon.get()->electron.get() != 0) {
                // Delete the photon
                scls::Fraction peak_energy = scls::Fraction(2);
                matter_bohr_model_simulation()->remove_circle(current_particule.get()->name());
                if(duration < 1.5) {
                    current_photon.get()->electron.get()->energy = peak_energy * (duration - scls::Fraction(1));
                }
                else if(duration < 2) {
                    // Emits the photon
                    current_photon.get()->electron.get()->energy = peak_energy - peak_energy * (duration - scls::Fraction(1));
                    if(current_photon.get()->electron.get()->has_photon) {
                        current_photon.get()->electron.get()->has_photon = false;
                        // Create the particule
                        std::shared_ptr<Bohr_Model::Photon> new_photon = matter_bohr_model().photon_datas(0);
                        new_photon.get()->creation_time = scls::time_ns();
                        new_photon.get()->start_position = current_photon.get()->electron.get()->center();
                        double needed_angle = current_photon.get()->electron.get()->angle.to_double() + (__matter_bohr_model_simulation_start - window_struct()->execution_time()) * 180.0;
                        double* rotated = scls::__rotate_vector_3d(5.0, 0, 0, 0, needed_angle + 180.0, 0);
                        new_photon.get()->end_position = new_photon.get()->start_position + Vector("", scls::Fraction(rotated[0] * 100, 100), scls::Fraction(rotated[2] * 200, 200));
                        matter_bohr_model_simulation_photons().push_back(new_photon); delete rotated;
                        // Create the particule
                        std::shared_ptr<Circle>& current_particule = new_photon.get()->circle;
                        current_particule = *matter_bohr_model_simulation()->add_circle(current_photon.get()->circle.get()->name() + std::string("_emitted"), new_photon.get()->start_position, scls::Fraction(1, 7));
                        current_particule.get()->set_border_color(scls::Color(150, 150, 0));current_particule.get()->set_border_radius(2);
                        current_particule.get()->set_color(scls::Color(255, 255, 0));
                    }
                }
                else {
                    // Delete the photon
                    current_photon.get()->electron.get()->energy = 0;
                    current_photon.get()->electron.get()->has_photon_attached = false;
                    matter_bohr_model_simulation_photons().erase(matter_bohr_model_simulation_photons().begin() + i);
                }
            }
            else {matter_bohr_model_simulation_photons().erase(matter_bohr_model_simulation_photons().begin() + i);}
        }

        // Introduce a photon
        if(window_struct()->key_pressed_during_this_frame("m") || window_struct()->key_pressed("l")) {
            // Choose an electron
            int n = rand()%matter_bohr_model().electron_number();
            std::shared_ptr<Bohr_Model::Electron> current_electron = matter_bohr_model_simulation_electrons()[n];
            if(!current_electron.get()->has_photon_attached){
                // Create the photon
                std::string needed_name = std::string("photon_") + std::to_string(matter_bohr_model_simulation_photons_number());
                matter_bohr_model_simulation_photons_number()++;
                std::shared_ptr<Bohr_Model::Photon> current_photon = matter_bohr_model().photon_datas(0);
                current_photon.get()->creation_time = scls::time_ns();
                scls::Formula x = -2; scls::Formula y = 0;

                // Get the final electron
                int movement_duration = 1;
                double needed_angle = current_electron.get()->angle.to_double() + ((__matter_bohr_model_simulation_start + movement_duration) - window_struct()->execution_time()) * 180.0;
                double* rotated = scls::__rotate_vector_3d(-0.75 - current_electron.get()->distance.to_double(), 0, 0, 0, needed_angle, 0);
                Vector target_vector = Vector(std::string(""), rotated[0] * 100.0, rotated[2] * 100.0); delete rotated;
                target_vector.set_x(*target_vector.x() / scls::Fraction(100));
                target_vector.set_y(*target_vector.y() / scls::Fraction(100));
                current_photon.get()->end_position = target_vector;
                current_photon.get()->electron = current_electron;
                current_electron->has_photon = true;
                current_electron->has_photon_attached = true;
                // Get the start position
                rotated = scls::__rotate_vector_3d(-4.0, 0, 0, 0, needed_angle, 0);
                Vector start_vector = Vector(std::string(""), rotated[0] * 100.0, rotated[2] * 100.0); delete rotated;
                start_vector.set_x(*start_vector.x() / scls::Fraction(100));
                start_vector.set_y(*start_vector.y() / scls::Fraction(100));
                start_vector += target_vector;
                current_photon.get()->start_position = start_vector;

                // Create the particule
                std::shared_ptr<Circle>& current_particule = current_photon.get()->circle;
                current_particule = *matter_bohr_model_simulation()->add_circle(needed_name, start_vector, scls::Fraction(1, 7));
                current_particule.get()->set_border_color(scls::Color(150, 150, 0));current_particule.get()->set_border_radius(2);
                current_particule.get()->set_color(scls::Color(255, 255, 0));
                // Add the photon
                matter_bohr_model_simulation_photons().push_back(current_photon);
            }
        }

        matter_bohr_model_simulation()->update_texture();
    }

    // Update the events
    void Physic_Page::update_event() {
        // Basic events
        scls::GUI_Page::update_event();
        check_navigation();
    }
}
