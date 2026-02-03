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

	// Do a bac subject
    void bac(std::string path) {
        // Asserts
        while(path.size() > 0 && (path.at(path.size() - 1) == '/' || path.at(path.size() - 1) == '\\')){path = path.substr(0, path.size() - 1);}

        // Base text
        std::string text = std::string("<h1>Bac de mathématiques</h1>");
        text += std::string("<h2>Exercice 1 : Probabilités</h2>");

        // First exercice
        pleos::Probability_Universe universe = pleos::Probability_Universe();
        universe.add_event("G", scls::Fraction(1, 5));
        universe.add_event("D", scls::Fraction(41, 500));
        universe.add_event_conditionally("G", "D", scls::Fraction(2, 1000));
        std::string universe_redaction;universe.solve(&universe_redaction);text += universe_redaction;
        universe_redaction=std::string();universe.solve(&universe_redaction);text += universe_redaction;
        std::string s;std::shared_ptr<pleos::Tree<std::string>> needed_tree = universe.tree(s);
        std::string tree_to_xml_1 = needed_tree.get()->graph()->to_xml_text();
        needed_tree = universe.tree(1, 0, s);
        std::string tree_to_xml_2 = needed_tree.get()->graph()->to_xml_text();
        text +=  std::string("</br>") + tree_to_xml_1 + std::string("</br></br>") + tree_to_xml_2;

        // Create the page
        scls::Text_Image_Generator tig;scls::Text_Style style;style.set_max_width(1000);
        std::shared_ptr<scls::__Image_Base> page_1_image = tig.image_shared_ptr<pleos::Text>(text, style);
        page_1_image.get()->save_png(path + std::string("/bac.png"));
    }

    // Do the test
    void test(std::string path) {
    	// Create the datas
    	std::string to_return = std::string();
    	to_return += std::string("<h1>PLEOS</h1>");
    	to_return += std::string("<h2>Catalogue</h2>");

    	to_return += std::string("<h3>Algorithmes implémentés</h3>");
    	to_return += std::string("<h3>Algorithmes à implémenter</h3>");

    	struct Alg{Alg(std::string c, std::string d, bool i):category(c),description(d),implemented(i){};std::string category = std::string();std::string description = std::string();bool implemented = false;};
    	std::vector<Alg> algs = std::vector<Alg>();

    	algs.push_back(Alg(std::string("Géométrie"), std::string("Animation de pavage"), false));

    	algs.push_back(Alg(std::string("Analyse"), std::string("Méthode de Newton-Raphson"), false));
    	algs.push_back(Alg(std::string("Analyse"), std::string("Racines de polynômes"), false));
    	algs.push_back(Alg(std::string("Analyse"), std::string("Étude du signe / variation de fonctions polynomiales"), false));
    	algs.push_back(Alg(std::string("Analyse"), std::string("Calcul de dérivés"), false));
    	algs.push_back(Alg(std::string("Analyse"), std::string("Calcul intégral / primitives"), false));
    	algs.push_back(Alg(std::string("Analyse"), std::string("Fonction R2 -> R 3D"), false));
    	algs.push_back(Alg(std::string("Analyse"), std::string("Représentation de champ 2D"), false));
    	algs.push_back(Alg(std::string("Analyse"), std::string("Analyse complexe"), false));
    	algs.push_back(Alg(std::string("Analyse"), std::string("Analyse vectorielle"), false));
    	algs.push_back(Alg(std::string("Analyse"), std::string("Développement en série entière"), false));
    	algs.push_back(Alg(std::string("Analyse"), std::string("Équation différentielle"), false));

    	algs.push_back(Alg(std::string("Algorithmes"), std::string("Systèmes de fonctions itérées"), false));
    	algs.push_back(Alg(std::string("Algorithmes"), std::string("Trac"), false));

    	algs.push_back(Alg(std::string("Algébrique"), std::string("Division de polynôme"), false));
    	algs.push_back(Alg(std::string("Algébrique"), std::string("Polynôme par racine / factorisation"), false));

    	for(int i = 0;i<static_cast<int>(algs.size());i++) {
			to_return += std::string("<p>") + algs.at(i).description + std::string("</p>");
		}

    	to_return += std::string("<h3>Animations implémentés</h3>");
    	to_return += std::string("<h3>Animations à implémenter</h3>");

    	std::vector<Alg> anims = std::vector<Alg>();
    	anims.push_back(Alg(std::string("Logique"), std::string("Argument diagonal de Cantor"), false));
    	anims.push_back(Alg(std::string("Logique"), std::string("Équipotence de N, Z, Q"), false));

    	for(int i = 0;i<static_cast<int>(anims.size());i++) {
			to_return += std::string("<p>") + anims.at(i).description + std::string("</p>");
		}

    	// Create the page
    	scls::Text_Image_Generator tig;scls::Text_Style style;style.set_max_width(1000);
    	std::shared_ptr<scls::__Image_Base> page_1_image = tig.image_shared_ptr<pleos::Text>(to_return, style);
    	page_1_image.get()->save_png(path + std::string("/page_1.png"));

        /*// Asserts
        while(path.size() > 0 && (path.at(path.size() - 1) == '/' || path.at(path.size() - 1) == '\\')){path = path.substr(0, path.size() - 1);}

        // Base text if the test
        std::vector<std::string> treated_function_expression = {std::string("2x - 2"),  std::string("4x*x + 8x - 9"), std::string("(3x*x - 2x - 5)/(5x*x + 9x - 2)"), std::string("sqrt(2x*x + 8x - 2)"), std::string("(exp(4x*x - 5))/(4x*x+2x-6)")};
        std::vector<std::string> treated_function_name = {std::string("f"), std::string("g"), std::string("h"), std::string("i"), std::string("j")};
        std::string treated_function_text = std::string();
        for(int i = 0;i<static_cast<int>(treated_function_expression.size());i++) {
            treated_function_text += std::string("<math>f\\{<mforall>x<min>R, x<mto>") + treated_function_expression.at(i) + std::string("}</math></br>");
        }
        std::string page = std::string("<h1>Test de PLEOS</h1><h2>Test de fonctions</h2><p>Voici la liste des fonctions qui seront traitées ici :</br>") + treated_function_text + std::string(".</p>");

        // Do each function test
        scls::Textual_Math_Settings settings;
        for(int i = 0;i<static_cast<int>(treated_function_expression.size());i++) {
            // Create the function to study
            std::shared_ptr<pleos::Function_Studied> fs = pleos::Function_Studied::new_function_studied_shared_ptr(*scls::string_to_formula(treated_function_expression.at(i)).get());
            fs.get()->set_function_unknown(std::string("x"));
            fs.get()->set_name(treated_function_name.at(i));

            // Study the function
            std::string current_function_text = std::string();
            current_function_text += std::string("<p>");
            current_function_text += fs.get()->introduction(&settings);current_function_text += std::string("</br>");
            pleos::function_definition_set(fs.get(), &current_function_text, &settings);current_function_text += std::string("</br>");
            pleos::function_roots(fs.get(), &current_function_text, &settings);current_function_text += std::string("</br>");
            pleos::function_sign(fs.get(), &current_function_text, &settings);current_function_text += std::string("</br>");
            current_function_text += std::string("Dressons le tableau de signe de cette fonction.</p>");
            current_function_text += pleos::function_sign_table(fs.get(), &current_function_text, &settings);current_function_text += std::string("</p>");
            scls::Formula derivate = pleos::function_derivation(fs.get(), &current_function_text, &settings);current_function_text += std::string("</br>");
            std::cout << "A " << derivate.to_std_string(&settings) << std::endl;
            current_function_text += std::string("Traçons cette fonction dans un graphique.</br>");
            current_function_text += std::string("<graphic><function expression=\"") + treated_function_expression.at(i) + std::string("\"></function>");
            current_function_text += std::string("<function color=\"blue\" expression=\"") + derivate.to_std_string(&settings) + std::string("\"></function></graphic>");

            // Finish the study
            current_function_text += std::string("</p>");
            page += current_function_text;
        }

        // Create the page
        scls::Text_Image_Generator tig;scls::Text_Style style;style.set_max_width(1000);
        std::shared_ptr<scls::__Image_Base> page_1_image = tig.image_shared_ptr<pleos::Text>(page, style);
        page_1_image.get()->save_png(path + std::string("/page_1.png"));//*/
    }
}
