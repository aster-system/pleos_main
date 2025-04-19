//******************
//
// pleos_test.cpp
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
// This file contains the source code of "pleos_test.h".
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

// Include PLEOS Test
#include "../headers/pleos_test.h"

// The namespace "pleos" is used to simplify the all.
namespace pleos {

    // Do the test
    void test(std::string path) {
        // Asserts
        while(path.size() > 0 && (path.at(path.size() - 1) == '/' || path.at(path.size() - 1) == '\\')){path = path.substr(0, path.size() - 1);}

        // Base text if the test
        std::vector<std::string> treated_function_expression = {std::string("2x - 2"), std::string("4x*x + 8x - 9"), std::string("(3x*x - 2x - 5)/(5x*x + 9x - 2)"), std::string("sqrt(2x*x + 8x - 2)")};
        std::vector<std::string> treated_function_name = {std::string("f"), std::string("g"), std::string("h"), std::string("i")};
        std::string treated_function_text = std::string();
        for(int i = 0;i<static_cast<int>(treated_function_expression.size());i++) {
            treated_function_text += std::string("<math>f\\{<mforall>x<min>R, x<mto>") + treated_function_expression.at(i) + std::string("}</math></br>");
        }
        std::string page = std::string("<h1>Test de PLEOS</h1><h2>Test de fonctions</h2><p>Voici la liste des fonctions qui seront traitées ici :</br>") + treated_function_text + std::string(".</p>");

        // Do each function test
        for(int i = 0;i<static_cast<int>(treated_function_expression.size());i++) {
            // Create the function to study
            std::shared_ptr<pleos::Function_Studied> fs = pleos::Function_Studied::new_function_studied_shared_ptr(scls::string_to_formula(treated_function_expression.at(i)));
            fs.get()->set_function_unknown(std::string("x"));
            fs.get()->set_name(treated_function_name.at(i));

            // Study the function
            std::string current_function_text = std::string();
            current_function_text += std::string("<p>");
            current_function_text += fs.get()->introduction();current_function_text += std::string("</br>");
            pleos::function_definition_set(fs.get(), &current_function_text);current_function_text += std::string("</br>");
            pleos::function_roots(fs.get(), &current_function_text);current_function_text += std::string("</br>");
            pleos::function_sign(fs.get(), &current_function_text);current_function_text += std::string("</br>");
            current_function_text += std::string("Dressons le tableau de signe de cette fonction.</p>");
            current_function_text += pleos::function_sign_table(fs.get(), &current_function_text);current_function_text += std::string("</p>");
            pleos::function_derivation(fs.get(), &current_function_text);current_function_text += std::string("</br>");
            current_function_text += std::string("Traçons cette fonction dans un graphique.</br>");
            current_function_text += std::string("<graphic><function expression=\"") + treated_function_expression.at(i) + std::string("\"></function></graphic>");

            // Finish the study
            current_function_text += std::string("</p>");
            page += current_function_text;
        }

        // Create the page
        scls::Text_Image_Generator tig;scls::Text_Style style;style.max_width = 1000;
        std::shared_ptr<scls::Image> page_1_image = tig.image_shared_ptr<pleos::Text>(page, style);
        page_1_image.get()->save_png(path + std::string("/page_1.png"));
    }
}
