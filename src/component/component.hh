#ifndef XFRC_COMPONENT_COMPONENT_HH
#define XFRC_COMPONENT_COMPONENT_HH

#include <string>

namespace xfrc {

class component {
public:
    explicit component(std::string name);

    auto
    get_uuid() -> unsigned long int;

    auto
    get_name() -> std::string const &;

    auto
    is_enabled() -> bool;

    auto
    enable() -> void;

    auto
    disable() -> void;

private:
    unsigned long int uuid_;
    std::string       name_;
    bool              is_enabled_;
};

} // namespace xfrc

#endif
