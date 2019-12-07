/*
** EPITECH PROJECT, 2019
** IGraphicWrapper.hpp
** File description:
**
*/

#ifndef R_TYPE_CLIENT_IGRAPHICWRAPPER_HPP
#define R_TYPE_CLIENT_IGRAPHICWRAPPER_HPP

namespace rtype {
    class IGraphicWrapper {
        public:
            virtual void createWindows(size_t width, size_t height) = 0;
            virtual void setBackground(const std::string &image1,
                                       const std::string &image2) = 0;
            virtual void drawBackground() = 0;
    };
}

#endif //R_TYPE_CLIENT_IGRAPHICWRAPPER_HPP
