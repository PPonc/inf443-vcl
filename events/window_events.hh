//
// Created by pponchon on 17/03/2022.
//

#ifndef ANIMATIONVCL_WINDOW_EVENTS_HH
#define ANIMATIONVCL_WINDOW_EVENTS_HH

#include "event.hh"

#include <sstream>

namespace vcl::event {

    class WindowResizeEvent : public Event {
    public:
        WindowResizeEvent(int w, int h) : _width(w), _height(h) {}

        unsigned int width() const { return _width; }
        unsigned int height() const { return _height; }

        std::string to_string() const override {
            std::stringstream ss;
            ss << "WindowResizeEvent: " << _width << ", " << _height;
            return ss.str();
        }

        EVENT_CLASS_DEFINITION(WindowResize, EventCategoryWindow)

    private:
        unsigned int _width, _height;
    };

    class WindowCloseEvent : public Event {
    public:
        WindowCloseEvent() = default;

        EVENT_CLASS_DEFINITION(WindowClose, EventCategoryWindow)
    };

}

#endif //ANIMATIONVCL_WINDOW_EVENTS_HH
