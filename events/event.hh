//
// Created by pponchon on 17/03/2022.
//

#ifndef ANIMATIONVCL_EVENT_HH
#define ANIMATIONVCL_EVENT_HH

#include <functional>
#include <string>

namespace vcl::event {

    enum class EventType {
        None = 0,
        WindowClose, WindowResize, WindowFocus, WindowLostFocus, WindowMoved,
        AppTick, AppUpdate, AppRender,
        KeyPressed, KeyReleased, KeyTyped,
        MouseButtonPressed, MouseButtonReleased, MouseMoved, MouseScrolled
    };

    enum EventCategory {
        None = 0,
        EventCategoryApplication = 1 << 0,
        EventCategoryInput = 1 << 1,
        EventCategoryKeyboard = 1 << 2,
        EventCategoryMouse = 1 << 3,
        EventCategoryMouseButton = 1 << 4,
        EventCategoryWindow = 1 << 5
    };

#define EVENT_CLASS_TYPE(type_) static EventType type() { return EventType::type_; }        \
                               virtual EventType event_type() const override { return type(); } \
                               virtual const char *name() const override { return #type_; }

#define EVENT_CLASS_CATEGORY(category) virtual int category_flags() const override { return category; }

#define EVENT_CLASS_DEFINITION(type, category) \
            EVENT_CLASS_TYPE(type)             \
            EVENT_CLASS_CATEGORY(category)

    struct Event {
    public:
        virtual ~Event() = default;

        bool handled = false;

        virtual EventType event_type() const = 0;
        virtual const char *name() const = 0;
        virtual int category_flags() const = 0;

        virtual std::string to_string() const { return std::string(name()); }

        bool is_category(EventCategory category) const {
            return category_flags() & category;
        }
    };

    class EventDispatcher {
    public:
        EventDispatcher(Event& event) : _event_ref(event) {}

        template<typename T, typename F>
        bool dispatch(const F& func) {
            if (_event_ref.event_type() == T::type()) {
                _event_ref.handled |= func(static_cast<T&>(_event_ref));
                return true;
            }
            return false;
        }

    private:
        Event& _event_ref;
    };

    template<typename OStream>
    inline OStream& operator<<(OStream& os, const Event& event) {
        return os << event.to_string();
    }

#define BIND_EVENT_FN(fn) [this](auto&&... args) -> decltype(auto) { return this->fn(std::forward<decltype(args)>(args)...); }

}

#endif //ANIMATIONVCL_EVENT_HH
