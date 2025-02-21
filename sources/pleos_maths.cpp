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

    // Loads an object in a page from XML
    std::shared_ptr<scls::GUI_Object> Maths_Page::__create_loaded_object_from_type(std::string object_name, std::string object_type, scls::GUI_Object* parent) {
        // Algebra
        if(object_name == "maths_algebra_definitions_body") {a_algebra_definitions_page = *parent->new_object<scls::GUI_Text>(object_name);return a_algebra_definitions_page;}
        else if(object_name == "maths_algebra_matrices_body") {a_algebra_matrices_page = *parent->new_object<scls::GUI_Text>(object_name);return a_algebra_matrices_page;}

        // Arithmetic
        else if(object_name == "maths_arithmetic_definitions_body") {a_arithmetic_definitions_page = *parent->new_object<scls::GUI_Text>(object_name);return a_arithmetic_definitions_page;}
        else if(object_name == "maths_arithmetic_calculator_body"){a_arithmetic_calculator_page = *parent->new_object<scls::GUI_Text>(object_name);return a_arithmetic_calculator_page;}
        else if(object_name == "maths_arithmetic_calculator_input"){a_arithmetic_calculator_input = *parent->new_object<scls::GUI_Text_Input>(object_name);return a_arithmetic_calculator_input;}
        else if(object_name == "maths_arithmetic_calculator_redaction"){a_arithmetic_calculator_redaction = *parent->new_object<scls::GUI_Text>(object_name);return a_arithmetic_calculator_redaction;}

        // Functions
        else if(object_name == "maths_functions_definitions_body") {a_functions_definitions_page = *parent->new_object<scls::GUI_Text>(object_name);return a_functions_definitions_page;}
        else if(object_name == "maths_functions_exponential_body") {a_functions_exponential_page = *parent->new_object<scls::GUI_Text>(object_name);return a_functions_exponential_page;}
        else if(object_name == "maths_functions_forms_body") {a_functions_forms_page = *parent->new_object<scls::GUI_Text>(object_name);return a_functions_forms_page;}
        else if(object_name == "maths_functions_redaction_body") {a_functions_redaction_page = *parent->new_object<scls::GUI_Object>(object_name);return a_functions_redaction_page;}
        else if(object_name == "maths_functions_redaction") {a_functions_redaction = *parent->new_object<scls::GUI_Text>(object_name);return a_functions_redaction;}
        else if(object_name == "maths_functions_redaction_analyse") {a_functions_redaction_analyse = *parent->new_object<scls::GUI_Text>(object_name);return a_functions_redaction_analyse;}
        else if(object_name == "maths_functions_redaction_elements"){a_functions_redaction_elements = *parent->new_object<scls::GUI_Scroller_Choice>(object_name);return a_functions_redaction_elements;}
        else if(object_name == "maths_functions_redaction_elements_chosen"){a_functions_redaction_elements_chosen = *parent->new_object<scls::GUI_Scroller_Choice>(object_name);return a_functions_redaction_elements_chosen;}
        else if(object_name == "maths_functions_redaction_elements_created"){a_functions_redaction_elements_created = *parent->new_object<scls::GUI_Scroller_Choice>(object_name);return a_functions_redaction_elements_created;}
        else if(object_name == "maths_functions_redaction_elements_creation"){a_functions_redaction_elements_creation = *parent->new_object<scls::GUI_Scroller_Choice>(object_name);return a_functions_redaction_elements_creation;}
        else if(object_name == "maths_functions_redaction_expression"){a_functions_redaction_expression = *parent->new_object<scls::GUI_Text_Input>(object_name);return a_functions_redaction_expression;}
        else if(object_name == "maths_functions_redaction_graphic"){a_functions_redaction_graphic = *parent->new_object<Graphic>(object_name);return a_functions_redaction_graphic;}
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
        else if(object_name == "maths_geometry_redaction_graphic"){a_geometry_redaction_graphic = *parent->new_object<Graphic>(object_name);return a_geometry_redaction_graphic;}
        else if(object_name == "maths_geometry_redaction_vector"){a_geometry_redaction_vector = *parent->new_object<scls::GUI_Object>(object_name);return a_geometry_redaction_vector;}
        else if(object_name == "maths_geometry_redaction_vector_name"){a_geometry_redaction_vector_name = *parent->new_object<scls::GUI_Text_Input>(object_name);return a_geometry_redaction_vector_name;}
        else if(object_name == "maths_geometry_redaction_vector_x"){a_geometry_redaction_vector_x = *parent->new_object<scls::GUI_Text_Input>(object_name);return a_geometry_redaction_vector_x;}
        else if(object_name == "maths_geometry_redaction_vector_y"){a_geometry_redaction_vector_y = *parent->new_object<scls::GUI_Text_Input>(object_name);return a_geometry_redaction_vector_y;}
        else if(object_name == "maths_geometry_vector_body"){a_geometry_vector_page = *parent->new_object<scls::GUI_Text>(object_name);return a_geometry_vector_page;}

        // Logic
        else if(object_name == "maths_logic_definitions_body") {a_logic_definitions_page = *parent->new_object<scls::GUI_Text>(object_name);return a_logic_definitions_page;}
        else if(object_name == "maths_logic_language_body"){a_logic_language_page = *parent->new_object<scls::GUI_Text>(object_name);return a_logic_language_page;}

        // Pages
        else if(object_name == "maths_algebra_page"){a_algebra_page = *parent->new_object<scls::GUI_Object>(object_name);return a_algebra_page;}
        else if(object_name == "maths_arithmetic_page"){a_arithmetic_page = *parent->new_object<scls::GUI_Object>(object_name);return a_arithmetic_page;}
        else if(object_name == "maths_functions_page") {a_functions_page = *parent->new_object<scls::GUI_Object>(object_name);return a_functions_page;}
        else if(object_name == "maths_geometry_page"){a_geometry_page = *parent->new_object<scls::GUI_Object>(object_name);return a_geometry_page;}
        else if(object_name == "maths_logic_page"){a_logic_page = *parent->new_object<scls::GUI_Object>(object_name);return a_logic_page;}

        // Navigation
        else if(object_name == "maths_hub"){a_hub_button = *parent->new_object<scls::GUI_Text>(object_name);return a_hub_button;}
        else if(object_name == "maths_navigation") {a_navigation = *parent->new_object<scls::GUI_Scroller_Choice>(object_name);return a_navigation;}

        return scls::GUI_Page::__create_loaded_object_from_type(object_name, object_type, parent);
    }

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

    // Adds an element to create
    void Maths_Page::add_element_created(std::string current_choice) {
        // Creation name
        std::string final_choice = current_choice;
        std::string needed_title = "";
        int object_created = 0;
        if(current_choice == "vector"){
            final_choice += std::string("-") + std::to_string(geometry_redaction_elements_created()->count_object_similar("vector", "-"));
            needed_title = std::string("Vecteur");
            object_created = PLEOS_MATHEMATICS_GEOMETRY_VECTOR;

            // Create the needed vector
            geometry_vectors_created().push_back(std::make_shared<pleos::Vector>("", 1, 1));
            geometry_select_vector(geometry_vectors_created()[geometry_vectors_created().size() - 1]);
        }
        else if(current_choice == "form"){
            final_choice += std::string("-") + std::to_string(geometry_redaction_elements_created()->count_object_similar("form", "-"));
            needed_title = std::string("Forme");
            object_created = PLEOS_MATHEMATICS_GEOMETRY_FORM;

            // Create the needed form
            geometry_form_2d_created().push_back(std::make_shared<pleos::Form_2D>(""));
            geometry_select_form_2d(geometry_form_2d_created()[geometry_form_2d_created().size() - 1]);
        }
        else if(current_choice == "point"){
            final_choice += std::string("-") + std::to_string(geometry_redaction_elements_created()->count_object_similar("point", "-"));
            needed_title = std::string("Point");
            object_created = PLEOS_MATHEMATICS_GEOMETRY_POINT;

            // Create the needed vector
            geometry_vectors_created().push_back(std::make_shared<pleos::Vector>("", 1, 1));
            geometry_vectors_created()[geometry_vectors_created().size() - 1].get()->set_type(Vector_Type::VT_Point);
            geometry_select_vector(geometry_vectors_created()[geometry_vectors_created().size() - 1]);
        }

        // Get the good current choice
        std::shared_ptr<scls::GUI_Text>* object = geometry_redaction_elements_created()->add_object(final_choice, needed_title);
        if(object != 0){
            if(object_created == PLEOS_MATHEMATICS_GEOMETRY_FORM){currently_selected_form_2d()->set_connected_object(*object);}
            else if(object_created == PLEOS_MATHEMATICS_GEOMETRY_POINT || object_created == PLEOS_MATHEMATICS_GEOMETRY_VECTOR){currently_selected_vector()->set_connected_object(*object);}
        }
    }

    // Function called after the XML loading
    void Maths_Page::after_xml_loading(){
        scls::GUI_Page::after_xml_loading();
        hide_sub_pages(true);
        a_functions_redaction_elements_chosen.get()->unselected_objects_style().cursor = GLFW_ARROW_CURSOR;
        geometry_redaction_graphic()->set_operation_at_click(PLEOS_OPERATION_VECTOR);
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
        for(int i = 0;i<static_cast<int>(functions_created().size());i++) {
            redaction += functions_created()[i].get()->introduction();
            if(i < static_cast<int>(functions_created().size()) - 1){redaction += std::string(" ");}
        } redaction += std::string("</br></br>");

        // Get datas for each functions
        for(int i = 0;i<static_cast<int>(functions_created().size());i++) {
            std::shared_ptr<pleos::Function_Studied> needed_function = functions_created()[i];
            std::string& function_name = needed_function.get()->function_name;
            scls::Formula& needed_formula = needed_function.get()->function_formula;

            // Do the redaction
            redaction += std::string("Nous avons la fonction ") + function_name + std::string(" tel que :</br></br>");
            redaction += std::string("<math><mi>") + function_name + std::string("(x") + std::string(")</mi><mo>=</mo>") + needed_formula.to_mathml() + std::string("</math></br></br>");

            // Add the needed arguments
            std::vector<scls::GUI_Scroller_Choice::GUI_Scroller_Single_Choice>& objects = functions_redaction_elements_chosen()->objects();
            for(int j = 0;j<static_cast<int>(objects.size());j++) {
                std::string complete_name = objects[j].name(); std::vector<std::string> cutted = scls::cut_string(complete_name, std::string("-"));
                std::string current_function_name = reinterpret_cast<scls::GUI_Text_Input*>(objects[j].object()->child_by_name(objects[j].object()->name() + "_input_name"))->text();
                std::string type = cutted[0];

                if(current_function_name == function_name) {
                    // Analyse the argument
                    if(type == "definition_set") {function_definition_set(needed_function.get(), &redaction);}
                    else if(type == "image") {
                        // Calculate an image of the function
                        scls::Formula needed_value = scls::string_to_formula(reinterpret_cast<scls::GUI_Text_Input*>(objects[j].object()->child_by_name(objects[j].object()->name() + "_input_x"))->text());
                        function_image(*needed_function.get(), needed_value, redaction);
                    }
                    else if(type == "roots") {function_roots(needed_function.get(), redaction);}
                    redaction += std::string("</br></br>");
                }
            }

            // Check the graphic part
            if(needed_function.get()->definition_set.get() == 0){function_definition_set(needed_function.get(), 0);}
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
        functions_redaction_expression()->set_text(needed_function.get()->function_formula.to_std_string());
        functions_redaction_name()->set_text(needed_function.get()->function_name);
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
        if(static_cast<int>(geometry_vectors_created().size()) > 1){redaction += std::string("Nous allons définir ") + std::to_string(geometry_vectors_created().size()) + std::string(" vecteurs. ");}
        for(int i = 0;i<static_cast<int>(geometry_vectors_created().size());i++) {
            redaction += geometry_vectors_created()[i].get()->introduction();
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
                std::shared_ptr<Vector> needed_vector = geometry_vector_created(needed_vector_name);
                if(needed_vector.get() != 0){needed_vector.get()->norm(&redaction);}
            }
            else if(type == "vector_complex_number") {
                std::string needed_vector_name = reinterpret_cast<scls::GUI_Text_Input*>(objects[i].object()->child_by_name(objects[i].object()->name() + "_name"))->text();
                std::shared_ptr<Vector> needed_vector = geometry_vector_created(needed_vector_name);
                if(needed_vector.get() != 0){needed_vector.get()->complex_number(&redaction);}
            }
            else if(type == "vector_angle") {
                std::string needed_vector_name = reinterpret_cast<scls::GUI_Text_Input*>(objects[i].object()->child_by_name(objects[i].object()->name() + "_name"))->text();
                std::shared_ptr<Vector> needed_vector = geometry_vector_created(needed_vector_name);
                needed_vector_name = reinterpret_cast<scls::GUI_Text_Input*>(objects[i].object()->child_by_name(objects[i].object()->name() + "_reference"))->text();
                std::shared_ptr<Vector> needed_reference = geometry_vector_created(needed_vector_name);
                if(needed_vector.get() != 0 && needed_reference.get() != 0) {
                    needed_vector.get()->angle(needed_reference.get(), &redaction);
                }
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
            for(int i = 0;i<static_cast<int>(needed_form_2d.get()->points().size());i++){needed_points+=needed_form_2d.get()->points()[i].get()->name();if(i<needed_form_2d.get()->points().size()-1){needed_points+=std::string(";");}}
            geometry_redaction_form_points()->set_text(needed_points);
        }
        else {geometry_redaction_form()->set_visible(false);geometry_redaction_vector()->set_visible(false);}
    }

    // Selects a geometry vector
    void Maths_Page::geometry_select_vector(std::shared_ptr<pleos::Vector> needed_vector) {
        check_geometry_hiding();
        currently_selected_vector_shared_ptr() = needed_vector;

        if(needed_vector.get() != 0) {
            // Set the needed text
            geometry_redaction_form()->set_visible(false);geometry_redaction_vector()->set_visible(true);
            geometry_redaction_vector_name()->set_text(needed_vector.get()->name());
            geometry_redaction_vector_x()->set_text(needed_vector.get()->x()->to_std_string());
            geometry_redaction_vector_y()->set_text(needed_vector.get()->y()->to_std_string());
        }
        else {geometry_redaction_form()->set_visible(false);geometry_redaction_vector()->set_visible(false);}
    }

    //******************
    //
    // Check the events
    //
    //******************

    // Checks the events of arithmetic
    void Maths_Page::check_arithmetic() {
        if(window_struct()->key_pressed_during_this_frame("left control")) {
            // Do the calculation in the calculator
            std::string needed_text = arithmetic_calculator_input()->text();
            scls::Formula needed_formula = scls::string_to_formula(needed_text);
            std::string current_text = arithmetic_calculator_redaction()->text();
            if(current_text.size() == 29 && current_text == std::string("Pas de rédaction à afficher")){current_text = std::string("");}
            if(current_text != ""){current_text += std::string("</br>");}
            current_text += needed_formula.to_std_string();
            arithmetic_calculator_redaction()->set_text(current_text);
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
                if(current_choice == "definition_set"){
                    needed_height = 60;
                    needed_title = std::string("Ensemble de définition");
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

        // Check the redactions
        if(current_page() == PLEOS_MATHS_GEOMETRY_DEFINITION_PAGE && geometry_definitions_page()->is_clicked_during_this_frame(GLFW_MOUSE_BUTTON_LEFT)){check_redaction(geometry_definitions_page());}
        if(current_page() == PLEOS_MATHS_GEOMETRY_VECTOR_PAGE && geometry_vector_page()->is_clicked_during_this_frame(GLFW_MOUSE_BUTTON_LEFT)){check_redaction(geometry_vector_page());}

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
            currently_selected_vector()->set_x(needed_x);
            currently_selected_vector()->set_y(needed_y);
        }
    }

    // Checks the events of hiding all pages
    void Maths_Page::check_hiding() {
        // Check geometry hiding
        if(current_page() == PLEOS_MATHS_GEOMETRY_REDACTION_PAGE){check_geometry_hiding();}
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

            // Algebra pages
            if(page == "algebra_definitions"){display_algebra_definition_page();}
            else if(page == "algebra_matrices"){display_algebra_matrices_page();}
            // Arithmetic pages
            else if(page == "arithmetic_definitions"){display_arithmetic_definitions_page();}
            else if(page == "arithmetic_calculator"){display_arithmetic_calculator_page();}
            // Functions pages
            else if(page == "functions_definitions"){display_functions_definitions_page();}
            else if(page == "functions_exponential"){display_functions_exponential_page();}
            else if(page == "functions_forms"){display_functions_forms_page();}
            else if(page == "functions_graphic"){display_functions_redaction_graphic_page();}
            else if(page == "functions_redaction"){display_functions_redaction_page();}
            // Geometry pages
            else if(page == "geometry_complex_numbers"){display_geometry_complex_numbers_page();}
            else if(page == "geometry_definitions"){display_geometry_definitions_page();}
            else if(page == "geometry_redaction"){display_geometry_redaction_page();}
            else if(page == "geometry_redaction_graphic"){display_geometry_redaction_graphic_page();}
            else if(page == "geometry_vector"){display_geometry_vector_page();}
            // Logic pages
            else if(page == "logic_definitions"){display_logic_definitions_page();}
            else if(page == "logic_language"){display_logic_language_page();}
        }

        // Check the hub button
        if(hub_button()->is_clicked_during_this_frame(GLFW_MOUSE_BUTTON_LEFT)) {window_struct()->hide_all_pages_2d();window_struct()->display_page_2d("hub");}
    }

    // Checks the redaction parts
    void Maths_Page::check_redaction(scls::GUI_Text* redaction_part) {
        // Asserts
        if(!redaction_part->is_clicked_during_this_frame(GLFW_MOUSE_BUTTON_LEFT)){return;}

        int x = window_struct()->mouse_x() - redaction_part->x_in_absolute_pixel();
        int y = (window_struct()->window_height() - window_struct()->mouse_y()) - redaction_part->y_in_absolute_pixel();
        std::shared_ptr<scls::XML_Text> current_xml = redaction_part->text_clicked_at_position(x, y);
        if(current_xml.get() != 0) {std::cout << "R " << current_xml.get() << " " << current_xml.get()->xml_balise() << " " << current_xml.get()->text() << std::endl;}
    }

    // Update the events
    void Maths_Page::update_event() {
        // Basic events
        scls::GUI_Page::update_event();
        check_navigation();

        if(current_page() != PLEOS_MATHS_ARITHMETIC_CALCULATOR_PAGE && window_struct()->key_pressed_during_this_frame("left control")){display_geometry_pythagorean_theorem_demonstration();}

        // Check the good page
        if(current_page() == PLEOS_MATHS_ARITHMETIC_CALCULATOR_PAGE){check_arithmetic();}
        else if(current_page() == PLEOS_MATHS_FUNCTIONS_REDACTION_PAGE){check_functions();}
        else if(current_page() == PLEOS_MATHS_GEOMETRY_REDACTION_PAGE || current_page() == PLEOS_MATHS_GEOMETRY_DEFINITION_PAGE){check_geometry();}
        else if(current_page() == PLEOS_MATHS_LOGIC_DEFINITIONS_PAGE || current_page() == PLEOS_MATHS_LOGIC_LANGUAGE_PAGE){check_logic();}
    }
}
