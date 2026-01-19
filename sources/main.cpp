//******************
//
// main.cpp
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
// This file contains the main part of the prototype software.
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

// Include PLEOS Hub header
#include "../headers/pleos_hub.h"

// Include PLEOS Test header
#include "../../../scls-image-michelangelo/scls_image_directory/scls_image_table.h"

// Init SCLS
SCLS_INIT

int main(int argc, char* argv[]) {
	//pleos::bac(std::string("tests/"));
	//pleos::test(std::string("tests/"));

	pleos::Pleos_Window window(900, 600, argv[0]);
    window.load_from_xml("assets/window.txt");
    pleos::Hub_Page* hub = window.hub();
    hub->handle_saasf();

    while(window.run()) {
        window.update_event();
        window.update();

        window.render();
    }//*/

    /*std::string content = std::string("<h1>Les polynômes</h1>");
    std::string redaction = std::string();
    std::shared_ptr<scls::__Formula> f_1 = scls::string_to_formula(std::string("8x*x*x*x*x*x-5x*x*x*x*x+6x*x*x*x-4x*x*x+2"));
    std::shared_ptr<scls::__Formula> f_2 = scls::string_to_formula(std::string("2x+2"));
    pleos::polynomial_division(f_1.get()->polynomial(), f_2.get()->polynomial(), &redaction);content += std::string("<p>") + redaction + std::string("</p>");
    //redaction = std::string();pleos::study_function(scls::string_to_formula(std::string("0")).get(), &redaction);content += std::string("<p>") + redaction + std::string("</p>");
    //redaction = std::string();pleos::study_function(scls::string_to_formula(std::string("8x")).get(), &redaction);content += std::string("<p>") + redaction + std::string("</p>");
    //redaction = std::string();pleos::study_function(scls::string_to_formula(std::string("-3x+7")).get(), &redaction);content += std::string("<p>") + redaction + std::string("</p>");
    //redaction = std::string();pleos::study_function(scls::string_to_formula(std::string("2x*x-8x+1")).get(), &redaction);content += std::string("<p>") + redaction + std::string("</p>");
    //redaction = std::string();pleos::study_function(scls::string_to_formula(std::string("2x*x-4x+2")).get(), &redaction);content += std::string("<p>") + redaction + std::string("</p>");
    //redaction = std::string();pleos::study_function(scls::string_to_formula(std::string("5x*x+x+4")).get(), &redaction);content += std::string("<p>") + redaction + std::string("</p>");
    //redaction = std::string();pleos::study_function(scls::string_to_formula(std::string("(7x*x+2x-4)/(8x - 9)")).get(), &redaction);content += std::string("<p>") + redaction + std::string("</p>");
    //pleos::study_function(scls::string_to_formula(std::string("(1 + n)^4-(1 - n)^4")).get(), &redaction);content += std::string("<p>") + redaction + std::string("</p>");
    scls::Text_Style style;style.set_max_width(900);
    pleos::string_to_image(content, style).save_png("tests/cours.png");//*/

	/*std::string content = std::string("<h1>Système linéaire</h1>");
    std::string redaction = std::string();
	std::vector<std::shared_ptr<pleos::Function_Studied>> functions_shared_ptr;
	std::vector<pleos::Function_Studied*> functions;
	functions_shared_ptr.push_back(std::make_shared<pleos::Function_Studied>(scls::string_to_formula(std::string("x+y+z-6"))));
	functions_shared_ptr.push_back(std::make_shared<pleos::Function_Studied>(scls::string_to_formula(std::string("2x-y+z-3"))));
	functions_shared_ptr.push_back(std::make_shared<pleos::Function_Studied>(scls::string_to_formula(std::string("x+2y-z-4"))));
	//functions_shared_ptr.push_back(std::make_shared<pleos::Function_Studied>(scls::string_to_formula(std::string("-4x+2y+2z-1"))));
	for(int i=0;i<static_cast<int>(functions_shared_ptr.size());i++){functions.push_back(functions_shared_ptr.at(i).get());}
    pleos::solve_system(functions, &redaction);content += redaction;
    scls::Text_Style style;style.set_max_width(600);
    pleos::string_to_image(content, style).save_png("tests/systeme_lineaire.png");//*/

    /*scls::Text_Style style;style.set_font_size(24);style.set_max_width(800);
    pleos::string_to_image(scls::read_file("tests/test.txt"), style).save_png("tests/cours.png");//*/

    return 0;
}
