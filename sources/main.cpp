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

/*
double max_double(std::vector<double>& doubles){double current_max = doubles[0];for(int i = 1;i<static_cast<int>(doubles.size());i++){if(doubles[i] > current_max){current_max = doubles[i];}}return current_max;}

void draw(std::shared_ptr<scls::Image> img, std::vector<double>& value_1, std::vector<double>& value_2, double& max_value_1, double& max_value_2) {
    int last_x = 0; int last_y = 0;int width = img.get()->width();
    int separation_x = width / (value_1.size() - 1);
    for(int i = 0;i<static_cast<int>(value_1.size());i++) {
        int current_x = ((value_2[i] / max_value_2) * static_cast<double>(width));
        int current_y = img.get()->height() - ((value_1[i] / max_value_1) * static_cast<double>(width));
        img.get()->draw_circle(current_x, current_y, 10, scls::Color(0, 0, 0));
        if(i > 0){img.get()->draw_line(current_x, current_y, last_x, last_y, scls::Color(0, 0, 0),  5);}
        last_x = current_x;
        last_y = current_y;
    }
}

    int width = 1000;
    std::shared_ptr<scls::Image> img = std::make_shared<scls::Image>(width, width, scls::Color(255, 255, 255));

    std::vector<double> value_1_exp_1 = {27.26, 26.98, 26.93, 26.07, 25.06, 17.99, 12.93, 9.07, 6.95, 5.63, 4.73, 3.57, 0.98};
    std::vector<double> value_2_exp_1 = {0.409, 0.967, 1.39, 1.86, 2.05, 2.43, 2.64, 2.76, 2.8, 2.83, 2.84, 2.86, 2.93};

    value_1_exp_1 = {20.8, 19.9, 18.88, 17.5, 15.8, 13.5, 7.5, 4.4, 0.061};
    value_2_exp_1 = {0, 45.5, 84.1, 116, 150, 173, 200, 210, 224};

    std::vector<double> value_1_exp_2 = {11.25, 11.27, 11.12, 11.10, 11.02, 10.01, 9.37, 8.44, 7.5, 5.63, 4.37, 2.5, 0.35};
    std::vector<double> value_2_exp_2 = {0.182, 0.409, 0.75, 1.02, 1.26, 1.71, 1.86, 1.99, 2.09, 2.27, 2.46, 2.52, 2.7};

    double max_value_1 = std::max(max_double(value_1_exp_1), max_double(value_1_exp_2));double max_value_2 = std::max(max_double(value_2_exp_1), max_double(value_2_exp_2));
    draw(img, value_1_exp_1, value_2_exp_1, max_value_1, max_value_2);
    //draw(img, value_1_exp_2, value_2_exp_2, max_value_1, max_value_2);
    img.get()->draw_circle(1, img.get()->width() - 1, img.get()->width(), scls::Color(255, 0, 0), 3);

    scls::Text_Image_Generator tig;
    std::shared_ptr<pleos::Table> needed_table_shared_ptr = std::make_shared<pleos::Table>();
    pleos::Table* needed_table = needed_table_shared_ptr.get();
    std::shared_ptr<scls::Text_Style> needed_style = std::make_shared<scls::Text_Style>();
    needed_table->case_at(0, 0)->image = tig.image_shared_ptr("Intensité", *needed_style.get());
    needed_table->case_at(1, 0)->image = tig.image_shared_ptr("Tension", *needed_style.get());
    needed_table->case_at(2, 0)->image = tig.image_shared_ptr("Puissance", *needed_style.get());
    needed_table->case_at(3, 0)->image = tig.image_shared_ptr("Résistance", *needed_style.get());
    for(int i = 0;i<static_cast<int>(value_1_exp_1.size());i++){
        needed_table->case_at(0, i + 1)->image = tig.image_shared_ptr(scls::format_number_to_text(value_2_exp_1[i]), *needed_style.get());
        needed_table->case_at(1, i + 1)->image = tig.image_shared_ptr(scls::format_number_to_text(value_1_exp_1[i]), *needed_style.get());
        needed_table->case_at(2, i + 1)->image = tig.image_shared_ptr(scls::format_number_to_text(value_1_exp_1[i] * value_2_exp_1[i]), *needed_style.get());
        needed_table->case_at(3, i + 1)->image = tig.image_shared_ptr(scls::format_number_to_text(value_2_exp_1[i] / value_1_exp_1[i]), *needed_style.get());
    }

    img.get()->save_png("tests/lux.png");
    needed_table->to_image().get()->save_png("tests/table.png");

//*/

int main(int argc, char* argv[]) {
    pleos::Pleos_Window window(900, 600, argv[0]);
    window.load_from_xml("assets/window.txt");

    while(window.run()) {
        window.update_event();
        window.update();

        window.render();
    } //*/

    return 0;
}
