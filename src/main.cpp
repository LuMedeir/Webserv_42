//
// Created by vinicius on 11/2/24.
//


#include <cstdlib>
#include <iostream>
#include <map>
#include <string>

#include "common.hpp"
#include "parser_config_file/CheckFile.hpp"
#include "parser_config_file/ConfigParser.hpp"

int main(int argc, char* argv[])
{
    std::string configuration_file;

    if (argc < 2)
        configuration_file = DEFAULT_CONFIG_FILE;
    else
        configuration_file = argv[1];

    CheckFile(configuration_file);

    try
    {
        ConfigParser parser;
        std::vector<Server> servers = parser.parse(configuration_file);

        for (std::vector<Server>::const_iterator it = servers.begin(); it != servers.end(); ++it)
            std::cout << *it << std::endl;

    }
    catch (const ConfigParseError& e)
    {
        std::cerr << "Error on line " << e.getLine() << ": " << e.what() << std::endl;
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}
