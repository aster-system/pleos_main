//******************
//
// pleos_maths.h
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
// This file contains the page of the Maths plugin.
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

#ifndef PLEOS_MATHS
#define PLEOS_MATHS

// Include PLEOS Libs
#include "../../pleos_libs/pleos_mathematics.h"
#include "../../pleos_libs/pleos_table.h"
#include "../../pleos_libs/pleos_text.h"

// Possible pages
#define PLEOS_MATHS_HOME_PAGE 0
// Logic pages
#define PLEOS_MATHS_LOGIC_PAGE 100
#define PLEOS_MATHS_LOGIC_DEFINITIONS_PAGE 101
#define PLEOS_MATHS_LOGIC_SET_THEORY_PAGE 102
#define PLEOS_MATHS_LOGIC_LANGUAGE_PAGE 110
// Algebra pages
#define PLEOS_MATHS_ALGEBRA_STRUCTURES_PAGE 503
#define PLEOS_MATHS_ALGEBRA_EQUATIONS_PAGE 505
#define PLEOS_MATHS_ALGEBRA_SOLVER_PAGE 580
// Arithmetic pages
#define PLEOS_MATHS_ARITHMETIC_PAGE 200
#define PLEOS_MATHS_ARITHMETIC_NUMBERS_SETS_PAGE 205
#define PLEOS_MATHS_ARITHMETIC_DIVISION_PAGE 210
#define PLEOS_MATHS_ARITHMETIC_CALCULATOR_PAGE 250
#define PLEOS_MATHS_ARITHMETIC_CALCULATOR_CONGRUENCE_CIRCLE_PAGE 255
// Functions pages
#define PLEOS_MATHS_FUNCTIONS_PAGE 300
#define PLEOS_MATHS_FUNCTIONS_REDACTION_PAGE 301
#define PLEOS_MATHS_FUNCTION_INTEGRATION_PAGE 315
// Geometry pages
#define PLEOS_MATHS_GEOMETRY_PAGE 400
#define PLEOS_MATHS_GEOMETRY_DEFINITION_PAGE 401
#define PLEOS_MATHS_GEOMETRY_VECTOR_PAGE 402
#define PLEOS_MATHS_GEOMETRY_REDACTION_PAGE 450
// Random pages
#define PLEOS_MATHS_RANDOM_PAGE 500

// The namespace "pleos" is used to simplify the all.
namespace pleos {

    class Maths_Page : public scls::GUI_Page {
        // Class representating the "Maths" page for PLEOS
    public:

        // Maths_Page constructor
        Maths_Page(scls::_Window_Advanced_Struct* window_struct, std::string name):scls::GUI_Page(window_struct, name){};
        // Loads an object in a page from XML
        virtual std::shared_ptr<scls::GUI_Object> __create_loaded_object_from_type(std::string object_name, std::string object_type, scls::GUI_Object* parent);

        //******************
        //
        // Algebra handling
        //
        //******************

        // Redacts the needed redaction for the algebra part
        void algebra_redact();

        //******************
        //
        // Arithmetic handling
        //
        //******************

        // Adds an element to create
        void arithmetic_add_element_created(std::string current_choice);

        // Updates the congruence circle
        void arithmetic_update_congruence_circle();
        // Redacts the needed redaction for the arithmetic part
        void arithmetic_redact();
        // Selects an arithmetic object
        void arithmetic_select_object(std::shared_ptr<Arithmetic_Object> arithmetic_object);

        // Getters and setters
        inline std::vector<std::shared_ptr<Arithmetic_Object>>& arithmetic_objects_created(){return a_current_state.a_arithmetic_objects_created;};
        inline Arithmetic_Object* arithmetic_currently_selected_object(){return a_current_state.a_arithmetic_currently_selected_object.get();};

        //******************
        //
        // Functions handling
        //
        //******************

        // Adds an element to analyse
        void functions_add_element(std::string current_choice);
        // Adds an element to create
        void functions_add_element_created(std::string current_choice);

        // Redacts the needed redaction for the functions part
        void functions_redact();
        // Resets the function part of the software
        inline void functions_reset(){functions_add_element_created(std::string("function"));};
        // Selects a functions vector
        void functions_select_function(std::shared_ptr<pleos::Function_Studied> needed_function);

        // Getters and setters
        inline pleos::Function_Studied* currently_selected_function() const {return a_current_state.a_functions_currently_selected_function.get();}
        inline std::shared_ptr<pleos::Function_Studied>& currently_selected_function_shared_ptr() {return a_current_state.a_functions_currently_selected_function;}
        inline std::shared_ptr<pleos::Function_Studied> function_created(std::string vector_name) {for(int i = 0;i<static_cast<int>(a_current_state.a_functions_created.size());i++){if(a_current_state.a_functions_created[i].get()->name() == vector_name){return a_current_state.a_functions_created[i];}}return std::shared_ptr<pleos::Function_Studied>();};
        inline std::vector<std::shared_ptr<pleos::Function_Studied>>& functions_created() {return a_current_state.a_functions_created;};

        //******************
        //
        // Geometry handling
        //
        //******************

        // Adds an element to analyse
        void add_element(std::string current_choice);
        // Adds an element to create
        void add_element_created_button(std::string final_choice, std::string needed_title, int object_created);
        std::string add_element_created_final_choice(std::string current_choice);
        void add_element_created(std::string current_choice);

        // Shows a demonstration of the Pythagoras theorem
        void display_geometry_pythagorean_theorem_demonstration();

        // Redacts the needed redaction for the geometry part
        void geometry_redact();
        // Resets the geometry part
        inline void geometry_reset(){geometry_redaction_elements_created()->reset();geometry_redaction_elements_chosen()->reset();a_current_state.a_geometry_form_2d_created.clear();a_current_state.a_geometry_vectors_created.clear();currently_selected_form_2d_shared_ptr().reset();currently_selected_vector_shared_ptr().reset();};
        // Selects a geometry form 2D
        void geometry_select_form_2d(std::shared_ptr<pleos::Form_2D> needed_form_2d);
        inline void geometry_select_form_2d(){geometry_select_form_2d(std::shared_ptr<pleos::Form_2D>());};
        // Selects a geometry vector
        void geometry_select_vector(std::shared_ptr<pleos::Vector> needed_vector);
        inline void geometry_select_vector(){geometry_select_vector(std::shared_ptr<pleos::Vector>());};

        // Getters and setters
        inline pleos::Form_2D* currently_selected_form_2d() const {return a_current_state.a_geometry_currently_selected_form_2d.get();}
        inline std::shared_ptr<pleos::Form_2D>& currently_selected_form_2d_shared_ptr() {return a_current_state.a_geometry_currently_selected_form_2d;}
        inline pleos::Vector* currently_selected_vector() const {return a_current_state.a_geometry_currently_selected_vector.get();}
        inline std::shared_ptr<pleos::Vector>& currently_selected_vector_shared_ptr() {return a_current_state.a_geometry_currently_selected_vector;}
        inline std::vector<std::shared_ptr<pleos::Form_2D>>& geometry_form_2d_created() {return a_current_state.a_geometry_form_2d_created;};
        inline std::shared_ptr<pleos::Vector> geometry_vector_created(std::string vector_name) {for(int i = 0;i<static_cast<int>(a_current_state.a_geometry_vectors_created.size());i++){if(a_current_state.a_geometry_vectors_created[i].get()->name() == vector_name){return a_current_state.a_geometry_vectors_created[i];}}return std::shared_ptr<Vector>();};
        inline std::vector<std::shared_ptr<pleos::Vector>>& geometry_vectors_created() {return a_current_state.a_geometry_vectors_created;};

        //******************
        //
        // Check the events
        //
        //******************

        // Function called after the XML loading
        virtual void after_xml_loading();
        // Checks the events of each pages
        void check_algebra();
        void check_arithmetic();
        void check_functions();
        void check_geometry();
        void check_logic();
        // Checks the events of hiding each pages
        void check_arithmetic_hiding();
        void check_functions_hiding();
        void check_geometry_hiding();
        void check_hiding();
        // Checks the events of navigation
        void check_navigation();
        // Checks the redaction parts
        void check_redaction(scls::__GUI_Text_Metadatas* redaction_part);
        // Updates the events
        virtual void update_event();

        //******************
        //
        // Handle the pages
        //
        //******************

        // Displays the algebra page
        void display_algebra_page(){hide_all();algebra_page()->set_visible(true);};
        void display_algebra_definition_page(){display_algebra_page();algebra_definitions_page()->set_visible(true);};
        void display_algebra_matrices_page(){display_algebra_page();algebra_matrices_page()->set_visible(true);};
        // Displays the arithmetic page
        void display_arithmetic_page(){hide_all();arithmetic_page()->set_visible(true);};
        void display_arithmetic_calculator_page(){set_current_page(PLEOS_MATHS_ARITHMETIC_CALCULATOR_PAGE);display_arithmetic_page();arithmetic_calculator_page()->set_visible(true);}
        void display_arithmetic_definitions_page(){display_arithmetic_page();arithmetic_definitions_page()->set_visible(true);}
        // Displays the functions page
        void display_functions_page(){hide_all();functions_page()->set_visible(true);};
        void display_functions_definitions_page(){display_functions_page();functions_definitions_page()->set_visible(true);};
        void display_functions_exponential_page(){display_functions_page();functions_exponential_page()->set_visible(true);};
        void display_functions_forms_page(){display_functions_page();functions_forms_page()->set_visible(true);};
        void display_functions_redaction_page(bool reset){unsigned short last_page=current_page();set_current_page(PLEOS_MATHS_FUNCTIONS_REDACTION_PAGE);display_functions_page();functions_redaction_page()->load_with_children();functions_redaction_page()->set_visible(true);functions_redaction()->set_visible(true);if(last_page!=PLEOS_MATHS_FUNCTIONS_REDACTION_PAGE&&reset){functions_reset();}};
        inline void display_functions_redaction_page(){display_functions_redaction_page(true);};
        void display_functions_redaction_graphic_page(bool reset){unsigned short last_page=current_page();set_current_page(PLEOS_MATHS_FUNCTIONS_REDACTION_PAGE);display_functions_page();functions_redaction_page()->load_with_children();functions_redaction_page()->set_visible(true);functions_redaction_graphic()->set_visible(true);if(last_page!=PLEOS_MATHS_FUNCTIONS_REDACTION_PAGE&&reset){functions_reset();}};
        inline void display_functions_redaction_graphic_page(){display_functions_redaction_graphic_page(true);};
        // Displays the geometry page
        void display_geometry_page(){hide_all();geometry_page()->set_visible(true);};
        void display_geometry_complex_numbers_page(){display_geometry_page();geometry_complex_numbers_page()->set_visible(true);};
        void display_geometry_definitions_page(){display_geometry_page();set_current_page(PLEOS_MATHS_GEOMETRY_DEFINITION_PAGE);geometry_definitions_page()->set_visible(true);};
        void display_geometry_redaction_graphic_page(){set_current_page(PLEOS_MATHS_GEOMETRY_REDACTION_PAGE);display_geometry_page();geometry_redaction_page()->set_visible(true);geometry_redaction_graphic()->set_visible(true);};
        void display_geometry_redaction_page(){set_current_page(PLEOS_MATHS_GEOMETRY_REDACTION_PAGE);display_geometry_page();geometry_redaction_page()->set_visible(true);geometry_redaction()->set_visible(true);};
        void display_geometry_vector_page(){display_geometry_page();set_current_page(PLEOS_MATHS_GEOMETRY_VECTOR_PAGE);geometry_vector_page()->set_visible(true);};
        // Displays the logic page
        void display_logic_page(){hide_all();logic_page()->set_visible(true);set_current_page(PLEOS_MATHS_LOGIC_PAGE);};
        void display_logic_definitions_page(){display_logic_page();set_current_page(PLEOS_MATHS_LOGIC_DEFINITIONS_PAGE);logic_definitions_page()->set_visible(true);};
        void display_logic_language_page(){display_logic_page();set_current_page(PLEOS_MATHS_LOGIC_LANGUAGE_PAGE);logic_language_page()->set_visible(true);};
        void display_logic_set_theory_page(){display_logic_page();set_current_page(PLEOS_MATHS_LOGIC_SET_THEORY_PAGE);logic_set_theory_page()->set_visible(true);};

        // Hides all the pages
        void hide_all(){hide_sub_pages(true);check_hiding();};
        // Displays a page by its name
        void display_page(std::string needed_page);

        // Returns / resets the current page
        inline unsigned short current_page() const {return a_current_state.current_page;};
        inline void set_current_page(unsigned short new_page) {a_current_state.current_page = new_page;};

        //******************
        //
        // GUI handling
        //
        //******************

        // Returns navigation
        inline scls::GUI_Text* hub_button() const {return a_hub_button.get();};

        // Returns pages
        inline scls::GUI_Text* functions_definitions_page() const {return a_functions_definitions_page.get();};
        inline scls::GUI_Object* functions_forms_page() const {return a_functions_forms_page.get();};
        inline scls::GUI_Object* functions_page() const {return a_functions_page.get();};
        inline scls::GUI_Object* functions_redaction_page() const {return a_functions_redaction_page.get();};
        inline scls::GUI_Object* geometry_page() const {return a_geometry_page.get();};
        GUI_PAGE(scls::GUI_Object, a_home_page, PLEOS_MATHS_HOME_PAGE, home_page, display_home_page, hide_all);
        inline scls::GUI_Object* logic_page() const {return a_logic_page.get();};
        inline scls::GUI_Scroller_Choice* navigation() const {return a_navigation.get();};

        // Returns algebra
        inline scls::GUI_Object* algebra_page() const {return a_algebra_page.get();};
        inline scls::GUI_Text* algebra_definitions_page() const {return a_algebra_definitions_page.get();};
        inline scls::GUI_Text* algebra_matrices_page() const {return a_algebra_matrices_page.get();};
        GUI_PAGE(scls::GUI_Text_Base<Text>, a_algebra_equations_page, PLEOS_MATHS_ALGEBRA_EQUATIONS_PAGE, algebra_equations_page, display_algebra_equations_page, display_algebra_page);
        GUI_PAGE(scls::GUI_Object, a_algebra_solver_page, PLEOS_MATHS_ALGEBRA_SOLVER_PAGE, algebra_solver_page, display_algebra_solver_page, display_algebra_page);
        GUI_PAGE(scls::GUI_Object, a_algebra_structures_page, PLEOS_MATHS_ALGEBRA_STRUCTURES_PAGE, algebra_structures_page, display_algebra_structures_page, display_algebra_page);
        GUI_PAGE(scls::GUI_Text_Base<Text>, a_algebra_solver_redaction, PLEOS_MATHS_ALGEBRA_SOLVER_PAGE, algebra_solver_redaction, display_algebra_solver_redaction, display_algebra_solver_page);
        GUI_OBJECT(scls::GUI_Text_Input, a_algebra_solver_redaction_input, algebra_solver_redaction_input);

        // Returns arithmetic
        inline scls::GUI_Object* arithmetic_page() const {return a_arithmetic_page.get();};
        inline scls::GUI_Text* arithmetic_definitions_page() const {return a_arithmetic_definitions_page.get();};
        inline scls::GUI_Scroller_Choice* arithmetic_calculator_elements() const {return a_arithmetic_calculator_elements.get();};
        inline scls::GUI_Scroller_Choice* arithmetic_calculator_elements_chosen() const {return a_arithmetic_calculator_elements_chosen.get();};
        inline std::vector<std::shared_ptr<scls::GUI_Object>>& arithmetic_created_object_for_selected_object() {return a_current_state.a_arithmetic_created_object_for_selected_object;};
        inline scls::GUI_Object* arithmetic_calculator_elements_datas() const {return a_arithmetic_calculator_elements_datas.get();};
        inline scls::GUI_Text* arithmetic_calculator_elements_datas_title() const {return a_arithmetic_calculator_elements_datas_title.get();};
        inline scls::GUI_Text* arithmetic_calculator_page() const {return a_arithmetic_calculator_page.get();};
        inline scls::GUI_Text* arithmetic_calculator_redaction() const {return a_arithmetic_calculator_redaction.get();};
        GUI_PAGE(scls::GUI_Text_Base<Text>, a_arithmetic_division_page, PLEOS_MATHS_ARITHMETIC_DIVISION_PAGE, arithmetic_division_page, display_arithmetic_division_page, display_arithmetic_page);
        GUI_PAGE(scls::GUI_Text_Base<Text>, a_arithmetic_numbers_sets_page, PLEOS_MATHS_ARITHMETIC_NUMBERS_SETS_PAGE, arithmetic_numbers_sets_page, display_arithmetic_numbers_sets_page, display_arithmetic_page);
        GUI_PAGE(scls::GUI_Object, a_arithmetic_calculator_congruence_circle, PLEOS_MATHS_ARITHMETIC_CALCULATOR_CONGRUENCE_CIRCLE_PAGE, arithmetic_calculator_congruence_circle, display_arithmetic_calculator_congruence_circle, arithmetic_calculator_page);

        //  Returns functions
        inline scls::GUI_Text* functions_exponential_page() const {return a_functions_exponential_page.get();};
        GUI_PAGE(scls::GUI_Text_Base<Text>, a_functions_integration_page, PLEOS_MATHS_FUNCTION_INTEGRATION_PAGE, functions_integration_page, display_functions_integration_page, display_functions_page);
        inline scls::GUI_Text* functions_redaction() const {return a_functions_redaction.get();};
        inline scls::GUI_Object* functions_redaction_analyse() const {return a_functions_redaction_analyse.get();};
        inline scls::GUI_Scroller_Choice* functions_redaction_elements() const {return a_functions_redaction_elements.get();};
        inline scls::GUI_Scroller_Choice* functions_redaction_elements_chosen() const {return a_functions_redaction_elements_chosen.get();};
        inline scls::GUI_Scroller_Choice* functions_redaction_elements_created() const {return a_functions_redaction_elements_created.get();};
        inline scls::GUI_Scroller_Choice* functions_redaction_elements_creation() const {return a_functions_redaction_elements_creation.get();};
        inline scls::GUI_Text_Input* functions_redaction_expression() const {return a_functions_redaction_expression.get();};
        inline Graphic_Object* functions_redaction_graphic() const {return a_functions_redaction_graphic.get();};
        inline scls::GUI_Text_Input* functions_redaction_name() const {return a_functions_redaction_name.get();};

        // Returns geometry
        inline scls::GUI_Object* geometry_complex_numbers_page() const {return a_geometry_complex_numbers_page.get();};
        inline scls::GUI_Text* geometry_definitions_page() const {return a_geometry_definitions_body.get();};
        inline scls::GUI_Text* geometry_redaction() const {return a_geometry_redaction.get();};
        inline scls::GUI_Object* geometry_redaction_analyse() const {return a_geometry_redaction_analyse.get();};
        inline scls::GUI_Scroller_Choice* geometry_redaction_elements() const {return a_geometry_redaction_elements.get();};
        inline scls::GUI_Scroller_Choice* geometry_redaction_elements_chosen() const {return a_geometry_redaction_elements_chosen.get();};
        inline scls::GUI_Scroller_Choice* geometry_redaction_elements_created() const {return a_geometry_redaction_elements_created.get();};
        inline scls::GUI_Scroller_Choice* geometry_redaction_elements_creation() const {return a_geometry_redaction_elements_creation.get();};
        inline Graphic_Object* geometry_redaction_graphic() const {return a_geometry_redaction_graphic.get();};
        inline scls::GUI_Object* geometry_redaction_page() const {return a_geometry_redaction_page.get();};
        inline scls::GUI_Object* geometry_redaction_vector() const {return a_geometry_redaction_vector.get();};
        inline scls::GUI_Text_Base<Text>* geometry_vector_page() const {return a_geometry_vector_page.get();};
        // Form redaction
        inline scls::GUI_Object* geometry_redaction_form() const {return a_geometry_redaction_form.get();};
        inline scls::GUI_Text_Input* geometry_redaction_form_name() const {return a_geometry_redaction_form_name.get();};
        inline scls::GUI_Text_Input* geometry_redaction_form_points() const {return a_geometry_redaction_form_points.get();};
        // Vector redaction
        inline scls::GUI_Text_Input* geometry_redaction_vector_name() const {return a_geometry_redaction_vector_name.get();};
        inline scls::GUI_Text_Input* geometry_redaction_vector_x() const {return a_geometry_redaction_vector_x.get();};
        inline scls::GUI_Text_Input* geometry_redaction_vector_y() const {return a_geometry_redaction_vector_y.get();};

        // Returns random
        GUI_PAGE(scls::GUI_Object, a_random_page, PLEOS_MATHS_RANDOM_PAGE, random_page, display_random_page, hide_all);
        GUI_PAGE(scls::GUI_Text_Base<Text>, a_random_probability_page, PLEOS_MATHS_RANDOM_PAGE, random_probability_page, display_random_probability_page, display_random_page);

        // Home
        GUI_PAGE(scls::GUI_Text_Base<Text>, a_home_definition_page, PLEOS_MATHS_HOME_PAGE, home_definition_page, display_home_definition_page, display_home_page);

        // Returns logic
        inline scls::GUI_Text* logic_definitions_page() const {return a_logic_definitions_page.get();};
        inline scls::GUI_Text* logic_language_page() const {return a_logic_language_page.get();};
        inline scls::GUI_Text_Base<Text>* logic_set_theory_page() const {return a_logic_set_theory_page.get();};

    private:

        // Current state of the page
        struct {
            // Arithmetic
            // Created arithmetic object
            std::vector<std::shared_ptr<Arithmetic_Object>> a_arithmetic_objects_created = std::vector<std::shared_ptr<Arithmetic_Object>>();
            // Created object for the arithmetic selected object
            std::vector<std::shared_ptr<scls::GUI_Object>> a_arithmetic_created_object_for_selected_object = std::vector<std::shared_ptr<scls::GUI_Object>>();
            // Currently arithmetic vector
            std::shared_ptr<Arithmetic_Object> a_arithmetic_currently_selected_object = std::shared_ptr<Arithmetic_Object>();
            // Congruence circle
            double a_arithmetic_congruence_circle_modulo = 20;
            double a_arithmetic_congruence_circle_points = 50;

            // Functions
            // Created functions
            std::vector<std::shared_ptr<pleos::Function_Studied>> a_functions_created = std::vector<std::shared_ptr<pleos::Function_Studied>>();
            // Currently selected vector
            std::shared_ptr<pleos::Function_Studied> a_functions_currently_selected_function = std::shared_ptr<pleos::Function_Studied>();

            // Geometry
            // Created forms
            std::vector<std::shared_ptr<pleos::Form_2D>> a_geometry_form_2d_created = std::vector<std::shared_ptr<pleos::Form_2D>>();
            // Currently selected form
            std::shared_ptr<pleos::Form_2D> a_geometry_currently_selected_form_2d = std::shared_ptr<pleos::Form_2D>();
            // Created vectors
            std::vector<std::shared_ptr<pleos::Vector>> a_geometry_vectors_created = std::vector<std::shared_ptr<pleos::Vector>>();
            // Currently selected vector
            std::shared_ptr<pleos::Vector> a_geometry_currently_selected_vector = std::shared_ptr<pleos::Vector>();

            // Current page
            unsigned short current_page = PLEOS_MATHS_HOME_PAGE;
        } a_current_state;

        // Global navigation
        std::shared_ptr<scls::GUI_Text> a_hub_button;
        std::shared_ptr<scls::GUI_Scroller_Choice> a_navigation;

        // Pages
        std::shared_ptr<scls::GUI_Object> a_algebra_page;
        std::shared_ptr<scls::GUI_Object> a_arithmetic_page;
        std::shared_ptr<scls::GUI_Object> a_functions_page;
        std::shared_ptr<scls::GUI_Object> a_geometry_page;
        std::shared_ptr<scls::GUI_Object> a_logic_page;

        // Algebra page
        std::shared_ptr<scls::GUI_Text> a_algebra_definitions_page;
        std::shared_ptr<scls::GUI_Text> a_algebra_matrices_page;

        // Arithmetic page
        std::shared_ptr<scls::GUI_Text> a_arithmetic_calculator_page;
        std::shared_ptr<scls::GUI_Scroller_Choice> a_arithmetic_calculator_elements;
        std::shared_ptr<scls::GUI_Scroller_Choice> a_arithmetic_calculator_elements_chosen;
        std::shared_ptr<scls::GUI_Object> a_arithmetic_calculator_elements_datas;
        std::shared_ptr<scls::GUI_Text> a_arithmetic_calculator_elements_datas_title;
        std::shared_ptr<scls::GUI_Text> a_arithmetic_calculator_redaction;
        std::shared_ptr<scls::GUI_Text> a_arithmetic_definitions_page;

        // Functions page
        std::shared_ptr<scls::GUI_Text> a_functions_definitions_page;
        std::shared_ptr<scls::GUI_Text> a_functions_exponential_page;
        std::shared_ptr<scls::GUI_Text> a_functions_forms_page;
        std::shared_ptr<scls::GUI_Text> a_functions_redaction;
        std::shared_ptr<scls::GUI_Text> a_functions_redaction_analyse;
        std::shared_ptr<scls::GUI_Object> a_functions_redaction_page;
        std::shared_ptr<scls::GUI_Scroller_Choice> a_functions_redaction_elements;
        std::shared_ptr<scls::GUI_Scroller_Choice> a_functions_redaction_elements_chosen;
        std::shared_ptr<scls::GUI_Scroller_Choice> a_functions_redaction_elements_created;
        std::shared_ptr<scls::GUI_Scroller_Choice> a_functions_redaction_elements_creation;
        std::shared_ptr<scls::GUI_Text_Input> a_functions_redaction_expression;
        std::shared_ptr<Graphic_Object> a_functions_redaction_graphic;
        std::shared_ptr<scls::GUI_Text_Input> a_functions_redaction_name;

        // Geometry page
        std::shared_ptr<scls::GUI_Object> a_geometry_complex_numbers_page;
        std::shared_ptr<scls::GUI_Text> a_geometry_definitions_body;
        std::shared_ptr<scls::GUI_Text> a_geometry_redaction;
        std::shared_ptr<scls::GUI_Text> a_geometry_redaction_analyse;
        std::shared_ptr<scls::GUI_Scroller_Choice> a_geometry_redaction_elements;
        std::shared_ptr<scls::GUI_Scroller_Choice> a_geometry_redaction_elements_chosen;
        std::shared_ptr<scls::GUI_Scroller_Choice> a_geometry_redaction_elements_created;
        std::shared_ptr<scls::GUI_Scroller_Choice> a_geometry_redaction_elements_creation;
        std::shared_ptr<Graphic_Object> a_geometry_redaction_graphic;
        std::shared_ptr<scls::GUI_Object> a_geometry_redaction_page;
        std::shared_ptr<scls::GUI_Text_Base<Text>> a_geometry_vector_page;
        // Redaction form
        std::shared_ptr<scls::GUI_Object> a_geometry_redaction_form;
        std::shared_ptr<scls::GUI_Text_Input> a_geometry_redaction_form_name;
        std::shared_ptr<scls::GUI_Text_Input> a_geometry_redaction_form_points;
        // Redaction vector
        std::shared_ptr<scls::GUI_Object> a_geometry_redaction_vector;
        std::shared_ptr<scls::GUI_Text_Input> a_geometry_redaction_vector_name;
        std::shared_ptr<scls::GUI_Text_Input> a_geometry_redaction_vector_x;
        std::shared_ptr<scls::GUI_Text_Input> a_geometry_redaction_vector_y;

        // Logic page
        std::shared_ptr<scls::GUI_Text> a_logic_definitions_page;
        std::shared_ptr<scls::GUI_Text> a_logic_language_page;
        std::shared_ptr<scls::GUI_Text_Base<Text>> a_logic_set_theory_page;
    };
}

#endif // PLEOS_MATHS
