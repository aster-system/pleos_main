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
#include "../headers/pleos_test.h"

// Init SCLS
SCLS_INIT

int main(int argc, char* argv[]) {
    //pleos::bac(std::string("tests/"));

    pleos::Table t;scls::Text_Style s;s.set_font_size(40);scls::Text_Image_Generator tig;
    for(int i = 0;i<30;i++) {
        if((i + 1) % 2 == 0){s.set_background_color(scls::Color(170, 255, 170));}
        else{s.set_background_color(scls::Color(255, 170, 170));}
        t.set_cases_value(0, i, 1, 1, std::string("P(") + std::to_string(i + 1) + std::string(")"), s, &tig);
        t.set_cases_value(1, i, 1, 1, std::to_string(i + 1) + std::string(" est pair"), s, &tig);
        if((i + 1) % 2 == 0){
            t.set_cases_value(2, i, 1, 1, std::string("Vrai"), s, &tig);
            t.case_at(0, i)->set_background_color(scls::Color(170, 255, 170));
            t.case_at(1, i)->set_background_color(scls::Color(170, 255, 170));
            t.case_at(2, i)->set_background_color(scls::Color(170, 255, 170));
        }
        else{
            t.set_cases_value(2, i, 1, 1, std::string("Faux"), s, &tig);
            t.case_at(0, i)->set_background_color(scls::Color(255, 170, 170));
            t.case_at(1, i)->set_background_color(scls::Color(255, 170, 170));
            t.case_at(2, i)->set_background_color(scls::Color(255, 170, 170));
        }
    }
    t.to_image().save_png("tests/test.png");

    /*pleos::Pleos_Window window(900, 600, argv[0]);
    window.load_from_xml("assets/window.txt");

    while(window.run()) {
        window.update_event();
        window.update();

        window.render();
    }//*/

    /*std::string content = std::string("<h1>Les polynômes</h1>");
    std::string redaction = std::string();pleos::polynomial_roots(scls::string_to_formula(std::string("3")), &redaction);content += std::string("<p>") + redaction + std::string("</p>");
    redaction = std::string();pleos::polynomial_roots(scls::string_to_formula(std::string("0")), &redaction);content += std::string("<p>") + redaction + std::string("</p>");
    redaction = std::string();pleos::polynomial_roots(scls::string_to_formula(std::string("8x")), &redaction);content += std::string("<p>") + redaction + std::string("</p>");
    redaction = std::string();pleos::polynomial_roots(scls::string_to_formula(std::string("-3x+7")), &redaction);content += std::string("<p>") + redaction + std::string("</p>");
    redaction = std::string();pleos::polynomial_roots(scls::string_to_formula(std::string("2x*x-8x+1")), &redaction);content += std::string("<p>") + redaction + std::string("</p>");
    redaction = std::string();pleos::polynomial_roots(scls::string_to_formula(std::string("2x*x-4x+2")), &redaction);content += std::string("<p>") + redaction + std::string("</p>");
    redaction = std::string();pleos::polynomial_roots(scls::string_to_formula(std::string("5x*x+x+4")), &redaction);content += std::string("<p>") + redaction + std::string("</p>");
    scls::Text_Style style;style.set_max_width(600);
    pleos::string_to_image(content, style).save_png("tests/polynome.png");//*/

    /*scls::Text_Style style;style.set_font_size(24);style.set_max_width(800);
    pleos::string_to_image(scls::read_file("tests/test_note.txt"), style).save_png("tests/polynome.png");//*/

    return 0;
}
