#ifndef XFRC_ENTITY_ENTITY_REGISTRY_HH
#define XFRC_ENTITY_ENTITY_REGISTRY_HH

#include "entity.hh"
#include <map>

namespace xfrc::entity {

// Employed to hide registry
class entity_registry {
public:
    static auto
    register_entity(entity const &entity) -> void;

    static auto
    unregister_entity(uuid uuid_) -> void;

    static auto
    entity_exists(uuid uuid_) -> bool;

    static auto
    get_entity(uuid uuid_) -> entity const &;

private:
    explicit entity_registry();

    // clang-tidy incorrectly marks this as wrong
    // See: https://bugs.llvm.org/show_bug.cgi?id=48040
    // TODO: remove NOLINT when issue is solved.
    static std::map<uuid, entity const &> registry; // NOLINT
};

auto
generate_uuid() -> uuid;

} // namespace xfrc::entity

#endif
