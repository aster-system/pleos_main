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

int main(int argc, char* argv[]) {
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

    /*double branches = 8;
    double center_x = 0;
    double center_y = 0;
    double r_outer = 4;
    double r_inner = 3;
    scls::Vector_Base_2D p = scls::Vector_Base_2D(50 * cos(0.5), 50 * sin(0.5), -50 * sin(0.5), 50 * cos(0.5), 500, 500);
    std::vector<scls::Point_2D> points = std::vector<scls::Point_2D>(branches * 2);
    const double angle_step = SCLS_PI / branches;
    int i = 0;
    while (i < branches * 2) {
        // On commence à -PI/2 pour que la première pointe soit vers le haut
        double angle  = static_cast<double>(i) * angle_step;
        double radius = (i % 2 == 0) ? r_outer : r_inner;

        double x = center_x + radius * std::cos(angle);
        double y = center_y + radius * std::sin(angle);
        points[i] = scls::Point_2D(1000 - p.base_to_canonical_x(x, y), p.base_to_canonical_y(x, y));
        ++i;
    }

    scls::Image img = scls::Image(1000, 1000);
    img.fill_form(points, scls::Color(255, 0, 0));
    scls::draw_grid(img, &p);
    img.save_png("tests/f.png");//*/

    std::shared_ptr<scls::Formula_Base> function = scls::string_to_algebra_element<scls::Formula_Base>("(x*x)/4+x/2-1");

	int duration = 12;
	scls::Video_Encoder enc = scls::Video_Encoder(std::string("./tests/t.mp4"), duration, 1080, 1920);
    std::shared_ptr<scls::Formula_Base> f = scls::string_to_algebra_element<scls::Formula_Base>("(1/4) * x + 2");
    for(int i = 0;i<duration*60;i++) {
        scls::Image image = scls::Image(1080, 1920, scls::Color(255, 255, 255));
        scls::Plane_Base p = scls::Plane_Base(100, 100, image.width() / 2, image.height() / 2);
        scls::draw_grid(image, &p);
        scls::draw_function_graph(image, function.get(), &p, 0, 1000);
        if(i <= 600){scls::draw_function_secant(image, function.get(), &p, -3.0, 5.0 - (i / 60.0) * (8.0/10.0));}
        else{scls::draw_function_tangent(image, function.get(), &p, -3);}

        enc.write_video_frame(image);
        enc.go_to_next_frame();
    }
    enc.close_encoding();//*/

    /*int duration = 10;
    scls::Video_Encoder enc = scls::Video_Encoder(std::string("./tests/t.mp4"), duration, 1000, 1000);
    std::shared_ptr<scls::Formula_Base> f = scls::string_to_algebra_element<scls::Formula_Base>("(1/4) * x + 2");
    for(int i = 0;i<duration*60;i++) {
        double branches = 8;
        double center_x = 500;
        double center_y = 500;
        double r_outer = 200;
        double r_inner = 150;
        double v = (static_cast<double>(i) / 60.0);
        double v_2 = (static_cast<double>(i) / 60.0);
        if(v < 0.1){v=0.1;}
        if(v_2 < 0.1){v_2=0.1;}

        if(i > 240.0){v = 0;}
        else if(i > 180.0){v = -50 + 50 * (v - 3);}
        else if(i > 60.0){v = 50 - 50 * (v - 1);}
        else{v = v * 50;}

        if(i > 480.0){v_2 = 0;}
        else if(i > 420.0){v_2 = -50 + (v_2 - 7) * 50;}
        else if(i > 300.0){v_2 = 50 - (v_2 - 5) * 50;}
        else if(i > 240.0){v_2 = (v_2 - 4) * 50;}
        else{v_2 = 0;}

        scls::Vector_Base p = scls::Vector_Base(50, v_2, v, 50, 500, 500);
        std::vector<scls::Point_2D> points = std::vector<scls::Point_2D>(branches * 2);
        const double angle_step = SCLS_PI / branches;
        for (int i = 0; i < branches * 2; ++i) {
            // On commence à -PI/2 pour que la première pointe soit vers le haut
            double angle  = static_cast<double>(i) * angle_step;
            double radius = (i % 2 == 0) ? r_outer : r_inner;

            double x = center_x + radius * std::cos(angle);
            double y = center_y + radius * std::sin(angle);
            points[i] = scls::Point_2D(500 - p.canonical_to_base_x(x, y) * 50, 500 + p.canonical_to_base_y(x, y) * 50);
        }

        scls::Image img = scls::Image(1000, 1000);
        scls::draw_grid(img, &p);
        img.fill_form(points, scls::Color(255, 0, 0));

        scls::Image img = scls::Image(1000, 1000);
        scls::Vector_Base p = scls::Vector_Base(50, 0, 0, 50, 500, 500);
        scls::draw_grid(img, &p);
        scls::draw_function_graph(img, f.get(), &p, -1000, -10.0 + (static_cast<double>(i) / 60.0) * 2.0);
        img.save_png("tests/f.png");

        enc.write_video_frame(img);
        enc.go_to_next_frame();
    }
    enc.close_encoding();//*/

    return 0;
}
