//
// Created by pponchon on 17/03/2022.
//

#ifndef ANIMATIONVCL_APPLICATION_EVENT_HH
#define ANIMATIONVCL_APPLICATION_EVENT_HH

#include "event.hh"

namespace vcl::event {
#define APP_EVENTS(class_def) \
        class_def(AppTick)    \
        class_def(AppUpdate)  \
        class_def(AppRender)  \

#define my_def(name)                                            \
    class name##Event : public Event {                          \
    public:                                                     \
        name##Event() = default;                                \
        EVENT_CLASS_DEFINITION(name, EventCategoryApplication)  \
    };

    APP_EVENTS(my_def)

#undef my_def

#undef APP_EVENTS
}

#endif //ANIMATIONVCL_APPLICATION_EVENT_HH
