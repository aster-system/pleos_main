//******************
//
// pleos_hub.cpp
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
// The "Hub" part provides a hub between every part of the software.
//
// This file contains the source code of "pleos_hub.h".
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

// Include PLEOS Libs
#include "../headers/pleos_hub.h"

// The namespace "pleos" is used to simplify the all.
namespace pleos {
    // Loads an object in a page from XML
    std::shared_ptr<scls::GUI_Object> Hub_Page::__create_loaded_object_from_type(std::string object_name, std::string object_type, scls::GUI_Object* parent) {
        // Navigation
        if(object_name == "hub_navigation_chemistry_button"){a_navigation_chemistry_button = *parent->new_object<scls::GUI_Text>(object_name);return a_navigation_chemistry_button;}
        else if(object_name == "hub_navigation_it_button"){a_navigation_it_button = *parent->new_object<scls::GUI_Text>(object_name);return a_navigation_it_button;}
        else if(object_name == "hub_navigation_maths_button") {a_navigation_maths_button = *parent->new_object<scls::GUI_Text>(object_name);return a_navigation_maths_button;}
        else if(object_name == "hub_navigation_physic_button"){a_navigation_physic_button = *parent->new_object<scls::GUI_Text>(object_name);return a_navigation_physic_button;}
        else if(object_name == "hub_navigation_settings_button"){a_navigation_settings_button = *parent->new_object<scls::GUI_Text>(object_name);return a_navigation_settings_button;}

        return scls::GUI_Page::__create_loaded_object_from_type(object_name, object_type, parent);
    }

    // Checks the events of navigation
    void Hub_Page::check_navigation() {
        if(a_navigation_chemistry_button.get()->is_clicked_during_this_frame(GLFW_MOUSE_BUTTON_LEFT)) {window_struct()->hide_all_pages_2d();window_struct()->display_page_2d("chemistry");}
        if(a_navigation_it_button.get()->is_clicked_during_this_frame(GLFW_MOUSE_BUTTON_LEFT)) {window_struct()->hide_all_pages_2d();window_struct()->display_page_2d("it");}
        if(a_navigation_maths_button.get()->is_clicked_during_this_frame(GLFW_MOUSE_BUTTON_LEFT)) {window_struct()->hide_all_pages_2d();window_struct()->display_page_2d("maths");}
        if(a_navigation_physic_button.get()->is_clicked_during_this_frame(GLFW_MOUSE_BUTTON_LEFT)) {window_struct()->hide_all_pages_2d();window_struct()->display_page_2d("physic");}
        if(a_navigation_settings_button.get()->is_clicked_during_this_frame(GLFW_MOUSE_BUTTON_LEFT)) {window_struct()->hide_all_pages_2d();window_struct()->display_page_2d("settings");}
    }

    // Updates the events
    void Hub_Page::update_event() {GUI_Page::update_event();check_navigation();handle_saasf();}

    //******************
    //
    // Handle SAASF
    //
    //******************

    // SAASF datas
    bool __saasf_is_part(std::string to_test){return (to_test == std::string("it") || to_test == std::string("maths") || to_test == std::string("physic"));};
    bool __saasf_is_sub_part(std::string part, std::string to_test){
        if(part == std::string("maths")){return (to_test == std::string("algebra") || to_test == std::string("arithmetic") || to_test == std::string("geometry") || to_test == std::string("logic") || to_test == std::string("topology"));}
        return false;
    };

    // Apply the images for SAASF
    int __saasf_image_number = 0;std::shared_ptr<Text_Environment> __saasf_text_environment;
    void __saasf_images(scls::Replica_Project* replica, std::shared_ptr<scls::__XML_Text_Base> content, std::string path, std::string current_replica_file_path) {
        // Datas about the path
        std::vector<std::string> cutted = scls::cut_string(current_replica_file_path, std::string("/"));
        int category_to_learn = 0;if(cutted.at(0) != std::string("learn")){category_to_learn=1;}
        while(cutted.size() > 0 && (cutted.at(0) == std::string("creations") || cutted.at(0) == std::string("learn"))){cutted.erase(cutted.begin());}
        std::string current_part = std::string();std::string current_sub_part = std::string();
        if(cutted.size() > 0){current_part = cutted.at(0);if(cutted.size() > 1){current_sub_part = cutted.at(1);}}

        std::filesystem::create_directory(path + std::string("/images/"));
        scls::Text_Style style = scls::Text_Style();
        for(int i = 0;i<static_cast<int>(content.get()->sub_texts().size());i++) {
            std::string attribute_name = content.get()->sub_texts().at(i).get()->xml_balise_name();
            if(is_special_pleos_balise(attribute_name)) {
                std::shared_ptr<scls::__Image_Base> img = generate_text_image(content.get()->sub_texts().at(i), style, content, __saasf_text_environment);
                if(img.get() != 0){
                    // Generate a new image from the special balise
                    std::string img_path = path + std::string("/images/img") + std::to_string(__saasf_image_number) + std::string(".png");
                    img.get()->save_png(img_path);
                    content.get()->sub_texts().at(i).get()->clear();
                    content.get()->sub_texts().at(i).get()->add_xml_attribute(std::string("src"), replica->attached_pattern()->path_to_root(current_replica_file_path) + std::string("images/img") + std::to_string(__saasf_image_number) + std::string(".png"));
                    content.get()->sub_texts().at(i).get()->set_xml_balise_name(std::string("img"));
                    content.get()->sub_texts().at(i).get()->balise_datas()->has_content = false;
                    content.get()->sub_texts().at(i).get()->balise_datas()->is_paragraph = false;
                    __saasf_image_number++;
                }
                else{__saasf_images(replica, content.get()->sub_texts().at(i), path, current_replica_file_path);}
            }
            else if(attribute_name == std::string("a")){
                // HMLT link

                // Get the needed datas
                std::vector<scls::XML_Attribute>& attributes = content.get()->sub_texts().at(i).get()->xml_balise_attributes();
                std::string url = std::string();int url_attribute = -1;
                for(int j = 0;j<static_cast<int>(attributes.size());j++) {
                    if(attributes[j].name == "href") {url = attributes.at(j).value;url_attribute = j;}
                }

                // Formats the link
                std::vector<std::string> cutted = scls::cut_string(url, std::string(":"));
                if(cutted.size() < 1 || (cutted.at(0) != std::string("https") && cutted.at(0) != std::string("http"))) {
                    // Parse the link
                    cutted = scls::cut_string(scls::replace(url, std::string("#"), std::string("/")), std::string("/"));
                    std::string needed_part = current_part;std::string needed_sub_part = current_sub_part;std::string other = std::string();
                    while(cutted.size() > 0){
                        if(cutted.at(0) != std::string() && cutted.at(0) != std::string("learn")) {
                            // Format
                            std::vector<std::string> temp = scls::cut_string(cutted.at(0), std::string("."));
                            cutted[0] = temp.at(0);

                            if(__saasf_is_part(cutted.at(0))) {needed_part = cutted.at(0);}
                            else if(__saasf_is_sub_part(needed_part, cutted.at(0))) {needed_sub_part = cutted.at(0);}
                            else if(cutted.size() == 1){other += cutted.at(0);}
                        }

                        cutted.erase(cutted.begin());
                    }

                    // Create the final link
                    std::string final_link = std::string();
                    for(int i=0;i<static_cast<int>(category_to_learn);i++){final_link+=std::string("../");}
                    if(category_to_learn>0){final_link+=std::string("learn/");}
                    if(category_to_learn>0){final_link += needed_part + std::string("/");}
                    else if(needed_part != current_part){final_link += std::string("../../") + needed_part + std::string("/");}
                    if(category_to_learn>0 || needed_sub_part != current_sub_part){final_link += needed_sub_part + std::string(".html");}
                    if(other != std::string()){final_link += std::string("#") + other;}
                    attributes[url_attribute].value = final_link;
                }
            }
            else if((attribute_name == std::string("msqrt"))){
                // HMLT square root
                if(content.get()->sub_texts().at(i).get()->sub_texts().size() == 0){
                    std::shared_ptr<scls::__XML_Text_Base> content_copy = std::make_shared<scls::__XML_Text_Base>(*content.get()->sub_texts().at(i).get());
                    content_copy.get()->set_xml_balise_name(std::string("mi"));
                    content.get()->sub_texts().at(i).get()->clear();
                    content.get()->sub_texts().at(i).get()->set_xml_balise_name(attribute_name);
                    content.get()->sub_texts().at(i).get()->add_sub_balise(content_copy);
                }
                else{__saasf_images(replica, content.get()->sub_texts().at(i), path, current_replica_file_path);}
            }
            else if((attribute_name == std::string("msub") || attribute_name == std::string("msup")) && i > 0){
                // HMLT a sup
                std::shared_ptr<scls::__XML_Text_Base> content_copy = std::make_shared<scls::__XML_Text_Base>(*content.get()->sub_texts().at(i - 1).get());
                std::shared_ptr<scls::__XML_Text_Base> content_copy_sup = std::make_shared<scls::__XML_Text_Base>(*content.get()->sub_texts().at(i).get());
                content_copy_sup.get()->set_xml_balise_name(std::string("mi"));
                content.get()->sub_texts().at(i - 1).get()->clear();
                content.get()->sub_texts().at(i - 1).get()->set_xml_balise_name(attribute_name);
                content.get()->sub_texts().at(i - 1).get()->add_sub_balise(content_copy);
                content.get()->sub_texts().at(i - 1).get()->add_sub_balise(content_copy_sup);
                content.get()->sub_texts().erase(content.get()->sub_texts().begin() + i);i--;
            }
            else if(attribute_name == std::string("mvec") || attribute_name == std::string("vec")){
                // HMLT a vector
                std::shared_ptr<scls::__XML_Text_Base> content_copy = std::make_shared<scls::__XML_Text_Base>(*content.get()->sub_texts().at(i).get());
                content_copy.get()->set_xml_balise_name(std::string("mi"));
                content.get()->sub_texts().at(i).get()->clear();
                content.get()->sub_texts().at(i).get()->set_xml_balise_name(std::string("mover"));
                content.get()->sub_texts().at(i).get()->add_sub_balise(content_copy);
                content.get()->sub_texts().at(i).get()->add_sub_balise(std::string("<mo stretchy=\"false\">&#x2192;</mo>"));
            }
            else{__saasf_images(replica, content.get()->sub_texts().at(i), path, current_replica_file_path);}
        }
    }

    // Returns the pattern for SAASF
    std::string __saasf_pattern_content = std::string("&lt;!DOCTYPE html&gt;</br>&lt;html lang=\"fr\"&gt;</br>&lt;head&gt;</br>&lt;link href=\"&lt;scls_var path_to_root&gt;styles/style.css\" rel=\"stylesheet\"&gt;</br>&lt;title&gt;&lt;scls_var page_title&gt;&lt;/title&gt;</br>&lt;scls_var fonts global&gt;</br>&lt;/head&gt;</br></br>&lt;body class=\"open-sans-bold\"&gt;</br>&lt;scls_var header global&gt;</br>&lt;div id=\"main_div\"&gt;</br>&lt;h1&gt;&lt;scls_var main_title&gt;&lt;/h1&gt;</br>&lt;scls_var main_description&gt;</br>&lt;div class=\"left_arrow_right_text\"&gt;</br>&lt;scls_var explaination_parts[]&gt;</br>&lt;div class=\"left_arrow_right_text_child\"&gt;</br>&lt;img alt=\"Contenu\" class=\"arrow left_arrow_right_text_arrow\" src=\"&lt;scls_var path_to_root&gt;images/arrow.png\"&gt;</br>&lt;h2 class=\"left_arrow_right_text_title\"&gt;</br>&lt;scls_var explaination_title&gt;</br>&lt;/h2&gt;</br>&lt;div class=\"left_arrow_right_text_text\"&gt;</br>&lt;scls_var explaination_content&gt;</br>&lt;/div&gt;</br>&lt;/div&gt;</br>&lt;/scls_var&gt;</br>&lt;/div&gt;</br>&lt;/div&gt;</br>&lt;/div&gt;</br>&lt;/div&gt;</br>&lt;scls_var footer global&gt;</br>&lt;/body&gt;</br>&lt;/html&gt;");
    std::shared_ptr<scls::Pattern_Project> saasf_pattern_project(std::string path){
        std::shared_ptr<scls::Pattern_Project> to_return = std::make_shared<scls::Pattern_Project>(scls::String(std::string("pattern_project")), path);
        to_return.get()->new_pattern("main", __saasf_pattern_content);
        to_return.get()->parse_project();
        return to_return;
    }

    // Translate word for SAASF
    std::string __saasf_translate(std::string word, bool add_determinant, bool capitalise_first_letter) {
        std::string to_return = std::string();
        std::vector<std::string> cutted = scls::cut_string(word, std::string("_"));
        if(scls::string_is_number(cutted.at(0))){cutted.erase(cutted.begin());}word = std::string();
        for(int i = 0;i<static_cast<int>(cutted.size());i++){word += cutted.at(i);if(i != static_cast<int>(cutted.size()) - 1){word += std::string("_");}}

        // Creations
        if(word == "circle_algorithm"){if(add_determinant){to_return = std::string("l'algorithme de traçage du cercle");}else{to_return = std::string("algorithme de traçage du cercle");};}
        else if(word == std::string("calendar")){if(add_determinant){to_return = std::string("le calendrier");}else{to_return = std::string("calendrier");};}
        // Subjects
        else if(word == std::string("chemistry")){if(add_determinant){to_return = std::string("la chimie");}else{to_return = std::string("chimie");};}
        else if(word == std::string("it")){if(add_determinant){to_return = std::string("l'informatique");}else{to_return = std::string("informatique");}}
        else if(word == std::string("maths")){if(add_determinant){to_return = std::string("les mathématiques");}else{to_return = std::string("mathématiques");}}
        else if(word == std::string("physic")){if(add_determinant){to_return = std::string("la physique");}else{to_return = std::string("physique");}}
        // Sub-subjects
        else if(word == std::string("algebra")){if(add_determinant){to_return = std::string("l'algèbre");}else{to_return = std::string("algèbre");};}
        else if(word == std::string("analysis")){if(add_determinant){to_return = std::string("l'analyse");}else{to_return = std::string("analyse");};}
        else if(word == std::string("arithmetic")){if(add_determinant){to_return = std::string("l'arithmétique");}else{to_return = std::string("arithmétique");};}
        else if(word == std::string("algorithms")){if(add_determinant){to_return = std::string("les algorithmes");}else{to_return = std::string("algorithme");};}
        else if(word == std::string("bases")){if(add_determinant){to_return = std::string("les bases");}else{to_return = std::string("bases");};}
        else if(word == std::string("cryptography")){if(add_determinant){to_return = std::string("la cryptographie");}else{to_return = std::string("cryptographie");};}
        else if(word == std::string("data_structures")){if(add_determinant){to_return = std::string("les structures de données");}else{to_return = std::string("structures de données");};}
        else if(word == std::string("functions")){if(add_determinant){to_return = std::string("les fonctions");}else{to_return = std::string("fonctions");};}
        else if(word == std::string("geometry")){if(add_determinant){to_return = std::string("la géométrie");}else{to_return = std::string("géométrie");};}
        else if(word == std::string("hardware")){if(add_determinant){to_return = std::string("l'hardware");}else{to_return = std::string("hardware");};}
        else if(word == std::string("introduction")){if(add_determinant){to_return = std::string("l'introduction");}else{to_return = std::string("introduction");};}
        else if(word == std::string("logic")){if(add_determinant){to_return = std::string("la logique");}else{to_return = std::string("logique");};}
        else if(word == std::string("matter")){if(add_determinant){to_return = std::string("la matière");}else{to_return = std::string("matière");};}
        else if(word == std::string("mechanic")){if(add_determinant){to_return = std::string("la mécanique");}else{to_return = std::string("mécanique");};}
        else if(word == std::string("network")){if(add_determinant){to_return = std::string("le réseau");}else{to_return = std::string("réseau");};}
        else if(word == std::string("os")){if(add_determinant){to_return = std::string("les systèmes d'exploitation");}else{to_return = std::string("systèmes d'exploitation");};}
        else if(word == std::string("probability")){if(add_determinant){to_return = std::string("les probabilités");}else{to_return = std::string("probabilités");};}
        else if(word == std::string("random")){if(add_determinant){to_return = std::string("les sciences du hasard");}else{to_return = std::string("sciences du hasard");};}
        else if(word == std::string("thermodynamic")){if(add_determinant){to_return = std::string("la thermodynamique");}else{to_return = std::string("thermodynamique");};}
        else if(word == std::string("topology")){if(add_determinant){to_return = std::string("la topologie");}else{to_return = std::string("topologie");}}

        // Others
        else if(word == std::string("chapter")){if(add_determinant){to_return = std::string("le chapitre");}else{to_return = std::string("chapitre");}}
        else if(word == std::string("definitions")){if(add_determinant){to_return = std::string("les définitions");}else{to_return = std::string("définitions");}}

        // Capitalise the first letter
        if(to_return == std::string()) {scls::print("PLEOS", std::string("Can't translate the word \"") + word + "\" for SAASF.");}
        else{if(capitalise_first_letter) {to_return = scls::capitalise_letter(to_return, 0);}}

        return to_return;
    }

    // Parts of SAASF
    // Index.html
    // Realisation
    std::string __saasf_index_realisation = std::string("Ce site web est réalisé avec les très célèbres langages HTML et CSS, vu en SNT (même si le niveau néessaire pour créer un site de ce genre est bien supérieur à celui demandé en SNT). Pour la structuration, nous utilisation les outils \"Agatha\" du logiciel \"SCLS Workspace\", et \"PLEOS\" notre organisation. La version actuelle du site web, modifiée le 22/09/2025, a été soumise à un contrôle précis de toutes les informations transmises par PLEOS, mais ne peut pas garantir que tout fonctionne comme prévu. Cependant, il est déjà possible d'y découvrir des choses assez intéressantes !");

    // Convert the entire software in SAASF
    std::string __saasf_global_footer_content = std::string("&lt;footer&gt;</br>    &lt;h1&gt;Plus d'informations&lt;/h1&gt;</br> &lt;div class=\"open-sans-regular\"&gt;</br>SAASF est proposé par l'organisation &lt;a href=\"https://aster-system.github.io/aster-system/\" target=\"_blank\"&gt;Aster Système&lt;/a&gt;.&lt;br&gt;</br>  Le site web est disponible sur Github, &lt;a href=\"https://github.com/aster-system/saasf\" target=\"_blank\"&gt;dans ce repositorie&lt;/a&gt;.&lt;br&gt;</br>  &lt;span xmlns:cc=\"http://creativecommons.org/ns#\" xmlns:dct=\"http://purl.org/dc/terms/\"&gt;</br>Le texte dans &lt;a property=\"dct:title\" rel=\"cc:attributionURL\" href=\"https://aster-system.github.io/saasf/\"&gt;SAASF&lt;/a&gt; par</br>  &lt;span property=\"cc:attributionName\"&gt;Aster Système&lt;/span&gt; est proposé sous license &lt;a href=\"https://creativecommons.org/licenses/by-sa/4.0/?ref=chooser-v1\" target=\"_blank\" rel=\"license noopener noreferrer\" style=\"display:inline-block;\"&gt;CC BY-SA 4.0&lt;img style=\"height:22px!important;margin-left:3px;vertical-align:text-bottom;\" src=\"https://mirrors.creativecommons.org/presskit/icons/cc.svg?ref=chooser-v1\" alt=\"\"&gt;&lt;img style=\"height:22px!important;margin-left:3px;vertical-align:text-bottom;\" src=\"https://mirrors.creativecommons.org/presskit/icons/by.svg?ref=chooser-v1\" alt=\"\"&gt;&lt;img style=\"height:22px!important;margin-left:3px;vertical-align:text-bottom;\" src=\"https://mirrors.creativecommons.org/presskit/icons/sa.svg?ref=chooser-v1\" alt=\"\"&gt;&lt;/a&gt;</br>  &lt;/span&gt;</br>&lt;/br&gt;Sauf indication contraire, les images sont placées dans le domaine public.&lt;/div&gt;</br>&lt;/footer&gt;");
    std::string __saasf_global_font_content = std::string("&lt;link rel=\"preconnect\" href=\"https://fonts.googleapis.com\"&gt;</br>&lt;link rel=\"preconnect\" href=\"https://fonts.gstatic.com\" crossorigin=\"\"&gt;</br>&lt;link href=\"https://fonts.googleapis.com/css2?family=Hammersmith+One&amp;display=swap\" rel=\"stylesheet\"&gt;</br>&lt;link href=\"https://fonts.googleapis.com/css2?family=Open+Sans:ital,wght@0,300..800;1,300..800&amp;display=swap\" rel=\"stylesheet\"&gt;</br>");
    std::string __saasf_global_header_content = std::string("&lt;header class=\"hammersmith-one-regular\"&gt;</br>&lt;a href=\"&lt;scls_var path_to_root&gt;index.html\"&gt;</br>    &lt;img alt=\"Logo de SAASF\" src=\"&lt;scls_var path_to_root&gt;images/aster_system_logo.png\" style=\"max-height:150px;\"&gt;</br>&lt;/a&gt;</br>&lt;/header&gt;");
    struct __SAASF_Subjet_Part {std::string name;int number=0;std::string path;};
    bool __saasf_sort_subjects(__SAASF_Subjet_Part& subject_1, __SAASF_Subjet_Part& subject_2){return subject_1.number < subject_2.number;};
    std::string __saasf_style = std::string("a {color: white;}.arrow {transform: rotate(90deg);height: 0.6em;}body {background-color: rgb(0, 33, 91);box-sizing: border-box;color: white;font-size: 18px;margin: 0;max-width: 100vw;}.code_sample {background-color: rgb(30, 30, 30);border: black solid 3px;color: white;margin: 2px;padding: 5px;}footer {background-color: white;color: black;padding: 4px;}footer a {color: black;}footer h1 {font-size: 2em;margin: 0;}header {background-color: white;color: black;display: flex;height: 150px;width: 100%;}header nav {height: 100%;position: relative;display: flex;flex: 1;justify-content: space-around;}header nav div {align-content: center;font-size: 300%;height: 100%;}header nav div a {color: black;}h4 {background-color: rgb(51, 51, 255);color: white;}.important {color: red;}.important a {color: red;}.left_arrow_right_text {display: flex;flex-direction: column;width: 100%;}.left_arrow_right_text_child {display: grid;grid-auto-columns: max-content;}.left_arrow_right_text_arrow {grid-column: 1;grid-row: 2;height: 2em;max-width: 15vw;}.left_arrow_right_text_text {grid-column: 2;grid-row: 2;max-width: 85vw;width: 100%;}.left_arrow_right_text_title {grid-column: 2;grid-row: 1;max-width: 85vw;}#main_div {margin: 8px;}#main_div h1 {font-size: 4em;}#main_div h2 {font-size: 2.5em;}table {background-color: white;color: black;}table, th, td {border: 1px solid black;border-collapse: collapse;}.voc {background-color: rgb(220, 220, 220);}.hammersmith-one-regular {font-family: \"Hammersmith One\", sans-serif;font-weight: 400;font-style: normal;}.open-sans-bold {font-family: \"Open Sans\", sans-serif;font-optical-sizing: auto;font-weight: 700;font-style: normal;font-variation-settings: \"wdth\" 100;}.open-sans-regular {font-family: \"Open Sans\", sans-serif;font-optical-sizing: auto;font-weight: 400;font-style: normal;font-variation-settings: \"wdth\" 100;}");
    void Hub_Page::to_saasf(std::string assets, std::string path){
        // Get the needed datas
        __saasf_text_environment = std::make_shared<Text_Environment>();__saasf_text_environment.get()->load_definitions_from_path(std::string("assets/definitions"));
        std::vector<std::string> creations = scls::directory_content(assets + std::string("/creations/"));
        std::vector<std::string> subjects = scls::directory_content(assets + std::string("/plugins/"));
        for(int i = 0;i<static_cast<int>(creations.size());i++){std::vector<std::string>cutted=scls::cut_string(creations[i], "/");creations[i]=cutted[cutted.size()-1];cutted=scls::cut_string(creations[i], ".");creations[i]=cutted[0];}
        for(int i = 0;i<static_cast<int>(subjects.size());i++){std::vector<std::string>cutted=scls::cut_string(subjects[i], "/");subjects[i]=cutted[cutted.size()-1];}

        // Create the pattern project
        std::filesystem::create_directory(path + std::string("saasf_export/"));
        std::shared_ptr<scls::Pattern_Project> needed_pattern = saasf_pattern_project(path);

        // Create the replica project
        std::shared_ptr<scls::Replica_Project> needed_replica = std::make_shared<scls::Replica_Project>("saasf", path, needed_pattern);
        // Set the global variables
        needed_replica.get()->set_global_variable_value("footer", __saasf_global_footer_content);
        needed_replica.get()->set_global_variable_value("font", __saasf_global_font_content);
        needed_replica.get()->set_global_variable_value("header", __saasf_global_header_content);

        // Add the style
        needed_replica.get()->new_replica_file("styles/style.css", 0)->content_out_pattern = __saasf_style;

        // Add the pages

        // Index.html
        std::shared_ptr<scls::Replica_File> index = needed_replica.get()->new_replica_file("index.html", needed_pattern.get()->pattern_by_name("main"));
        index.get()->set_variable_value(std::string("main_title"), std::string("SAASF"));
        index.get()->set_variable_value(std::string("main_description"), std::string("SAASF, pour Service d'Apprentissage d'Aster Système en Français, est une branche de l'organisation &lt;a href=\"https://aster-system.github.io/aster-system/\"&gt;Aster Système&lt;/a&gt;. Il s'agit d'un site web, regroupant pleins d'informations structurées sous forme Wiki sur divers sujets pris par, entre autre, le créateur de l'organisation."));
        index.get()->set_variable_value(std::string("page_title"), std::string("SAASF - Hub"));
        // Explaination
        scls::Replica_File_Variable_Element* element = index.get()->variable_list(std::string("explaination_parts[]"))->new_element<scls::Replica_File_Variable_Element>();
        element->set_variable_value(std::string("explaination_title"), std::string("Réalisation"));
        element->set_variable_value(std::string("explaination_content"), __saasf_index_realisation);
        // Aster System Learn
        element = index.get()->variable_list(std::string("explaination_parts[]"))->new_element<scls::Replica_File_Variable_Element>();
        element->set_variable_value(std::string("explaination_title"), std::string("Aster Système Learn"));
        std::string explaination_content = std::string("Voici la liste de tous les savoirs accessibles sur les médias (Youtube, Tiktok, Instagram...) d'Aster Système Learn pour l'instant :&lt;ul&gt;");
        for(int i = 0;i<static_cast<int>(subjects.size());i++){explaination_content += std::string("&lt;li&gt;&lt;a href=\"./learn/") + subjects[i] + std::string(".html\"&gt;") + __saasf_translate(subjects.at(i), true, true) + std::string("&lt;/a&gt;&lt;/li&gt;");}
        explaination_content += std::string("&lt;li&gt;&lt;a href=\"./learn/definitions.html\"&gt;") + __saasf_translate(std::string("definitions"), false, true) + std::string("&lt;/a&gt;&lt;/li&gt;");
        explaination_content += std::string("&lt;/ul&gt;");
        element->set_variable_value(std::string("explaination_content"), explaination_content);
        // Aster System Creations
        element = index.get()->variable_list(std::string("explaination_parts[]"))->new_element<scls::Replica_File_Variable_Element>();
        element->set_variable_value(std::string("explaination_title"), std::string("Les créations Aster Système"));
        explaination_content = std::string("Voici la liste de toutes les créations Open Source d'Aster Système :&lt;ul&gt;");
        for(int i = 0;i<static_cast<int>(creations.size());i++){explaination_content += std::string("&lt;li&gt;&lt;a href=\"./creations/") + creations[i] + std::string(".html\"&gt;") + __saasf_translate(creations.at(i), true, true) + std::string("&lt;/a&gt;&lt;/li&gt;");}
        explaination_content += std::string("&lt;/ul&gt;");
        element->set_variable_value(std::string("explaination_content"), explaination_content);

        // Subjects main pages
        for(int i = 0;i<static_cast<int>(subjects.size());i++) {
            // Asserts
            if(!__saasf_is_part(subjects.at(i))){continue;}

            // Create the file
            std::string subject_file_name = std::string("learn/") + subjects[i] + std::string(".html");
            std::shared_ptr<scls::Replica_File> current_file = needed_replica.get()->new_replica_file(subject_file_name, needed_pattern.get()->pattern_by_name("main"));
            current_file.get()->set_variable_value(std::string("main_title"), __saasf_translate(subjects.at(i), true, true));
            current_file.get()->set_variable_value(std::string("main_description"), scls::format_string_from_plain_text(scls::format_string_break_line(scls::read_file(assets + std::string("/plugins/") + subjects.at(i) + std::string("/home/definition.txt")), std::string(" "))));
            current_file.get()->set_variable_value(std::string("page_title"), std::string("SAASF - ") + __saasf_translate(subjects.at(i), false, true));

            // Preparation of the page
            std::vector<std::string> cutted;
            std::vector<std::string> sub_subjects = scls::directory_content(assets + std::string("/plugins/") + subjects[i]);
            int course = -1;for(int i = 0;i<static_cast<int>(sub_subjects.size());i++){std::vector<std::string>cutted=scls::cut_string(sub_subjects.at(i), std::string("\\"));if(cutted.at(cutted.size() - 1) == std::string("course")){course=i;break;}}

            if(course > -1) {
                // Course
                scls::Replica_File_Variable_Element* element = current_file.get()->variable_list(std::string("explaination_parts[]"))->new_element<scls::Replica_File_Variable_Element>();
                element->set_variable_value(std::string("explaination_title"), std::string("Le cours"));
                explaination_content = std::string("Voici la liste de tous les savoirs accessible sur ") + __saasf_translate(subjects.at(i), true, false) + std::string(" sous le format \"Cours\" pour l'instant :&lt;ul&gt;");
                std::string explaination_content_school = std::string("Certains cours proposé ici parlent aussi des programmes proposés par l'éducation nationale au lycée. En général, ils sont accompagnés de commentaires, visant leur contenu. Voici les programmes décrits :&lt;ul&gt;");

                // Get the sub-files
                std::vector<std::string> chapters = scls::directory_content(sub_subjects.at(course));
                for(int i = 0;i<static_cast<int>(chapters.size());i++){if(static_cast<int>(chapters.at(i).size()) >= 11 && chapters.at(i).substr(chapters.at(i).size() - 11, 11) == std::string("program.txt")){chapters.erase(chapters.begin() + i);break;}}
                std::vector<std::string> program = scls::cut_string(scls::read_file(sub_subjects.at(course) + std::string("/program.txt")), std::string("\n"));
                for(int j = 0;j<static_cast<int>(chapters.size());j++){
                    if(std::filesystem::is_directory(chapters[j])){
                        cutted = scls::cut_string(chapters[j], "/");
                        cutted = scls::cut_string(cutted[cutted.size() - 1], "\\");
                        std::string sub_subject_name = cutted[cutted.size() - 1];
                        if(sub_subject_name != std::string("home") && sub_subject_name != std::string("school")) {
                            // Get the precise title
                            cutted = scls::cut_string(sub_subject_name, std::string("_"));
                            std::string title = __saasf_translate(cutted.at(0), true, true) + std::string(" ") + cutted.at(1);

                            std::string file_name = subjects[i] + std::string("/") + sub_subject_name + std::string(".html");
                            std::string file_name_complete = std::string("learn/") + file_name;
                            if(static_cast<int>(program.size()) <= j){explaination_content += std::string("&lt;li&gt;&lt;a href=\"./") + file_name + std::string("\"&gt;") + title + std::string("&lt;/a&gt;&lt;/li&gt;");}
                            else{explaination_content += std::string("&lt;li&gt;&lt;a href=\"./") + file_name + std::string("\"&gt;") + title + std::string(" - ") + program.at(j) + std::string("&lt;/a&gt;&lt;/li&gt;");}

                            // Add the needed file
                            std::shared_ptr<scls::Replica_File> needed_file = needed_replica.get()->new_replica_file(file_name_complete, needed_pattern.get()->pattern_by_name("main"));
                            needed_file.get()->set_variable_value(std::string("main_title"), title);
                            needed_file.get()->set_variable_value(std::string("main_description"), std::string());
                            needed_file.get()->set_variable_value(std::string("page_title"), std::string("SAASF - ") + title);

                            // Set the good content
                            cutted = scls::directory_content(assets + std::string("/plugins/") + subjects[i] + std::string("/course/") + sub_subject_name + std::string("/"));
                            std::vector<__SAASF_Subjet_Part> parts;
                            for(int j = 0;j<static_cast<int>(cutted.size());j++){
                                std::vector<std::string>cutted_temp=scls::cut_string(cutted[j],std::string("/"));
                                cutted_temp=scls::cut_string(cutted_temp[cutted_temp.size() - 1],std::string("\\"));
                                cutted_temp=scls::cut_string(cutted_temp[cutted_temp.size() - 1],std::string("_"));
                                if(cutted_temp.size() > 0 && scls::string_is_number(cutted_temp[0])){
                                    __SAASF_Subjet_Part to_add;
                                    to_add.name = cutted_temp[0];
                                    to_add.number = std::stoi(cutted_temp[0]);
                                    to_add.path = cutted[j];

                                    parts.push_back(to_add);
                                }
                            }
                            std::sort(parts.begin(), parts.end(), __saasf_sort_subjects);
                            for(int k = 0;k<static_cast<int>(parts.size());k++) {
                                std::shared_ptr<scls::__XML_Text_Base> file_content = scls::xml(window_struct()->balises_shared_ptr(), scls::format_string_break_line(scls::read_file(parts[k].path), std::string(" ")));
                                file_content.get()->replace_balise_by_name("h3", "h4");file_content.get()->replace_balise_by_name("h2", "h3");
                                file_content.get()->replace_balise_by_name("important", "span class=\"important\"");
                                utf_8_symbol_xml(file_content, true);
                                __saasf_images(needed_replica.get(), file_content, needed_replica.get()->export_path(path), file_name_complete);
                                scls::Replica_File_Variable_Element* current_part = needed_file.get()->variable_list(std::string("explaination_parts[]"))->new_element<scls::Replica_File_Variable_Element>();
                                std::shared_ptr<scls::__XML_Text_Base> title = file_content.get()->remove_balise_by_name("h1");
                                if(title.get() != 0){current_part->set_variable_value(std::string("explaination_title"), title.get()->text());}
                                current_part->set_variable_value(std::string("explaination_content"), scls::format_string_from_plain_text(file_content.get()->full_text()));
                            }
                        }
                    }
                }
                for(int j = chapters.size();j<static_cast<int>(program.size());j++){explaination_content += std::string("&lt;li&gt;") + __saasf_translate(std::string("chapter"), true, true) + std::string(" ") + std::to_string(j) + std::string(" (bientôt disponible) - ") + program.at(j) + std::string("&lt;/li&gt;");}
                element->set_variable_value(std::string("explaination_content"), explaination_content);
            }

            // Explaination
            scls::Replica_File_Variable_Element* element = current_file.get()->variable_list(std::string("explaination_parts[]"))->new_element<scls::Replica_File_Variable_Element>();
            element->set_variable_value(std::string("explaination_title"), std::string("Les différents brouillons"));
            explaination_content = std::string("Voici la liste de tous les savoirs en préparation sur ") + __saasf_translate(subjects.at(i), true, false) + std::string(" sur les médias (Youtube, Tiktok, Instagram...) d'Aster Système Learn pour l'instant :&lt;ul&gt;");
            std::string explaination_content_school = std::string("Certains cours proposé ici parlent aussi des programmes proposés par l'éducation nationale au lycée. En général, ils sont accompagnés de commentaires, visant leur contenu. Voici les programmes décrits :&lt;ul&gt;");
            bool use_school = false;

            // Get the sub-files
            for(int j = 0;j<static_cast<int>(sub_subjects.size());j++){
                if(j != course && std::filesystem::is_directory(sub_subjects[j])){
                    cutted = scls::cut_string(sub_subjects[j], "/");
                    cutted = scls::cut_string(cutted[cutted.size() - 1], "\\");
                    std::string sub_subject_name = cutted[cutted.size() - 1];
                    if(sub_subject_name != std::string("home") && sub_subject_name != std::string("school")) {
                        std::string file_name = subjects[i] + std::string("/") + sub_subject_name + std::string(".html");
                        std::string file_name_complete = std::string("learn/") + file_name;
                        explaination_content += std::string("&lt;li&gt;&lt;a href=\"./") + file_name + std::string("\"&gt;") + __saasf_translate(sub_subject_name, true, true) + std::string("&lt;/a&gt;&lt;/li&gt;");

                        // Add the needed file
                        std::shared_ptr<scls::Replica_File> needed_file = needed_replica.get()->new_replica_file(file_name_complete, needed_pattern.get()->pattern_by_name("main"));
                        needed_file.get()->set_variable_value(std::string("main_title"), __saasf_translate(sub_subject_name, true, true));
                        needed_file.get()->set_variable_value(std::string("main_description"), std::string());
                        needed_file.get()->set_variable_value(std::string("page_title"), std::string("SAASF - ") + __saasf_translate(sub_subject_name, false, true));

                        // Set the good content
                        cutted = scls::directory_content(assets + std::string("/plugins/") + subjects[i] + std::string("/") + sub_subject_name + std::string("/"));
                        std::vector<__SAASF_Subjet_Part> parts;
                        for(int j = 0;j<static_cast<int>(cutted.size());j++){
                            std::vector<std::string>cutted_temp=scls::cut_string(cutted[j],std::string("/"));
                            cutted_temp=scls::cut_string(cutted_temp[cutted_temp.size() - 1],std::string("\\"));
                            cutted_temp=scls::cut_string(cutted_temp[cutted_temp.size() - 1],std::string("_"));
                            if(cutted_temp.size() > 0 && scls::string_is_number(cutted_temp[0])){
                                __SAASF_Subjet_Part to_add;
                                to_add.name = cutted_temp[0];
                                to_add.number = std::stoi(cutted_temp[0]);
                                to_add.path = cutted[j];

                                parts.push_back(to_add);
                            }
                        }
                        std::sort(parts.begin(), parts.end(), __saasf_sort_subjects);
                        for(int k = 0;k<static_cast<int>(parts.size());k++) {
                            std::shared_ptr<scls::__XML_Text_Base> file_content = scls::xml(window_struct()->balises_shared_ptr(), scls::format_string_break_line(scls::read_file(parts[k].path), std::string(" ")));
                            file_content.get()->replace_balise_by_name("h3", "h4");file_content.get()->replace_balise_by_name("h2", "h3");
                            file_content.get()->replace_balise_by_name("important", "span class=\"important\"");
                            utf_8_symbol_xml(file_content, true);
                            __saasf_images(needed_replica.get(), file_content, needed_replica.get()->export_path(path), file_name_complete);
                            scls::Replica_File_Variable_Element* current_part = needed_file.get()->variable_list(std::string("explaination_parts[]"))->new_element<scls::Replica_File_Variable_Element>();
                            std::shared_ptr<scls::__XML_Text_Base> title = file_content.get()->remove_balise_by_name("h1");
                            if(title.get() != 0){current_part->set_variable_value(std::string("explaination_title"), title.get()->text());}
                            current_part->set_variable_value(std::string("explaination_content"), scls::format_string_from_plain_text(file_content.get()->full_text()));
                        }
                    }
                    else if(sub_subject_name == std::string("school")) {
                        use_school = true;
                        std::string file_name = subjects[i] + std::string("/") + sub_subject_name + std::string(".html");
                        std::string file_name_complete = std::string("learn/") + file_name;
                        explaination_content_school += std::string("&lt;li&gt;&lt;a href=\"./") + file_name + std::string("\"&gt;") + std::string("Lycée") + std::string("&lt;/a&gt;&lt;/li&gt;");

                        // Add the needed file
                        std::shared_ptr<scls::Replica_File> needed_file = needed_replica.get()->new_replica_file(file_name_complete, needed_pattern.get()->pattern_by_name("main"));
                        needed_file.get()->set_variable_value(std::string("main_title"), std::string("Au lycée"));
                        needed_file.get()->set_variable_value(std::string("main_description"), std::string());
                        needed_file.get()->set_variable_value(std::string("page_title"), std::string("SAASF - Lycée"));

                        // Set the good content
                        cutted = scls::directory_content(assets + std::string("/plugins/") + subjects[i] + std::string("/") + sub_subject_name);
                        std::vector<__SAASF_Subjet_Part> parts;
                        for(int j = 0;j<static_cast<int>(cutted.size());j++){
                            std::vector<std::string>cutted_temp=scls::cut_string(cutted[j],std::string("/"));
                            cutted_temp=scls::cut_string(cutted_temp[cutted_temp.size() - 1],std::string("\\"));
                            cutted_temp=scls::cut_string(cutted_temp[cutted_temp.size() - 1],std::string("."));
                            cutted_temp=scls::cut_string(cutted_temp[0],std::string("_"));
                            if(cutted_temp.size() > 1 && scls::string_is_number(cutted_temp[1])){
                                __SAASF_Subjet_Part to_add;
                                to_add.name = cutted_temp[0];
                                to_add.number = std::stoi(cutted_temp[1]);
                                to_add.path = cutted[j];

                                parts.push_back(to_add);
                            }
                        }
                        std::sort(parts.begin(), parts.end(), __saasf_sort_subjects);
                        // Add each parts
                        for(int k = 0;k<static_cast<int>(parts.size());k++) {
                            std::shared_ptr<scls::__XML_Text_Base> file_content = scls::xml(window_struct()->balises_shared_ptr(), scls::format_string_break_line(scls::read_file(parts[k].path), std::string(" ")));
                            file_content.get()->replace_balise_by_name("h3", "h4");file_content.get()->replace_balise_by_name("h2", "h3");
                            file_content.get()->replace_balise_by_name("important", "span class=\"important\"");
                            utf_8_symbol_xml(file_content, true);
                            __saasf_images(needed_replica.get(), file_content, needed_replica.get()->export_path(path), file_name_complete);
                            scls::Replica_File_Variable_Element* current_part = needed_file.get()->variable_list(std::string("explaination_parts[]"))->new_element<scls::Replica_File_Variable_Element>();
                            std::shared_ptr<scls::__XML_Text_Base> title = file_content.get()->remove_balise_by_name("h1");
                            if(title.get() != 0){current_part->set_variable_value(std::string("explaination_title"), title.get()->text());}
                            current_part->set_variable_value(std::string("explaination_content"), scls::format_string_from_plain_text(file_content.get()->full_text()));
                        }
                    }
                }
            }
            element->set_variable_value(std::string("explaination_content"), explaination_content);

            if(use_school) {
                // School part
                explaination_content_school += std::string("&lt;/ul&gt;");
                element = current_file.get()->variable_list(std::string("explaination_parts[]"))->new_element<scls::Replica_File_Variable_Element>();
                element->set_variable_value(std::string("explaination_title"), std::string("Les programmes de lycée"));
                element->set_variable_value(std::string("explaination_content"), explaination_content_school);
            }
        }

        // Definitions page
        index = needed_replica.get()->new_replica_file("learn/definitions.html", needed_pattern.get()->pattern_by_name("main"));
        index.get()->set_variable_value(std::string("main_title"), std::string("SAASF - Définitions"));
        index.get()->set_variable_value(std::string("main_description"), std::string("Le site web est développé avec PLEOS, offrant un système de définition permettant d'efficacement y accéder. Toutes ces définitions sont présentes ici."));
        index.get()->set_variable_value(std::string("page_title"), std::string("SAASF - Définitions"));
        // Add each definitions
        element = index.get()->variable_list(std::string("explaination_parts[]"))->new_element<scls::Replica_File_Variable_Element>();
        element->set_variable_value(std::string("explaination_title"), std::string("Toutes les définitions"));
        explaination_content = std::string("Un système de classification plus précis pour chaque définitions est à venir. En attendant, voici toutes les définitions accessibles :&lt;ul&gt;");
        for(int i = 0;i<static_cast<int>(__saasf_text_environment.get()->definitions().size());i++){
            explaination_content += std::string("&lt;li&gt;") + __saasf_text_environment.get()->definitions().at(i).get()->content(true) + std::string("&lt;/li&gt;");
        }
        explaination_content += std::string("&lt;/ul&gt;");
        element->set_variable_value(std::string("explaination_content"), explaination_content);

        /*
        // Explaination
        scls::Replica_File_Variable_Element* element = index.get()->variable_list(std::string("explaination_parts[]"))->new_element<scls::Replica_File_Variable_Element>();
        element->set_variable_value(std::string("explaination_title"), std::string("Réalisation"));
        element->set_variable_value(std::string("explaination_content"), __saasf_index_realisation);
        // Aster System Learn
        element = index.get()->variable_list(std::string("explaination_parts[]"))->new_element<scls::Replica_File_Variable_Element>();
        element->set_variable_value(std::string("explaination_title"), std::string("Aster Système Learn"));
        std::string explaination_content = std::string("Voici la liste de tous les savoirs accessibles sur les médias (Youtube, Tiktok, Instagram...) d'Aster Système Learn pour l'instant :&lt;ul&gt;");
        for(int i = 0;i<static_cast<int>(subjects.size());i++){explaination_content += std::string("&lt;li&gt;&lt;a href=\"./learn/") + subjects[i] + std::string(".html\"&gt;") + __saasf_translate(subjects.at(i), true, true) + std::string("&lt;/a&gt;&lt;/li&gt;");}
        explaination_content += std::string("&lt;/ul&gt;");
        element->set_variable_value(std::string("explaination_content"), explaination_content);
        // Aster System Creations
        element = index.get()->variable_list(std::string("explaination_parts[]"))->new_element<scls::Replica_File_Variable_Element>();
        element->set_variable_value(std::string("explaination_title"), std::string("Les créations Aster Système"));
        explaination_content = std::string("Voici la liste de toutes les créations Open Source d'Aster Système :&lt;ul&gt;");
        for(int i = 0;i<static_cast<int>(creations.size());i++){explaination_content += std::string("&lt;li&gt;&lt;a href=\"./creations/") + creations[i] + std::string(".html\"&gt;") + __saasf_translate(creations.at(i), true, true) + std::string("&lt;/a&gt;&lt;/li&gt;");}
        explaination_content += std::string("&lt;/ul&gt;");
        element->set_variable_value(std::string("explaination_content"), explaination_content);
        //*/

        // Creation main pages
        for(int i = 0;i<static_cast<int>(creations.size());i++){
            std::string creation_name = creations.at(i);
            std::string file_name = creation_name + std::string(".html");
            std::string file_name_complete = std::string("creations/") + file_name;

            //explaination_content += std::string("&lt;li&gt;&lt;a href=\"./") + file_name + std::string("\"&gt;") + __saasf_translate(creation_name, true, true) + std::string("&lt;/a&gt;&lt;/li&gt;");

            // Add the needed file
            std::shared_ptr<scls::Replica_File> needed_file = needed_replica.get()->new_replica_file(file_name_complete, needed_pattern.get()->pattern_by_name("main"));
            needed_file.get()->set_variable_value(std::string("main_title"), __saasf_translate(creation_name, true, true));
            needed_file.get()->set_variable_value(std::string("main_description"), std::string());
            needed_file.get()->set_variable_value(std::string("page_title"), std::string("SAASF - ") + __saasf_translate(creation_name, false, true));

            // Add the text
            std::shared_ptr<scls::__XML_Text_Base> file_content = scls::xml(window_struct()->balises_shared_ptr(), scls::format_string_break_line(scls::read_file(assets + std::string("/creations/") + creation_name + std::string(".txt")), std::string(" ")));;
            file_content.get()->replace_balise_by_name("h3", "h4");file_content.get()->replace_balise_by_name("h2", "h3");
            file_content.get()->replace_balise_by_name("important", "span class=\"important\"");
            utf_8_symbol_xml(file_content, true);
            __saasf_images(needed_replica.get(), file_content, needed_replica.get()->export_path(path), file_name_complete);
            scls::Replica_File_Variable_Element* current_part = needed_file.get()->variable_list(std::string("explaination_parts[]"))->new_element<scls::Replica_File_Variable_Element>();
            std::shared_ptr<scls::__XML_Text_Base> title = file_content.get()->remove_balise_by_name("h1");
            if(title.get() != 0){current_part->set_variable_value(std::string("explaination_title"), title.get()->text());}
            current_part->set_variable_value(std::string("explaination_content"), scls::format_string_from_plain_text(file_content.get()->full_text()));
        }

        // Create the main file
        needed_replica.get()->export_project(path, window_struct()->balises_shared_ptr().get());

        // Create the images
        path = needed_replica.get()->export_path(path);
        std::filesystem::create_directory(path + std::string("/images/"));
        scls::aster_system_logo().get()->save_png(path + std::string("/images/aster_system_logo.png"));
        std::shared_ptr<scls::__Image_Base> arrow = std::make_shared<scls::__Image_Base>(200, 154, scls::Color(0, 0, 0, 0));
        arrow.get()->fill_triangle(0, arrow.get()->height(), arrow.get()->width(), arrow.get()->height(), arrow.get()->width() / 2, 0, scls::Color(255, 0, 0));
        arrow.get()->save_png(path + std::string("/images/arrow.png"));

        std::cout << "L " << path << std::endl;
    };
}
