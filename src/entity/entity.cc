#include "entity.hh"

#include "entity/entity_registry.hh"

namespace xfrc::entity {

entity::entity(std::string constant_name)
    : _constant_name(std::move(constant_name))
    , _variable_name("none")
    , _uuid(generate_uuid()) {
    entity_registry::register_entity(*this);
}

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
}

auto
entity::get_uuid() const -> uuid {
    return this->_uuid;
}

} // namespace xfrc::entity
