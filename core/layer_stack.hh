//
// Created by pponchon on 17/03/2022.
//

#ifndef ANIMATIONVCL_LAYER_STACK_HH
#define ANIMATIONVCL_LAYER_STACK_HH

#include "layer.hh"

#include <vector>

namespace vcl::core {

    class LayerStack {
    public:
        using iterator = std::vector<Layer *>::iterator;
        using reverse_iterator = std::vector<Layer *>::reverse_iterator;
        using const_iterator = std::vector<Layer *>::const_iterator;
        using const_reverse_iterator = std::vector<Layer *>::const_reverse_iterator;

        LayerStack() = default;

        ~LayerStack() {
            for (auto *layer: _layers) {
                layer->on_detach();
                delete layer;
            }
        }

        void push_layer(Layer *layer) {
            _layers.push_back(layer);
            layer->on_attach();
        }

        void pop_layer(Layer *layer) {
            auto it = std::find(begin(), end(), layer);
            if (it != end()) {
                layer->on_detach();
                _layers.erase(it);
            }
        }

        size_t stack_size() const { return _layers.size(); }

        iterator begin() { return _layers.begin(); }
        iterator end() { return _layers.end(); }
        reverse_iterator rbegin() { return _layers.rbegin(); }
        reverse_iterator rend() { return _layers.rend(); }
        const_iterator begin() const { return _layers.begin(); }
        const_iterator end() const { return _layers.end(); }
        const_reverse_iterator rbegin() const { return _layers.rbegin(); }
        const_reverse_iterator rend() const { return _layers.rend(); }

    private:
        std::vector<Layer *> _layers;
    };

}

#endif //ANIMATIONVCL_LAYER_STACK_HH
