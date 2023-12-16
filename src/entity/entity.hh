#ifndef XFRC_ENTITY_ENTITY_HH
#define XFRC_ENTITY_ENTITY_HH

#include <string>

namespace xfrc::entity {

using uuid             = unsigned int;
using property_bitmask = unsigned int;

class entity {
public:
    explicit entity(std::string constant_name);

    entity(const entity &)     = default;
    entity(entity &&) noexcept = delete;

    auto
    operator= (const entity &) -> entity & = default;
    auto
    operator= (entity &&) -> entity & = delete;

    virtual ~entity();

    [[nodiscard]] auto
    constant_name() const -> std::string const &;

    [[nodiscard]] auto
    variable_name() const -> std::string const &;

    auto
    set_variable_name(std::string name) -> void;

    [[nodiscard]] auto
    get_uuid() const -> uuid;

    virtual auto
    publish_properties(property_bitmask properties) -> void;

private:
    std::string _constant_name;
    std::string _variable_name;
    uuid        _uuid;
};

} // namespace xfrc::entity

#endif
