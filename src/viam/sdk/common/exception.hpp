#pragma once
#include <grpc/status.h>
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <string>

template <typename... Args>
std::string concat_varargs(Args const&... args) {
    std::ostringstream stream;
    using List = int[];
    (void)List{0, ((void)(stream << args << " "), 0)...};

    return stream.str();
}

enum ViamErrorCode {
    GENERIC = 0,
    PERMISSION_DENIED = 1,
    DUPLICATE_RESOURCE = 2,
    RESOURCE_NOT_FOUND = 3,
    NOT_SUPPORTED = 4,
    VALIDATION = 5,
    CONNECTION = 6
};

grpc_status_code viam_error_to_grpc_status(ViamErrorCode code) {
    return grpc_status_code::GRPC_STATUS_UNKNOWN;
}
ViamErrorCode grpc_status_to_viam_error_code(grpc_status_code code) {
    return ViamErrorCode::GENERIC;
}

class ViamException : public std::runtime_error {
   public:
    ViamErrorCode error_code;
    template <typename... Args>
    ViamException(Args const&... what)
        : std::runtime_error("ViamException: " + concat_varargs(what...)){};

    template <typename... Args>
    ViamException(const std::string& type, Args const&... what)
        : std::runtime_error("ViamException(" + type + "): " + concat_varargs(what...)){};

    static ViamException from_grpc_status(grpc_status_code code) {
        return ViamException(code);
    }
    static ViamException from_viam_error_code(ViamErrorCode code) {
        // TODO
        return ViamException(code);
    }
};

class PermissionDeniedException : public ViamException {
   public:
    template <typename... Args>
    PermissionDeniedException(Args const&... what) : ViamException("PermissionDenied", what...){};
};

class DuplicateResourceException : public ViamException {
   public:
    DuplicateResourceException(const std::string& what...)
        : ViamException("DuplicateResource", what){};
};

// TODO
class ResourceNotFoundException : public ViamException {};

class NotSupportedException : public ViamException {};

class ValidationException : public ViamException {};

// Python calls this a ViamGRPCError
class ConnectionException : public ViamException {};
