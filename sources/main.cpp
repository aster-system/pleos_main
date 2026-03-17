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

#include <chrono>

// Include PLEOS Hub header
#include "../headers/pleos_hub.h"

#define OTL
#ifdef OTL
#include "../../../one_thousand_ludo/ludo.h"
#endif // OTL

// Include PLEOS Test header
#include "../../../scls-image-michelangelo/scls_image_directory/scls_image_table.h"
#include "../../../scls-image-michelangelo/scls_image_directory/scls_image_turtle.h"

// Init SCLS
SCLS_INIT

// Execute a command
int command(int argc, char* argv[]) {
	if(argc <= 1){return PLEOS_COMMAND_NOT_ENOUGH_PARAMETERS;};

	// Parameters
	std::string command_name = argv[1];
	std::string command_full = command_name;
	std::vector<std::string> command_parameters = std::vector<std::string>(argc - 2);
	for(int i = 0;i<argc - 2;i++){
		command_parameters[i] = argv[2 + i];
		command_full += std::string(" ") + argv[2 + i];
	}

	// Execute
	try {
		#ifdef OTL
	    if(command_name == std::string_view("generate_ludo")) {return generate_ludo_game();}
	    else if(command_name == std::string_view("generate_ludo_video")) {return generate_ludo_video();}
	    else if(command_name == std::string_view("trombi") || command_name == std::string_view("trombinoscope")) {
            int error = 0;
            if(command_parameters.size() <= 0){error = PLEOS_COMMAND_NOT_ENOUGH_PARAMETERS;}
            else{error = photo_directory(command_parameters.at(0));}

            // Error handling
            if(error < 0) {
                std::string timestamp = scls::current_date().to_std_string();
                scls::append_in_file("tests/log.txt", timestamp + " - Erreur : la commande \"" + command_full + "\" a généré l'erreur " + std::to_string(error) + "\n");
            }
            return error;
	    }
	    else {
		#endif // OTL

            int error = pleos::execute(command_name, "tests/solve.png", command_parameters);
            if(error < 0) {
                std::string timestamp = scls::current_date().to_std_string();
                scls::append_in_file("tests/log.txt", timestamp + " - Erreur : la commande \"" + command_full + "\" a généré l'erreur " + std::to_string(error) + "\n");
            }
            return error;

		#ifdef OTL
	    }
		#endif // OTL
	}
	catch (std::exception* e) {
	    std::cout << "B " << std::endl;
	    return PLEOS_COMMAND_INTERNAL_ERROR;
	}
	return 0;
}

void branch(scls::Turtle& t, double branch_width, int step, int n) {
	if(n <= 0){return;}

	constexpr double angle = 10;
	t.rotate_degrees(angle);
	t.go_forward(branch_width / static_cast<double>((step - n) + 2));
	branch(t, branch_width, step, n - 1);
	t.go_forward(-branch_width / static_cast<double>((step - n) + 2));
	t.rotate_degrees(-angle * 2);
	t.go_forward(branch_width / static_cast<double>((step - n) + 2));
	branch(t, branch_width, step, n - 1);
	t.go_forward(-branch_width / static_cast<double>((step - n) + 2));
	t.rotate_degrees(angle);
}
void branch(scls::Turtle& t, double branch_width, int step){branch(t, branch_width, step, step);}

void add_actions_von_koch_curve(scls::Turtle& t, double branch_width, int step, int n) {
	constexpr double angle = -60;
	if(n <= 0){t.add_action_move_forward(branch_width / 3);}
	else{add_actions_von_koch_curve(t, branch_width / 3, step, n - 1);}
	t.add_action_rotate(angle);

	if(n <= 0){t.add_action_move_forward(branch_width / 3);}
	else{add_actions_von_koch_curve(t, branch_width / 3, step, n - 1);}
	t.add_action_rotate(-angle * 2);

	if(n <= 0){t.add_action_move_forward(branch_width / 3);}
	else{add_actions_von_koch_curve(t, branch_width / 3, step, n - 1);}
	t.add_action_rotate(angle);

	if(n <= 0){t.add_action_move_forward(branch_width / 3);}
	else{add_actions_von_koch_curve(t, branch_width / 3, step, n - 1);}
}
void add_actions_von_koch_curve(scls::Turtle& t, double branch_width, int step){add_actions_von_koch_curve(t, branch_width, step, step);}
void von_koch_curve(scls::Turtle& t, double branch_width, int step, int n) {
	constexpr double angle = -60;
	if(n <= 0){t.go_forward(branch_width / 3);}
	else{von_koch_curve(t, branch_width / 3, step, n - 1);}
	t.rotate_degrees(angle);

	if(n <= 0){t.go_forward(branch_width / 3);}
	else{von_koch_curve(t, branch_width / 3, step, n - 1);}
	t.rotate_degrees(-angle * 2);

	if(n <= 0){t.go_forward(branch_width / 3);}
	else{von_koch_curve(t, branch_width / 3, step, n - 1);}
	t.rotate_degrees(angle);

	if(n <= 0){t.go_forward(branch_width / 3);}
	else{von_koch_curve(t, branch_width / 3, step, n - 1);}
}
void von_koch_curve(scls::Turtle& t, double branch_width, int step){von_koch_curve(t, branch_width, step, step);}

void add_actions_von_koch_snowflake(scls::Turtle& t, double branch_width, int step) {
	constexpr double angle = 120;
	add_actions_von_koch_curve(t, branch_width, step);
	t.add_action_rotate(angle);
	add_actions_von_koch_curve(t, branch_width, step);
	t.add_action_rotate(angle);
	add_actions_von_koch_curve(t, branch_width, step);
	t.add_action_rotate(angle);
}
void von_koch_snowflake(scls::Turtle& t, double branch_width, int step) {
	constexpr double angle = 120;
	von_koch_curve(t, branch_width, step);
	t.rotate_degrees(angle);
	von_koch_curve(t, branch_width, step);
	t.rotate_degrees(angle);
	von_koch_curve(t, branch_width, step);
	t.rotate_degrees(angle);
}

int main(int argc, char* argv[]) {
	//return pleos::execute("graphic", "tests/solve.png", std::vector<std::string>(1, std::string("<graphic><background_color white><base width=5 height=5><function expression=\"x/3\"><curve_area number=5 area_end=2></function></graphic>")));
	//return command(argc, argv);

	/*pleos::Pleos_Window window(900, 600, argv[0]);
    window.load_from_xml("assets/window.txt");
    pleos::Hub_Page* hub = window.hub();
    hub->handle_saasf();

    while(window.run()) {
        window.update_event();
        window.update();

        window.render();
    }//*/

    std::shared_ptr<scls::Formula_Base> f = scls::string_to_algebra_element<scls::Formula_Base>(std::string("1/(x+1)"));
    while(f.get()->simplify_step() != scls::Formula_Base::NO_SIMPLIFICATION){}
    scls::mclaurin(f.get(), std::string("x"), 14);

	// Video
    int image_width = 1000;
    scls::Plane_Base b = scls::Plane_Base(image_width / 20, image_width / 20, image_width / 2, image_width / 2);
    scls::Video_Encoder enc = scls::Video_Encoder("tests/t.mp4", 10, image_width, image_width);
     std::shared_ptr<scls::Formula_Base> f_current;
    for(int i = 0;i<20;i++) {
        if(i + 1 < 11) f_current = scls::mclaurin(f.get(), std::string("x"), i + 1);
        while(f_current.get()->simplify_step() != scls::Formula_Base::NO_SIMPLIFICATION){}

        // Draw the base
        scls::Image img = scls::Image(image_width, image_width, scls::Color(255, 255, 255));
        scls::draw_grid(img, &b);
        scls::Point_2D last_point = scls::Point_2D(-1, 0);
        for(int j = 0;j<img.width();j++){
            scls::Point_2D current_point = scls::Point_2D(j, img.height() - b.base_y_to_canonical_y(f.get()->replace_unknowns("x", b.canonical_x_to_base_x(j)).get()->value<scls::Fraction>()->to_double()));
            img.draw_line(last_point.x(), last_point.y(), current_point.x(), current_point.y(), scls::Color(255, 0, 0), 5);
            last_point = current_point;
        }
        last_point = scls::Point_2D(-1, 0);
        for(int j = 0;j<img.width();j++){
            scls::Point_2D current_point = scls::Point_2D(j, img.height() - b.base_y_to_canonical_y(f_current.get()->replace_unknowns("x", b.canonical_x_to_base_x(j)).get()->value<scls::Fraction>()->to_double()));
            img.draw_line(last_point.x(), last_point.y(), current_point.x(), current_point.y(), scls::Color(0, 0, 255), 5);
            last_point = current_point;
        }

        for(int j = 0;j<30;j++) {
            enc.write_video_frame(img);
            enc.go_to_next_frame();
        }
    }
    enc.close_encoding();//*/
}
