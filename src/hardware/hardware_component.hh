#ifndef XFRC_COMPONENT_COMPONENT_HH
#define XFRC_COMPONENT_COMPONENT_HH

#include "entity/entity.hh"
#include <string>

namespace xfrc::hardware {

class hardware_component : public virtual entity::entity {
public:
    explicit hardware_component(std::string component_name);

    [[nodiscard]] auto
    is_enabled() const -> bool;

    auto
    enable() -> void;

    auto
    disable() -> void;

protected:
    virtual auto
    on_disable() -> void;

    virtual auto
    on_enable() -> void;

private:
    bool _is_enabled;
};

} // namespace xfrc::hardware

#endif
