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
#include "../../../one_thousand_ludo/ludo.h"

// Include PLEOS Test header
#include "../../../scls-image-michelangelo/scls_image_directory/scls_image_table.h"

// Init SCLS
SCLS_INIT

// exec.exe study "3*x*x+5*x-2"

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
            int error = pleos::execute(command_name, "tests/solve.png", command_parameters);
            if(error < 0) {
                std::string timestamp = scls::current_date().to_std_string();
                scls::append_in_file("tests/log.txt", timestamp + " - Erreur : la commande \"" + command_full + "\" a généré l'erreur " + std::to_string(error) + "\n");
            }
            return error;
	    }
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

    return 0;
}
