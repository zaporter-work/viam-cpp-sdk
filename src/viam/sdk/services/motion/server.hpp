/// @file services/motion/server.hpp
///
/// @brief Implements a gRPC server for the `Motion` service.
#pragma once

#include <memory>

#include <viam/api/service/motion/v1/motion.grpc.pb.h>

#include <viam/sdk/resource/resource_manager.hpp>
#include <viam/sdk/resource/resource_server_base.hpp>
#include <viam/sdk/rpc/server.hpp>

namespace viam {
namespace sdk {

/// @class MotionServer
/// @brief gRPC server implementation of a `Motion` service.
/// @ingroup Motion
class MotionServer : public ResourceServer,
                     public viam::service::motion::v1::MotionService::Service {
   public:
    MotionServer();
    explicit MotionServer(std::shared_ptr<ResourceManager> manager);

    ::grpc::Status Move(::grpc::ServerContext* context,
                        const ::viam::service::motion::v1::MoveRequest* request,
                        ::viam::service::motion::v1::MoveResponse* response) override;
    ::grpc::Status MoveOnMap(::grpc::ServerContext* context,
                             const ::viam::service::motion::v1::MoveOnMapRequest* request,
                             ::viam::service::motion::v1::MoveOnMapResponse* response) override;
    ::grpc::Status MoveOnGlobe(::grpc::ServerContext* context,
                               const ::viam::service::motion::v1::MoveOnGlobeRequest* request,
                               ::viam::service::motion::v1::MoveOnGlobeResponse* response) override;
    ::grpc::Status GetPose(::grpc::ServerContext* context,
                           const ::viam::service::motion::v1::GetPoseRequest* request,
                           ::viam::service::motion::v1::GetPoseResponse* response) override;
    ::grpc::Status DoCommand(::grpc::ServerContext* context,
                             const ::viam::common::v1::DoCommandRequest* request,
                             ::viam::common::v1::DoCommandResponse* response) override;

    void register_server(std::shared_ptr<Server> server) override;
};

}  // namespace sdk
}  // namespace viam
