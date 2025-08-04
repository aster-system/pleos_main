//******************
//
// pleos_maths.cpp
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
// The "Maths" part aims mathematics lessons.
// Its goal is to provide a big amount of well structured informations, with animations and solving system.
//
// This file contains the source code of "pleos_maths.h".
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
#include "../headers/pleos_maths.h"

// The namespace "pleos" is used to simplify the all.
namespace pleos {

    // Log datas in a log file for PLEOS
    std::string pleos_log_content(){std::string needed_path = "tests/log.txt";return scls::read_file(needed_path);};
    void pleos_log(std::string content) {
        std::string needed_path = "tests/log.txt";
        std::string file_content = pleos_log_content();
        file_content += content + std::string("\n");
        scls::write_in_file(needed_path, file_content);
    }

    // Loads an object in a page from XML
    std::shared_ptr<scls::GUI_Object> Maths_Page::__create_loaded_object_from_type(std::string object_name, std::string object_type, scls::GUI_Object* parent) {
        // Algebra
        if(object_name == "maths_algebra_definitions_body") {a_algebra_definitions_page = *parent->new_object<scls::GUI_Text>(object_name);return a_algebra_definitions_page;}
        else if(object_name == "maths_algebra_matrices_body") {a_algebra_matrices_page = *parent->new_object<scls::GUI_Text>(object_name);return a_algebra_matrices_page;}
        GUI_OBJECT_CREATION(scls::GUI_Text_Base<Text>, a_algebra_equations_page, "maths_algebra_equations_body")
        GUI_OBJECT_CREATION(pleos::GUI_Text, a_algebra_series_page, "maths_algebra_series_body")
        GUI_OBJECT_CREATION(scls::GUI_Object, a_algebra_solver_page, "maths_algebra_solver_body")
        GUI_OBJECT_CREATION(scls::GUI_Text_Base<Text>, a_algebra_solver_redaction, "maths_algebra_solver_redaction")
        GUI_OBJECT_CREATION(scls::GUI_Text_Input, a_algebra_solver_redaction_input, "maths_algebra_solver_redaction_input")
        GUI_OBJECT_CREATION(scls::GUI_Text_Base<Text>, a_algebra_structures_page, "maths_algebra_structures_body")

        // Arithmetic
        else if(object_name == "maths_arithmetic_definitions_body") {a_arithmetic_definitions_page = *parent->new_object<scls::GUI_Text>(object_name);return a_arithmetic_definitions_page;}
        else if(object_name == "maths_arithmetic_calculator_body"){a_arithmetic_calculator_page = *parent->new_object<scls::GUI_Text>(object_name);return a_arithmetic_calculator_page;}
        else if(object_name == "maths_arithmetic_calculator_elements"){a_arithmetic_calculator_elements = *parent->new_object<scls::GUI_Scroller_Choice>(object_name);return a_arithmetic_calculator_elements;}
        else if(object_name == "maths_arithmetic_calculator_elements_chosen"){a_arithmetic_calculator_elements_chosen = *parent->new_object<scls::GUI_Scroller_Choice>(object_name);return a_arithmetic_calculator_elements_chosen;}
        else if(object_name == "maths_arithmetic_calculator_elements_datas"){a_arithmetic_calculator_elements_datas = *parent->new_object<scls::GUI_Object>(object_name);return a_arithmetic_calculator_elements_datas;}
        else if(object_name == "maths_arithmetic_calculator_elements_datas_title"){a_arithmetic_calculator_elements_datas_title = *parent->new_object<scls::GUI_Text>(object_name);return a_arithmetic_calculator_elements_datas_title;}
        GUI_OBJECT_CREATION(scls::GUI_Object, a_arithmetic_calculator_congruence_circle, "maths_arithmetic_calculator_congruence_circle")
        GUI_OBJECT_CREATION(scls::GUI_Text_Base<Text>, a_arithmetic_division_page, "maths_arithmetic_division_body")
        else if(object_name == "maths_arithmetic_calculator_redaction"){a_arithmetic_calculator_redaction = *parent->new_object<scls::GUI_Text>(object_name);return a_arithmetic_calculator_redaction;}
        GUI_OBJECT_CREATION(scls::GUI_Text_Base<Text>, a_arithmetic_numbers_sets_page, "maths_arithmetic_numbers_sets_body")

        // Functions
        else if(object_name == "maths_functions_definitions_body") {a_functions_definitions_page = *parent->new_object<scls::GUI_Text>(object_name);return a_functions_definitions_page;}
        else if(object_name == "maths_functions_exponential_body") {a_functions_exponential_page = *parent->new_object<scls::GUI_Text>(object_name);return a_functions_exponential_page;}
        else if(object_name == "maths_functions_forms_body") {a_functions_forms_page = *parent->new_object<scls::GUI_Text>(object_name);return a_functions_forms_page;}
        GUI_OBJECT_CREATION(scls::GUI_Text_Base<Text>, a_functions_integration_page, "maths_functions_integration_body")
        else if(object_name == "maths_functions_redaction_body") {a_functions_redaction_page = *parent->new_object<scls::GUI_Object>(object_name);return a_functions_redaction_page;}
        else if(object_name == "maths_functions_redaction") {a_functions_redaction = *parent->new_object<scls::GUI_Text>(object_name);return a_functions_redaction;}
        else if(object_name == "maths_functions_redaction_analyse") {a_functions_redaction_analyse = *parent->new_object<scls::GUI_Text>(object_name);return a_functions_redaction_analyse;}
        else if(object_name == "maths_functions_redaction_elements"){a_functions_redaction_elements = *parent->new_object<scls::GUI_Scroller_Choice>(object_name);return a_functions_redaction_elements;}
        else if(object_name == "maths_functions_redaction_elements_chosen"){a_functions_redaction_elements_chosen = *parent->new_object<scls::GUI_Scroller_Choice>(object_name);return a_functions_redaction_elements_chosen;}
        else if(object_name == "maths_functions_redaction_elements_created"){a_functions_redaction_elements_created = *parent->new_object<scls::GUI_Scroller_Choice>(object_name);return a_functions_redaction_elements_created;}
        else if(object_name == "maths_functions_redaction_elements_creation"){a_functions_redaction_elements_creation = *parent->new_object<scls::GUI_Scroller_Choice>(object_name);return a_functions_redaction_elements_creation;}
        else if(object_name == "maths_functions_redaction_expression"){a_functions_redaction_expression = *parent->new_object<scls::GUI_Text_Input>(object_name);return a_functions_redaction_expression;}
        else if(object_name == "maths_functions_redaction_graphic"){a_functions_redaction_graphic = *parent->new_object<Graphic_Object>(object_name);return a_functions_redaction_graphic;}
        else if(object_name == "maths_functions_redaction_name"){a_functions_redaction_name = *parent->new_object<scls::GUI_Text_Input>(object_name);return a_functions_redaction_name;}

        // Geometry
        else if(object_name == "maths_geometry_definitions_body") {a_geometry_definitions_body = *parent->new_object<scls::GUI_Text>(object_name);return a_geometry_definitions_body;}
        else if(object_name == "maths_geometry_complex_numbers_body") {a_geometry_complex_numbers_page = *parent->new_object<scls::GUI_Text>(object_name);return a_geometry_complex_numbers_page;}
        else if(object_name == "maths_geometry_redaction"){a_geometry_redaction = *parent->new_object<scls::GUI_Text>(object_name);return a_geometry_redaction;}
        else if(object_name == "maths_geometry_redaction_analyse"){a_geometry_redaction_analyse = *parent->new_object<scls::GUI_Text>(object_name);return a_geometry_redaction_analyse;}
        else if(object_name == "maths_geometry_redaction_body"){a_geometry_redaction_page = *parent->new_object<scls::GUI_Object>(object_name);return a_geometry_redaction_page;}
        else if(object_name == "maths_geometry_redaction_elements_choice"){a_geometry_redaction_elements = *parent->new_object<scls::GUI_Scroller_Choice>(object_name);return a_geometry_redaction_elements;}
        else if(object_name == "maths_geometry_redaction_elements_chosen"){a_geometry_redaction_elements_chosen = *parent->new_object<scls::GUI_Scroller_Choice>(object_name);return a_geometry_redaction_elements_chosen;}
        else if(object_name == "maths_geometry_redaction_elements_created"){a_geometry_redaction_elements_created = *parent->new_object<scls::GUI_Scroller_Choice>(object_name);return a_geometry_redaction_elements_created;}
        else if(object_name == "maths_geometry_redaction_elements_creation"){a_geometry_redaction_elements_creation = *parent->new_object<scls::GUI_Scroller_Choice>(object_name);return a_geometry_redaction_elements_creation;}
        else if(object_name == "maths_geometry_redaction_form"){a_geometry_redaction_form = *parent->new_object<scls::GUI_Object>(object_name);return a_geometry_redaction_form;}
        else if(object_name == "maths_geometry_redaction_form_name"){a_geometry_redaction_form_name = *parent->new_object<scls::GUI_Text_Input>(object_name);return a_geometry_redaction_form_name;}
        else if(object_name == "maths_geometry_redaction_form_points"){a_geometry_redaction_form_points = *parent->new_object<scls::GUI_Text_Input>(object_name);return a_geometry_redaction_form_points;}
        else if(object_name == "maths_geometry_redaction_graphic"){a_geometry_redaction_graphic = *parent->new_object<Graphic_Object>(object_name);return a_geometry_redaction_graphic;}
        else if(object_name == "maths_geometry_redaction_vector"){a_geometry_redaction_vector = *parent->new_object<scls::GUI_Object>(object_name);return a_geometry_redaction_vector;}
        else if(object_name == "maths_geometry_redaction_vector_name"){a_geometry_redaction_vector_name = *parent->new_object<scls::GUI_Text_Input>(object_name);return a_geometry_redaction_vector_name;}
        else if(object_name == "maths_geometry_redaction_vector_x"){a_geometry_redaction_vector_x = *parent->new_object<scls::GUI_Text_Input>(object_name);return a_geometry_redaction_vector_x;}
        else if(object_name == "maths_geometry_redaction_vector_y"){a_geometry_redaction_vector_y = *parent->new_object<scls::GUI_Text_Input>(object_name);return a_geometry_redaction_vector_y;}
        else if(object_name == "maths_geometry_vector_body"){a_geometry_vector_page = *parent->new_object<scls::GUI_Text_Base<Text>>(object_name);return a_geometry_vector_page;}

        // Home
        GUI_OBJECT_CREATION(scls::GUI_Text_Base<Text>, a_home_definition_page, "maths_home_definitions_body")

        // Logic
        GUI_OBJECT_CREATION(pleos::GUI_Text, a_logic_definitions_page, "maths_logic_definitions_body")
        else if(object_name == "maths_logic_language_body"){a_logic_language_page = *parent->new_object<scls::GUI_Text>(object_name);return a_logic_language_page;}
        GUI_OBJECT_CREATION(pleos::GUI_Text, a_logic_propositional_page, "maths_logic_propositional_body")
        else if(object_name == "maths_logic_set_theory_body"){a_logic_set_theory_page = *parent->new_object<scls::GUI_Text_Base<Text>>(object_name);return a_logic_set_theory_page;}

        // Pages
        else if(object_name == "maths_algebra_page"){a_algebra_page = *parent->new_object<scls::GUI_Object>(object_name);return a_algebra_page;}
        else if(object_name == "maths_arithmetic_page"){a_arithmetic_page = *parent->new_object<scls::GUI_Object>(object_name);return a_arithmetic_page;}
        else if(object_name == "maths_functions_page") {a_functions_page = *parent->new_object<scls::GUI_Object>(object_name);return a_functions_page;}
        else if(object_name == "maths_geometry_page"){a_geometry_page = *parent->new_object<scls::GUI_Object>(object_name);return a_geometry_page;}
        GUI_OBJECT_CREATION(scls::GUI_Object, a_home_page, "maths_home_page")
        else if(object_name == "maths_logic_page"){a_logic_page = *parent->new_object<scls::GUI_Object>(object_name);return a_logic_page;}

        // Random
        GUI_OBJECT_CREATION(scls::GUI_Object, a_random_page, "maths_random_page")
        GUI_OBJECT_CREATION(pleos::GUI_Text, a_random_probability_page, "maths_random_probability_body")
        GUI_OBJECT_CREATION(pleos::GUI_Text, a_random_probability_law_page, "maths_random_probability_law_body")

        // School
        GUI_OBJECT_CREATION(scls::GUI_Object, a_school_page, "maths_school_page")
        GUI_OBJECT_CREATION(pleos::GUI_Text, a_school_term_1_page, "maths_school_term_1_body")
        GUI_OBJECT_CREATION(pleos::GUI_Text, a_school_term_2_page, "maths_school_term_2_body")

        // Navigation
        else if(object_name == "maths_hub"){a_hub_button = *parent->new_object<scls::GUI_Text>(object_name);return a_hub_button;}
        else if(object_name == "maths_navigation") {a_navigation = *parent->new_object<scls::GUI_Scroller_Choice>(object_name);return a_navigation;}

        return scls::GUI_Page::__create_loaded_object_from_type(object_name, object_type, parent);
    }

    //******************
    //
    // Algebra handling
    //
    //******************

    // Redacts the needed redaction for the algebra part
    void Maths_Page::algebra_redact() {
        std::string input = algebra_solver_redaction_input()->text();
        std::string redaction = std::string();

        // Get all the part of the input
        std::vector<scls::Formula> formulas = std::vector<scls::Formula>();
        std::vector<std::string> input_cutted = scls::cut_string(input, std::string(";"));

        // Load all the formula
        scls::Textual_Math_Settings settings;
        for(int i = 0;i<static_cast<int>(input_cutted.size());i++) {
            std::vector<std::string> cutted = scls::cut_string(input_cutted.at(i), std::string("="));
            if(cutted.size() == 2) {
                if(formulas.size() > 0) {
                    // An unknown is precised
                    std::string current_redaction = input_cutted.at(i);
                    scls::Formula needed_value = scls::string_to_formula(cutted.at(1));
                    scls::__Formula_Base::Formula needed_formula = formulas[formulas.size() - 1].replace_unknown(cutted.at(0), needed_value);
                    formulas[formulas.size() - 1] = *needed_formula.formula_base();
                    current_redaction += std::string(" = ") + needed_formula.to_std_string(&settings);
                    if(i < static_cast<int>(input_cutted.size())){current_redaction += std::string("</br></br>");}
                    redaction += current_redaction;
                }
            }
            else {
                std::string current_redaction = input_cutted.at(i);
                scls::Formula needed_formula = scls::string_to_formula(input_cutted.at(i));
                current_redaction += std::string(" = ") + needed_formula.to_std_string(&settings);
                if(i < static_cast<int>(input_cutted.size())){current_redaction += std::string("</br></br>");}
                redaction += current_redaction;formulas.push_back(needed_formula);
            }
        }

        algebra_solver_redaction()->set_text(redaction);
    }

    //******************
    //
    // Arithmetic handling
    //
    //******************

    // Adds an element to create
    void Maths_Page::arithmetic_add_element_created(std::string current_choice){
        // Direct elements
        if(current_choice == "congruence_circle"){arithmetic_calculator_redaction()->set_visible(false);display_arithmetic_calculator_congruence_circle();arithmetic_update_congruence_circle();return;}
        arithmetic_calculator_redaction()->set_visible(true);arithmetic_calculator_congruence_circle()->set_visible(false);

        // Create the needed object
        arithmetic_objects_created().push_back(std::make_shared<Arithmetic_Object>());
        std::shared_ptr<Arithmetic_Object> arithmetic_object_shared_ptr = arithmetic_objects_created()[arithmetic_objects_created().size() - 1];
        Arithmetic_Object* arithmetic_object = arithmetic_object_shared_ptr.get();

        // Creation name
        std::string final_choice = current_choice;
        std::string needed_title = "";
        if(current_choice == "gcd"){
            int number = arithmetic_calculator_elements_chosen()->count_object_similar(current_choice, "-");
            final_choice += std::string("-") + std::to_string(number);
            needed_title = std::string("PGCD ") + std::to_string(number + 1);
        }
        else if(current_choice == std::string("decomposition")) {
            int number = arithmetic_calculator_elements_chosen()->count_object_similar(current_choice, "-");
            final_choice += std::string("-") + std::to_string(number);
            needed_title = std::string("Décomposition ") + std::to_string(number + 1);
        }

        // Get the good current choice
        arithmetic_object->choice = current_choice;
        std::shared_ptr<scls::GUI_Text>* object = arithmetic_calculator_elements_chosen()->add_object(final_choice, needed_title);
        if(object != 0){arithmetic_object->connected_object = *object;}
        arithmetic_select_object(arithmetic_object_shared_ptr);
    };

    // Redacts the needed redaction for the arithmetic part
    void Maths_Page::arithmetic_redact() {
        // Do the calculation in the calculator
        check_arithmetic_hiding();
        // Prepare the redaction
        std::string current_text = arithmetic_calculator_redaction()->text();
        if(current_text.size() == 29 && current_text == std::string("Pas de rédaction à afficher")){current_text = std::string("");}
        if(current_text != ""){current_text += std::string("</br>");}

        // Get the good redaction
        current_text = "";
        for(int i = 0;i<static_cast<int>(arithmetic_objects_created().size());i++) {
            if(arithmetic_objects_created()[i].get()->choice == std::string("gcd")) {
                // Get the GCD
                arithmetic_gcd(arithmetic_objects_created()[i].get(), &current_text);

                if(arithmetic_objects_created()[i].get()->choice_1) {
                    // Get the Bezout identity
                    current_text += std::string("</br></br>");
                    arithmetic_bezout_identity(arithmetic_objects_created()[i].get(), &current_text);
                }
            }
            else if(arithmetic_objects_created()[i].get()->choice == std::string("decomposition")) {
                // Get the decomposition
                arithmetic_decomposition(arithmetic_objects_created()[i].get(), &current_text);
            }

            // Add a separation
            if(i < static_cast<int>(arithmetic_objects_created().size()) - 1){current_text += std::string("</br></br>");}
        }

        // Finish the redaction
        arithmetic_calculator_redaction()->set_text(current_text);
    }

    // Selects an arithmetic object
    int __arithmetic_object_created = 0;
    void Maths_Page::arithmetic_select_object(std::shared_ptr<Arithmetic_Object> arithmetic_object) {
        // Set the current object
        check_arithmetic_hiding();
        a_current_state.a_arithmetic_currently_selected_object = arithmetic_object;

        // Set the good graphic datas
        arithmetic_calculator_elements_datas_title()->set_text(arithmetic_object.get()->connected_object.get()->text());

        // Finalise the creation
        scls::Textual_Math_Settings settings;
        if(arithmetic_object->choice == "gcd"){
            // Create the title of the name of the first number
            std::shared_ptr<scls::GUI_Text> first_title = *arithmetic_calculator_elements_datas()->new_object<scls::GUI_Text>(arithmetic_calculator_elements_datas()->name() + "-first_title_" + std::to_string(__arithmetic_object_created));
            first_title.get()->set_height_in_pixel(30);
            first_title.get()->set_text_alignment_horizontal(scls::H_Right);
            first_title.get()->set_width_in_scale(scls::Fraction(1, 5));
            first_title.get()->set_x_in_object_scale(scls::Fraction(1, 5));
            first_title.get()->set_y_in_object_scale(scls::Fraction(3, 4));
            first_title.get()->set_text(std::string("Premier nombre"));
            arithmetic_created_object_for_selected_object().push_back(first_title);

            // Create the name of the first number
            std::shared_ptr<scls::GUI_Text_Input> first_input = *arithmetic_calculator_elements_datas()->new_object<scls::GUI_Text_Input>(arithmetic_calculator_elements_datas()->name() + "-first_input_" + std::to_string(__arithmetic_object_created));
            first_input.get()->set_border_width_in_pixel(1);
            first_input.get()->set_height_in_pixel(30);
            first_input.get()->set_width_in_scale(scls::Fraction(1, 6));
            first_input.get()->set_x_in_object_scale(scls::Fraction(2, 5));
            first_input.get()->set_y_in_object_scale(scls::Fraction(3, 4));
            first_input.get()->set_text(arithmetic_object.get()->value_1.to_std_string(&settings));
            arithmetic_object.get()->input_1 = first_input;
            arithmetic_created_object_for_selected_object().push_back(first_input);

            // Create the title of the name of the second number
            std::shared_ptr<scls::GUI_Text> second_title = *arithmetic_calculator_elements_datas()->new_object<scls::GUI_Text>(arithmetic_calculator_elements_datas()->name() + "-second_title_" + std::to_string(__arithmetic_object_created));
            second_title.get()->set_height_in_pixel(30);
            second_title.get()->set_text_alignment_horizontal(scls::H_Right);
            second_title.get()->set_width_in_scale(scls::Fraction(1, 5));
            second_title.get()->set_x_in_object_scale(scls::Fraction(3, 5));
            second_title.get()->set_y_in_object_scale(scls::Fraction(3, 4));
            second_title.get()->set_text(std::string("Second nombre"));
            arithmetic_created_object_for_selected_object().push_back(second_title);

            // Create the name of the second number
            std::shared_ptr<scls::GUI_Text_Input> second_input = *arithmetic_calculator_elements_datas()->new_object<scls::GUI_Text_Input>(arithmetic_calculator_elements_datas()->name() + "-second_input_" + std::to_string(__arithmetic_object_created));
            second_input.get()->set_border_width_in_pixel(1);
            second_input.get()->set_height_in_pixel(30);
            second_input.get()->set_width_in_scale(scls::Fraction(1, 6));
            second_input.get()->set_x_in_object_scale(scls::Fraction(4, 5));
            second_input.get()->set_y_in_object_scale(scls::Fraction(3, 4));
            second_input.get()->set_text(arithmetic_object.get()->value_2.to_std_string(&settings));
            arithmetic_object.get()->input_2 = second_input;
            arithmetic_created_object_for_selected_object().push_back(second_input);

            // If the Bezout identity must be find or not
            std::shared_ptr<scls::GUI_Scroller_Choice> bezout_choice = *arithmetic_calculator_elements_datas()->new_object<scls::GUI_Scroller_Choice>(arithmetic_calculator_elements_datas()->name() + "-first_choice_" + std::to_string(__arithmetic_object_created));
            bezout_choice.get()->set_border_width_in_pixel(1);
            bezout_choice.get()->set_height_in_pixel(30);
            bezout_choice.get()->set_width_in_scale(scls::Fraction(1, 6));
            bezout_choice.get()->set_x_in_object_scale(scls::Fraction(1, 5));
            bezout_choice.get()->set_y_in_object_scale(scls::Fraction(1, 2));
            bezout_choice.get()->add_object(std::string("bezout_identity"), std::string("Identité de Bezout"));
            bezout_choice.get()->selected_objects_style().a_background_color = scls::Color(0, 102, 0);
            if(arithmetic_object.get()->choice_1){bezout_choice.get()->select_object("bezout_identity");}
            arithmetic_object.get()->choice_input_1 = bezout_choice;
            arithmetic_created_object_for_selected_object().push_back(bezout_choice);
        }
        else if(arithmetic_object->choice == "decomposition"){
            // Create the title of the name of the first number
            std::shared_ptr<scls::GUI_Text> first_title = *arithmetic_calculator_elements_datas()->new_object<scls::GUI_Text>(arithmetic_calculator_elements_datas()->name() + "-first_title_" + std::to_string(__arithmetic_object_created));
            first_title.get()->set_height_in_pixel(30);
            first_title.get()->set_text_alignment_horizontal(scls::H_Right);
            first_title.get()->set_width_in_scale(scls::Fraction(1, 5));
            first_title.get()->set_x_in_object_scale(scls::Fraction(1, 5));
            first_title.get()->set_y_in_object_scale(scls::Fraction(3, 4));
            first_title.get()->set_text(std::string("Nombre à décomposer"));
            arithmetic_created_object_for_selected_object().push_back(first_title);

            // Create the name of the first number
            std::shared_ptr<scls::GUI_Text_Input> first_input = *arithmetic_calculator_elements_datas()->new_object<scls::GUI_Text_Input>(arithmetic_calculator_elements_datas()->name() + "-first_input_" + std::to_string(__arithmetic_object_created));
            first_input.get()->set_border_width_in_pixel(1);
            first_input.get()->set_height_in_pixel(30);
            first_input.get()->set_width_in_scale(scls::Fraction(1, 6));
            first_input.get()->set_x_in_object_scale(scls::Fraction(2, 5));
            first_input.get()->set_y_in_object_scale(scls::Fraction(3, 4));
            first_input.get()->set_text(arithmetic_object.get()->value_1.to_std_string(&settings));
            arithmetic_object.get()->input_1 = first_input;
            arithmetic_created_object_for_selected_object().push_back(first_input);
        }

        __arithmetic_object_created++;
    }

    // Updates the congruence circle
    void Maths_Page::arithmetic_update_congruence_circle() {
        std::shared_ptr<scls::__Image_Base> img = division_circle(arithmetic_calculator_congruence_circle()->height_in_pixel(), static_cast<double>(arithmetic_calculator_congruence_circle()->height_in_pixel()) * 0.4, a_current_state.a_arithmetic_congruence_circle_modulo, a_current_state.a_arithmetic_congruence_circle_points);
        arithmetic_calculator_congruence_circle()->texture()->set_image(img);
        set_should_render_during_this_frame(true);
    }

    //******************
    //
    // Functions handling
    //
    //******************

    // Function called after the XML loading
    void Maths_Page::after_xml_loading(){
        scls::GUI_Page::after_xml_loading();
        hide_sub_pages(true);
        a_functions_redaction_elements_chosen.get()->unselected_objects_style().cursor = GLFW_ARROW_CURSOR;
        geometry_redaction_graphic()->set_operation_at_click(PLEOS_OPERATION_VECTOR);
        display_home_definition_page();
    }

    // Adds an element to analyse
    void Maths_Page::functions_add_element(std::string current_choice) {
        // Creation name
        std::string final_choice = current_choice;
        if(current_choice == "image"){
            final_choice += std::string("-") + std::to_string(functions_redaction_elements_chosen()->count_object_similar("image", "-"));
        }

        // Get the good current choice
        std::shared_ptr<scls::GUI_Object>* object = functions_redaction_elements_chosen()->add_object(final_choice);

        // Do the good configuration
        if(object != 0) {
            int needed_height = 30;
            std::string needed_title = "";
            // Creation settings
            if(current_choice == "area_under_curve"){
                needed_height = 60;
                needed_title = std::string("Aire sous la courbe");
            }
            else if(current_choice == "definition_set"){
                needed_height = 60;
                needed_title = std::string("Ensemble de définition");
            }
            else if(current_choice == "functions_analysis_derivate"){
                needed_height = 60;
                needed_title = std::string("Fonction dérivée");
            }
            else if(current_choice == "functions_analysis_primitive"){
                needed_height = 60;
                needed_title = std::string("Fonction primitive");
            }
            else if(current_choice == "image"){
                needed_height = 90;
                needed_title = std::string("Image");
            }
            else if(current_choice == "roots"){
                needed_height = 60;
                needed_title = std::string("Racines");
            }

            final_choice = object->get()->name();
            object->get()->set_border_width_in_pixel(1);
            object->get()->set_height_in_pixel(needed_height);
            functions_redaction_elements_chosen()->place_objects();

            // Create the title
            std::shared_ptr<scls::GUI_Text> title = *object->get()->new_object<scls::GUI_Text>(final_choice + "_title");
            title.get()->attach_top_in_parent();
            title.get()->set_height_in_pixel(30);
            title.get()->set_width_in_scale(1);
            title.get()->set_x_in_object_scale(scls::Fraction(1, 2));
            title.get()->set_text(needed_title);

            // Neeeded function
            // Create the title
            std::shared_ptr<scls::GUI_Text> title_name = *object->get()->new_object<scls::GUI_Text>(final_choice + "_title_name");
            title_name.get()->attach_bottom_of_object_in_parent(title);
            title_name.get()->attach_left_in_parent();
            title_name.get()->set_height_in_pixel(30);
            title_name.get()->set_text(std::string("Pour la fonction"));
            title_name.get()->set_width_in_scale(scls::Fraction(1, 2));

            // Create the input
            std::shared_ptr<scls::GUI_Text_Input> input_name = *object->get()->new_object<scls::GUI_Text_Input>(final_choice + "_input_name");
            input_name.get()->attach_bottom_of_object_in_parent(title);
            input_name.get()->attach_right_in_parent();
            input_name.get()->set_border_width_in_pixel(1);
            input_name.get()->set_height_in_pixel(30);
            input_name.get()->set_width_in_scale(scls::Fraction(1, 2));

            // Finalise the creation
            if(current_choice == "image"){
                // Create the title
                std::shared_ptr<scls::GUI_Text> title_x = *object->get()->new_object<scls::GUI_Text>(final_choice + "_title_x");
                title_x.get()->attach_bottom_of_object_in_parent(title_name);
                title_x.get()->attach_left_in_parent();
                title_x.get()->set_height_in_pixel(30);
                title_x.get()->set_text(std::string("Pour x = "));
                title_x.get()->set_width_in_scale(scls::Fraction(1, 2));

                // Create the input
                std::shared_ptr<scls::GUI_Text_Input> input_x = *object->get()->new_object<scls::GUI_Text_Input>(final_choice + "_input_x");
                input_x.get()->attach_bottom_of_object_in_parent(title_name);
                input_x.get()->attach_right_in_parent();
                input_x.get()->set_border_width_in_pixel(1);
                input_x.get()->set_height_in_pixel(30);
                input_x.get()->set_width_in_scale(scls::Fraction(1, 2));
            }
        }
    }

    // Adds an element to create
    void Maths_Page::functions_add_element_created(std::string current_choice) {
        // Creation name
        std::string final_choice = current_choice;
        std::string needed_title = "";
        if(current_choice == "function"){
            final_choice += std::string("-") + std::to_string(functions_redaction_elements_created()->count_object_similar(current_choice, "-"));
            needed_title = std::string("Fonction f");

            // Create the needed vector
            functions_created().push_back(std::make_shared<pleos::Function_Studied>());
            functions_created()[functions_created().size() - 1].get()->set_name("f");
            functions_select_function(functions_created()[functions_created().size() - 1]);
        }

        // Get the good current choice
        std::shared_ptr<scls::GUI_Text>* object = functions_redaction_elements_created()->add_object(final_choice, needed_title);
        if(object != 0){currently_selected_function()->set_connected_object(*object);}
    }

    // Redacts the needed redaction for the functions part
    void Maths_Page::functions_redact() {
        // Starts the redaction
        check_functions_hiding(); functions_redaction_graphic()->reset();
        std::string redaction = std::string();
        if(static_cast<int>(functions_created().size()) > 1){redaction += std::string("Nous allons définir ") + std::to_string(functions_created().size()) + std::string(" fonctions. ");}
        // Create the introduction of the redaction
        scls::Textual_Math_Settings settings;
        for(int i = 0;i<static_cast<int>(functions_created().size());i++) {
            redaction += functions_created()[i].get()->introduction(&settings);
            if(i < static_cast<int>(functions_created().size()) - 1){redaction += std::string(" ");}
            pleos_log(functions_created()[i].get()->formula()->to_std_string(&settings));
        } redaction += std::string("</br></br>");

        std::cout << pleos_log_content() << std::endl;

        // Get datas for each functions
        for(int i = 0;i<static_cast<int>(functions_created().size());i++) {
            std::shared_ptr<pleos::Function_Studied> needed_function = functions_created()[i];
            std::string function_name = needed_function.get()->name();
            scls::Formula* needed_formula = needed_function.get()->formula();
            std::cout << i << " " << needed_formula->to_std_string(&settings) << std::endl;

            // Do the redaction
            redaction += std::string("Nous avons la fonction ") + function_name + std::string(" tel que :</br></br>");
            redaction += std::string("<math><mi>") + function_name + std::string("(x") + std::string(")</mi><mo>=</mo>") + needed_formula->to_mathml(&settings) + std::string("</math></br></br>");

            // Add the needed arguments
            std::vector<scls::GUI_Scroller_Choice::GUI_Scroller_Single_Choice>& objects = functions_redaction_elements_chosen()->objects();
            for(int j = 0;j<static_cast<int>(objects.size());j++) {
                std::string complete_name = objects[j].name(); std::vector<std::string> cutted = scls::cut_string(complete_name, std::string("-"));
                std::string current_function_name = reinterpret_cast<scls::GUI_Text_Input*>(objects[j].object()->child_by_name(objects[j].object()->name() + "_input_name"))->text();
                std::string type = cutted[0];

                if(current_function_name == function_name) {
                    // Analyse the argument
                    if(type == "area_under_curve") {
                        int rect_number = 20;
                        for(int i = 0;i<rect_number;i++) {
                            scls::Fraction needed_value = needed_formula->value(scls::Fraction(i, rect_number)).real();
                            if(needed_value != 0) {
                                std::shared_ptr<pleos::Form_2D> new_form = functions_redaction_graphic()->new_rect(std::string("square_") + std::to_string(i), static_cast<double>(i) / static_cast<double>(rect_number), 0, 1.0 / static_cast<double>(rect_number), needed_value.to_double());
                                new_form.get()->set_border_width(1);
                            }
                        }
                    }
                    else if(type == "definition_set") {function_definition_set(needed_function.get(), &redaction, &settings);}
                    else if(type == "functions_analysis_derivate") {function_derivation(needed_function.get(), &redaction, &settings);}
                    else if(type == "functions_analysis_primitive") {function_primitive(needed_function.get(), &redaction, &settings);}
                    else if(type == "image") {
                        // Calculate an image of the function
                        scls::Formula needed_value = scls::string_to_formula(reinterpret_cast<scls::GUI_Text_Input*>(objects[j].object()->child_by_name(objects[j].object()->name() + "_input_x"))->text());
                        function_image(needed_function.get(), needed_value, redaction, &settings);
                    }
                    else if(type == "roots") {function_roots(needed_function.get(), &redaction, &settings);}
                    redaction += std::string("</br></br>");
                }
            }

            // Check the graphic part
            if(needed_function.get()->definition_set() == 0){function_definition_set(needed_function.get(), 0, 0);}
            functions_redaction_graphic()->add_function(needed_function);
            redaction += std::string("</br></br>");
        }

        // Finish the redaction
        functions_redaction_graphic()->update_texture();
        functions_redaction()->set_text(redaction);
    }

    // Selects a functions vector
    void Maths_Page::functions_select_function(std::shared_ptr<pleos::Function_Studied> needed_function) {
        check_functions_hiding();
        currently_selected_function_shared_ptr() = needed_function;

        // Set the needed text
        scls::Textual_Math_Settings settings;
        functions_redaction_expression()->set_text(needed_function.get()->formula()->to_std_string(&settings));
        functions_redaction_name()->set_text(needed_function.get()->name());
    }

    //******************
    //
    // Geometry handling
    //
    //******************

    // Adds an element to analyse
    void Maths_Page::add_element(std::string current_choice) {
        // Creation name
        std::string final_choice = current_choice;
        if(current_choice == "vector"){
            final_choice += std::string("-") + std::to_string(geometry_redaction_elements_chosen()->count_object_similar("vector", "-"));
        }
        else if(current_choice == "vector_complex_number"){
            final_choice += std::string("-") + std::to_string(geometry_redaction_elements_chosen()->count_object_similar("vector_complex_number", "-"));
        }
        else if(current_choice == "vector_angle"){
            final_choice += std::string("-") + std::to_string(geometry_redaction_elements_chosen()->count_object_similar("vector_angle", "-"));
        }

        // Get the good current choice
        std::shared_ptr<scls::GUI_Object>* object = geometry_redaction_elements_chosen()->add_object(final_choice);

        // Do the good configuration
        if(object != 0) {
            int needed_height = 30;
            std::string needed_title = "";
            // Creation settings
            if(current_choice == "vector_angle"){
                needed_height = 90;
                needed_title = std::string("Angle");
            }
            if(current_choice == "vector_complex_number"){
                needed_height = 60;
                needed_title = std::string("Nombre complexe");
            } else if(current_choice == "vector_norm"){
                needed_height = 60;
                needed_title = std::string("Norme");
            }

            final_choice = object->get()->name();
            object->get()->set_border_width_in_pixel(1);
            object->get()->set_height_in_pixel(needed_height);
            geometry_redaction_elements_chosen()->place_objects();

            // Create the title
            std::shared_ptr<scls::GUI_Text> title = *object->get()->new_object<scls::GUI_Text>(final_choice + "_title");
            title.get()->attach_top_in_parent();
            title.get()->set_height_in_pixel(30);
            title.get()->set_width_in_scale(1);
            title.get()->set_x_in_object_scale(scls::Fraction(1, 2));
            title.get()->set_text(needed_title);

            // Finalise the creation
            if(current_choice == "vector_complex_number"){
                // Create the title of the name of the needed vector
                std::shared_ptr<scls::GUI_Text> name_title = *object->get()->new_object<scls::GUI_Text>(final_choice + "_title_name");
                name_title.get()->attach_bottom_of_object_in_parent(title);
                name_title.get()->set_height_in_pixel(30);
                name_title.get()->set_width_in_scale(scls::Fraction(1, 2));
                name_title.get()->set_x_in_object_scale(scls::Fraction(1, 4));
                name_title.get()->set_text(std::string("Objet :"));

                // Create the name of the needed vector
                std::shared_ptr<scls::GUI_Text_Input> name_input = *object->get()->new_object<scls::GUI_Text_Input>(final_choice + "_name");
                name_input.get()->attach_bottom_of_object_in_parent(title);
                name_input.get()->set_border_width_in_pixel(1);
                name_input.get()->set_height_in_pixel(30);
                name_input.get()->set_width_in_scale(scls::Fraction(1, 5));
                name_input.get()->set_x_in_object_scale(scls::Fraction(3, 4));
            }
            else if(current_choice == "vector_norm"){
                // Create the title of the name of the needed vector
                std::shared_ptr<scls::GUI_Text> name_title = *object->get()->new_object<scls::GUI_Text>(final_choice + "_title_name");
                name_title.get()->attach_bottom_of_object_in_parent(title);
                name_title.get()->set_height_in_pixel(30);
                name_title.get()->set_width_in_scale(scls::Fraction(1, 2));
                name_title.get()->set_x_in_object_scale(scls::Fraction(1, 4));
                name_title.get()->set_text(std::string("Vecteur :"));

                // Create the name of the needed vector
                std::shared_ptr<scls::GUI_Text_Input> name_input = *object->get()->new_object<scls::GUI_Text_Input>(final_choice + "_name");
                name_input.get()->attach_bottom_of_object_in_parent(title);
                name_input.get()->set_border_width_in_pixel(1);
                name_input.get()->set_height_in_pixel(30);
                name_input.get()->set_width_in_scale(scls::Fraction(1, 5));
                name_input.get()->set_x_in_object_scale(scls::Fraction(3, 4));
            }
            else if(current_choice == "vector_angle"){
                // Create the title of the name of the needed vector
                std::shared_ptr<scls::GUI_Text> name_title = *object->get()->new_object<scls::GUI_Text>(final_choice + "_title_name");
                name_title.get()->attach_bottom_of_object_in_parent(title);
                name_title.get()->set_height_in_pixel(30);
                name_title.get()->set_width_in_scale(scls::Fraction(1, 2));
                name_title.get()->set_x_in_object_scale(scls::Fraction(1, 4));
                name_title.get()->set_text(std::string("Vecteur :"));

                // Create the name of the needed vector
                std::shared_ptr<scls::GUI_Text_Input> name_input = *object->get()->new_object<scls::GUI_Text_Input>(final_choice + "_name");
                name_input.get()->attach_bottom_of_object_in_parent(title);
                name_input.get()->set_border_width_in_pixel(1);
                name_input.get()->set_height_in_pixel(30);
                name_input.get()->set_width_in_scale(scls::Fraction(1, 5));
                name_input.get()->set_x_in_object_scale(scls::Fraction(3, 4));

                // Create the title of the reference of the needed vector
                std::shared_ptr<scls::GUI_Text> reference_title = *object->get()->new_object<scls::GUI_Text>(final_choice + "_title_reference");
                reference_title.get()->attach_bottom_of_object_in_parent(name_title);
                reference_title.get()->set_height_in_pixel(30);
                reference_title.get()->set_width_in_scale(scls::Fraction(1, 2));
                reference_title.get()->set_x_in_object_scale(scls::Fraction(1, 4));
                reference_title.get()->set_text(std::string("Référence :"));

                // Create the name of the needed vector
                std::shared_ptr<scls::GUI_Text_Input> reference_input = *object->get()->new_object<scls::GUI_Text_Input>(final_choice + "_reference");
                reference_input.get()->attach_bottom_of_object_in_parent(name_title);
                reference_input.get()->set_border_width_in_pixel(1);
                reference_input.get()->set_height_in_pixel(30);
                reference_input.get()->set_width_in_scale(scls::Fraction(1, 5));
                reference_input.get()->set_x_in_object_scale(scls::Fraction(3, 4));
            }
        }
    }

    // Adds the button for the element created
    void Maths_Page::add_element_created_button(std::string final_choice, std::string needed_title, int object_created) {
        // Get the good current choice
        std::shared_ptr<scls::GUI_Text>* object = geometry_redaction_elements_created()->add_object(final_choice, needed_title);
        if(object != 0){
            if(object_created == PLEOS_MATHEMATICS_GEOMETRY_FORM){currently_selected_form_2d()->set_connected_object(*object);}
            else if(object_created == PLEOS_MATHEMATICS_GEOMETRY_POINT || object_created == PLEOS_MATHEMATICS_GEOMETRY_VECTOR){currently_selected_vector()->set_connected_object(*object);}
        }
    }

    // Returns the final choice for the element created
    std::string Maths_Page::add_element_created_final_choice(std::string current_choice) {
        std::string final_choice = current_choice;

        // Get the choice
        if(current_choice == "vector"){
            final_choice += std::string("-") + std::to_string(geometry_redaction_elements_created()->count_object_similar("vector", "-"));
        }
        else if(current_choice == "form"){
            final_choice += std::string("-") + std::to_string(geometry_redaction_elements_created()->count_object_similar("form", "-"));
        }
        else if(current_choice == "point"){
            final_choice += std::string("-") + std::to_string(geometry_redaction_elements_created()->count_object_similar("point", "-"));
        }

        return final_choice;
    }

    // Adds an element to create
    void Maths_Page::add_element_created(std::string current_choice) {
        // Creation name
        std::string final_choice = add_element_created_final_choice(current_choice);
        std::string needed_title = "";
        int object_created = 0;
        if(current_choice == "vector"){
            needed_title = std::string("Vecteur");
            object_created = PLEOS_MATHEMATICS_GEOMETRY_VECTOR;

            // Create the needed vector
            geometry_vectors_created().push_back(std::make_shared<Point_2D>(geometry_redaction_graphic()->graphic_base_shared_ptr(), "", 1, 1));
            geometry_select_vector(geometry_vectors_created()[geometry_vectors_created().size() - 1]);
        }
        else if(current_choice == "form"){
            needed_title = std::string("Forme");
            object_created = PLEOS_MATHEMATICS_GEOMETRY_FORM;

            // Create the needed form
            geometry_form_2d_created().push_back(std::make_shared<pleos::Form_2D>(geometry_redaction_graphic()->graphic_base_shared_ptr(), ""));
            geometry_select_form_2d(geometry_form_2d_created()[geometry_form_2d_created().size() - 1]);
        }
        else if(current_choice == "point"){
            needed_title = std::string("Point");
            object_created = PLEOS_MATHEMATICS_GEOMETRY_POINT;

            // Create the needed vector
            geometry_vectors_created().push_back(std::make_shared<Point_2D>(geometry_redaction_graphic()->graphic_base_shared_ptr(), "", 1, 1));
            geometry_vectors_created()[geometry_vectors_created().size() - 1].get()->set_type(Vector_Type::VT_Point);
            geometry_select_vector(geometry_vectors_created()[geometry_vectors_created().size() - 1]);
        }

        // Set the current choice
        add_element_created_button(final_choice, needed_title, object_created);
    }

    // Shows a demonstration of the Pythagoras theorem
    void Maths_Page::display_geometry_pythagorean_theorem_demonstration() {
        // Set the good page
        geometry_reset();
        display_geometry_redaction_graphic_page();

        // Create the main form
        // First triangle
        add_element_created("point");
        currently_selected_vector()->set_name("A");
        currently_selected_vector()->set_x(0);
        currently_selected_vector()->set_y(1);
        currently_selected_vector_shared_ptr().reset();
        add_element_created("point");
        currently_selected_vector()->set_name("B");
        currently_selected_vector()->set_x(0);
        currently_selected_vector()->set_y(0);
        currently_selected_vector_shared_ptr().reset();
        add_element_created("point");
        currently_selected_vector()->set_name("C");
        currently_selected_vector()->set_x(3);
        currently_selected_vector()->set_y(0);
        currently_selected_vector_shared_ptr().reset();
        // Form
        add_element_created("form");
        currently_selected_form_2d()->set_name("ABC");
        currently_selected_form_2d()->add_point(geometry_vector_created(std::string("A")));
        currently_selected_form_2d()->add_point(geometry_vector_created(std::string("B")));
        currently_selected_form_2d()->add_point(geometry_vector_created(std::string("C")));
        currently_selected_form_2d_shared_ptr().reset(); currently_selected_vector_shared_ptr().reset();

        // Create the others forms
        // Second triangle
        add_element_created("point");
        currently_selected_vector()->set_name("D");
        currently_selected_vector()->set_x(4);
        currently_selected_vector()->set_y(0);
        currently_selected_vector_shared_ptr().reset();
        add_element_created("point");
        currently_selected_vector()->set_name("E");
        currently_selected_vector()->set_x(4);
        currently_selected_vector()->set_y(3);
        currently_selected_vector_shared_ptr().reset();
        add_element_created("form");
        currently_selected_form_2d()->set_name("CDE");
        currently_selected_form_2d()->add_point(geometry_vector_created(std::string("C")));
        currently_selected_form_2d()->add_point(geometry_vector_created(std::string("D")));
        currently_selected_form_2d()->add_point(geometry_vector_created(std::string("E")));
        currently_selected_form_2d_shared_ptr().reset(); currently_selected_vector_shared_ptr().reset();
        // Third triangle
        add_element_created("point");
        currently_selected_vector()->set_name("F");
        currently_selected_vector()->set_x(0);
        currently_selected_vector()->set_y(4);
        currently_selected_vector_shared_ptr().reset();
        add_element_created("point");
        currently_selected_vector()->set_name("G");
        currently_selected_vector()->set_x(1);
        currently_selected_vector()->set_y(4);
        currently_selected_vector_shared_ptr().reset();
        add_element_created("form");
        currently_selected_form_2d()->set_name("AFG");
        currently_selected_form_2d()->add_point(geometry_vector_created(std::string("A")));
        currently_selected_form_2d()->add_point(geometry_vector_created(std::string("F")));
        currently_selected_form_2d()->add_point(geometry_vector_created(std::string("G")));
        currently_selected_form_2d_shared_ptr().reset(); currently_selected_vector_shared_ptr().reset();
        // Fourth triangle
        add_element_created("point");
        currently_selected_vector()->set_name("H");
        currently_selected_vector()->set_x(4);
        currently_selected_vector()->set_y(4);
        currently_selected_vector_shared_ptr().reset();
        add_element_created("form");
        currently_selected_form_2d()->set_name("GEH");
        currently_selected_form_2d()->add_point(geometry_vector_created(std::string("G")));
        currently_selected_form_2d()->add_point(geometry_vector_created(std::string("E")));
        currently_selected_form_2d()->add_point(geometry_vector_created(std::string("H")));
        currently_selected_form_2d_shared_ptr().reset(); currently_selected_vector_shared_ptr().reset();//*/

        // Finish the demonstration
        geometry_redact();
    }

    // Redacts the needed redaction for the geometry part
    void Maths_Page::geometry_redact() {
        // Do the redaction
        check_geometry_hiding(); geometry_redaction_graphic()->reset();
        std::string redaction = std::string();
        // Add the vectors
        scls::Textual_Math_Settings settings;
        if(static_cast<int>(geometry_vectors_created().size()) > 1){redaction += std::string("Nous allons définir ") + std::to_string(geometry_vectors_created().size()) + std::string(" vecteurs. ");}
        for(int i = 0;i<static_cast<int>(geometry_vectors_created().size());i++) {
            redaction += geometry_vectors_created()[i].get()->introduction(&settings);
            if(i < static_cast<int>(geometry_vectors_created().size()) - 1){redaction += std::string(" ");}
            // Add the needed vector
            geometry_redaction_graphic()->add_vector(*geometry_vectors_created()[i].get());
        } redaction += std::string("</br></br>");
        // Add the forms
        if(static_cast<int>(geometry_form_2d_created().size()) > 1){redaction += std::string("Nous allons définir ") + std::to_string(geometry_form_2d_created().size()) + std::string(" formes. ");}
        for(int i = 0;i<static_cast<int>(geometry_form_2d_created().size());i++) {
            redaction += geometry_form_2d_created()[i].get()->introduction();
            if(i < static_cast<int>(geometry_form_2d_created().size()) - 1){redaction += std::string(" ");}
            // Add the needed vector
            geometry_redaction_graphic()->add_form(geometry_form_2d_created()[i]);
        } redaction += std::string("</br></br>");

        // Add the needed arguments
        std::vector<scls::GUI_Scroller_Choice::GUI_Scroller_Single_Choice>& objects = geometry_redaction_elements_chosen()->objects();
        for(int i = 0;i<static_cast<int>(objects.size());i++) {
            redaction += std::string("</br></br>");
            std::string complete_name = objects[i].name(); std::vector<std::string> cutted = scls::cut_string(complete_name, std::string("-"));
            std::string type = cutted[0];

            // Analyse the argument
            if(type == "vector_norm") {
                std::string needed_vector_name = reinterpret_cast<scls::GUI_Text_Input*>(objects[i].object()->child_by_name(objects[i].object()->name() + "_name"))->text();
                std::shared_ptr<Point_2D> needed_vector = geometry_vector_created(needed_vector_name);
                //if(needed_vector.get() != 0){needed_vector.get()->norm(&redaction, &settings);}
            }
            else if(type == "vector_complex_number") {
                std::string needed_vector_name = reinterpret_cast<scls::GUI_Text_Input*>(objects[i].object()->child_by_name(objects[i].object()->name() + "_name"))->text();
                std::shared_ptr<Point_2D> needed_vector = geometry_vector_created(needed_vector_name);
                //if(needed_vector.get() != 0){needed_vector.get()->complex_number(&redaction, &settings);}
            }
            else if(type == "vector_angle") {
                std::string needed_vector_name = reinterpret_cast<scls::GUI_Text_Input*>(objects[i].object()->child_by_name(objects[i].object()->name() + "_name"))->text();
                std::shared_ptr<Point_2D> needed_vector = geometry_vector_created(needed_vector_name);
                needed_vector_name = reinterpret_cast<scls::GUI_Text_Input*>(objects[i].object()->child_by_name(objects[i].object()->name() + "_reference"))->text();
                std::shared_ptr<Point_2D> needed_reference = geometry_vector_created(needed_vector_name);
                //if(needed_vector.get() != 0 && needed_reference.get() != 0) {needed_vector.get()->angle(needed_reference.get(), &redaction, &settings);}
            } redaction += std::string("</br></br>");
        }//*/

        geometry_redaction_graphic()->update_texture();
        geometry_redaction()->set_text(redaction);
    }

    // Selects a geometry form 2D
    void Maths_Page::geometry_select_form_2d(std::shared_ptr<pleos::Form_2D> needed_form_2d) {
        check_geometry_hiding();
        currently_selected_form_2d_shared_ptr() = needed_form_2d;

        if(needed_form_2d.get() != 0) {
            // Set the needed text
            geometry_redaction_form()->set_visible(true);geometry_redaction_vector()->set_visible(false);
            geometry_redaction_form_name()->set_text(needed_form_2d.get()->name());
            std::string needed_points = std::string("");
            for(int i = 0;i<static_cast<int>(needed_form_2d.get()->points().size());i++){needed_points+=needed_form_2d.get()->points()[i].get()->name();if(i<static_cast<int>(needed_form_2d.get()->points().size())-1){needed_points+=std::string(";");}}
            geometry_redaction_form_points()->set_text(needed_points);
        }
        else {geometry_redaction_form()->set_visible(false);geometry_redaction_vector()->set_visible(false);}
    }

    // Selects a geometry vector
    void Maths_Page::geometry_select_vector(std::shared_ptr<Point_2D> needed_vector) {
        check_geometry_hiding();
        currently_selected_vector_shared_ptr() = needed_vector;

        if(needed_vector.get() != 0) {
            // Set the needed text
            scls::Textual_Math_Settings settings;
            geometry_redaction_form()->set_visible(false);geometry_redaction_vector()->set_visible(true);
            geometry_redaction_vector_name()->set_text(needed_vector.get()->name());
            geometry_redaction_vector_x()->set_text(needed_vector.get()->x_formula().to_std_string(&settings));
            geometry_redaction_vector_y()->set_text(needed_vector.get()->y_formula().to_std_string(&settings));
        }
        else {geometry_redaction_form()->set_visible(false);geometry_redaction_vector()->set_visible(false);}
    }

    //******************
    //
    // Check the events
    //
    //******************

    // Checks the events of algebra
    void Maths_Page::check_algebra() {
        // Do the algebra redaction
        if(window_struct()->key_pressed_during_this_frame("left control")) {algebra_redact();}
    }

    // Checks the events of arithmetic
    void Maths_Page::check_arithmetic() {
        // Do the arithmetic redaction
        if(window_struct()->key_pressed_during_this_frame("left control")) {arithmetic_redact();}

        // Adds a created element
        if(arithmetic_calculator_elements()->selection_modified()) {
            std::string current_choice = arithmetic_calculator_elements()->currently_selected_objects_during_this_frame()[0].name();
            arithmetic_calculator_elements()->unselect_object(arithmetic_calculator_elements()->currently_selected_objects()[0]);
            arithmetic_add_element_created(current_choice);
        }

        // Select a created element
        for(int i = 0;i<static_cast<int>(arithmetic_objects_created().size());i++) {
            if(arithmetic_objects_created()[i].get()->connected_object.get()->is_clicked_during_this_frame(GLFW_MOUSE_BUTTON_LEFT)) {
                arithmetic_select_object(arithmetic_objects_created()[i]);
            }
        }

        // Updates the congruence circle
        #define MODULO_SPEED 1.0
        #define POINTS_SPEED 25.0
        if(current_page() == PLEOS_MATHS_ARITHMETIC_CALCULATOR_CONGRUENCE_CIRCLE_PAGE) {
            bool modified = false;

            // Handle modulo
            if(window_struct()->key_pressed("left arrow")) {a_current_state.a_arithmetic_congruence_circle_modulo += MODULO_SPEED * window_struct()->delta_time();modified = true;}
            if(window_struct()->key_pressed("right arrow")) {
                a_current_state.a_arithmetic_congruence_circle_modulo -= MODULO_SPEED * window_struct()->delta_time();
                if(a_current_state.a_arithmetic_congruence_circle_modulo < 1) {a_current_state.a_arithmetic_congruence_circle_modulo = 1;}
                modified = true;
            }

            // Handle points
            if(window_struct()->key_pressed("up arrow")) {a_current_state.a_arithmetic_congruence_circle_points += POINTS_SPEED * window_struct()->delta_time();modified = true;}
            if(window_struct()->key_pressed("down arrow")) {
                a_current_state.a_arithmetic_congruence_circle_points -= POINTS_SPEED * window_struct()->delta_time();
                if(a_current_state.a_arithmetic_congruence_circle_points < 5) {a_current_state.a_arithmetic_congruence_circle_points = 5;}
                modified = true;
            }

            // Update the circle
            if(modified){arithmetic_update_congruence_circle();}
        }
    }

    // Checks the events of hiding arithmetic page
    void Maths_Page::check_arithmetic_hiding() {
        if(arithmetic_currently_selected_object() != 0) {
            // Set the needed values
            if(arithmetic_currently_selected_object()->choice == std::string("gcd")) {
                // GCD
                // Choices
                if(arithmetic_currently_selected_object()->choice_input_1.get() != 0) {
                    arithmetic_currently_selected_object()->choice_1 = arithmetic_currently_selected_object()->choice_input_1.get()->contains_selected_object("bezout_identity");;
                }
                // Values
                if(arithmetic_currently_selected_object()->input_1.get() != 0) {
                    arithmetic_currently_selected_object()->value_1 = scls::string_to_formula(arithmetic_currently_selected_object()->input_1.get()->text());
                }
                if(arithmetic_currently_selected_object()->input_2.get() != 0) {
                    arithmetic_currently_selected_object()->value_2 = scls::string_to_formula(arithmetic_currently_selected_object()->input_2.get()->text());
                }
            }
            else if(arithmetic_currently_selected_object()->choice == std::string("decomposition")) {
                // GCD
                // Values
                if(arithmetic_currently_selected_object()->input_1.get() != 0) {
                    arithmetic_currently_selected_object()->value_1 = scls::string_to_formula(arithmetic_currently_selected_object()->input_1.get()->text());
                }
            }

            // Reset the object
            arithmetic_currently_selected_object()->choice_input_1.reset();
            arithmetic_currently_selected_object()->input_1.reset();
            arithmetic_currently_selected_object()->input_2.reset();
            for(int i = 0;i<static_cast<int>(arithmetic_created_object_for_selected_object().size());i++){
                arithmetic_calculator_elements_datas()->delete_child(arithmetic_created_object_for_selected_object()[i].get());
            }
            arithmetic_calculator_elements_datas_title()->set_text(std::string("Aucun élément sélectionné"));
        }
    }

    // Check the events of functions
    void Maths_Page::check_functions() {
        // Analyse a function
        if(functions_redaction_analyse()->is_clicked_during_this_frame(GLFW_MOUSE_BUTTON_LEFT)) {functions_redact();}

        // Add a chosen element
        if(functions_redaction_elements()->selection_modified()) {
            std::string current_choice = functions_redaction_elements()->currently_selected_objects_during_this_frame()[0].name();
            functions_redaction_elements()->unselect_object(functions_redaction_elements()->currently_selected_objects()[0]);
            functions_add_element(current_choice);
        }

        // Adds a created element
        if(functions_redaction_elements_creation()->selection_modified()) {
            std::string current_choice = functions_redaction_elements_creation()->currently_selected_objects_during_this_frame()[0].name();
            functions_redaction_elements_creation()->unselect_object(functions_redaction_elements_creation()->currently_selected_objects()[0]);
            functions_add_element_created(current_choice);
        }

        // Select a created element
        for(int i = 0;i<static_cast<int>(a_current_state.a_functions_created.size());i++) {
            if(a_current_state.a_functions_created[i].get()->connected_object()->is_clicked_during_this_frame(GLFW_MOUSE_BUTTON_LEFT)) {
                functions_select_function(a_current_state.a_functions_created[i]);
            }
        }
    }

    // Checks the events of hiding functions page
    void Maths_Page::check_functions_hiding() {
        if(currently_selected_function() != 0) {
            // Set the needed values
            currently_selected_function()->set_formula(scls::string_to_formula(functions_redaction_expression()->text()));
            currently_selected_function()->set_name(functions_redaction_name()->text());
        }
    }

    // Check the events of geometry
    void Maths_Page::check_geometry() {
        // Analyse the geometry
        if(geometry_redaction_analyse()->is_clicked_during_this_frame(GLFW_MOUSE_BUTTON_LEFT)) {geometry_redact();}

        // Add a chosen element
        if(geometry_redaction_elements()->selection_modified()) {
            std::string current_choice = geometry_redaction_elements()->currently_selected_objects_during_this_frame()[0].name();
            geometry_redaction_elements()->unselect_object(geometry_redaction_elements()->currently_selected_objects()[0]);
            add_element(current_choice);
        }

        // Add a created element
        if(geometry_redaction_elements_creation()->selection_modified()) {
            std::string current_choice = geometry_redaction_elements_creation()->currently_selected_objects_during_this_frame()[0].name();
            if(current_choice == "vector") {geometry_redaction_graphic()->set_operation_at_click(PLEOS_OPERATION_VECTOR);}
            else if(current_choice == "point"){geometry_redaction_graphic()->set_operation_at_click(PLEOS_OPERATION_POINT);}
            else if(current_choice == "form"){geometry_redaction_graphic()->set_operation_at_click(PLEOS_OPERATION_FORM);}
        }
        if(geometry_redaction_elements_creation()->currently_confirmed_objects().size() > 0) {
            std::string current_choice = geometry_redaction_elements_creation()->currently_confirmed_objects()[0];
            add_element_created(current_choice);
        }

        // Select a created element
        // Select a vector
        for(int i = 0;i<static_cast<int>(a_current_state.a_geometry_vectors_created.size());i++) {
            if(a_current_state.a_geometry_vectors_created[i].get()->connected_object()->is_clicked_during_this_frame(GLFW_MOUSE_BUTTON_LEFT)) {
                geometry_select_vector(a_current_state.a_geometry_vectors_created[i]);
            }
        }
        // Select a form 2D
        for(int i = 0;i<static_cast<int>(a_current_state.a_geometry_form_2d_created.size());i++) {
            if(a_current_state.a_geometry_form_2d_created[i].get()->connected_object()->is_clicked_during_this_frame(GLFW_MOUSE_BUTTON_LEFT)) {
                geometry_select_form_2d(a_current_state.a_geometry_form_2d_created[i]);
            }
        }

        // Check operation at click
        /*for(int i = 0;i<static_cast<int>(geometry_redaction_graphic()->created_objects_at_click_this_frame().size());i++) {
            std::shared_ptr<__Graphic_Object_Base> current_object = geometry_redaction_graphic()->created_objects_at_click_this_frame().at(i);
            geometry_vectors_created().push_back(current_object);
            geometry_select_vector(current_object);
            if(current_object.get()->type() == Vector_Type::VT_Vector) {
                std::string  final_choice = add_element_created_final_choice(std::string("vector"));
                add_element_created_button(final_choice, std::string("Vector"), PLEOS_MATHEMATICS_GEOMETRY_VECTOR);
            }
            else {
                std::string final_choice = add_element_created_final_choice(std::string("point"));
                add_element_created_button(final_choice, std::string("Point"), PLEOS_MATHEMATICS_GEOMETRY_POINT);
            }
        }//*/
    }

    // Checks the events of hiding geometry page
    void Maths_Page::check_geometry_hiding() {
        // Asserts
        if(current_page() != PLEOS_MATHS_GEOMETRY_REDACTION_PAGE){return;}

        if(currently_selected_form_2d() != 0) {
            // Get the points
            std::vector<std::string> cutted = scls::cut_string(geometry_redaction_form_points()->text(), ";");

            // Set the needed values
            currently_selected_form_2d()->points().clear();
            currently_selected_form_2d()->set_name(geometry_redaction_form_name()->text());
            for(int i = 0;i<static_cast<int>(cutted.size());i++){currently_selected_form_2d()->add_point(geometry_vector_created(cutted[i]));}
        }
        if(currently_selected_vector() != 0) {
            // Get the X and Y
            scls::Formula needed_x = scls::string_to_formula(geometry_redaction_vector_x()->text());
            scls::Formula needed_y = scls::string_to_formula(geometry_redaction_vector_y()->text());

            // Set the needed values
            currently_selected_vector()->set_name(geometry_redaction_vector_name()->text());
            currently_selected_vector()->set_x(needed_x.value_to_double());
            currently_selected_vector()->set_y(needed_y.value_to_double());
        }
    }

    // Checks the events of hiding all pages
    void Maths_Page::check_hiding() {
        // Check hiding
        if(current_page() == PLEOS_MATHS_ARITHMETIC_CALCULATOR_PAGE){check_arithmetic_hiding();}
        else if(current_page() == PLEOS_MATHS_GEOMETRY_REDACTION_PAGE){check_geometry_hiding();}
        else if(current_page() == PLEOS_MATHS_FUNCTIONS_REDACTION_PAGE){check_functions_hiding();}
    }

    // Checks the events of logic pages
    void Maths_Page::check_logic() {
        // Check the redactions
        if(current_page() == PLEOS_MATHS_LOGIC_DEFINITIONS_PAGE){check_redaction(logic_definitions_page());}
        if(current_page() == PLEOS_MATHS_LOGIC_LANGUAGE_PAGE){check_redaction(logic_language_page());}
    }

    // Check the events of navigation
    void Maths_Page::check_navigation() {
        // Check the selected page
        if(a_navigation.get()->selection_modified()){
            std::string page = a_navigation.get()->currently_selected_objects_during_this_frame()[0].name();
            display_page(page);
        }

        // Check the hub button
        if(hub_button()->is_clicked_during_this_frame(GLFW_MOUSE_BUTTON_LEFT)) {window_struct()->hide_all_pages_2d();window_struct()->display_page_2d("hub");}
    }

    // Checks the redaction parts
    void Maths_Page::check_redaction(scls::__GUI_Text_Metadatas* redaction_part) {
        // Asserts
        if(!redaction_part->is_clicked_during_this_frame(GLFW_MOUSE_BUTTON_LEFT)){return;}

        int x = window_struct()->mouse_x() - redaction_part->x_in_absolute_pixel();
        int y = (window_struct()->window_height() - window_struct()->mouse_y()) - redaction_part->y_in_absolute_pixel();
        std::shared_ptr<scls::__XML_Text_Base> current_xml = redaction_part->text_clicked_at_position(x, y);
        if(current_xml.get() != 0) {
            // Link balise
            if(current_xml.get()->xml_balise_name() == std::string("a")) {
                std::string link = std::string();
                for(int j = 0;j<static_cast<int>(current_xml.get()->xml_balise_attributes().size());j++) {
                    scls::XML_Attribute& current_attribute = current_xml.get()->xml_balise_attributes()[j];
                    std::string current_attribute_name = current_attribute.name;
                    std::string current_attribute_value = current_attribute.value;
                    if(current_attribute_value[0] == '\"'){current_attribute_value = current_attribute_value.substr(1, current_attribute_value.size() - 1);}
                    if(current_attribute_value[current_attribute_value.size()-1] == '\"'){current_attribute_value = current_attribute_value.substr(0, current_attribute_value.size() - 1);}

                    // Load the link
                    if(current_attribute_name == "href") {link = current_attribute_value;}
                }

                // Parse the link
                while(link.size() > 0 && (link[0] == '.' || link[0] == '/')){link = link.substr(1, link.size() - 1);}
                std::vector<std::string> cutted = scls::cut_string(link, "#");
                std::string page = cutted[0];
                // Display the page
                display_page(page);
            }
        }
    }

    // Displays a page by its name
    void Maths_Page::display_page(std::string page) {
        // Algebra pages
        if(page == "algebra_definitions"){display_algebra_definition_page();}
        GUI_OBJECT_SELECTION(display_algebra_equations_page(), "algebra_equations")
        else if(page == "algebra_matrices"){display_algebra_matrices_page();}
        GUI_OBJECT_SELECTION(display_algebra_series_page(), "algebra_series")
        GUI_OBJECT_SELECTION(display_algebra_solver_redaction(), "algebra_solver")
        GUI_OBJECT_SELECTION(display_algebra_structures_page(), "algebra_structures")
        // Arithmetic pages
        else if(page == "arithmetic_definitions"){display_arithmetic_definitions_page();}
        else if(page == "arithmetic_calculator"){display_arithmetic_calculator_page();}
        GUI_OBJECT_SELECTION(display_arithmetic_division_page(), "arithmetic_division")
        GUI_OBJECT_SELECTION(display_arithmetic_numbers_sets_page(), "arithmetic_numbers_sets")
        // Functions pages
        else if(page == "analysis_definitions"){display_functions_definitions_page();}
        else if(page == "analysis_exponential"){display_functions_exponential_page();}
        GUI_OBJECT_SELECTION(display_functions_redaction_graphic_page(), "analysis_graphic")
        GUI_OBJECT_SELECTION(display_functions_integration_page(), "analysis_integration")
        GUI_OBJECT_SELECTION(display_functions_redaction_page(), "analysis_redaction")
        // Geometry pages
        else if(page == "geometry_complex_numbers"){display_geometry_complex_numbers_page();}
        else if(page == "geometry_definitions"){display_geometry_definitions_page();}
        else if(page == "geometry_redaction"){display_geometry_redaction_page();}
        else if(page == "geometry_redaction_graphic"){display_geometry_redaction_graphic_page();}
        else if(page == "geometry_vector"){display_geometry_vector_page();}
        // Home pages
        GUI_OBJECT_SELECTION(display_home_definition_page(), "home")
        // Logic pages
        else if(page == "logic_definitions"){display_logic_definitions_page();}
        else if(page == "logic_language"){display_logic_language_page();}
        GUI_OBJECT_SELECTION(display_logic_propositional_page(), "logic_propositional")
        else if(page == "logic_set_theory"){display_logic_set_theory_page();}
        // Random pages
        GUI_OBJECT_SELECTION(display_random_probability_page(), "random_probability")
        GUI_OBJECT_SELECTION(display_random_probability_law_page(), "random_probability_law")
        // School pages
        GUI_OBJECT_SELECTION(display_school_term_1_page(), "maths_school_term_1")
        GUI_OBJECT_SELECTION(display_school_term_2_page(), "maths_school_term_2")

        // If the page is unknown
        else {scls::print("PLEOS Maths", std::string("Unknown page \"") + page + std::string("\"."));return;}


        // Handle navigation
        if(!a_navigation.get()->contains_selected_object(page)){a_navigation.get()->select_object(page);}
    }

    // Update the events
    void Maths_Page::update_event() {
        // Basic events
        scls::GUI_Page::update_event();
        check_navigation();

        if(window_struct()->key_pressed_during_this_frame("up arrow")){window_struct()->hide_all_pages_2d();window_struct()->display_page_2d("notes");}

        if(current_page() != PLEOS_MATHS_ALGEBRA_SOLVER_PAGE && current_page() != PLEOS_MATHS_ARITHMETIC_CALCULATOR_PAGE && current_page() != PLEOS_MATHS_ARITHMETIC_CALCULATOR_CONGRUENCE_CIRCLE_PAGE && window_struct()->key_pressed_during_this_frame("left control")){display_geometry_pythagorean_theorem_demonstration();}

        // Check the good page
        if(current_page() == PLEOS_MATHS_ALGEBRA_EQUATIONS_PAGE || current_page() == PLEOS_MATHS_ALGEBRA_SOLVER_PAGE){check_algebra();}
        else if(current_page() == PLEOS_MATHS_ARITHMETIC_CALCULATOR_PAGE || current_page() == PLEOS_MATHS_ARITHMETIC_CALCULATOR_CONGRUENCE_CIRCLE_PAGE){check_arithmetic();}
        else if(current_page() == PLEOS_MATHS_FUNCTIONS_REDACTION_PAGE){check_functions();}
        else if(current_page() == PLEOS_MATHS_GEOMETRY_DEFINITION_PAGE){check_redaction(geometry_definitions_page());}
        else if(current_page() == PLEOS_MATHS_GEOMETRY_REDACTION_PAGE){check_geometry();}
        else if(current_page() == PLEOS_MATHS_GEOMETRY_VECTOR_PAGE){check_redaction(geometry_vector_page());}
        else if(current_page() == PLEOS_MATHS_LOGIC_DEFINITIONS_PAGE || current_page() == PLEOS_MATHS_LOGIC_LANGUAGE_PAGE){check_logic();}
    }
}
