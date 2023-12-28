#include "entity.hh"

#include <sstream>

namespace xfrc::entity {

auto
generate_uuid() -> uuid {
    static uuid entity_count = 0;
    return entity_count++;
}

entity::entity(std::string constant_name, std::string variable_name)
    : _constant_name(std::move(constant_name))
    , _variable_name(std::move(variable_name))
    , _uuid(generate_uuid())
    , _enabled(false) {
    std::stringstream strstr;
    strstr << constant_name << "::" << variable_name;
    _fullname = strstr.str();
}

// Name

auto
entity::constant_name() const -> std::string const & {
    return this->_constant_name;
}

auto
entity::variable_name() const -> std::string const & {
    return this->_variable_name;
}

auto
entity::set_variable_name(std::string name) -> void {
    this->_variable_name = std::move(name);

    std::stringstream strstr;
    strstr << _constant_name << "::" << _variable_name;
    _fullname = strstr.str();
}

auto
entity::full_name() const -> std::string const & {
    return _fullname;
}

auto
entity::get_uuid() const -> uuid {
    return this->_uuid;
}

// State

auto
entity::enable() -> void {
    _enabled = true;
    this->on_enable();
}

auto
entity::disable() -> void {
    _enabled = false;
    this->on_disable();
}

auto
entity::reset() -> void {
    on_reset();
    disable();
}

auto
entity::is_enabled() const -> bool {
    return _enabled;
}

auto
entity::is_disabled() const -> bool {
    return ! _enabled;
}

} // namespace xfrc::entity
