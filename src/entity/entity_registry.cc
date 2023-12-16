#include "entity_registry.hh"

#include <stdexcept>

namespace xfrc::entity {

entity_registry::entity_registry() = default;

// see header comment on declaration as to why NOLINT is here.
std::map<uuid, entity const &> entity_registry::registry {}; // NOLINT

auto
entity_registry::register_entity(entity const &entity) -> void {
    if (entity_registry::entity_exists(entity.get_uuid())) {
        throw std::logic_error { "[entity_registry] Attempted to register a "
                                 "UUID that has already been registered." };
    }

    registry.insert({ entity.get_uuid(), entity });
}

auto
entity_registry::unregister_entity(uuid uuid_) -> void {
    if (! entity_registry::entity_exists(uuid_)) {
        throw std::logic_error { "[entity_registry] Attempted to unregister a "
                                 "UUID that hasn't been registered." };
    }

    registry.erase(registry.find(uuid_));
}

auto
entity_registry::entity_exists(uuid uuid_) -> bool {
    return registry.find(uuid_) != registry.end();
}

auto
entity_registry::get_entity(uuid uuid_) -> entity const & {
    if (! entity_registry::entity_exists(uuid_)) {
        throw std::logic_error {
            "[entity_registry] Attempted to access an unregistered entity"
        };
    }

    return registry.at(uuid_);
}

auto
generate_uuid() -> uuid {
    static uuid entity_count = 0;
    return entity_count++;
}

} // namespace xfrc::entity
