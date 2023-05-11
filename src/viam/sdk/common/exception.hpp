#pragma once
#include <grpc/status.h>
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <string>

namespace viam {
namespace sdk {

enum class ViamErrorCode : unsigned int {
    generic = 0,
    permission_denied = 1,
    duplicate_resource = 2,
    unsupported = 3,
    validation = 4,
    connection = 5
};

class ViamException : public std::runtime_error {
   public:
    template <typename... Args>
    explicit ViamException(Args const&... what)
        : std::runtime_error("ViamException: " + concat_exception_varargs(what...)),
          _error_code(ViamErrorCode::generic){};

    template <typename... Args>
    explicit ViamException(const std::string& type, const ViamErrorCode& code, Args const&... what)
        : std::runtime_error("ViamException(" + type + "): " + concat_exception_varargs(what...)),
          _error_code(code){};

    virtual ~ViamException() = default;

    [[nodiscard]] static ViamException from_grpc_status(grpc_status_code code);
    [[nodiscard]] static ViamException from_viam_error_code(ViamErrorCode code);

    ViamErrorCode get_error_code() const;

   private:
    ViamErrorCode _error_code;

    // Will be selected if no args are passed
    // PRNote: This could be made constexpr const char*
    std::string concat_exception_varargs() {
        return "Unknown";
    }
    template <typename... Args>
    std::string concat_exception_varargs(Args const&... args) {
        std::ostringstream stream;
        using List = int[];
        (void)List{0, ((void)(stream << args << " "), 0)...};
        return stream.str();
    }
};

class PermissionDeniedException : public ViamException {
   public:
    template <typename... Args>
    explicit PermissionDeniedException(Args const&... what)
        : ViamException("PermissionDenied", ViamErrorCode::permission_denied, what...){};
};

class DuplicateResourceException : public ViamException {
   public:
    template <typename... Args>
    explicit DuplicateResourceException(Args const&... what)
        : ViamException("DuplicateResource", ViamErrorCode::duplicate_resource, what...){};
};

// TODO
class ResourceNotFoundException : public ViamException {};

class UnsupportedException : public ViamException {};

class ValidationException : public ViamException {};

// Python calls this a ViamGRPCError
class ConnectionException : public ViamException {};
}  // namespace sdk
}  // namespace viam
