//******************
//
// pleos_it.h
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
// The "IT" part aims IT lessons.
// Its goal is to teach everyone about IT, easily, and with cool informations and animations.
//
// This file contains the source code of "pleos_it.h".
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
#include "../headers/pleos_it.h"

// The namespace "pleos" is used to simplify the all.
namespace pleos {
    // Loads an object in a page from XML
    std::shared_ptr<scls::GUI_Object> IT_Page::__create_loaded_object_from_type(std::string object_name, std::string object_type, scls::GUI_Object* parent) {
        // Trees simulation
        if(object_name == "it_data_structures_tree_simulation"){a_data_structures_tree_simulation = *parent->new_object<scls::GUI_Object>(object_name);return a_data_structures_tree_simulation;}

        // Pages
        else if(object_name == "it_algorithms_page") {a_algorithms_page = *parent->new_object<scls::GUI_Object>(object_name);return a_algorithms_page;}
        else if(object_name == "it_algorithms_sort_body") {a_algorithms_sort_page = *parent->new_object<scls::GUI_Text_Base<Text>>(object_name);return a_algorithms_sort_page;}
        else if(object_name == "it_data_structures_page") {a_data_structures_page = *parent->new_object<scls::GUI_Object>(object_name);return a_data_structures_page;}
        else if(object_name == "it_data_structures_tree_body"){a_data_structures_tree_page = *parent->new_object<scls::GUI_Text_Base<Text>>(object_name);return a_data_structures_tree_page;}
        else if(object_name == "it_data_structures_tree_simulation_body"){a_data_structures_tree_simulation_page = *parent->new_object<scls::GUI_Text>(object_name);return a_data_structures_tree_simulation_page;}

        // Algorithms
        GUI_OBJECT_CREATION(scls::GUI_Object, a_algorithms_sort_comparaison_page, "it_algorithms_sort_comparaison_body")
        GUI_OBJECT_CREATION(scls::GUI_Scroller_Choice, a_algorithms_sort_comparaison_elements, "it_algorithms_sort_comparaison_elements")
        GUI_OBJECT_CREATION(scls::GUI_Object, a_algorithms_sort_comparaison_elements_datas, "it_algorithms_sort_comparaison_elements_datas")
        GUI_OBJECT_CREATION(scls::GUI_Text, a_algorithms_sort_comparaison_elements_datas_title, "it_algorithms_sort_comparaison_elements_datas_title")
        GUI_OBJECT_CREATION(scls::GUI_Object, a_algorithms_sort_comparaison_simulation, "it_algorithms_sort_comparaison_simulation")

        // Navigation
        else if(object_name == "it_hub"){a_hub_button = *parent->new_object<scls::GUI_Text>(object_name);return a_hub_button;}
        else if(object_name == "it_navigation") {a_navigation = *parent->new_object<scls::GUI_Scroller_Choice>(object_name);return a_navigation;}

        return scls::GUI_Page::__create_loaded_object_from_type(object_name, object_type, parent);
    }

    //******************
    //
    // Algorithms handling
    //
    //******************

    // Adds an element to create
    int __algorithms_object_created = 0;
    void IT_Page::algorithms_add_element_created(std::string current_choice) {
        // Direct elements
        if(current_choice == "visual_representation"){
            display_algorithms_sort_comparaison_simulation();algorithms_comparaison_start();
            algorithms_sort_comparaison_elements_datas_title()->set_text("Représentation visuelle");

            // Add the sort type needed
            std::shared_ptr<scls::GUI_Scroller_Choice>& sort_type = a_current_state.algorithms_sort_comparaison_type;
            sort_type = *algorithms_sort_comparaison_elements_datas()->new_object<scls::GUI_Scroller_Choice>(algorithms_sort_comparaison_elements_datas()->name() + "-first_input_" + std::to_string(__algorithms_object_created));
            sort_type.get()->set_border_width_in_pixel(1);
            sort_type.get()->set_height_in_scale(scls::Fraction(5, 6));
            sort_type.get()->set_width_in_scale(scls::Fraction(1, 5));
            sort_type.get()->attach_left_in_parent();
            sort_type.get()->attach_bottom_in_parent();
            // Add the needed sort
            sort_type.get()->add_object("bubble", "Tri bulle");
            sort_type.get()->add_object("fusion", "Tri fusion");
            sort_type.get()->add_object("insertion", "Tri par insertion");
            sort_type.get()->add_object("selection", "Tri par sélection");
            sort_type.get()->select_object("selection");
            algorithms_created_object_for_selected_object().push_back(sort_type);

            // Number of comparaisons
            std::shared_ptr<scls::GUI_Text>& comparaison_number = a_current_state.algorithms_sort_comparaison_number_display;
            comparaison_number = *algorithms_sort_comparaison_elements_datas()->new_object<scls::GUI_Text>(algorithms_sort_comparaison_elements_datas()->name() + "-first_displayer_" + std::to_string(__algorithms_object_created));
            comparaison_number.get()->set_height_in_scale(scls::Fraction(5, 6));
            comparaison_number.get()->set_width_in_scale(scls::Fraction(1, 2));
            comparaison_number.get()->set_x_in_object_scale(scls::Fraction(1, 2));
            comparaison_number.get()->set_y_in_object_scale(scls::Fraction(2, 3));
            comparaison_number.get()->set_text(std::string("Nombre de comparaisons : 0"));

            // Numbers of permutations
            std::shared_ptr<scls::GUI_Text>& permutation_number = a_current_state.algorithms_sort_comparaison_permutation_number_display;
            permutation_number = *algorithms_sort_comparaison_elements_datas()->new_object<scls::GUI_Text>(algorithms_sort_comparaison_elements_datas()->name() + "-second_displayer_" + std::to_string(__algorithms_object_created));
            permutation_number.get()->set_height_in_scale(scls::Fraction(5, 6));
            permutation_number.get()->set_width_in_scale(scls::Fraction(1, 2));
            permutation_number.get()->set_x_in_object_scale(scls::Fraction(1, 2));
            permutation_number.get()->set_y_in_object_scale(scls::Fraction(1, 3));
            permutation_number.get()->set_text(std::string("Nombre de permutations : 0"));

            return;
        }
    }

    // Do a comparaison part of the algorithm with the bubble algorithm
    void IT_Page::algorithms_comparaison_bubble() {
        if(a_current_state.algorithms_sort_comparaison_index < algorithms_sort_comparaison_values().size()) {
            int min_index = a_current_state.algorithms_sort_comparaison_index;
            int i = algorithms_sort_comparaison_values().size() - 2;
            while(i >= min_index) {
                if(algorithms_sort_comparaison_values()[i] > algorithms_sort_comparaison_values()[i + 1]) {
                    double temp = algorithms_sort_comparaison_values()[i];
                    algorithms_sort_comparaison_values()[i] = algorithms_sort_comparaison_values()[i + 1];
                    algorithms_sort_comparaison_values()[i + 1] = temp;
                    a_current_state.algorithms_sort_comparaison_current.get()->a_algorithms_sort_comparaison_permutation_number++;
                }
                i--;
                a_current_state.algorithms_sort_comparaison_current.get()->a_algorithms_sort_comparaison_number++;
            }

            a_current_state.algorithms_sort_comparaison_moved_index_max = min_index;
            a_current_state.algorithms_sort_comparaison_moved_index_min = i;
            a_current_state.algorithms_sort_comparaison_index++;
        }
    }

    // Do a comparaison part of the algorithm with the insertion algorithm
    void IT_Page::algorithms_comparaison_insertion() {
        if(a_current_state.algorithms_sort_comparaison_index < algorithms_sort_comparaison_values().size()) {
            int current_index = a_current_state.algorithms_sort_comparaison_index;
            int i = 0;
            while(i < a_current_state.algorithms_sort_comparaison_index) {
                a_current_state.algorithms_sort_comparaison_current.get()->a_algorithms_sort_comparaison_number++;
                if(algorithms_sort_comparaison_values()[i] > algorithms_sort_comparaison_values()[current_index]) {break;}
                i++;
            }

            // Permute the next variables
            int needed_index = i;
            while(i < a_current_state.algorithms_sort_comparaison_index) {
                double temp = algorithms_sort_comparaison_values()[current_index];
                algorithms_sort_comparaison_values()[current_index] = algorithms_sort_comparaison_values()[i];
                algorithms_sort_comparaison_values()[i] = temp;
                i++;
                a_current_state.algorithms_sort_comparaison_current.get()->a_algorithms_sort_comparaison_permutation_number++;
            }

            a_current_state.algorithms_sort_comparaison_moved_index_max = needed_index;
            a_current_state.algorithms_sort_comparaison_moved_index_min = current_index;
            a_current_state.algorithms_sort_comparaison_index++;
        }
    }

    // Do a comparaison part of the algorithm with the fusion algorithm
    void IT_Page::__algorithms_comparaison_fusion_division(Sort_Datas* datas) {
        // Division
        if(datas->values_end == datas->values_start || datas->values_start + 1 == datas->values_end){return;}
        std::vector<double>::iterator middle = datas->values_start + (datas->values_end - datas->values_start) / 2;
        std::shared_ptr<Sort_Datas> sort_1 = std::make_shared<Sort_Datas>();
        sort_1.get()->values_start = datas->values_start;
        sort_1.get()->values_end = middle;
        datas->sub_sorts.push_back(sort_1);
        __algorithms_comparaison_fusion_division(sort_1.get());
        std::shared_ptr<Sort_Datas> sort_2 = std::make_shared<Sort_Datas>();
        sort_2.get()->values_start = middle;
        sort_2.get()->values_end = datas->values_end;
        datas->sub_sorts.push_back(sort_2);
        __algorithms_comparaison_fusion_division(sort_2.get());
    }
    void IT_Page::__algorithms_comparaison_fusion(Sort_Datas* datas) {
        // Sub sorts
        if(datas->sub_sorts.size() < 2){return;}

        // Fusion
        std::vector<double> buf_1 = datas->sub_sorts[0].get()->buffer(); int i_1 = 0;
        std::vector<double> buf_2 = datas->sub_sorts[1].get()->buffer(); int i_2 = 0;
        std::vector<double>::iterator current = datas->values_start;
        while(i_1 < buf_1.size() && i_2 < buf_2.size()) {
            if(buf_1[i_1] < buf_2[i_2]){(*current) = buf_1[i_1];i_1++;}
            else{(*current) = buf_2[i_2];i_2++;}
            current++;
            datas->a_algorithms_sort_comparaison_permutation_number++;
        }
        while(i_1 < buf_1.size()) {
            (*current) = buf_1[i_1];i_1++;
            current++;
            datas->a_algorithms_sort_comparaison_permutation_number++;
        }
        while(i_2 < buf_2.size()) {
            (*current) = buf_2[i_2];i_2++;
            current++;
            datas->a_algorithms_sort_comparaison_permutation_number++;
        }

        // End the algorithm
        datas->sub_sorts.clear();
        datas->good = true;
    }
    bool IT_Page::algorithms_comparaison_fusion(Sort_Datas* datas) {
        if(datas->sub_sorts.size() > datas->current_sub_sort) {
            if(algorithms_comparaison_fusion(datas->sub_sorts[datas->current_sub_sort].get())){
                datas->current_sub_sort++;
            }
        }
        else {__algorithms_comparaison_fusion(datas);return true;}
        return false;
    }

    // Do a comparaison part of the algorithm with the selection algorithm
    void IT_Page::algorithms_comparaison_selection() {
        if(a_current_state.algorithms_sort_comparaison_index < algorithms_sort_comparaison_values().size()) {
            int min_index = a_current_state.algorithms_sort_comparaison_index;
            int i = a_current_state.algorithms_sort_comparaison_index + 1;
            while(i < algorithms_sort_comparaison_values().size()) {
                if(algorithms_sort_comparaison_values()[i] < algorithms_sort_comparaison_values()[min_index]) {
                    min_index = i;
                }
                i++;
                a_current_state.algorithms_sort_comparaison_current.get()->a_algorithms_sort_comparaison_number++;
            }
            double temp = algorithms_sort_comparaison_values()[a_current_state.algorithms_sort_comparaison_index];
            algorithms_sort_comparaison_values()[a_current_state.algorithms_sort_comparaison_index] = algorithms_sort_comparaison_values()[min_index];
            algorithms_sort_comparaison_values()[min_index] = temp;
            a_current_state.algorithms_sort_comparaison_current.get()->a_algorithms_sort_comparaison_permutation_number++;

            a_current_state.algorithms_sort_comparaison_moved_index_max = min_index;
            a_current_state.algorithms_sort_comparaison_moved_index_min = a_current_state.algorithms_sort_comparaison_index;
            a_current_state.algorithms_sort_comparaison_index++;
        }
    }

    // Starts the comparaison part of the algorithm
    void IT_Page::algorithms_comparaison_start() {
        // Values in the algorithm
        int value_number = 200;
        std::vector<double>& values = algorithms_sort_comparaison_values();
        values = std::vector<double>(value_number, 0);
        for(int i = 0;i<value_number;i++){values[i] = i + 1;}

        // Shuffle the list
        std::random_shuffle(values.begin(), values.end());

        // Update the graphic
        a_current_state.algorithms_sort_comparaison_index = 0;
        a_current_state.algorithms_sort_comparaison_moved_index_max = -1;
        a_current_state.algorithms_sort_comparaison_moved_index_min = -1;
        a_current_state.algorithms_sort_comparaison_current = std::make_shared<Sort_Datas>();
        a_current_state.algorithms_sort_comparaison_current.get()->a_algorithms_sort_comparaison_number = 0;
        a_current_state.algorithms_sort_comparaison_current.get()->a_algorithms_sort_comparaison_permutation_number = 0;
        a_current_state.algorithms_sort_comparaison_current.get()->sub_sorts.clear();
        a_current_state.algorithms_sort_comparaison_current.get()->values_start = values.begin();
        a_current_state.algorithms_sort_comparaison_current.get()->values_end = values.end();
        algorithms_update_comparaison();
    }

    // Update the texture of the algorithm comparaison simulation part
    void IT_Page::algorithms_update_comparaison(){
        // Create the image
        scls::Color background_color = scls::Color(255, 255, 255);
        int needed_width = algorithms_sort_comparaison_simulation()->height_in_pixel();
        std::shared_ptr<scls::Image> image = std::make_shared<scls::Image>(needed_width, needed_width, background_color);

        // Draw the values
        int current_x = 0;
        double maximum_height = image.get()->height();
        std::vector<double>& values = algorithms_sort_comparaison_values();
        double value_number = values.size();
        for(int i = 0;i<static_cast<int>(values.size());i++) {
            scls::Color current_color = scls::Color(255, 0, 0);
            int needed_height = round((values[i] / value_number) * maximum_height);
            int part_width = static_cast<double>(image.get()->width()) / value_number;

            // Set the color
            if(i == a_current_state.algorithms_sort_comparaison_moved_index_max){current_color = scls::Color(255, 128, 0);}
            else if(i == a_current_state.algorithms_sort_comparaison_moved_index_min){current_color = scls::Color(204, 204, 0);}

            // Draw the line
            image.get()->fill_rect(current_x, image.get()->height() - needed_height, part_width, needed_height, current_color);
            current_x += part_width;
        }

        algorithms_sort_comparaison_simulation()->texture()->set_image(image);
        set_should_render_during_this_frame(true);

        // Set the text
        if(a_current_state.algorithms_sort_comparaison_number_display.get() != 0) {
            a_current_state.algorithms_sort_comparaison_number_display.get()->set_text(std::string("Nombre de comparaisons : ") + std::to_string(algorithms_sort_comparaison_number()));
        }
        if(a_current_state.algorithms_sort_comparaison_permutation_number_display.get() != 0) {
            a_current_state.algorithms_sort_comparaison_permutation_number_display.get()->set_text(std::string("Nombre de permutations : ") + std::to_string(algorithms_sort_comparaison_permutation_number()));
        }
    }

    //******************
    //
    // Check events
    //
    //******************

    // Checks the events of algorithms
    void IT_Page::check_algorithms() {
        // Adds a created element
        if(algorithms_sort_comparaison_elements()->selection_modified()) {
            std::string current_choice = algorithms_sort_comparaison_elements()->currently_selected_objects_during_this_frame()[0].name();
            algorithms_sort_comparaison_elements()->unselect_object(algorithms_sort_comparaison_elements()->currently_selected_objects()[0]);
            algorithms_add_element_created(current_choice);
        }

        // Handle a new type of sort for visual representation
        if(a_current_state.algorithms_sort_comparaison_type.get() != 0 && a_current_state.algorithms_sort_comparaison_type.get()->selection_modified()) {
            algorithms_comparaison_start();
        }

        if(current_page() == PLEOS_IT_ALGORITHMS_SORT_COMPARAISON_SIMULATION_PAGE) {
           // Restart the comparaison
            if(window_struct()->key_pressed_during_this_frame("z")){algorithms_comparaison_start();}

            // Animate the comparaison
            if(window_struct()->key_pressed("a")) {
                if(a_current_state.algorithms_sort_comparaison_type.get() != 0) {
                    if(a_current_state.algorithms_sort_comparaison_type.get()->contains_selected_object("bubble")) {algorithms_comparaison_bubble();}
                    else if(a_current_state.algorithms_sort_comparaison_type.get()->contains_selected_object("insertion")) {algorithms_comparaison_insertion();}
                    else if(a_current_state.algorithms_sort_comparaison_type.get()->contains_selected_object("fusion")) {
                        if(!a_current_state.algorithms_sort_comparaison_current.get()->good && a_current_state.algorithms_sort_comparaison_current.get()->sub_sorts.size() <= 0){
                            __algorithms_comparaison_fusion_division();
                        }
                        algorithms_comparaison_fusion();
                    }
                    else{algorithms_comparaison_selection();}
                }
                else{algorithms_comparaison_selection();}
                algorithms_update_comparaison();
            }
        }
    }

    // Check the events of navigation
    void IT_Page::check_navigation() {
        // Check the selected page
        if(a_navigation.get()->selection_modified()){
            std::string page = a_navigation.get()->currently_selected_objects_during_this_frame()[0].name();

            // IT pages
            if(page == "algorithms"){display_algorithms_page();}
            else if(page == "algorithms_sort"){display_algorithms_sort_page();}
            GUI_OBJECT_SELECTION(display_algorithms_sort_comparaison_page(), "algorithms_sort_comparaison")
            else if(page == "data_structures_trees"){display_data_structures_trees_page();}
            else if(page == "data_structures_trees_graphic"){
                display_data_structures_trees_simulation_page();

                std::string content = "<tree graph=\"animals\" name=\"Animal\"><tree name=\"Félins\"><tree name=\"Chats\"></tree><tree name=\"Léopards\"></tree><tree name=\"Panthères\"></tree></tree><tree name=\"Canidés\"><tree name=\"Loups\"></tree><tree name=\"Chiens\"></tree><tree name=\"Coyotes\"></tree></tree></tree>";
                scls::Text_Style style;style.set_border_width(1);
                std::shared_ptr<Tree<std::string>> tree = tree_from_xml(content, style, window_struct()->balises_shared_ptr());
                std::shared_ptr<scls::Image> needed_image = tree.get()->to_image() ;
                needed_image.get()->save_png("tests/arbre.png");
                data_structures_tree_simulation()->texture()->set_image(needed_image);
            }
        }

        // Check the hub button
        if(hub_button()->is_clicked_during_this_frame(GLFW_MOUSE_BUTTON_LEFT)) {window_struct()->hide_all_pages_2d();window_struct()->display_page_2d("hub");}
    }

    // Update the events
    void IT_Page::update_event() {
        // Basic events
        scls::GUI_Page::update_event();
        check_navigation();

        if(current_page() == PLEOS_IT_ALGORITHMS_SORT_COMPARAISON_PAGE || current_page() == PLEOS_IT_ALGORITHMS_SORT_COMPARAISON_SIMULATION_PAGE){check_algorithms();}
    }
}
