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
	//return pleos::execute("graphic", "tests/solve.png", std::vector<std::string>(1, std::string("<graphic><background_color white><base width=5 height=5><function expression=\"x/3\"><curve_area number=5 area_end=2></function></graphic>")));
	//return command(argc, argv);

	pleos::Pleos_Window window(900, 600, argv[0]);
    window.load_from_xml("assets/window.txt");
    pleos::Hub_Page* hub = window.hub();
    hub->handle_saasf();

    while(window.run()) {
        window.update_event();
        window.update();

        window.render();
    }//*/

	/*std::string content = std::string("<graphic><background_color white><base draw=0><repeat times=160><repeat times=10><circle tags=c x=-4+(repetition(1)*-1+random()/2)/2 y=(-80+repetition(0)+random()/2)/16 radius=1/32 physic=2 collision=circle velocity=(1+random(),-1/2+random())></repeat></repeat><form name=\"f\" points=new(-1,-1);new(1,-1);new(1,1) border_color=black color=red physic=1 collision=mesh></graphic>");
	std::shared_ptr<pleos::Graphic> g = pleos::Graphic::new_graphic();
	g.get()->graphic_from_xml(content, 500, 500);
	g.get()->to_image(500, 500).get()->save_png("tests/g.png");
	g.get()->set_scale(20, 20);

	std::vector<pleos::__Graphic_Object_Base*> c = std::vector<pleos::__Graphic_Object_Base*>(160);
	for(int i = 0;i<160;i++) {
		c[i] = g.get()->objects_by_tag("c").at(i * 10 + 1).get();
	}
	pleos::__Graphic_Object_Base* f = g.get()->object_by_name(std::string("f"));
	std::vector<scls::Point_2D> last = std::vector<scls::Point_2D>(160, scls::Point_2D(-100, 0));
	//*/

	/*
	scls::Window window(500, 500, argv[0]);
	scls::GUI_Page* a = window.new_page_2d<scls::GUI_Page>("gui").get();
	window.display_page_2d("gui");

	while(window.run()) {
		window.update_event();
		window.update();

		if(window.key_pressed("a")){
			g.get()->update(0.02);
			g.get()->physic_engine()->update_physic(0.02);
		}

		g.get()->set_foreground_object(f);
		a->parent_object()->set_texture(g.get()->to_image(500, 500));

		for(int i = 0;i<20;i++) {
			if(last[i].x() != -100){g.get()->new_line(std::string("l"), last[i].x(), last[i].y(), c[i]->x(), c[i]->y());}
			last[i] = c[i]->position();
		}

		window.render();
	}
	//*/

    /*// Video
    scls::Video_Encoder enc = scls::Video_Encoder("tests/t.mp4", 10, 1000, 1000);
    for(int i = 0;i<10;i++) {
        for(int j = 0;j<60;j++) {
            g.get()->update(0.02);
			g.get()->physic_engine()->update_physic(0.02);
            g.get()->set_foreground_object(f);

            enc.write_video_frame(g.get()->to_image(1000, 1000));
            enc.go_to_next_frame();

            for(int i = 0;i<160;i++) {
                if(last[i].x() != -100){g.get()->new_line(std::string("l"), last[i].x(), last[i].y(), c[i]->x(), c[i]->y()).get()->set_border_width(3);}
                last[i] = c[i]->position();
            }
        }
    }
    enc.close_encoding();/*/
}
