/*
** EPITECH PROJECT, 2019
** MyProgArgs.hpp
** File description:
**
*/

#ifndef MYPROGARGS_HPP
#define MYPROGARGS_HPP

#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include <exception>

namespace uti {
    class CannotOpenFile : public std::exception {};
    class MyProgArgs {
        public:
            MyProgArgs(int argc, char **argv) : _argv{argv, argv + argc} {};
            [[nodiscard]] std::vector<std::string> getArgs() const { return _argv; }
            [[nodiscard]] std::size_t getSize() const { return _argv.size(); }
            [[nodiscard]] std::string getExecutableName() const { return _argv.front(); }
            [[nodiscard]] std::fstream openFile(std::size_t index) const
            {
                std::fstream file;
                file.open(this->_argv.at(index), std::fstream::in);
                if (!file.is_open()) {
                    std::cerr << "Error : failed to open " << _argv.at(1) << std::endl;
                    throw uti::CannotOpenFile();
                }
                return file;
            }
        private:
            std::vector<std::string> _argv;
    };
}


#endif //MYPROGARGS_HPP
