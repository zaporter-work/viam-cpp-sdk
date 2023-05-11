#include <viam/sdk/resource/resource.hpp>

#include <unordered_map>

#include <grpcpp/support/status.h>

#include <viam/sdk/common/exception.hpp>
#include <viam/sdk/common/utils.hpp>
#include <viam/sdk/resource/resource_api.hpp>

namespace viam {
namespace sdk {

Resource::~Resource() = default;

grpc::StatusCode Resource::stop(AttributeMap extra) {
    return stop();
}

grpc::StatusCode Resource::stop() {
    return grpc::StatusCode::UNIMPLEMENTED;
}

const std::string& Type::type_namespace() const {
    return namespace_;
}

void Type::set_namespace(const std::string type_namespace) {
    this->namespace_ = type_namespace;
}

void Type::set_resource_type(const std::string resource_type) {
    this->resource_type_ = resource_type;
}

const std::string& Type::resource_type() const {
    return resource_type_;
}

const std::string& Subtype::resource_subtype() const {
    return resource_subtype_;
}

void Subtype::set_resource_subtype(const std::string subtype) {
    this->resource_subtype_ = subtype;
}

Subtype Subtype::from_string(std::string subtype) {
    if (std::regex_match(subtype, MODEL_REGEX)) {
        std::vector<std::string> subtype_parts;
        boost::split(subtype_parts, subtype, boost::is_any_of(":"));
        return {subtype_parts.at(0), subtype_parts.at(1), subtype_parts.at(2)};
    }
    throw ViamException("string " + subtype + " is not a valid subtype name");
}

Subtype::Subtype(Type type, std::string resource_subtype)
    : Type(type), resource_subtype_(resource_subtype) {}

Subtype::Subtype(std::string namespace_, std::string resource_type, std::string resource_subtype)
    : Type(namespace_, resource_type), resource_subtype_(resource_subtype) {}

bool Subtype::is_service_type() {
    return (this->resource_type() == "service");
}

bool Subtype::is_component_type() {
    return (this->resource_type() == "component");
}

const Subtype* Name::to_subtype() const {
    return this;
}

const std::string& Name::name() const {
    return name_;
}

API Resource::static_api() {
    return {RDK, RESOURCE, "Resource"};
}

void Resource::reconfigure(Dependencies deps, ResourceConfig cfg){};

ResourceType Resource::type() const {
    return {RESOURCE};
}

ResourceName Resource::get_resource_name(std::string name) {
    ResourceName r;
    *r.mutable_namespace_() = RDK;
    *r.mutable_type() = RESOURCE;
    *r.mutable_subtype() = this->dynamic_api().resource_subtype();
    *r.mutable_name() = std::move(name);

    return r;
}

viam::common::v1::ResourceName Name::to_proto() const {
    viam::common::v1::ResourceName rn;
    *rn.mutable_namespace_() = this->type_namespace();
    *rn.mutable_name() = this->name();
    *rn.mutable_type() = this->resource_type();
    *rn.mutable_subtype() = this->resource_subtype();
    return rn;
}

Name Name::from_string(std::string name) {
    if (!std::regex_match(name, NAME_REGEX)) {
        throw ViamException("Received invalid Name string: " + name);
    }
    std::vector<std::string> slash_splits;
    boost::split(slash_splits, name, boost::is_any_of("/"));

    Subtype subtype = Subtype::from_string(slash_splits.at(0));

    std::vector<std::string> colon_splits;
    boost::split(colon_splits, slash_splits.at(1), boost::is_any_of(":"));
    std::string remote;
    std::string resource_name = colon_splits.at(0);
    if (colon_splits.size() > 1) {
        remote = colon_splits.at(0);
        resource_name = colon_splits.at(1);
    }

    return Name(subtype, remote, resource_name);
}

Name::Name(Subtype subtype, std::string remote, std::string name)
    : Subtype(subtype), remote_name_(std::move(remote)), name_(std::move(name)) {}

bool operator==(const Subtype& lhs, const Subtype& rhs) {
    return lhs.to_string() == rhs.to_string();
}

bool operator<(const Subtype& lhs, const Subtype& rhs) {
    return lhs.to_string() < rhs.to_string();
}

bool operator==(const Name& lhs, const Name& rhs) {
    return lhs.to_string() == rhs.to_string();
}

bool operator==(const RPCSubtype& lhs, const RPCSubtype& rhs) {
    return lhs.subtype_.to_string() == rhs.subtype_.to_string() &&
           lhs.proto_service_name_ == rhs.proto_service_name_ &&
           lhs.descriptor_.DebugString() == rhs.descriptor_.DebugString();
}

bool operator==(const Model& lhs, const Model& rhs) {
    return lhs.to_string() == rhs.to_string();
}

RPCSubtype::RPCSubtype(Subtype subtype,
                       std::string proto_service_name,
                       const google::protobuf::ServiceDescriptor& descriptor)
    : descriptor_(std::move(descriptor)),
      proto_service_name_(std::move(proto_service_name)),
      subtype_(std::move(subtype)) {}

RPCSubtype::RPCSubtype(Subtype subtype, const google::protobuf::ServiceDescriptor& descriptor)
    : descriptor_(std::move(descriptor)), subtype_(std::move(subtype)) {}

const std::string& RPCSubtype::proto_service_name() const {
    return proto_service_name_;
};

const Subtype& RPCSubtype::subtype() const {
    return subtype_;
};

ModelFamily::ModelFamily(std::string namespace_, std::string family)
    : namespace_(namespace_), family_(family) {}

Model::Model(ModelFamily model_family, std::string model_name)
    : model_family_(std::move(model_family)), model_name_(std::move(model_name)) {}

Model::Model(std::string namespace_, std::string family, std::string model_name)
    : Model(ModelFamily(std::move(namespace_), std::move(family)), std::move(model_name)) {}

Model Model::from_str(std::string model) {
    if (std::regex_match(model, MODEL_REGEX)) {
        std::vector<std::string> model_parts;
        boost::split(model_parts, model, boost::is_any_of(":"));
        return {model_parts.at(0), model_parts.at(1), model_parts.at(2)};
    }
    if (std::regex_match(model, SINGLE_FIELD_REGEX)) {
        return {"rdk", "builtin", model};
    }
    throw ViamException("string " + model + " is not a valid model name");
}

std::string ModelFamily::to_string() const {
    if (namespace_.empty()) {
        return family_;
    }
    return namespace_ + ":" + family_;
}

std::string Model::to_string() const {
    const std::string mf = model_family_.to_string();
    if (mf.empty()) {
        return model_name_;
    }
    return mf + ":" + model_name_;
}

Model::Model() : Model(ModelFamily(RDK, BUILTIN), BUILTIN) {}

}  // namespace sdk
}  // namespace viam
