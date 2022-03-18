//
// Created by pponchon on 17/03/2022.
//

#ifndef ANIMATIONVCL_NAMED_OBJECT_HH
#define ANIMATIONVCL_NAMED_OBJECT_HH

#include <string>

namespace vcl::core {

    class NamedObject {
    public:
        NamedObject(const std::string& name) : _name(name) {}

        const std::string& name() const { return _name; }
        const char *name_str() const { return _name.c_str(); }
    protected:
        std::string& name() { return _name; }

    private:
        std::string _name;
    };

}

#endif //ANIMATIONVCL_NAMED_OBJECT_HH
