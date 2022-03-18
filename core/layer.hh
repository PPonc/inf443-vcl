//
// Created by pponchon on 17/03/2022.
//

#ifndef ANIMATIONVCL_LAYER_HH
#define ANIMATIONVCL_LAYER_HH

#include <string>
#include "events/event.hh"

#include "named_object.hh"

namespace vcl::core {

    class Layer : public NamedObject {
    public:
        Layer(const std::string& name = "Layer") : NamedObject(name) {}

        virtual ~Layer() = default;

        virtual void on_attach() {}
        virtual void on_detach() {}
        virtual void on_update(/* TODO Timestep ts */) {}
        virtual void on_imgui_render() {}
        virtual void on_event(event::Event& e) {}
    };

}

#endif //ANIMATIONVCL_LAYER_HH
