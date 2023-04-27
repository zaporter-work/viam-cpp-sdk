#pragma once
#include <stdexcept>

class ViamException : public std::runtime_error {
   public:
    ViamException() : std::runtime_error("Unknown Viam Exception"){};
    ViamException(const std::string& what...) : std::runtime_error("ViamException: " + what){};
    ViamException(const std::string& type, const std::string& what...)
        : std::runtime_error("ViamException(" + type + "): " + what){};
};

class InsecureConnectionException : public ViamException {
   public:
    InsecureConnectionException(const std::string& what...)
        : ViamException("InsecureConnectionException", what){};
};

class DuplicateResourceException : public ViamException {
   public:
    DuplicateResourceException(const std::string& what...)
        : ViamException("DuplicateResourceException", what){};
};

class ResourceNotFoundException : public ViamException {};

class NotSupportedException : public ViamException {};

class ValidationException : public ViamException {};

// Python calls this a ViamGRPCError
class ConnectionException : public ViamException {};
