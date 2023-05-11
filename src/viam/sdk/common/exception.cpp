#include <viam/sdk/common/exception.hpp>
namespace viam {
namespace sdk {

grpc_status_code viam_error_to_grpc_status(ViamErrorCode code) {
    return grpc_status_code::GRPC_STATUS_UNKNOWN;
}
ViamErrorCode grpc_status_to_viam_error_code(grpc_status_code code) {
    return ViamErrorCode::generic;
}
ViamException ViamException::from_grpc_status(grpc_status_code code) {
    return from_viam_error_code(grpc_status_to_viam_error_code(code));
}
ViamException ViamException::from_viam_error_code(ViamErrorCode code) {
    switch (code) {
            /* case ViamErrorCode::PERMISSION_DENIED: { */
            /*     return PermissionDeniedException(); */
            /* } */
            /* case ViamErrorCode::DUPLICATE_RESOURCE: { */
            /*     return DuplicateResourceException(); */
            /* } */
            /* case ViamErrorCode::UNSUPPORTED: { */
            /*     return UnsupportedException(); */
            /* } */
            /* case ViamErrorCode::VALIDATION: { */
            /*     return ValidationException(); */
            /* } */
            /* case ViamErrorCode::CONNECTION: { */
            /*     return ConnectionException(); */
            /* } */

        case ViamErrorCode::generic:
        default: {
            return ViamException("Unknown");
        }
    }
}

ViamErrorCode ViamException::get_error_code() const {
    return _error_code;
}
}  // namespace sdk
}  // namespace viam
