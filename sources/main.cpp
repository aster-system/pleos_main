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

// Init SCLS
SCLS_INIT

int main(int argc, char* argv[]) {
    pleos::Table test;
    scls::Text_Image_Generator tig;scls::Text_Style style;style.set_background_color(scls::Color(0, 0, 0, 0));style.set_font_size(100);
    test.case_at(0, 0)->set_background_color(scls::Color(0, 255, 0));
    test.image_at(0, 0) = tig.image_shared_ptr<pleos::__Text_Block>("x", style);
    test.case_at(0, 1)->set_background_color(scls::Color(0, 255, 0));
    test.image_at(0, 1) = tig.image_shared_ptr<pleos::__Text_Block>("f(x)", style);
    test.image_at(1, 0) = tig.image_shared_ptr<pleos::__Text_Block>("- infini", style);
    test.image_at(1, 1) = tig.image_shared_ptr<pleos::__Text_Block>("5", style);
    test.image_at(2, 0) = tig.image_shared_ptr<pleos::__Text_Block>("2", style);
    test.image_at(2, 1) = tig.image_shared_ptr<pleos::__Text_Block>("0", style);
    test.image_at(3, 0) = tig.image_shared_ptr<pleos::__Text_Block>("+ infini", style);
    test.image_at(3, 1) = tig.image_shared_ptr<pleos::__Text_Block>("+ infini", style);
    test.case_at(1, 0)->set_background_color(scls::Color(180, 180, 180));
    test.case_at(2, 0)->set_background_color(scls::Color(180, 180, 180));
    test.case_at(3, 0)->set_background_color(scls::Color(180, 180, 180));
    test.to_image().get()->save_png("tests/table.png");

    /*pleos::Pleos_Window window(900, 600, argv[0]);
    window.load_from_xml("assets/window.txt");

    while(window.run()) {
        window.update_event();
        window.update();

        window.render();
    } //*/

    return 0;
}
