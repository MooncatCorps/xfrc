#ifndef XFRC_ENTITY_ENTITY_HH
#define XFRC_ENTITY_ENTITY_HH

#include <cstdint>
#include <string>

namespace xfrc::entity {

using uuid = unsigned int;

auto
generate_uuid() -> uuid;

class entity {
public:
    explicit entity(std::string constant_name,
                    std::string variable_name = "unnamed");

    entity(const entity &)     = default;
    entity(entity &&) noexcept = delete;

    auto
    operator= (const entity &) -> entity & = default;
    auto
    operator= (entity &&) -> entity & = delete;

    virtual ~entity() = default;

    // Name

    [[nodiscard]] auto
    constant_name() const -> std::string const &;

    auto
    set_variable_name(std::string name) -> void;

    [[nodiscard]] auto
    variable_name() const -> std::string const &;

    [[nodiscard]] auto
    get_uuid() const -> uuid;

    [[nodiscard]] auto
    full_name() const -> std::string const &;

    // State

    auto
    enable() -> void;

    auto
    disable() -> void;

    auto
    reset() -> void;

    [[nodiscard]] auto
    is_enabled() const -> bool;

    [[nodiscard]] auto
    is_disabled() const -> bool;

protected:
    virtual auto
    on_enable() -> void = 0;

    virtual auto
    on_disable() -> void = 0;

    virtual auto
    on_reset() -> void = 0;

private:
    std::string _constant_name;
    std::string _variable_name;
    std::string _fullname;

    uuid _uuid;
    bool _enabled;
};

} // namespace xfrc::entity

#endif
