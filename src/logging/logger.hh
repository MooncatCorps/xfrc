#ifndef XFRC_LOGGING_LOGGER_HH
#define XFRC_LOGGING_LOGGER_HH

#include <string>

namespace xfrc::logging {

template <class... args>
auto
log_info(std::string const &message, args &&...arguments) -> void;

template <class... args>
auto
log_success(std::string const &message, args &&...arguments) -> void;

template <class... args>
auto
log_failure(std::string const &message, args &&...arguments) -> void;

template <class... args>
auto
log_error(std::string const &message, args &&...arguments) -> void;

template <class... args>
auto
log_warning(std::string const &message, args &&...arguments) -> void;

template <class... args>
auto
log_debug(std::string const &message, args &&...arguments) -> void;

} // namespace xfrc::logging

#include "logger.impl"

#endif
