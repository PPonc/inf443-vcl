//
// Created by pponchon on 17/03/2022.
//

#ifndef ANIMATIONVCL_MOUSE_EVENT_HH
#define ANIMATIONVCL_MOUSE_EVENT_HH

#include "event.hh"
#include <sstream>

namespace vcl::event {

    class MouseMovedEvent : public Event {
    public:
        MouseMovedEvent(const float x, const float y) : _mouseX(x), _mouseY(y) {}

        float x() const { return _mouseX; }

        float y() const { return _mouseY; }

        std::string to_string() const override {
            std::stringstream ss;
            ss << "MouseMovedEvent: " << _mouseX << ", " << _mouseY;
            return ss.str();
        }

        EVENT_CLASS_DEFINITION(MouseMoved, EventCategoryMouse | EventCategoryInput)

    private:
        float _mouseX, _mouseY;
    };

    class MouseScrolledEvent : public Event {
    public:
        MouseScrolledEvent(const float x, const float y) : _mouseX(x), _mouseY(y) {}

        float x_offset() const { return _mouseX; }

        float y_offset() const { return _mouseY; }

        std::string to_string() const override {
            std::stringstream ss;
            ss << "MouseScrolledEvent: " << _mouseX << ", " << _mouseY;
            return ss.str();
        }

        EVENT_CLASS_DEFINITION(MouseScrolled, EventCategoryMouse | EventCategoryInput)

    private:
        float _mouseX, _mouseY;
    };

//    class MouseButtonEvent : public Event {
//    public:
//        MouseCode mouse_button() const { return m_Button; }
//
//        EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput | EventCategoryMouseButton)
//
//    protected:
//        MouseButtonEvent(const MouseCode button)
//                : m_Button(button) {}
//
//        MouseCode m_Button;
//    };
//
//    class MouseButtonPressedEvent : public MouseButtonEvent {
//    public:
//        MouseButtonPressedEvent(const MouseCode button)
//                : MouseButtonEvent(button) {}
//
//        std::string ToString() const override {
//            std::stringstream ss;
//            ss << "MouseButtonPressedEvent: " << m_Button;
//            return ss.str();
//        }
//
//        EVENT_CLASS_TYPE(MouseButtonPressed)
//    };
//
//    class MouseButtonReleasedEvent : public MouseButtonEvent {
//    public:
//        MouseButtonReleasedEvent(const MouseCode button)
//                : MouseButtonEvent(button) {}
//
//        std::string ToString() const override {
//            std::stringstream ss;
//            ss << "MouseButtonReleasedEvent: " << m_Button;
//            return ss.str();
//        }
//
//        EVENT_CLASS_TYPE(MouseButtonReleased)
//    };

}

#endif //ANIMATIONVCL_MOUSE_EVENT_HH
