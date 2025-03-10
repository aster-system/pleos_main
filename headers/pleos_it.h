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
// This file contains the page of the IT plugin.
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

#ifndef PLEOS_IT_PAGE
#define PLEOS_IT_PAGE

// Include PLEOS Libs
#include "../../pleos_libs/pleos_it.h"
#include "../../pleos_libs/pleos_mathematics.h"
#include "../../pleos_libs/pleos_text.h"

// Possible pages
#define PLEOS_IT_HOME_PAGE 0
// Data structures
#define PLEOS_IT_DATA_STRUCTURES_TREES_PAGE 150
#define PLEOS_IT_DATA_STRUCTURES_TREES_SIMULATION_PAGE 151
// DAlgorithms
#define PLEOS_IT_ALGORITHMS_SORT_PAGE 210
#define PLEOS_IT_ALGORITHMS_SORT_COMPARAISON_PAGE 215
#define PLEOS_IT_ALGORITHMS_SORT_COMPARAISON_SIMULATION_PAGE 216

// The namespace "pleos" is used to simplify the all.
namespace pleos {
    class IT_Page : public scls::GUI_Page {
        // Class representating the "IT" page for PLEOS
    public:

        // IT_Page constructor
        IT_Page(scls::_Window_Advanced_Struct* window_struct, std::string name):scls::GUI_Page(window_struct, name){};
        // Loads an object in a page from XML
        virtual std::shared_ptr<scls::GUI_Object> __create_loaded_object_from_type(std::string object_name, std::string object_type, scls::GUI_Object* parent);

        //******************
        //
        // Algorithms handling
        //
        //******************

        // Adds an element to create
        void algorithms_add_element_created(std::string current_choice);
        // Do a comparaison part of the algorithm with the needed algorithm
        void algorithms_comparaison_bubble();
        void algorithms_comparaison_insertion();
        void algorithms_comparaison_selection();
        // Starts the comparaison part of the algorithm
        void algorithms_comparaison_start();
        // Updates the texture of the comparaison part of the algorithm
        void algorithms_update_comparaison();

        // Checks the events of algorithms
        void check_algorithms();
        // Checks the events of navigation
        void check_navigation();
        // Updates the events
        virtual void update_event();

        //******************
        //
        // Handle the pages
        //
        //******************

        //Displays the algorithms page
        void display_algorithms_page(){hide_all();algorithms_page()->set_visible(true);};
        void display_algorithms_sort_page(){display_algorithms_page();algorithms_sort_page()->set_visible(true);};
        GUI_OBJECT(scls::GUI_Scroller_Choice, a_algorithms_sort_comparaison_elements, algorithms_sort_comparaison_elements);
        GUI_OBJECT(scls::GUI_Object, a_algorithms_sort_comparaison_elements_datas, algorithms_sort_comparaison_elements_datas);
        GUI_OBJECT(scls::GUI_Text, a_algorithms_sort_comparaison_elements_datas_title, algorithms_sort_comparaison_elements_datas_title);
        GUI_PAGE(scls::GUI_Object, a_algorithms_sort_comparaison_page, PLEOS_IT_ALGORITHMS_SORT_COMPARAISON_PAGE, algorithms_sort_comparaison_page, display_algorithms_sort_comparaison_page, display_algorithms_page);
        GUI_PAGE(scls::GUI_Object, a_algorithms_sort_comparaison_simulation, PLEOS_IT_ALGORITHMS_SORT_COMPARAISON_SIMULATION_PAGE, algorithms_sort_comparaison_simulation, display_algorithms_sort_comparaison_simulation, display_algorithms_sort_comparaison_page);

        // Displays the data structure page
        void display_data_structures_page(){hide_all();data_structures_page()->set_visible(true);};
        void display_data_structures_trees_page(){set_current_page(PLEOS_IT_DATA_STRUCTURES_TREES_PAGE);display_data_structures_page();data_structures_tree_page()->set_visible(true);};
        void display_data_structures_trees_simulation_page(){set_current_page(PLEOS_IT_DATA_STRUCTURES_TREES_SIMULATION_PAGE);display_data_structures_page();data_structures_tree_simulation_page()->set_visible(true);};

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

        // Algorithms
        inline std::vector<std::shared_ptr<scls::GUI_Object>>& algorithms_created_object_for_selected_object(){return a_current_state.a_algorithms_created_object_for_selected_object;};
        inline std::vector<double>& algorithms_sort_comparaison_values(){return a_current_state.algorithms_sort_comparaison_values;};

        // Returns navigation
        inline scls::GUI_Text* hub_button() const {return a_hub_button.get();};

        // Returns pages
        inline scls::GUI_Object* algorithms_page() const {return a_algorithms_page.get();};
        inline scls::GUI_Text_Base<Text>* algorithms_sort_page() const {return a_algorithms_sort_page.get();};
        inline scls::GUI_Object* data_structures_page() const {return a_data_structures_page.get();};
        inline scls::GUI_Object* data_structures_tree_page() const {return a_data_structures_tree_page.get();};
        inline scls::GUI_Object* data_structures_tree_simulation_page() const {return a_data_structures_tree_simulation_page.get();};

        // Trees simulation
        inline scls::GUI_Object* data_structures_tree_simulation() const {return a_data_structures_tree_simulation.get();};

    private:
        // Current state of the page
        struct {
            // Algorithms
            // Created object for the arithmetic selected object
            std::vector<std::shared_ptr<scls::GUI_Object>> a_algorithms_created_object_for_selected_object = std::vector<std::shared_ptr<scls::GUI_Object>>();
            // Current index of the algorithm
            int algorithms_sort_comparaison_index = 0;
            // Moved index of the comparaison
            int algorithms_sort_comparaison_moved_index_max = -1;
            int algorithms_sort_comparaison_moved_index_min = -1;
            // Scroller containing the needed comparaison type
            std::shared_ptr<scls::GUI_Scroller_Choice> algorithms_sort_comparaison_type;
            // Sort comparaison
            std::vector<double> algorithms_sort_comparaison_values = std::vector<double>();

            // Current page
            unsigned short current_page = PLEOS_IT_HOME_PAGE;
        } a_current_state;

        // Global navigation
        std::shared_ptr<scls::GUI_Text> a_hub_button;
        std::shared_ptr<scls::GUI_Scroller_Choice> a_navigation;

        // Pages
        std::shared_ptr<scls::GUI_Object> a_algorithms_page;
        std::shared_ptr<scls::GUI_Text_Base<Text>> a_algorithms_sort_page;
        std::shared_ptr<scls::GUI_Object> a_data_structures_page;
        std::shared_ptr<scls::GUI_Object> a_data_structures_tree_page;
        std::shared_ptr<scls::GUI_Object> a_data_structures_tree_simulation_page;

        // Tree simulation
        std::shared_ptr<scls::GUI_Object> a_data_structures_tree_simulation;
    };
}

#endif // PLEOS_IT_PAGE
